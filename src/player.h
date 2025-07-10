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

#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "ipiece.h"
#include <list>

typedef std :: list<IPiece*> PieceList;

class Player  {

    PieceList    m_pieces;
    Color        m_color;
    IPiece       *m_king;
    IPiece       *m_attacker = nullptr;
    bool         m_oncheck = false;
    

    public:

    Player( Color color );
    ~Player( void );

    void Add( IPiece *piece );
    void Remove( IPiece *piece );
    IPiece* GetKing( void );
    void SetKing( IPiece *piece );
    void SetAttacker( IPiece *piece );
    bool GetCheckStatus( void );
    void SetCheckStatus( bool check );
    bool CheckPieces( IPiece *piece );
    std :: list<IPiece*> MovePieces( void );
    bool CanCheck( void );
    bool CanCatch( void );
    bool CanBlock( void );
};

#endif // __PLAYER_H__