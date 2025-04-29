#include <iostream>
#include "knight.h"


Knight :: Knight( Color color ) : Piece( color )  {

}

Knight :: ~Knight( void )  {

}

void Knight :: Movement( void )  {

}

bool Knight :: Check( int src_row, int src_col, int dst_row, int dst_col )  {
    return false;
}

void Knight :: Print( void )  {

    std :: cout << "N";
}
