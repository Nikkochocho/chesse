#include <iostream>
#include "knight.h"


Knight :: Knight( Color color, IBoard *boardVision )  {

    this -> m_type        = KNIGHT;
    this -> m_color       = color;
    this -> m_BoardVision = boardVision;
}

Knight :: ~Knight( void )  {

}

bool Knight :: CanMove( int dst_col, int dst_row )  {
    
    IPiece      *target = m_BoardVision -> GetPiece( dst_col, dst_row );
    int         jump_c  = abs( dst_col - m_position.col );
    int         jump_r  = abs( dst_row - m_position.row );
    bool        ret     = ( ( jump_c == 1 && jump_r == 2 ) || ( jump_c == 2 && jump_r == 1 ) );

    if ( ret )  {

        return CanSet( target );
    }

    return ret;
}

bool Knight :: KingCheck( void )  {

    IPiece        *piece;
    int           col;
    int           row;
    const int     col_number[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    const int     row_number[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    bool          ret           = false;

    for ( int i = 0; i < 8; i++ ) {

        col = m_position.col + col_number[i];
        row = m_position.row + row_number[i];

        if ( ( col < 0 || col > 7 ) || ( row < 0 || row > 7 ) )  {

            continue;
        }
        else  {

            piece = m_BoardVision -> GetPiece( col, row );

            if ( ( piece != nullptr ) && ( ( piece -> GetType() == KING ) && ( piece -> GetColor() != m_color ) ) )  {

                piece -> SetStatus( CHECK );
                ret = true;
                break;
            }
        }
    }

    return ret;
}

// LCOV_EXCL_START
void Knight :: Print( void )  {

    std :: cout << 'N';
}
// LCOV_EXCL_STOP