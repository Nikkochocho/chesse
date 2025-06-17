#include <iostream>
#include "bishop.h"


Bishop :: Bishop( Color color, IBoard *boardVision )  {

    this -> m_type = BISHOP;
    this -> m_color = color;
    this -> m_BoardVision = boardVision;
}

Bishop :: ~Bishop( void )  {

}

bool Bishop :: Check( int dst_col, int dst_row )  {

    if ( abs( dst_col - m_position.col ) == abs( dst_row - m_position.row ) )  {

        return IsFree( dst_col, dst_row );
    }

    return false;
}

void Bishop :: Print( void )  {

    std :: cout << 'B';
}