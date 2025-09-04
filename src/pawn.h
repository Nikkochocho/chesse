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

#ifndef __PAWN_H__
#define __PAWN_H__

#include "piece.h"


/**
 * @brief Chesse pawn class implementation.
 */
class Pawn : public Piece  {

    bool CaptureSet( IPiece *target );
    bool IsEnPassant( IPiece *piece );

    public:

    Pawn( Color color, IBoard *boardVision );
    virtual ~Pawn( void );
    
    bool CanMove( stPosition& dst_pos );
    bool MovementCheck( void );
    void Print( void );
};

#endif // __PAWN_H__