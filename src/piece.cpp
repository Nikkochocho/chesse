/*
 * chesse
 * Copyright (C) 2025  Lara H. Ferreira.
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "piece.h"


void Piece :: CalcDiagonals( stPosition& posAsc, stPosition& posDesc, bool diagonal, bool check )  {

    bool asc, desc;
    int direction   = diagonal ? 1 : -1; //default main; else secondary diagonal
    int minAsc      = diagonal ? -1 : 0;
    int minDesc     = diagonal ? 0 : -1;
    int maxAsc      = diagonal ? 7 : 8;
    int maxDesc     = diagonal ? 8 : 7;

    asc = desc = true;

    while ( asc || desc )  {

        if ( ( ( posAsc.col < maxAsc ) && ( posAsc.col > minAsc ) ) && ( posAsc.row < 7 ) )  {

            posAsc.col += direction;
            posAsc.row++;
        }
        else asc = false;

        if ( ( ( posDesc.col > minDesc ) && ( posDesc.col < maxDesc ) ) && ( posDesc.row > 0 ) )  {

            posDesc.col += ( direction * -1 );
            posDesc.row--;
        }
        else desc = false;

        if ( !check )  {

            break;
        }
    }
}

bool Piece :: CanReach( int dst_col, int dst_row, bool check )  { // DEFAULT -> TRUE for movement; CHECK -> TRUE if opponent king

    int itr_col  = 0;
    int itr_row  = 0;
    int dist_col = dst_col - m_position.col;
    int dist_row = dst_row - m_position.row;

    if ( ( dist_col == 0 ) && ( dist_row == 0 ) )  {

        return false;
    }

    if ( dist_col != 0 )  {

        itr_col = ( dist_col > 0 ) ? 1 : -1;
    }
    
    if ( dist_row != 0 )  { 

        itr_row = ( dist_row > 0 ) ? 1 : -1;
    }

    return IterationCheck( dist_col, dist_row, itr_col, itr_row, check );
}

bool Piece :: IterationCheck( int dist_col, int dist_row, int itr_col, int itr_row, bool check )  {

    int        col_iterations = 0;
    int        row_iterations = 0;
    bool       ret            = ( check ) ? false : true; // default return

    while ( ( row_iterations !=  dist_row ) || ( col_iterations !=  dist_col ) )  {

        row_iterations += itr_row;
        col_iterations += itr_col;
        
        IPiece *target = m_BoardVision -> GetPiece( ( m_position.col + col_iterations ), ( m_position.row + row_iterations ) );
        
        if ( check && IsOpponentKing( target ) )  {

            target -> SetStatus( CHECK );
            return true;
        }
        
        if ( !check && ( row_iterations ==  dist_row ) && ( col_iterations ==  dist_col ) )  {

            this -> m_availablePos.col = m_position.col + col_iterations;
            this -> m_availablePos.row = m_position.row + row_iterations;
            return CanSet( target );
        }
        
        if ( target != nullptr )  {

            return false;
        }
    }

    return ret;
}

bool Piece :: IsOpponentKing( IPiece *target )  {

    return ( ( target != nullptr ) && 
             ( target -> GetType() == KING && target -> GetColor() != m_color ) );
}

int Piece :: GetMovementCount( void )  {

    return this -> m_MovementCount;
}

void Piece :: AddMovementCount( void ) {

    this -> m_MovementCount++;
}

bool Piece :: CanSet( IPiece* target )  {

    return ( ( target == nullptr ) || ( ( target != nullptr ) && ( target -> GetColor() != m_color ) ) );
}  

// LCOV_EXCL_START
bool Piece :: CanMove( int dst_col, int dst_row )  {

    return false;
}

bool Piece :: MovementCheck( bool king_check )  {

    return false;
}

void Piece :: Print( void ) {

}
// LCOV_EXCL_STOP

Pieces Piece :: GetType( void )  { 

    return m_type;
}

Color Piece :: GetColor( void )  {

    return m_color;
}

Status Piece :: GetStatus( void )  {

    return m_state;
}

void Piece :: SetStatus( Status state )  {

    m_state = state;
}

stPosition& Piece :: Position( void )  {

    return m_position;
}

stPosition& Piece :: AvailablePosition( void )  {

    return m_availablePos;
}