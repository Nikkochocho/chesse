#include <iostream>
#include "rook.h"


Rook :: Rook( Color color, BoardVision *boardVision ) : Piece( color, boardVision )  {

}

Rook :: ~Rook( void )  {

}

void Rook :: Movement( void )  {

}

bool Rook :: Check( int src_row, int src_col, int dst_row, int dst_col )  {

    IPiece* target = m_BoardVision -> GetPiece( dst_row, dst_col );
    bool    ret = ( ( ( target == nullptr ) || ( target -> GetColor() != m_color ) ) && 
                    ( dst_row == src_row || dst_col == src_col ) );

    return ret;
}

void Rook :: Print( void )  {

    std :: cout << "R";
}
