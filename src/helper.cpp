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

#include <cctype>
#include "helper.h"


// LCOV_EXCL_START
/**
 * @brief Returns if input follows correct format.
 * @param pos array of column and row char value.
 */
bool ValidInput( char pos[2] )  {

    return ( isalpha( pos[0] ) && ( isdigit( pos[1] ) ) );
}

/**
 * @brief Pawn promotion validation.
 * @param promotion Indicates pawn's new type.
 * @return Promoted piece's new type.
 */
Pieces Conversion( char promotion )  {

    Pieces piece_type;

    switch ( promotion )  {

        case 'q': 
            piece_type = QUEEN; 
            break; 

        case 'b': 
            piece_type = BISHOP; 
            break;

        case 'n': 
            piece_type = KNIGHT; 
            break;

        case 'r':
            piece_type = ROOK; 
            break;

        default:
            piece_type = UNSET;
            break;
    }

    return piece_type;
}
// LCOV_EXCL_STOP