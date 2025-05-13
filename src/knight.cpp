#include <iostream>
#include "knight.h"


Knight :: Knight( Color color, IBoard *boardVision )  {

    this -> m_type = KNIGHT;
    this -> m_color = color;
    this -> m_BoardVision = boardVision;
}

Knight :: ~Knight( void )  {

}

bool Knight :: Check( int src_col, int src_row, int dst_col, int dst_row )  {
    
    int         jump_r = abs( dst_row - src_row );
    int         jump_c = abs( dst_col - src_col );
    IPiece      *target = m_BoardVision -> GetPiece( dst_col, dst_row );
    bool        ret = ( CanMove( target ) && 
                        ( ( jump_r == 1 && jump_c == 2 ) || ( jump_r == 2 && jump_c == 1 ) ) );

    return ret;
}

void Knight :: Print( void )  {

    std :: cout << 'N';
}
