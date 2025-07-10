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

#define MAX_COLS 8
#define MAX_ROWS 8


enum PlayerNumber  {

    PLAYER_1,
    PLAYER_2
};

enum Pieces  {

    KING,
    QUEEN,
    BISHOP,
    KNIGHT,
    ROOK,
    PAWN,
    UNSET
};

enum Color  {

    WHITE,
    BLACK
};

enum Status  {

    NORMAL,
    LONGCASTLE,
    SHORTCASTLE,
    ENPASSANT,
    PROMOTION,
    CHECK
};

struct stPosition  {

    int         col;
    int         row;
};

#endif // __DEFS_H__