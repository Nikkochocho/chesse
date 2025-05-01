#include <iostream>
#include "pawn.h"


Pawn :: Pawn( Color color, BoardVision *boardVision )  {
    
    m_bMovement = 0;
    this -> m_color = color;
    this -> m_BoardVision = boardVision;
}

Pawn :: ~Pawn( void )  {
    
}

void Pawn :: Movement( void )  {

    m_bMovement += 1;
}

bool Pawn :: Check( int src_row, int src_col, int dst_row, int dst_col )  {
    
    int         direction = ( m_color == WHITE ) ? 1 : -1;
    int         str_row = ( m_color == WHITE ) ? 1 : 6;
    int         enpassant_row = ( m_color == WHITE ) ? 4 : 3;
    IPiece*     target = m_BoardVision -> GetPiece( dst_row, dst_col );
    IPiece*     side_piece = m_BoardVision -> GetPiece( dst_row + ( direction * -1 ), dst_col ); //TODO: complete en passant implementation

    //capture
    if ( ( target != nullptr ) && ( target -> GetColor() != m_color ) && 
         ( abs( dst_col -  src_col ) == 1 ) && ( dst_row == src_row + direction ) )  {

        return true;
    }

    //en passant capture
    if ( ( side_piece != nullptr) && ( side_piece -> Print() == 'P' ) && ( side_piece -> GetColor() != m_color ) && 
         ( target == nullptr ) && ( src_row == enpassant_row) ) { //&& side_piece -> m_bMovement == 1)

        //side_piece = nullptr;
        return true;
    }

    //first move
    if ( src_row == str_row )  {

        return ( dst_col == src_col && dst_row == src_row + direction ||
                 dst_col == src_col && dst_row == src_row + 2 * direction );
    }

    //default
    return ( dst_col == src_col && dst_row == src_row + direction ); 
}

char Pawn :: Print( void )  {

    return 'P';
}
