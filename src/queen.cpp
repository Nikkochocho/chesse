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

void Queen :: Print( void )  {

    std :: cout << 'Q';
}
