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

#ifndef __IPIECE_H__
#define __IPIECE_H__

#include "defs.h"


/**
 * @brief Chesse piece interface implementation.
 */
class IPiece  {

    public:

    virtual int GetMovementCount( void ) = 0;
    virtual void AddMovementCount( void ) = 0;
    virtual bool CanSet( IPiece *target ) = 0;
    virtual bool CanMove( stPosition dst_pos ) = 0;
    virtual bool MovementCheck( void ) = 0;

    virtual void Print( void ) = 0;
    
    virtual Pieces GetType( void ) = 0;
    virtual Color GetColor( void ) = 0;
    virtual Status GetStatus( void ) = 0;
    virtual void SetStatus( Status state ) = 0;
    virtual stPosition& Position( void ) = 0;
    virtual stPosition& AvailablePosition( void ) = 0;
};

#endif // __IPIECE_H__