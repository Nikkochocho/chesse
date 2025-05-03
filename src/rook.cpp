#include <iostream>
#include "rook.h"


Rook :: Rook( Color color, IBoard *boardVision )  {

    this -> m_type = ROOK;
    this -> m_color = color;
    this -> m_BoardVision = boardVision;
}

Rook :: ~Rook( void )  {

}

bool Rook :: Check( int src_row, int src_col, int dst_row, int dst_col )  {

    if ( dst_row == src_row || dst_col == src_col )  {

        return IsFree( src_row, src_col, dst_row, dst_col );
    } 

    return false;
}

void Rook :: Print( void )  {

    std :: cout << 'R';
}
