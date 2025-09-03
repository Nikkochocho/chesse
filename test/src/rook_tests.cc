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

#include "rook_tests.h"
#include "board.h"
#include "rook.h"
#include "test_helper.h"


TEST( chesse_tests, ROOK_HORIZONTAL_FORWARD_MOVE_TEST )  {
    
    Board       board;
    Rook        piece   = Rook( WHITE, &board );
    stPosition  dst_pos = GetstPosition( 5, 0 );

    board.SetPiece( 0, 0, &piece );

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, ROOK_HORIZONTAL_BACKWARD_MOVE_TEST )  {
    
    Board       board;
    Rook        piece   = Rook( WHITE, &board );
    stPosition  dst_pos = GetstPosition( 0, 0 );

    board.SetPiece( 5, 0, &piece );

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, ROOK_VERTICAL_FORWARD_MOVE_TEST )  {
    
    Board       board;
    Rook        piece   = Rook( BLACK, &board );
    stPosition  dst_pos = GetstPosition( 0, 5 );

    board.SetPiece( 0, 0, &piece );

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, ROOK_VERTICAL_BACKWARD_MOVE_TEST )  {
    
    Board       board;
    Rook        piece   = Rook( BLACK, &board );
    stPosition  dst_pos = GetstPosition( 0, 0 );

    board.SetPiece( 0, 5, &piece );

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, ROOK_INVALID_MOVE_TEST )  {
    
    Board       board;
    Rook        piece   = Rook( BLACK, &board );
    stPosition  dst_pos = GetstPosition( 2, 2 );

    board.SetPiece( 0, 0, &piece );

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, ROOK_INVALID_TRESPASS_MOVE_TEST )  {
    
    Board       board;
    Rook        piece       = Rook( BLACK, &board );
    Rook        block_piece = Rook( WHITE, &board );
    stPosition  dst_pos     = GetstPosition( 5, 0 );

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 2, 0, &block_piece );

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, ROOK_CAPTURE_MOVE_TEST )  {
    
    Board       board;
    Rook        piece          = Rook( WHITE, &board );
    Rook        captured_piece = Rook( BLACK, &board );
    stPosition  dst_pos        = GetstPosition( 2, 0 );

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 2, 0, &captured_piece );

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, ROOK_INVALID_CAPTURE_MOVE_TEST )  {
    
    Board       board;
    Rook        piece          = Rook( WHITE, &board );
    Rook        captured_piece = Rook( WHITE, &board ); // same color
    stPosition  dst_pos        = GetstPosition( 0, 2 );

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 0, 2, &captured_piece );

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, false );
}