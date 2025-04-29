#include <iostream>
#include "knight.h"


Knight :: Knight( Color color, BoardVision *boardVision ) : Piece( color, boardVision )  {

}

Knight :: ~Knight( void )  {

}

void Knight :: Movement( void )  {

}

bool Knight :: Check( int src_row, int src_col, int dst_row, int dst_col )  {
    
    int     jump_r = abs(dst_row - src_row);
    int     jump_c = abs(dst_col - src_col);
    IPiece* target = m_BoardVision -> GetPiece( dst_row, dst_col );
    bool    ret = ( ( ( target == nullptr ) || ( target -> GetColor() != m_color ) ) && 
                    (jump_r == 1 && jump_c == 2) || (jump_r == 2 && jump_c == 1));

    return ret;
}

void Knight :: Print( void )  {

    std :: cout << "N";
}
