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
#include "bishop.h"

/**
 * @brief Constructor. Initialize all class data.
 */
Bishop :: Bishop( Color color, IBoard *boardVision )  {

    this -> m_type        = BISHOP;
    this -> m_color       = color;
    this -> m_BoardVision = boardVision;
}

/**
 * @brief Destructor. Finalize all class data.
 */
Bishop :: ~Bishop( void )  {

}

/**
 * @brief Checks if new position is valid under the piece's moveset.
 * @param dst_pos New position.
 */
bool Bishop :: CanMove( stPosition dst_pos )  {

    if ( abs( dst_pos.col - m_position.col ) == abs( dst_pos.row - m_position.row ) )  {

        return CanReach( dst_pos.col, dst_pos.row );
    }

    return false;
}

/**
 * @brief By default, checks if piece has any possible movement available. 
 * If king_check is true, inspects if piece can check the opponents' king.
 * @param king_check Verification type. Optional parameter, false by default. 
 */
bool Bishop :: MovementCheck( bool king_check )  {

    stPosition MainposAsc, MainposDesc, SecposAsc, SecposDesc;

    MainposAsc =  MainposDesc = SecposAsc = SecposDesc = m_position;

    CalcDiagonals( MainposAsc, MainposDesc, true, king_check ); // Main diagonal
    CalcDiagonals( SecposAsc, SecposDesc, false, king_check ); // Secondary diagonal

    return ( ( CanReach( MainposAsc.col, MainposAsc.row, king_check ) || CanReach( MainposDesc.col, MainposDesc.row, king_check ) ) ||
             ( CanReach( SecposAsc.col, SecposAsc.row, king_check ) || CanReach( SecposDesc.col, SecposDesc.row, king_check ) ) );
}

// LCOV_EXCL_START
/**
 * @brief Prints piece's text representation.
 */
void Bishop :: Print( void )  {

    std :: cout << 'B';
}
// LCOV_EXCL_STOP