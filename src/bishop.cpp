#include <iostream>
#include "bishop.h"


Bishop :: Bishop( Color color, IBoard *boardVision )  {

    this -> m_type = BISHOP;
    this -> m_color = color;
    this -> m_BoardVision = boardVision;
}

Bishop :: ~Bishop( void )  {

}

bool Bishop :: Check( int src_row, int src_col, int dst_row, int dst_col )  {

    if ( abs( dst_row - src_row ) == abs( dst_col - src_col ) )  {

        return IsFree( src_row, src_col, dst_row, dst_col );
    }

    return false;
}

void Bishop :: Print( void )  {

    std :: cout << 'B';
}