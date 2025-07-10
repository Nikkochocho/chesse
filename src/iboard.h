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

#ifndef __IBOARD_H__
#define __IBOARD_H__

#include "ipiece.h"


class IBoard  {

    public:

    virtual bool IsValid( int col, int row ) = 0;
    virtual IPiece* GetPromotion( Pieces piece, Color color ) = 0;
    virtual IPiece* GetPiece( int dst_c, int dst_r ) = 0;
    virtual void SetPiece( int col, int row, IPiece *piece ) = 0;
    virtual void RemovePiece( int col, int row ) = 0;
    virtual void Init( void ) = 0;
};

#endif // __IBOARD_H__