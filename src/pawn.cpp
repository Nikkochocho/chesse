#include <iostream>
#include "pawn.h"

Pawn :: Pawn( Color color ) : Piece(color)  {
    m_bFirstMove = false;
}

Pawn :: ~Pawn( void )  {

}

void Pawn :: Movement( void )  {

    m_bFirstMove = true;
}

bool Pawn :: Check( int src_row, int src_col, int dst_row, int dst_col )  {
    return false;
}

void Pawn :: Print( void )  {

    std :: cout << "P";
}
