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

#include "helper.h"

// LCOV_EXCL_START
Pieces Conversion( char promotion )  {

    Pieces piece_type;

    switch ( promotion )  {

        case 'Q': 
            piece_type = QUEEN; 
            break; 

        case 'B': 
            piece_type = BISHOP; 
            break;

        case 'N': 
            piece_type = KNIGHT; 
            break;

        case 'R':
            piece_type = ROOK; 
            break;

        default:
            piece_type = UNSET;
            break;
    }

    return piece_type;
}
// LCOV_EXCL_STOP