#include <iostream>
#include "rook.h"


Rook :: Rook( Color color, IBoard *boardVision )  {

    this -> m_type        = ROOK;
    this -> m_color       = color;
    this -> m_BoardVision = boardVision;
}

Rook :: ~Rook( void )  {

}

bool Rook :: CanMove( int dst_col, int dst_row )  {

    if ( dst_col == m_position.col || dst_row == m_position.row )  {

        return CanReach( dst_col, dst_row );
    } 

    return false;
}

bool Rook :: MovementCheck( bool king_check )  {

    return ( ( CanReach( 7, m_position.row, king_check ) || CanReach( 0, m_position.row, king_check ) ) ||
             ( CanReach( m_position.col, 7, king_check ) || CanReach( m_position.col, 0, king_check ) ) );
}

// LCOV_EXCL_START
void Rook :: Print( void )  {

    std :: cout << 'R';
}
// LCOV_EXCL_STOP