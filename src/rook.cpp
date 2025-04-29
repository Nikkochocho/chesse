#include <iostream>
#include "rook.h"


Rook :: Rook( Color color ) : Piece( color )  {

}

Rook :: ~Rook( void )  {

}

void Rook :: Movement( void )  {

}

bool Rook :: Check( int src_row, int src_col, int dst_row, int dst_col )  {

    return (dst_row == src_row || dst_col == src_col);
}

void Rook :: Print( void )  {

    std :: cout << "R";
}
