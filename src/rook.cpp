#include <iostream>
#include "rook.h"


Rook :: Rook( Color color, IBoard *boardVision )  {

    this -> m_type = ROOK;
    this -> m_color = color;
    this -> m_BoardVision = boardVision;
}

Rook :: ~Rook( void )  {

}

bool Rook :: Check( int dst_col, int dst_row )  {

    if ( dst_col == m_position.col || dst_row == m_position.row )  {

        return IsFree( dst_col, dst_row );
    } 

    return false;
}

bool Rook :: CheckVision( void )  {

    return ( ( IsFree( 7, m_position.row, true ) || IsFree( 0, m_position.row, true ) ) ||
             ( IsFree( m_position.col, 7, true ) || IsFree( m_position.col, 0, true ) ) );
}

void Rook :: Print( void )  {

    std :: cout << 'R';
}
