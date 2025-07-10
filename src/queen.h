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

#ifndef __QUEEN_H__
#define __QUEEN_H__

#include "piece.h"


class Queen : public Piece {

    public :

    Queen ( Color color, IBoard *boardVision );
    virtual ~Queen ( void );

    bool CanMove( int dst_col, int dst_row );
    bool MovementCheck( bool king_check );
    void Print( void );
};

#endif // __QUEEN_H__