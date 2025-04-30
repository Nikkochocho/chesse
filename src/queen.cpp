#include <iostream>
#include "queen.h"


Queen :: Queen( Color color, BoardVision *boardVision ) : Piece( color, boardVision )  {

}

Queen :: ~Queen( void )  {

}

void Queen :: Movement( void )  {

}

bool Queen :: Check( int src_row, int src_col, int dst_row, int dst_col )  {

    IPiece* target = m_BoardVision -> GetPiece( dst_row, dst_col );
    bool    ret = ( ( ( target == nullptr ) || ( target -> GetColor() != m_color ) ) && 
                    ( ( ( abs( dst_row - src_row ) == 1 ) && ( abs( dst_col - src_col ) == 1 ) ) || 
                      ( dst_row == src_row || dst_col == src_col ) ) );

    return ret;
}

void Queen :: Print( void )  {

    std :: cout << "Q";
}
