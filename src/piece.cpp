#include "piece.h"


Piece :: Piece( Color color, BoardVision *boardVision )  {
    
    m_color = color;
    m_BoardVision = boardVision;
}

void Piece :: Movement( void ) {

}

bool Piece :: Check( int src_row, int src_col, int dst_row, int dst_col )  {

    return false;
}

void Piece :: Print( void ) {

}

Color Piece :: GetColor( void )  {

    return m_color;
}