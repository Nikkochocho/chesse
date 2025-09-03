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

#include <iostream>
#include "knight.h"


/**
 * @brief Constructor. Initialize all class data.
 */
Knight :: Knight( Color color, IBoard *boardVision )  {

    this -> m_type        = KNIGHT;
    this -> m_color       = color;
    this -> m_BoardVision = boardVision;
}

/**
 * @brief Destructor. Finalize all class data.
 */
Knight :: ~Knight( void )  {

}

/**
 * @brief Checks if new position is valid under the piece's moveset.
 * @param dst_pos New position.
 */
bool Knight :: CanMove( stPosition dst_pos )  {
    
    IPiece      *target = m_BoardVision -> GetPiece( dst_pos.col, dst_pos.row );
    int         jump_c  = abs( dst_pos.col - m_position.col );
    int         jump_r  = abs( dst_pos.row - m_position.row );

    return ( ( ( jump_c == 1 && jump_r == 2 ) || ( jump_c == 2 && jump_r == 1 ) ) && CanSet( target ) );
}

/**
 * @brief Checks if piece has any possible movement available. 
 */
bool Knight :: MovementCheck( void )  {

    stPosition    pos;
    IPiece        *target;
    const int     col_number[MAX_SIZE] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    const int     row_number[MAX_SIZE] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    for ( int i = MIN_SIZE; i < MAX_SIZE; i++ ) {

        pos.col = m_position.col + col_number[i];
        pos.row = m_position.row + row_number[i];

        if ( !m_BoardVision -> IsValid( pos.col, pos.row ) )  {

            continue;
        }

        target = m_BoardVision -> GetPiece( pos.col, pos.row );

        if ( CanSet( target ) )  {

            this -> m_availablePos = pos;
            return true;
        }
    }

    return false;
}

// LCOV_EXCL_START
/**
 * @brief Prints piece's text representation.
 */
void Knight :: Print( void )  {

    std :: cout << 'N';
}
// LCOV_EXCL_STOP