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

#include "test_helper.h"


stPosition GetstPosition( int col, int row )  {

    stPosition piece_pos;

    piece_pos.col = col;
    piece_pos.row = row;

    return piece_pos;
}

void LongCastleMove( GamePlay& game )  {

    game.Move( 'b', '1', 'c', '3' );
    game.Move( 'e', '7', 'e', '5' );
    game.Move( 'b', '2', 'b', '3' );
    game.Move( 'd', '7', 'd', '6' );
    game.Move( 'c', '1', 'b', '2' );
    game.Move( 'f', '7', 'f', '6' );
    game.Move( 'e', '2', 'e', '3' );
    game.Move( 'f', '8', 'e', '7' );
    game.Move( 'd', '1', 'e', '2' );
    game.Move( 'b', '7', 'b', '6' );
    game.Move( 'e', '1', 'c', '1' );
}

void ShortCastleMove( GamePlay& game )  {

    game.Move( 'b', '2', 'b', '3' );
    game.Move( 'g', '8', 'f', '6' );
    game.Move( 'c', '2', 'c', '4' );
    game.Move( 'g', '7', 'g', '6' );
    game.Move( 'd', '2', 'd', '3' );
    game.Move( 'f', '8', 'g', '7' );
    game.Move( 'e', '2', 'e', '4' );
    game.Move( 'e', '8', 'g', '8' );
}

void PromotionMove( GamePlay& game )  {

    game.Move( 'd', '2', 'd', '4' );
    game.Move( 'e', '7', 'e', '5' );
    game.Move( 'd', '4', 'e', '5' );
    game.Move( 'f', '7', 'f', '5' );
    game.Move( 'e', '5', 'f', '6' );
    game.Move( 'd', '7', 'd', '5' );
    game.Move( 'f', '6', 'g', '7' );
    game.Move( 'g', '8', 'e', '7' );
    game.Move( 'g', '7', 'h', '8' );
}

void PawnCheck( GamePlay& game )  {

    game.Move( 'd', '2', 'd', '4' );
    game.Move( 'e', '7', 'e', '5' );
    game.Move( 'd', '4', 'e', '5' );
    game.Move( 'f', '7', 'f', '6' );
    game.Move( 'e', '5', 'f', '6' );
    game.Move( 'a', '7', 'a', '6' );
    game.Move( 'f', '6', 'f', '7' );
}

void RookCheck( GamePlay& game )  {

    game.Move( 'd', '2', 'd', '4' );
    game.Move( 'e', '7', 'e', '5' );
    game.Move( 'd', '4', 'e', '5' );
    game.Move( 'f', '7', 'f', '6' );
    game.Move( 'a', '2', 'a', '4' );
    game.Move( 'f', '6', 'e', '5' );
    game.Move( 'a', '1', 'a', '3' );
    game.Move( 'a', '7', 'a', '6' );
    game.Move( 'a', '3', 'e', '3' );
    game.Move( 'e', '5', 'e', '4' );
    game.Move( 'e', '3', 'e', '4' );
}

void KnightCheck( GamePlay& game )  {

    game.Move( 'b', '1', 'c', '3' );
    game.Move( 'e', '7', 'e', '5' );
    game.Move( 'c', '3', 'e', '4' );
    game.Move( 'd', '7', 'd', '6' );
    game.Move( 'e', '4', 'f', '6' );
}

void BishopCheck( GamePlay& game )  {

    game.Move( 'd', '2', 'd', '4' );
    game.Move( 'e', '7', 'e', '5' );
    game.Move( 'd', '4', 'e', '5' );
    game.Move( 'f', '8', 'b', '4' );
}

void QueenCheck( GamePlay& game )  {

    game.Move( 'f', '2', 'f', '4' );
    game.Move( 'e', '7', 'e', '5' );
    game.Move( 'e', '2', 'e', '4' );
    game.Move( 'd', '8', 'h', '4' );
}

void PawnCheckmate( GamePlay& game )  {

    game.Move( 'd', '2', 'd', '4' );
    game.Move( 'f', '7', 'f', '5' );
    game.Move( 'c', '2', 'c', '4' );
    game.Move( 'g', '8', 'f', '6' );
    game.Move( 'b', '1', 'c', '3' );
    game.Move( 'e', '7', 'e', '6' );
    game.Move( 'g', '1', 'f', '3' );
    game.Move( 'd', '7', 'd', '5' );
    game.Move( 'e', '2', 'e', '3' );
    game.Move( 'c', '7', 'c', '6' );
    game.Move( 'f', '1', 'd', '3' );
    game.Move( 'f', '8', 'd', '6' );
    game.Move( 'e', '1', 'g', '1' );
    game.Move( 'e', '8', 'g', '8' );
    game.Move( 'c', '3', 'e', '2' );
    game.Move( 'b', '8', 'd', '7' );
    game.Move( 'f', '3', 'g', '5' );
    game.Move( 'd', '6', 'h', '2' );
    game.Move( 'g', '1', 'h', '1' );
    game.Move( 'f', '6', 'g', '4' );
    game.Move( 'f', '2', 'f', '4' );
    game.Move( 'd', '8', 'e', '8' );
    game.Move( 'g', '2', 'g', '3' );
    game.Move( 'e', '8', 'h', '5' );
    game.Move( 'h', '1', 'g', '2' );
    game.Move( 'h', '2', 'g', '1' );
    game.Move( 'e', '2', 'g', '1' );
    game.Move( 'h', '5', 'h', '2' );
    game.Move( 'g', '2', 'f', '3' );
    game.Move( 'e', '6', 'e', '5' );
    game.Move( 'd', '4', 'e', '5' );
    game.Move( 'd', '7', 'e', '5' );
    game.Move( 'f', '4', 'e', '5' );
    game.Move( 'g', '4', 'e', '5' );
    game.Move( 'f', '3', 'f', '4' );
    game.Move( 'e', '5', 'g', '6' );
    game.Move( 'f', '4', 'f', '3' );
    game.Move( 'f', '5', 'f', '4' );
    game.Move( 'e', '3', 'f', '4' );
    game.Move( 'c', '8', 'g', '4' );
    game.Move( 'f', '3', 'g', '4' );
    game.Move( 'g', '6', 'e', '5' );
    game.Move( 'f', '4', 'e', '5' );
    game.Move( 'h', '7', 'h', '5' );
}

void RookCheckmate( GamePlay& game )  {

    game.Move( 'b', '2', 'b', '4' );
    game.Move( 'd', '7', 'd', '5' );
    game.Move( 'c', '1', 'b', '2' );
    game.Move( 'f', '7', 'f', '5' );
    game.Move( 'e', '2', 'e', '3' );
    game.Move( 'g', '8', 'f', '6' );
    game.Move( 'f', '2', 'f', '4' );
    game.Move( 'e', '7', 'e', '6' );
    game.Move( 'g', '1', 'f', '3' );
    game.Move( 'f', '8', 'b', '4' );
    game.Move( 'b', '1', 'c', '3' );
    game.Move( 'e', '8', 'g', '8' );
    game.Move( 'f', '3', 'g', '5' );
    game.Move( 'h', '7', 'h', '6' );
    game.Move( 'h', '2', 'h', '4' );
    game.Move( 'f', '6', 'g', '4' );
    game.Move( 'f', '1', 'd', '3' );
    game.Move( 'h', '6', 'g', '5' );
    game.Move( 'h', '4', 'g', '5' );
    game.Move( 'c', '7', 'c', '5' );
    game.Move( 'c', '3', 'b', '5' );
    game.Move( 'a', '7', 'a', '6' );
    game.Move( 'h', '1', 'h', '7' );
    game.Move( 'f', '8', 'f', '7' );
    game.Move( 'g', '5', 'g', '6' );
    game.Move( 'f', '7', 'f', '6' );
    game.Move( 'e', '1', 'e', '2' );
    game.Move( 'f', '6', 'g', '6' );
    game.Move( 'd', '1', 'h', '1' );
    game.Move( 'g', '4', 'h', '6' );
    game.Move( 'h', '7', 'g', '7' );
    game.Move( 'g', '6', 'g', '7' );
    game.Move( 'h', '1', 'h', '6' );
    game.Move( 'd', '8', 'e', '7' );
    game.Move( 'b', '5', 'd', '6' );
    game.Move( 'c', '8', 'd', '7' );
    game.Move( 'a', '1', 'h', '1' );
    game.Move( 'g', '8', 'f', '8' );
    game.Move( 'h', '6', 'h', '8' );
    game.Move( 'g', '7', 'g', '8' );
    game.Move( 'h', '8', 'g', '8' );
    game.Move( 'f', '8', 'g', '8' );
    game.Move( 'h', '1', 'h', '8' );
}

void KnightCheckmate( GamePlay& game )  {

    game.Move( 'e', '2', 'e', '4' );
    game.Move( 'e', '7', 'e', '5' );
    game.Move( 'g', '1', 'f', '3' );
    game.Move( 'b', '8', 'c', '6' );
    game.Move( 'f', '1', 'c', '4' );
    game.Move( 'd', '7', 'd', '6' );
    game.Move( 'b', '1', 'c', '3' );
    game.Move( 'c', '8', 'g', '4' );
    game.Move( 'f', '3', 'e', '5' );
    game.Move( 'g', '4', 'd', '1' );
    game.Move( 'c', '4', 'f', '7' );
    game.Move( 'e', '8', 'e', '7' );
    game.Move( 'c', '3', 'd', '5' );
}

void BishopCheckmate( GamePlay& game )  {
    
    game.Move( 'e', '2', 'e', '4' );
    game.Move( 'e', '7', 'e', '6' );
    game.Move( 'd', '2', 'd', '4' );
    game.Move( 'd', '7', 'd', '5' );
    game.Move( 'b', '1', 'c', '3' );
    game.Move( 'f', '8', 'b', '4' );
    game.Move( 'f', '1', 'd', '3' );
    game.Move( 'b', '4', 'c', '3' );
    game.Move( 'b', '2', 'c', '3' );
    game.Move( 'h', '7', 'h', '6' );
    game.Move( 'c', '1', 'a', '3' );
    game.Move( 'b', '8', 'd', '7' );
    game.Move( 'd', '1', 'e', '2' );
    game.Move( 'd', '5', 'e', '4' );
    game.Move( 'd', '3', 'e', '4' );
    game.Move( 'g', '8', 'f', '6' );
    game.Move( 'e', '4', 'd', '3' );
    game.Move( 'b', '7', 'b', '6' );
    game.Move( 'e', '2', 'e', '6' );
    game.Move( 'f', '7', 'e', '6' );
    game.Move( 'd', '3', 'g', '6' );
}

void QueenCheckmate( GamePlay& game )  {

    game.Move( 'f', '2', 'f', '4' );
    game.Move( 'e', '7', 'e', '5' );
    game.Move( 'g', '2', 'g', '4' );
    game.Move( 'd', '8', 'h', '4' );
}

void DoubleCheckmate( GamePlay& game )  {

    game.Move( 'e', '2', 'e', '4' );
    game.Move( 'e', '7', 'e', '5' );
    game.Move( 'g', '1', 'f', '3' );
    game.Move( 'b', '8', 'c', '6' );
    game.Move( 'f', '1', 'c', '4' );
    game.Move( 'f', '8', 'c', '5' );
    game.Move( 'c', '2', 'c', '3' );
    game.Move( 'g', '8', 'f', '6' );
    game.Move( 'd', '2', 'd', '4' );
    game.Move( 'e', '5', 'd', '4' );
    game.Move( 'e', '4', 'e', '5' );
    game.Move( 'f', '6', 'e', '4' );
    game.Move( 'c', '4', 'd', '5' );
    game.Move( 'e', '4', 'f', '2' );
    game.Move( 'e', '1', 'f', '2' );
    game.Move( 'd', '4', 'c', '3' );
    game.Move( 'f', '2', 'g', '3' );
    game.Move( 'c', '3', 'b', '2' );
    game.Move( 'c', '1', 'b', '2' );
    game.Move( 'c', '6', 'e', '7' );
    game.Move( 'f', '3', 'g', '5' );
    game.Move( 'e', '7', 'd', '5' );
    game.Move( 'g', '5', 'f', '7' );
    game.Move( 'e', '8', 'g', '8' );
    game.Move( 'f', '7', 'd', '8' );
    game.Move( 'c', '5', 'f', '2' );
    game.Move( 'g', '3', 'h', '3' );
    game.Move( 'd', '7', 'd', '6' );
    game.Move( 'e', '5', 'e', '6' );
    game.Move( 'd', '5', 'f', '4' );
    game.Move( 'h', '3', 'g', '4' );
    game.Move( 'f', '4', 'e', '6' );
    game.Move( 'd', '8', 'e', '6' );
    game.Move( 'c', '8', 'e', '6' );
    game.Move( 'g', '4', 'g', '5' );
    game.Move( 'f', '8', 'f', '5' );
    game.Move( 'g', '5', 'g', '4' );
    game.Move( 'h', '7', 'h', '5' );
    game.Move( 'g', '4', 'h', '3' );
    game.Move( 'f', '5', 'f', '3' );
}
void Stalemate( GamePlay& game )  {

    game.Move( 'c', '2', 'c', '4' );
    game.Move( 'h', '7', 'h', '5' );
    game.Move( 'h', '2', 'h', '4' );
    game.Move( 'a', '7', 'a', '5' );
    game.Move( 'd', '1', 'a', '4' );
    game.Move( 'a', '8', 'a', '6' );
    game.Move( 'a', '4', 'a', '5' );
    game.Move( 'a', '6', 'h', '6' );
    game.Move( 'a', '5', 'c', '7' );
    game.Move( 'f', '7', 'f', '6' );
    game.Move( 'c', '7', 'd', '7' );
    game.Move( 'e', '8', 'f', '7' );
    game.Move( 'd', '7', 'b', '7' );
    game.Move( 'd', '8', 'd', '3' );
    game.Move( 'b', '7', 'b', '8' );
    game.Move( 'd', '3', 'h', '7' );
    game.Move( 'b', '8', 'c', '8' );
    game.Move( 'f', '7', 'g', '6' );
    game.Move( 'c', '8', 'e', '6' );
}

void StalemateNoCapture( GamePlay& game )  {
    
    game.Move( 'a', '2', 'a', '4' );
    game.Move( 'c', '7', 'c', '5' );
    game.Move( 'd', '2', 'd', '4' );
    game.Move( 'd', '7', 'd', '6' );
    game.Move( 'd', '1', 'd', '2' );
    game.Move( 'e', '7', 'e', '5' );
    game.Move( 'd', '2', 'f', '4' );
    game.Move( 'e', '5', 'e', '4' );
    game.Move( 'h', '2', 'h', '3' );
    game.Move( 'f', '8', 'e', '7' );
    game.Move( 'f', '4', 'h', '2' );
    game.Move( 'e', '7', 'h', '4' );
    game.Move( 'a', '1', 'a', '3' );
    game.Move( 'c', '8', 'e', '6' );
    game.Move( 'a', '3', 'g', '3' );
    game.Move( 'e', '6', 'b', '3' );
    game.Move( 'b', '1', 'd', '2' );
    game.Move( 'd', '8', 'a', '5' );
    game.Move( 'd', '4', 'd', '5' );
    game.Move( 'e', '4', 'e', '3' );
    game.Move( 'c', '2', 'c', '4' );
    game.Move( 'f', '7', 'f', '5' );
    game.Move( 'f', '2', 'f', '3' );
    game.Move( 'f', '5', 'f', '4' );
}

void DoubleStalemate( GamePlay& game )  {

    game.Move( 'c', '2', 'c', '4' );
    game.Move( 'd', '7', 'd', '5' );
    game.Move( 'd', '1', 'b', '3' );
    game.Move( 'c', '8', 'h', '3' );
    game.Move( 'g', '2', 'h', '3' );
    game.Move( 'f', '7', 'f', '5' );
    game.Move( 'b', '3', 'b', '7' );
    game.Move( 'e', '8', 'f', '7' );
    game.Move( 'b', '7', 'a', '7' );
    game.Move( 'f', '7', 'g', '6' );
    game.Move( 'f', '2', 'f', '3' );
    game.Move( 'c', '7', 'c', '5' );
    game.Move( 'a', '7', 'e', '7' );
    game.Move( 'a', '8', 'a', '2' );
    game.Move( 'e', '1', 'f', '2' );
    game.Move( 'a', '2', 'b', '2' );
    game.Move( 'e', '7', 'g', '7' );
    game.Move( 'g', '6', 'h', '5' );
    game.Move( 'g', '7', 'g', '8' );
    game.Move( 'b', '2', 'b', '1' );
    game.Move( 'a', '1', 'b', '1' );
    game.Move( 'h', '5', 'h', '4' );
    game.Move( 'g', '8', 'h', '8' );
    game.Move( 'h', '7', 'h', '5' );
    game.Move( 'h', '8', 'h', '6' );
    game.Move( 'f', '8', 'h', '6' );
    game.Move( 'b', '1', 'b', '8' );
    game.Move( 'h', '6', 'e', '3' );
    game.Move( 'd', '2', 'e', '3' );
    game.Move( 'd', '8', 'b', '8' );
    game.Move( 'f', '2', 'g', '2' );
    game.Move( 'b', '8', 'f', '4' );
    game.Move( 'e', '3', 'f', '4' );
    game.Move( 'd', '5', 'd', '4' );
    game.Move( 'c', '1', 'e', '3' );
    game.Move( 'd', '4', 'e', '3' );
}