#include "piece.h"


void Piece :: Movement( void ) {

    this -> m_MovementCount++;
}

int Piece :: GetMovementCount( void )  {

    return this -> m_MovementCount;
}

bool Piece :: CanMove( IPiece* target )  {

    if ( ( target != nullptr ) && ( target -> GetColor() != m_color ) )  {

        target -> SetStatus ( CAPTURED );
    }

    return ( ( target == nullptr ) || ( target -> GetColor() != m_color ) );
}  

bool Piece :: IsFree( int src_col, int src_row, int dst_col, int dst_row )  {

    int col_iterations = 0;
    int row_iterations = 0;
    int iterator_col = 0;
    int iterator_row = 0;
    int dist_col = dst_col - src_col;
    int dist_row = dst_row - src_row;

    if ( dist_col != 0 ) 
        iterator_col = ( dst_col - src_col > 0 ) ? 1 : -1;
    
    if ( dist_row != 0 ) 
        iterator_row = ( dst_row - src_row > 0 ) ? 1 : -1;

    while ( ( row_iterations !=  dist_row ) || ( col_iterations !=  dist_col ) )  {

        row_iterations += iterator_row;
        col_iterations += iterator_col;
        
        IPiece *target = m_BoardVision -> GetPiece( ( src_col + col_iterations ), ( src_row + row_iterations ) );

        //last iteration
        if ( ( row_iterations ==  dist_row ) && ( col_iterations ==  dist_col ) ) 
            return CanMove( target );

        if ( target != nullptr ) 
            return false;
    }

    return true;
}

bool Piece :: Check( int src_col, int src_row, int dst_col, int dst_row )  {

    return false;
}

bool Piece :: CheckVision( int src_col, int src_row )  {

    return false;
}

void Piece :: Print( void ) {

}

stPosition& Piece :: Position( void )  {

    return m_position;
}


Color Piece :: GetColor( void )  {

    return m_color;
}

Pieces Piece :: GetType( void )  { 

    return m_type;
}

Status Piece :: GetStatus( void )  {

    return m_state;
}

void Piece :: SetStatus( Status state )  {

    m_state = state;
}