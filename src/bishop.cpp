#include <iostream>
#include "bishop.h"


Bishop :: Bishop( Color color, BoardVision *boardVision )  {

    this -> m_color = color;
    this -> m_BoardVision = boardVision;
}

Bishop :: ~Bishop( void )  {

}

void Bishop :: Movement( void )  {

}

bool Bishop :: Check( int src_row, int src_col, int dst_row, int dst_col )  {

    IPiece*     target = m_BoardVision -> GetPiece( dst_row, dst_col );
    bool        ret = ( ( ( target == nullptr ) ||( target -> GetColor() != m_color ) ) && 
                           ( abs( dst_row - src_row ) == abs( dst_col - src_col ) ) );

    return ret;
}

char Bishop :: Print( void )  {

    return 'B';
}
