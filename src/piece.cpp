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


/**
 * @brief Calculates Main and Secondary diagonal max positions.
 * @param posAsc Diagonal crescent position.
 * @param posDesc Diagonal decrescent position.
 * @param diagonal Diagonal type. true for Main and false for Secondary.
 * @param check returns on first iteration if true.
 */
void Piece :: CalcDiagonals( stPosition& posAsc, stPosition& posDesc, bool diagonal, bool check )  {

    bool asc, desc;
    int direction   = diagonal ? 1 : -1; // default main diagonal; else secondary diagonal
    int minAsc      = diagonal ? -1 : 0;
    int minDesc     = diagonal ? 0 : -1;
    int maxAsc      = diagonal ? 7 : 8;
    int maxDesc     = diagonal ? 8 : 7;

    asc = desc = true;

    while ( asc || desc )  {

        if ( ( ( posAsc.col < maxAsc ) && ( posAsc.col > minAsc ) ) && ( posAsc.row < ( MAX_SIZE - 1 ) ) )  {

            posAsc.col += direction;
            posAsc.row++;
        }
        else asc = false;

        if ( ( ( posDesc.col > minDesc ) && ( posDesc.col < maxDesc ) ) && ( posDesc.row > MIN_SIZE ) )  {

            posDesc.col += ( direction * -1 );
            posDesc.row--;
        }
        else desc = false;

        if ( !check )  {

            break;
        }
    }
}

/**
 * @brief Returns if piece can reach next position or check opponent's king.
 * @param dst_col New X axis position.
 * @param dst_row New Y axis position.
 * @param check Validation type. If true inspects if piece can check opponent's king;
 * if false checks if piece can reach new position.
 */
bool Piece :: CanReach( int dst_col, int dst_row, bool check )  { 

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

/**
 * @brief Inspects on each iteration if piece's move is trespassing or
 * if it can check opponent's king.
 * @param dist_col distance between current and next position on X axis.
 * @param dist_row distance between current and next position on Y axis.
 * @param itr_col column iterator; Value of 1 or -1.
 * @param itr_row row iterator; Value of 1 or -1.
 * @param check Validation type. If true inspects if piece can check opponent's king;
 * if false checks if piece can reach new position.
 */
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

/**
 * @brief Checks if target is the opponent player's king.
 * @param target IPiece object.
 */
bool Piece :: IsOpponentKing( IPiece *target )  {

    return ( ( target != nullptr ) && 
             ( target -> GetType() == KING && target -> GetColor() != m_color ) );
}

/**
 * @brief Returns piece's current movement count.
 * @return Movement count.
 */
int Piece :: GetMovementCount( void )  {

    return this -> m_MovementCount;
}

/**
 * @brief Adds to piece's movement count. 
 */
void Piece :: AddMovementCount( void ) {

    this -> m_MovementCount++;
}

/**
 * @brief Returns if piece can set on a target position.
 * @param pawn_capture Optional, false by default.
 * Used for pawn capture pattern.
 */
bool Piece :: CanSet( IPiece* target, bool pawn_capture )  {

    if ( pawn_capture )  {

        return ( target != nullptr ) && ( target -> GetColor() != m_color );
    }

    return ( ( target == nullptr ) || ( ( target != nullptr ) && ( target -> GetColor() != m_color ) ) );
} 

// LCOV_EXCL_START
/**
 * @brief Checks if new position is valid under the piece's moveset.
 * @param dst_col New X axis position.
 * @param dst_row New Y axis position.
 */
bool Piece :: CanMove( int dst_col, int dst_row )  {

    return false;
}

/**
 * @brief By default, checks if piece has any possible movement available. 
 * If king_check is true, inspects if piece can check the opponents' king.
 * @param king_check Verification type. Optional parameter, false by default. 
 */
bool Piece :: MovementCheck( bool king_check )  {

    return false;
}

/**
 * @brief Prints piece's text representation.
 */
void Piece :: Print( void ) {

}
// LCOV_EXCL_STOP
/**
 * @brief Returns piece's type.
 * @return Piece's type.
 */
Pieces Piece :: GetType( void )  { 

    return m_type;
}

/**
 * @brief Returns piece's color.
 * @return Piece's color.
 */
Color Piece :: GetColor( void )  {

    return m_color;
}

/**
 * @brief Returns piece's status.
 * @return Piece's status.
 */
Status Piece :: GetStatus( void )  {

    return m_state;
}

/**
 * @brief Sets piece's status change.
 * @param state status.
 */
void Piece :: SetStatus( Status state )  {

    m_state = state;
}

/**
 * @brief Gets and Sets piece's position.
 * @return Piece's position.
 */
stPosition& Piece :: Position( void )  {

    return m_position;
}

/**
 * @brief Gets and Sets piece's available position.
 * @return Piece's available position.
 */
stPosition& Piece :: AvailablePosition( void )  {

    return m_availablePos;
}