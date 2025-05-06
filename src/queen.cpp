#include <iostream>
#include "queen.h"


Queen :: Queen( Color color, IBoard *boardVision )  {

    this -> m_type = QUEEN;
    this -> m_color = color;
    this -> m_BoardVision = boardVision;
}

Queen :: ~Queen( void )  {

}

bool Queen :: Check( int src_col, int src_row, int dst_col, int dst_row )  {

    if ( ( abs( dst_row - src_row ) == abs( dst_col - src_col ) ) || ( dst_row == src_row || dst_col == src_col ) )  {

        return IsFree( src_col, src_row, dst_col, dst_row );
    }

    return false;
}

void Queen :: Print( void )  {

    std :: cout << 'Q';
}
