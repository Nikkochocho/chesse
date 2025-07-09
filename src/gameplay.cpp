#include <iostream>
#include "gameplay.h"


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

void GamePlay :: SpecialCases( IPiece *piece )  {

    int          direction;
    IPiece       *castle    = nullptr;
    IPiece       *remove    = nullptr;
    stPosition   pos        = piece -> Position();
    PlayerNumber opponent   = ( m_turn == PLAYER_1 ) ? PLAYER_2 : PLAYER_1;

    switch ( piece -> GetStatus() )  {

        case LONGCASTLE:
            castle = m_board -> GetPiece( ( pos.col - 2 ), pos.row );
            m_board -> SetPiece( ( pos.col + 1 ), pos.row, castle );
            castle -> AddMovementCount();
            m_board -> SetPiece( ( pos.col - 2 ), pos.row, nullptr );
            break;

        case SHORTCASTLE:
            castle = m_board -> GetPiece( ( pos.col + 1 ), pos.row );
            m_board -> SetPiece( ( pos.col - 1 ), pos.row, castle );
            castle -> AddMovementCount();
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

void GamePlay :: InsertChanges( stPosition pos, IPiece *piece, IPiece *target, PlayerNumber opponent, bool IsReverse )  {

    stPosition piece_pos  = piece -> Position();

    if ( !IsReverse )  {

        m_board -> SetPiece( piece_pos.col, piece_pos.row, nullptr );
        

        if ( target != nullptr )  {

            m_board -> SetPiece( pos.col, pos.row, nullptr );
            m_players[opponent] -> Remove( target );
        }

        m_board -> SetPiece( pos.col, pos.row, piece );
    }
    else  {

        m_board -> SetPiece( pos.col, pos.row, piece );
        m_board -> SetPiece( piece_pos.col, piece_pos.row, target );

        if ( target != nullptr )  {

            m_players[opponent] -> Add( target );
        }
    }
}

bool GamePlay :: VirtualMovement( IPiece *piece, int dst_c, int dst_r, PlayerNumber opponent, bool IsEscape )  {

    stPosition   dst_pos;
    stPosition   src_pos  = piece -> Position();
    IPiece       *target  = m_board -> GetPiece( dst_c, dst_r );

    dst_pos.col = dst_c;
    dst_pos.row = dst_r;

    InsertChanges( dst_pos, piece, target, opponent, false );

    if ( m_players[opponent] -> CanCheck() )  { //if check is not blocked

        InsertChanges( src_pos, piece, target, opponent, true );

        return false;
    }

    if ( ( !IsEscape ) && ( m_players[m_turn] -> GetCheckStatus() ) )  { //if check is blocked

        m_players[m_turn] -> GetKing() -> SetStatus( NORMAL );
        m_players[m_turn] -> SetAttacker( nullptr );
        m_players[m_turn] -> SetCheckStatus( false );
    }

    InsertChanges( src_pos, piece, target, opponent, true );

    return true;
}

bool GamePlay :: KingEscape( void )  {

    PlayerNumber opponent   = ( m_turn == PLAYER_1 ) ? PLAYER_2 : PLAYER_1;
    IPiece       *king      = m_players[opponent] -> GetKing();
    int          col        = king -> Position().col;
    int          row        = king -> Position().row;

    for ( int i = -1; i < 2; i++ )  {

        for ( int j = -1; j < 2; j++ )  {

            int      col_pos         = col + j;
            int      row_pos         = row + i;
            IPiece   *captured_piece = m_board -> GetPiece( col_pos, row_pos );

            if ( ( col_pos < 0 || col_pos > 7 ) || ( row_pos < 0 || row_pos > 7 ) )  {

                continue;
            }

            if ( ( king -> CanMove( col_pos, row_pos ) ) && ( VirtualMovement( king, col_pos, row_pos, m_turn, true ) ) )  {
                
                return true;
            }
        }
    }

    return false;
}

bool GamePlay :: HasAvailableMove( std :: list<IPiece*> available_pieces )  {

    int          count    = 0;

    for ( std :: list<IPiece*> :: iterator it = available_pieces.begin(); it != available_pieces.end(); it++ )  {

        IPiece *pPiece = *it; 
        int    col_pos = pPiece -> AvailablePosition().col;
        int    row_pos = pPiece -> AvailablePosition().row;

        if ( !VirtualMovement( pPiece, col_pos, row_pos, m_turn, false ) )  {

            count++;
        }
    }

    if ( count == available_pieces.size() )  {

        return false;
    }

    return true;
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

    if ( ( m_board -> IsValid( src_c, src_r ) ) && ( m_board -> IsValid( dst_c, dst_r ) ) &&
         ( dst_r != src_r || dst_c != src_c ) )  {
        
        PlayerNumber   opponent        = ( m_turn == PLAYER_1 ) ? PLAYER_2 : PLAYER_1;
        IPiece         *piece          = m_board -> GetPiece( src_c, src_r );
        IPiece         *captured_piece = m_board -> GetPiece( dst_c, dst_r );

        if ( ( piece != nullptr ) && ( m_players[m_turn] -> CheckPieces( piece ) ) && ( piece -> CanMove( dst_c, dst_r ) ) )  {
            
            if ( VirtualMovement( piece, dst_c, dst_r, opponent, false ) )  {

                if ( captured_piece != nullptr )  {
                    
                    m_players[opponent] -> Remove( captured_piece ); 
                    m_board -> RemovePiece( dst_c, dst_r );
                }

                m_board -> SetPiece( src_c, src_r, nullptr );
                m_board -> SetPiece( dst_c, dst_r, piece );
                piece -> AddMovementCount();
                SpecialCases( piece );

                if ( m_players[m_turn] -> CanCheck() )  {

                    m_players[opponent] -> SetCheckStatus( true );
                    m_players[opponent] -> SetAttacker( piece ); 

                    if ( ( !KingEscape() ) && ( !( m_players[opponent] -> CanCatch() ) && !( m_players[opponent] -> CanBlock() ) ) )  {

                        m_checkmate = true;
                    }
                }
                else  {

                    std :: list<IPiece*> available_pieces = m_players[opponent] -> MovePieces();

                    if ( ( !HasAvailableMove( available_pieces ) ) && ( !KingEscape() ) )  {

                        m_stalemate = true;
                    }
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

bool GamePlay :: Promote( char dst_col, char dst_row, Pieces piece_type )  {

    int            dst_c  = GetColIndex( dst_col );
    int            dst_r  = GetRowIndex( dst_row );
    IPiece         *piece = m_board -> GetPiece( dst_c, dst_r );
    Color          color  = piece -> GetColor();
    PlayerNumber   player = ( color == WHITE ) ? PLAYER_1 : PLAYER_2;

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

bool GamePlay :: IsStalemate( void )  {

    return m_stalemate;
}

PlayerNumber GamePlay :: GetTurn( void )  {

    return m_turn;
}

// LCOV_EXCL_START
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
// LCOV_EXCL_STOP