#include <iostream>
#include "pawn.h"


Pawn :: Pawn( Color color, IBoard *boardVision )  {
    
    this -> m_type        = PAWN;
    this -> m_color       = color;
    this -> m_BoardVision = boardVision;
}

Pawn :: ~Pawn( void )  {
    
}

bool Pawn :: CanMove( int dst_col, int dst_row )  {
    
    int         row           = ( m_color == WHITE ) ? 1 : -1;
    int         enpassant_row = ( m_color == WHITE ) ? 4 : 3;
    int         promotion_row = ( m_color == WHITE ) ? 7 : 0;
    IPiece      *target       = m_BoardVision -> GetPiece( dst_col, dst_row );
    IPiece      *side_piece   = m_BoardVision -> GetPiece( dst_col, dst_row + ( row * -1 ) );
    bool        ret           = ( ( target == nullptr ) &&
                                  ( ( dst_col == m_position.col ) && ( dst_row == m_position.row + row ) ) ); //default

    //first move
    if ( m_MovementCount == 0 )  { 

        ret = ( ( target == nullptr ) &&   
                ( ( dst_col == m_position.col && dst_row == m_position.row + row ) ||
                  ( dst_col == m_position.col && dst_row == m_position.row + 2 * row ) && ( side_piece == nullptr ) ) );
    }
    
    if ( dst_col != m_position.col )  { 

        if ( ( side_piece != nullptr ) && ( ( side_piece -> GetType() == PAWN ) && ( side_piece -> GetColor() != m_color ) ) && 
             ( target == nullptr ) && ( m_position.row == enpassant_row ) && ( side_piece -> GetMovementCount() == 1 ) )  {

            this -> SetStatus( ENPASSANT );
            return true; //en passant capture
        }  

        if ( ( target != nullptr ) && ( target -> GetColor() != m_color ) && 
            ( abs( dst_col -  m_position.col ) == 1 ) && ( dst_row == m_position.row + row ) )  {

            ret = true; //capture
        }

    }

    if ( ( ret == true ) && ( dst_row == promotion_row ) )  {

        this -> SetStatus( PROMOTION );
    }

    return ret; 
}

bool Pawn :: MovementCheck( bool king_check )  {

    IPiece    *piece;
    int       col_pos, row_pos, col;
    int       row      = ( m_color == WHITE ) ? 1 : -1;
    bool      ret      = false;

    if ( !king_check )  {

        ret = ( ( m_BoardVision -> GetPiece( m_position.col, m_position.row + row ) ) == nullptr ); 
    }

    for ( int i = 0; i < 2; i++ )  {

        col     = ( i == 0 ) ? 1 : -1;
        col_pos = m_position.col + col;
        
        row_pos = m_position.row + row;
        
        if ( ( col_pos < 0 || col_pos > 7 ) || ( row_pos < 0 || row_pos > 7 ) )  {

            continue;
        }

        piece = m_BoardVision -> GetPiece( ( col_pos ), ( row_pos ) );

        if ( ( piece != nullptr ) && ( piece -> GetColor() != m_color ) )  {

            if ( !king_check )  {

                ret = true;
            }
            else if ( piece -> GetType() == KING )  {

                piece -> SetStatus( CHECK );
                ret = true;
            }
        }

        if ( ret )  {

            break;
        }
    }

    return ret;
}

// LCOV_EXCL_START
void Pawn :: Print( void )  {

    std :: cout << 'P';
}
// LCOV_EXCL_STOP