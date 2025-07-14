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

#ifndef __PIECE_H__
#define __PIECE_H__

#include "iboard.h"


/**
 * @brief Chesse piece class implementation.
 */
class Piece : public IPiece  {

    protected:
    
    int         m_movementCount = 0;
    stPosition  m_position;
    stPosition  m_availablePos;
    Color       m_color;
    Pieces      m_type;
    Status      m_state         = NORMAL;
    IBoard      *m_BoardVision;

    
    void GetAxisLine( stPosition& Xpos, stPosition& Ypos, bool isAsc, bool check );
    void GetDiagonals( stPosition& posAsc, stPosition& posDesc, bool main, bool check );
    bool IsOpponentKing( IPiece *target ) ;
    bool CanReach( stPosition dst_pos, bool check = false );

    private:

    bool IterationCheck( stPosition dist, int itr_col, int itr_row, bool check );

    public:

    int GetMovementCount( void );
    void AddMovementCount( void );
    bool CanSet( IPiece *target );
    
    virtual bool CanMove( stPosition dst_pos );
    virtual bool MovementCheck( bool king_check );
    virtual void Print( void );
   
    Pieces GetType( void );
    Color GetColor( void );
    Status GetStatus( void );
    void SetStatus( Status state );
    stPosition& Position( void );
    stPosition& AvailablePosition( void );
};

#endif // __PIECE_H__