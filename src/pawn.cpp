#include <iostream>
#include "pawn.h"

Pawn :: Pawn( Color color, BoardVision *boardVision ) : Piece(color, boardVision)  {
    m_bFirstMove = false;
}

Pawn :: ~Pawn( void )  {

}

void Pawn :: Movement( void )  {

    m_bFirstMove = true;
}

bool Pawn :: Check( int src_row, int src_col, int dst_row, int dst_col )  {
    
    int direction = ( m_color == WHITE ) ? -1 : 1;
    //int str_row = ( m_color == WHITE ) ? 6 : 1; TODO: rever o codigo e (talvez) remover Movement()

     IPiece* target = m_BoardVision -> GetPiece( dst_row, dst_col );
     //IPiece* side_piece = m_BoardVision -> GetPiece( dst_row, dst_col + 1); TODO: en passant implementation


    //capture
    if ( (abs( dst_col -  src_col ) == 1 ) && ( target != nullptr ) && ( target -> GetColor() != m_color ) )  {
        return ( dst_row == src_row + direction );
    }

    //first move
    if ( !m_bFirstMove )  {
        return ( dst_col == src_col && dst_row == src_row + direction ||
                 dst_col == src_col && dst_row == src_row + 2 * direction );
    }

    //default
    return ( dst_col == src_col && dst_row == src_row + direction ); 
}

void Pawn :: Print( void )  {

    std :: cout << "P";
}
