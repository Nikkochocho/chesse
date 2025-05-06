#include <iostream>
#include "bishop.h"


Bishop :: Bishop( Color color, IBoard *boardVision )  {

    this -> m_type = BISHOP;
    this -> m_color = color;
    this -> m_BoardVision = boardVision;
}

Bishop :: ~Bishop( void )  {

}

bool Bishop :: Check( int src_col, int src_row, int dst_col, int dst_row )  {

    if ( abs( dst_row - src_row ) == abs( dst_col - src_col ) )  {

        return IsFree( src_col, src_row, dst_col, dst_row );
    }

    return false;
}

void Bishop :: Print( void )  {

    std :: cout << 'B';
}