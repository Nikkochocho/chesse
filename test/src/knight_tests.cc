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

#include "knight_tests.h"
#include "board.h"
#include "knight.h"
#include "king.h"


TEST( chesse_tests, KNIGHT_ALL_VALID_MOVES_TEST )  {
    
    Board         board;
    Knight        piece = Knight( WHITE, &board );
    const int     x[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    const int     y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    bool          ret;

    board.SetPiece( 4, 4, &piece );

    for ( int i = 0; i < 8; i++ ) {

        ret = piece.CanMove( ( piece.Position().col + x[i] ), ( piece.Position().row + y[i] ) );

        if ( !ret )
            break;
    }
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, KNIGHT_INVALID_VERTICAL_MOVE_TEST )  {

    Board         board;
    Knight        piece = Knight( WHITE, &board );

    board.SetPiece( 0, 0, &piece );

    bool          ret = piece.CanMove( 0, 1 );

    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, KNIGHT_INVALID_HORIZONTAL_MOVE_TEST )  {

    Board         board;
    Knight        piece = Knight( WHITE, &board );

    board.SetPiece( 0, 0, &piece );

    bool          ret = piece.CanMove( 1, 0 );

    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, KNIGHT_INVALID_DIAGONAL_MOVE_TEST )  {

    Board         board;
    Knight        piece = Knight( WHITE, &board );

    board.SetPiece( 0, 0, &piece );

    bool          ret = piece.CanMove( 1, 1 );

    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, KNIGHT_JUMP_OVER_MOVE_TEST )  {

    Board         board;
    Knight        piece = Knight( BLACK, &board );
    Knight        enemy_piece = Knight( WHITE, &board );
    Knight        friendly_piece = Knight( BLACK, &board );

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 0, 1, &friendly_piece );
    board.SetPiece( 0, 2, &enemy_piece );
    //should be able to jump over both

    bool          ret = piece.CanMove( 1, 2 );

    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, KNIGHT_CAPTURE_MOVE_TEST )  {

    Board         board;
    Knight        piece = Knight( BLACK, &board );
    Knight        captured_piece = Knight( WHITE, &board );

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 1, 2, &captured_piece );

    bool          ret = piece.CanMove( 1, 2 );

    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, KNIGHT_INVALID_CAPTURE_MOVE_TEST )  {

    Board         board;
    Knight        piece = Knight( WHITE, &board );
    Knight        captured_piece = Knight( WHITE, &board ); //same color

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 1, 2, &captured_piece );

    bool          ret = piece.CanMove( 1, 2 );

    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, KNIGHT_CHECK_KING ) {
    
    Board       board;

    Knight      piece = Knight( WHITE, &board );
    King        king = King( BLACK, &board );

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 1, 2, &king );

    bool        ret   = ( piece.MovementCheck( true ) && ( king.GetStatus() == CHECK ) );

    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, INVALID_KNIGHT_CHECK_KING ) {
    
    Board       board;

    Knight      piece = Knight( WHITE, &board );
    King        king = King( WHITE, &board ); //same color

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 1, 2, &king );

    bool        ret   = ( piece.MovementCheck( true ) && ( king.GetStatus() == CHECK ) );

    EXPECT_EQ ( ret, false );
}