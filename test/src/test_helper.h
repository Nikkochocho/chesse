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

#ifndef __TEST_HELPER_H__
#define __TEST_HELPER_H__

#include "gameplay.h"


stPosition GetstPosition( int col, int row );
void LongCastleMove( GamePlay& game );
void ShortCastleMove( GamePlay& game );
void PromotionMove( GamePlay& game );
void PawnCheck( GamePlay& game );
void RookCheck( GamePlay& game );
void KnightCheck( GamePlay& game );
void BishopCheck( GamePlay& game );
void QueenCheck( GamePlay& game );
void PawnCheckmate( GamePlay& game );
void RookCheckmate( GamePlay& game );
void KnightCheckmate( GamePlay& game );
void BishopCheckmate( GamePlay& game );
void QueenCheckmate( GamePlay& game );
void DoubleCheckmate( GamePlay& game );
void Stalemate( GamePlay& game );
void StalemateNoCapture( GamePlay& game );
void DoubleStalemate( GamePlay& game );

#endif // __TEST_HELPER_H__