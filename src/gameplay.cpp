#include <iostream>
#include "gameplay.h"


bool GamePlay :: IsValid( int src_c, int src_r, int dst_c, int dst_r )  {

    if ( src_r >= 0 && src_r < MAX_ROWS && src_c >= 0 && src_c < MAX_COLS &&
         dst_r >= 0 && dst_r < MAX_ROWS && dst_c >= 0 && dst_c < MAX_COLS &&
         dst_r != src_r || dst_c != src_c )  {

            return true;
        }

    return false;
}

int GamePlay :: GetColIndex( char ch )  {

    return ch - 'a';
}

int GamePlay :: GetRowIndex( char ch )  {

    return ch - '0' - 1;
}

void GamePlay :: InitPieces( void )  {

    for ( int col = 0; col < MAX_COLS; col++ ) {

        m_players[PLAYER_1] -> Add( m_board -> GetPiece( col, 1 ) );
        m_players[PLAYER_2] -> Add( m_board -> GetPiece( col, 6 ) );
    }

    for ( int col = 0; col < MAX_COLS; col++ ) {

        m_players[PLAYER_1] -> Add( m_board -> GetPiece( col, 0 ) ); 
        m_players[PLAYER_2] -> Add( m_board -> GetPiece( col, 7 ) );
    }

    m_players[PLAYER_1] -> SetKing( m_board -> GetPiece( 4, 0 ) );
    m_players[PLAYER_2] -> SetKing( m_board -> GetPiece( 4, 7 ) );
}

void GamePlay :: ChangeTurn( void )  {

    m_turn = ( m_turn == PLAYER_1 ) ? PLAYER_2 : PLAYER_1;
}

bool GamePlay :: ValidMovement( IPiece *piece, int dst_c, int dst_r, PlayerNumber opponent )  {

    IPiece *captured_piece = m_board -> GetPiece( dst_c, dst_r );
    int    col             = piece -> Position().col;
    int    row             = piece -> Position().row;

    m_board -> SetPiece( col, row, nullptr );

    if ( m_players[m_turn] -> GetCheckStatus() )  { //player on check

        if ( captured_piece != nullptr )  {

            m_players[opponent] -> Remove( captured_piece );
            m_board -> RemovePiece( captured_piece -> Position().col, captured_piece -> Position().row );
        }

        m_board -> SetPiece( dst_c, dst_r, piece );

        if ( m_players[opponent] -> CanCheck() )  { //if check is not blocked

            m_board -> SetPiece( col, row, piece );
            m_board -> SetPiece( dst_c, dst_r, captured_piece );
            m_players[opponent] -> Add( captured_piece );
            return false;
        }

        m_players[m_turn] -> GetKing() -> SetStatus( NORMAL );
        m_players[m_turn] -> SetCheckStatus( false );
        return true;
    }

    if ( m_players[opponent] -> CanCheck() )  { //checks if movement can make player check themselves

        m_board -> SetPiece( col, row, piece );
        return false;
    }

    if ( captured_piece != nullptr )  {

        SpecialCases( captured_piece, opponent );
    }

    return true;
}

void GamePlay :: SpecialCases( IPiece *piece, PlayerNumber opponent )  {

    int          direction;
    IPiece       *castle    = nullptr;
    IPiece       *remove    = nullptr;
    stPosition   pos        = piece -> Position();

    switch ( piece -> GetStatus() )  {

        case CAPTURED:
            m_players[opponent] -> Remove( piece );
            m_board -> RemovePiece( pos.col, pos.row );
            return;

        case LONGCASTLE:
            castle = m_board -> GetPiece( ( pos.col - 2 ), pos.row );
            m_board -> SetPiece( ( pos.col + 1 ), pos.row, castle );
            castle -> SetMovementCount();
            m_board -> SetPiece( ( pos.col - 2 ), pos.row, nullptr );
            break;

        case SHORTCASTLE:
            castle = m_board -> GetPiece( ( pos.col + 1 ), pos.row );
            m_board -> SetPiece( ( pos.col - 1 ), pos.row, castle );
            castle -> SetMovementCount();
            m_board -> SetPiece( ( pos.col + 1 ), pos.row, nullptr );
            break;

        case ENPASSANT: 
            direction = ( piece -> GetColor() == WHITE ) ? -1 : 1;
            remove = m_board -> GetPiece( pos.col, ( pos.row + direction ) );
            m_players[opponent] -> Remove( remove );
            m_board -> RemovePiece( pos.col, ( pos.row + direction ) );
            break;

        case PROMOTION:
            m_promotion = true;
            break;

        default: //status NORMAL
            return;
    }

    piece -> SetStatus( NORMAL );
}

GamePlay :: GamePlay( IBoard *board )  {

    this -> m_board = board;

    this -> m_players.insert( std :: make_pair< PlayerNumber, Player* >( PLAYER_1, new Player( WHITE ) ) );
    this -> m_players.insert( std :: make_pair< PlayerNumber, Player* >( PLAYER_2, new Player( BLACK ) ) );
}

GamePlay :: ~GamePlay( void )  {

    for ( auto item : m_players ) {
        
        delete item.second;
    }

    m_players.clear();
}

void GamePlay :: NewGame( void )  {

    m_board -> Init();
    InitPieces();
}

bool GamePlay :: Move( char src_col, char src_row, char dst_col, char dst_row )  {

    int  src_c = GetColIndex( src_col );
    int  src_r = GetRowIndex( src_row );
    int  dst_c = GetColIndex( dst_col );
    int  dst_r = GetRowIndex( dst_row );

    if ( IsValid( src_c, src_r, dst_c, dst_r ) )  {
        
        PlayerNumber   opponent = ( m_turn == PLAYER_1 ) ? PLAYER_2 : PLAYER_1;
        IPiece         *piece   = m_board -> GetPiece( src_c, src_r );

        if ( ( piece != nullptr ) && ( m_players[m_turn] -> CheckPieces( piece ) ) && 
               piece -> CanMove( dst_c, dst_r ) )  {
            
            if ( ValidMovement( piece, dst_c, dst_r, opponent ) )  {

                m_board -> SetPiece( dst_c, dst_r, piece );
                piece -> SetMovementCount();
                SpecialCases( piece, opponent );

                if ( m_players[m_turn] -> CanCheck() )  {

                    m_players[opponent] -> SetCheckStatus( true );
                }

                ChangeTurn();

                return true;
            }
        }
    }

    return false;
}

bool GamePlay :: HasPromotion( void )  {

    return m_promotion;
}

bool GamePlay :: Promote( char dst_col, char dst_row, char promotion )  {

    Pieces         piece_type;
    int            dst_c  = GetColIndex( dst_col );
    int            dst_r  = GetRowIndex( dst_row );
    IPiece         *piece = m_board -> GetPiece( dst_c, dst_r );
    Color          color  = piece -> GetColor();
    PlayerNumber   player = ( color == WHITE ) ? PLAYER_1 : PLAYER_2;

    switch ( promotion )  {

        case 'Q': 
            piece_type = QUEEN; 
            break; 

        case 'B': 
            piece_type = BISHOP; 
            break;

        case 'N': 
            piece_type = KNIGHT; 
            break;

        case 'R':
            piece_type = ROOK; 
            break;

        default:
            return false;
    }

    IPiece *promoted_piece = m_board -> GetPromotion( piece_type, color );

    m_board -> RemovePiece( dst_c, dst_r );
    this -> m_players[player] -> Remove( m_board -> GetPiece( dst_c, dst_r ) );
    m_board -> SetPiece( dst_c, dst_r, promoted_piece ) ;
    this -> m_players[player] -> Add( m_board -> GetPiece( dst_c, dst_r ) );

    m_promotion = false;

    return true;
}

bool GamePlay :: IsCheckmate( void )  {

    return m_checkmate;
}

PlayerNumber GamePlay :: GetTurn( void )  {

    return m_turn;
}

void GamePlay :: Print( void )  {
   
    int count_col = 0;
    int count_row = MAX_ROWS;

    for ( int i = 0; i < ( MAX_COLS * 2 ) + 1; i++ )  {

        if ( i % 2 != 0 )  {

            char output = 'a' + count_col;
            std :: cout << output;
            count_col++;
            continue;
        }

        std :: cout << " ";
    }

    std :: cout << std :: endl;

    for ( int cc = 0; cc < ( MAX_COLS * 2 ) + 1; cc++ )  {

        std :: cout << "-";
    }
    std :: cout << std :: endl;
    
    for ( int row = ( MAX_ROWS - 1 ); row >= 0; row-- )  {

        std :: cout << "|";

        for ( int col = 0; col < MAX_COLS; col++ )  {

            IPiece *piece = m_board -> GetPiece( col, row );

            if ( piece != nullptr )  {

                piece -> Print();
            }
            else  {

                std :: cout << " ";    
            }

            std :: cout << "|";

            if ( col == MAX_COLS - 1 )  {
                
                std :: cout << count_row << std :: endl;
                count_row--;
            }
        }

        for ( int cc = 0; cc < ( MAX_COLS * 2 ) + 1; cc++ )  {

            std :: cout << "-";
        }

        std :: cout << std :: endl;
    }
}