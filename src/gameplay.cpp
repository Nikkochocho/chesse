#include <iostream>
#include "gameplay.h"


int GamePlay :: GetColIndex( char ch )  {

    return ch - 'a';
}

int GamePlay :: GetRowIndex( char ch )  {

    return ch - '0' - 1;
}

GamePlay :: GamePlay( IBoard* board )  {

    this -> m_board = board;
}

GamePlay :: ~GamePlay( void )  {
    
}

void GamePlay :: NewGame( void )  {

    m_board -> Init();
}

bool GamePlay :: IsValid( int src_r, int src_c, int dst_r, int dst_c )  {

    if( src_r >= 0 && src_r < MAX_ROWS && src_c >= 0 && src_c < MAX_COLS &&
        dst_r >= 0 && dst_r < MAX_ROWS && dst_c >= 0 && dst_c < MAX_COLS &&
        dst_r != src_r || dst_c != src_c )  {

            return true;
        }

    return false;
}

bool GamePlay :: Move( char src_row, char src_col, char dst_row, char dst_col )  {

    int  src_c = GetColIndex( src_col );
    int  src_r = GetRowIndex( src_row );
    int  dst_c = GetColIndex( dst_col );
    int  dst_r = GetRowIndex( dst_row );

    if( IsValid( src_r, src_c, dst_r, dst_c ) ) {
        
        IPiece    *piece = m_board -> GetPiece( src_r, src_c );
        IPiece    *castle = nullptr;
        int       direction;

        if ( ( piece != nullptr ) && piece -> Check( src_r, src_c, dst_r, dst_c ) )  {
            
            m_board -> SetPiece( dst_r, dst_c, piece );
            piece -> Movement();
            m_board -> SetPiece( src_r, src_c, nullptr );
            
            if( piece -> GetStatus() != NORMAL )  {

                switch( piece -> GetStatus() )  {

                    case LONGCASTLE:
                        castle = m_board -> GetPiece( dst_r, dst_c - 1 );
                        m_board -> SetPiece( dst_r, dst_c + 1, castle );
                        castle -> Movement();
                        m_board -> SetPiece( dst_r, dst_c - 1, nullptr );
                        break;

                    case SHORTCASTLE:
                        castle = m_board -> GetPiece( dst_r, dst_c + 1 );
                        m_board -> SetPiece( dst_r, dst_c - 1, castle );
                        castle -> Movement();
                        m_board -> SetPiece( dst_r, dst_c + 1, nullptr );
                        break;

                    case ENPASSANT: 
                        direction = piece -> GetColor() == WHITE ? -1 : 1;
                        m_board -> SetPiece( (dst_r + direction ), dst_c, nullptr );
                        break;

                    case PROMOTION:
                        m_promotion = true;
                        break;
                }

                piece -> SetStatus( NORMAL );
            }

            return true;
        }
    }

    return false;
}

bool GamePlay :: HasPromotion( void )  {

    return m_promotion;
}

bool GamePlay :: Promote( char dst_row, char dst_col, char promotion )  {

    int        dst_c = GetColIndex( dst_col );
    int        dst_r = GetRowIndex( dst_row );
    IPiece*    piece = m_board -> GetPiece( dst_r, dst_c );
    Color      color = piece -> GetColor();
    Pieces     piece_type;

    switch ( promotion )  {

        case 'Q': piece_type = QUEEN; break; 
        case 'B': piece_type = BISHOP; break;
        case 'N': piece_type = KNIGHT; break;
        case 'R': piece_type = ROOK; break;
        default: return false;
    }

    IPiece* promoted_piece = m_board -> GetPromotion( piece_type, color );
    m_board -> SetPiece( dst_r, dst_c, promoted_piece ) ;
    m_promotion = false;

    return true;
}

bool GamePlay :: IsCheckmate( void )  {

    return m_checkmate;
}

void GamePlay :: Print( void )  {
   
    int count_row = MAX_ROWS;
    int count_col = 0;

    for(int i = 0; i < ( MAX_COLS * 2 ) + 1; i++)  {

        if ( i % 2 != 0 )  {

            char output = 'a' + count_col;
            std :: cout << output;
            count_col++;
            continue;
        }

        std :: cout << " ";
    }

    std :: cout << std ::endl;

    for(int cc = 0; cc < ( MAX_COLS * 2 ) + 1; cc++)  {

        std :: cout << "-";
    }
    std :: cout << std ::endl;
    
    for(int row = ( MAX_ROWS - 1 ); row >= 0; row--)  {

        std :: cout << "|";

        for(int col = 0; col < MAX_COLS; col++)  {

            IPiece *piece = m_board -> GetPiece( row, col );

            if( piece != nullptr )  {

                piece -> Print();
            }
            else  {

                std :: cout << " ";    
            }

            std :: cout << "|";

            if( col == ( MAX_COLS - 1 ) )  {
                std :: cout << count_row << std ::endl;
                count_row--;
            }
        }

        for(int cc = 0; cc < (MAX_COLS * 2) + 1; cc++)  {

            std :: cout << "-";
        }

        std :: cout << std ::endl;
    }
}