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
#include "rook.h"


/**
 * @brief Constructor. Initialize all class data.
 */
Rook :: Rook( Color color, IBoard *boardVision )  {

    this -> m_type        = ROOK;
    this -> m_color       = color;
    this -> m_BoardVision = boardVision;
}

/**
 * @brief Destructor. Finalize all class data.
 */
Rook :: ~Rook( void )  {

}

/**
 * @brief Checks if new position is valid under the piece's moveset.
 * @param dst_pos New position.
 */
bool Rook :: CanMove( stPosition dst_pos )  {

    return ( ( dst_pos.col == m_position.col || dst_pos.row == m_position.row ) && CanReach( dst_pos ) );
}

/**
 * @brief Checks if piece has any possible movement available. 
 */
bool Rook :: MovementCheck( void )  {

    return AxisSet();
}

// LCOV_EXCL_START
/**
 * @brief Prints piece's text representation.
 */
void Rook :: Print( void )  {

    std :: cout << 'R';
}
// LCOV_EXCL_STOP