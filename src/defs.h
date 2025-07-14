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

#ifndef __DEFS_H__
#define __DEFS_H__

#define MAX_SIZE 8
#define MIN_SIZE 0


/**
 * @brief Player number enumerator definition.
 */
enum PlayerNumber  {

    PLAYER_1,
    PLAYER_2
};

/**
 * @brief Piece type enumerator definition.
 */
enum Pieces  {

    KING,
    QUEEN,
    BISHOP,
    KNIGHT,
    ROOK,
    PAWN,
    UNSET
};

/**
 * @brief Color enumerator definition.
 */
enum Color  {

    WHITE,
    BLACK
};

/**
 * @brief Status enumerator definition.
 */
enum Status  {

    NORMAL,
    LONGCASTLE,
    SHORTCASTLE,
    ENPASSANT,
    PROMOTION,
    CHECK
};

/**
 * @brief Position structure definition.
 */
struct stPosition  {

    int         col;
    int         row;
};

#endif // __DEFS_H__