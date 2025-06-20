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

bool Piece :: IsFree( int dst_col, int dst_row, bool check )  { //DEFAULT -> TRUE for movement; CHECK -> TRUE for CHECK

    int col_iterations = 0;
    int row_iterations = 0;
    int iterator_col = 0;
    int iterator_row = 0;
    int dist_col = dst_col - m_position.col;
    int dist_row = dst_row - m_position.row;

    if ( dist_col != 0 )  {

        iterator_col = ( dst_col - m_position.col > 0 ) ? 1 : -1;
    }
    
    if ( dist_row != 0 )  { 

        iterator_row = ( dst_row - m_position.row > 0 ) ? 1 : -1;
    }

    while ( ( row_iterations !=  dist_row ) || ( col_iterations !=  dist_col ) )  {

        row_iterations += iterator_row;
        col_iterations += iterator_col;
        
        IPiece *target = m_BoardVision -> GetPiece( ( m_position.col + col_iterations ), ( m_position.row + row_iterations ) );

        //King check
        if ( check == true )  {

            if ( target -> GetType() == KING && target -> GetColor() != m_color )  {

                target -> SetStatus( CHECK );
                return true;
            }
        }

        //Default - last iteration
        else {

            if ( ( row_iterations ==  dist_row ) && ( col_iterations ==  dist_col ) )  {

                return CanMove( target );
            }
        }

        if ( target != nullptr )  {

            return false;
        }
    }
}

bool Piece :: Check( int dst_col, int dst_row )  {

    return false;
}

bool Piece :: CheckVision( void )  {

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