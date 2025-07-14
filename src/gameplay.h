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

#ifndef __GAMEPLAY_H__
#define __GAMEPLAY_H__

#include <map>
#include "iboard.h"
#include "ipiece.h"
#include "player.h"


/**
 * @brief PlayerMap sequence map definition.
 */
typedef std :: map<PlayerNumber, Player*> PlayerMap;

/**
 * @brief Chesse gameplay class implementation.
 */
class GamePlay {

    IBoard       *m_board;
    PlayerMap    m_players;
    bool         m_checkmate = false;
    bool         m_stalemate = false;
    bool         m_promotion = false;
    PlayerNumber m_turn      = PLAYER_1;

    int GetColIndex( char ch );
    int GetRowIndex( char ch );
    stPosition GetPiecePosition( int col, int row );
    void InitPieces( void );
    void ChangeTurn( void );
    void SpecialCases( IPiece *piece );
    void InsertChanges( stPosition pos, IPiece *piece, IPiece *target, PlayerNumber opponent, bool IsReverse );
    bool VirtualMovement( IPiece *piece, stPosition dst_pos, PlayerNumber opponent, bool IsEscape );
    bool KingEscape( void );
    bool HasAvailableMove( const std :: list<IPiece*>& available_pieces );

    public:
    
    GamePlay( IBoard *board );
    ~GamePlay( void );

    void NewGame( void );
    void Promote( char dst_col, char dst_row, Pieces piece_type );
    bool Move( char src_col, char src_row, char dst_col, char dst_row );
    bool HasPromotion( void );
    bool IsCheckmate( void );
    bool IsStalemate( void );
    PlayerNumber GetTurn( void );
    void Print( void );
};

#endif // __GAMEPLAY_H__