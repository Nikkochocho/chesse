#include "piece.h"


void Piece :: CalcDiagonals( stPosition& posAsc, stPosition& posDesc, bool diagonal )  {

    bool asc, desc;
    bool direction = ( diagonal ) ? 1 : -1; //default main; else secondary diagonal

    asc = desc = true;

    while ( asc || desc )  {

        if ( ( posAsc.col < 7 ) && ( posAsc.row < 7 ) )  {

            posAsc.col += direction;
            posAsc.row++;
        }
        else asc = false;

        if ( ( posDesc.col > 0 ) && ( posDesc.row > 0 ) )  {

            posDesc.col += ( direction * -1 );
            posDesc.row--;
        }
        else desc = false;
    }
}

bool Piece :: TrespassCheck( int dist_col, int dist_row, int itr_col, int itr_row, bool check )  {

    int    col_iterations = 0;
    int    row_iterations = 0;
    bool   ret = ( check ) ? false : true; //default return

    while ( ( row_iterations !=  dist_row ) || ( col_iterations !=  dist_col ) )  {

        row_iterations += itr_row;
        col_iterations += itr_col;
        
        IPiece *target = m_BoardVision -> GetPiece( ( m_position.col + col_iterations ), ( m_position.row + row_iterations ) );
        
        if ( check && KingCheck( target ) )  {

            target -> SetStatus( CHECK );
            return true;
        }
        else if ( ( row_iterations ==  dist_row ) && ( col_iterations ==  dist_col ) )  {

                return CanMove( target );
        }
        
        if ( target != nullptr )  {

            return false;
        }
    }

    return ret;
}

bool Piece :: KingCheck( IPiece *target )  {

    return ( target != nullptr && target -> GetType() == KING && target -> GetColor() != m_color );
}

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

    int itr_col = 0;
    int itr_row = 0;
    int dist_col = dst_col - m_position.col;
    int dist_row = dst_row - m_position.row;

    if ( dist_col != 0 )  {

        itr_col = ( dst_col - m_position.col > 0 ) ? 1 : -1;
    }
    
    if ( dist_row != 0 )  { 

        itr_row = ( dst_row - m_position.row > 0 ) ? 1 : -1;
    }

    return TrespassCheck( dist_col, dist_row, itr_col, itr_row, check );
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