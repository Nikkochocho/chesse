#include <iostream>
#include "bishop.h"


Bishop :: Bishop( Color color, BoardVision *boardVision ) : Piece( color, boardVision )  {

}

Bishop :: ~Bishop( void )  {

}

void Bishop :: Movement( void )  {

}

bool Bishop :: Check( int src_row, int src_col, int dst_row, int dst_col )  {

    IPiece* target = m_BoardVision -> GetPiece( dst_row, dst_col );
    bool    ret = ( ( ( target == nullptr ) ||( target -> GetColor() != m_color ) ) && 
                    ( ( abs( dst_row - src_row ) == 1 ) && ( abs( dst_col - src_col ) == 1 ) ) );

    return ret;
}

void Bishop :: Print( void )  {

    std :: cout << "B";
}
