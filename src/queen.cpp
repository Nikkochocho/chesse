#include <iostream>
#include "queen.h"


Queen :: Queen( Color color, IBoard *boardVision )  {

    this -> m_type = QUEEN;
    this -> m_color = color;
    this -> m_BoardVision = boardVision;
}

Queen :: ~Queen( void )  {

}

bool Queen :: Check( int dst_col, int dst_row )  {

    if ( ( abs( dst_col - m_position.col ) == abs( dst_row - m_position.row ) ) || ( dst_col == m_position.col || dst_row == m_position.row ) )  {

        return IsFree( dst_col, dst_row );
    }

    return false;
}

bool Queen :: CheckVision( void )  {

    return ( ( IsFree( 7, m_position.row, true ) || IsFree( 0, m_position.row, true ) ) ||
             ( IsFree( m_position.col, 7, true ) || IsFree( m_position.col, 0, true ) ) ||
             ( IsFree( 7, 7, true ) || IsFree( 0, 0, true ) ) ||
             ( IsFree( 0, 7, true ) || IsFree( 7, 0, true ) ) );
}

void Queen :: Print( void )  {

    std :: cout << 'Q';
}
