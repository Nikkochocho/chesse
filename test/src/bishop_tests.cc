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

#include "bishop_tests.h"
#include "board.h"
#include "bishop.h"
#include "test_helper.h"


TEST( chesse_tests, BISHOP_PRIMARY_DIAGONAL_FORWARD_MOVE_TEST )  {
    
    Board       board;
    Bishop      piece    = Bishop( WHITE, &board );
    stPosition  dst_pos  = GetstPosition( 7, 7 );

    board.SetPiece( 4, 4, &piece );

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, BISHOP_PRIMARY_DIAGONAL_BACKWARD_MOVE_TEST )  {
    
    Board       board;
    Bishop      piece    = Bishop( BLACK, &board );
    stPosition  dst_pos  = GetstPosition( 4, 4 );

    board.SetPiece( 7, 7, &piece );

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, BISHOP_SECONDARY_DIAGONAL_FORWARD_MOVE_TEST )  {
    
    Board       board;
    Bishop      piece    = Bishop( WHITE, &board );
    stPosition  dst_pos  = GetstPosition( 1, 7 );

    board.SetPiece( 4, 4, &piece );

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, BISHOP_SECONDARY_DIAGONAL_BACKWARD_MOVE_TEST )  {
    
    Board       board;
    Bishop      piece    = Bishop( BLACK, &board );
    stPosition  dst_pos  = GetstPosition( 7, 1 );

    board.SetPiece( 4, 4, &piece );

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, BISHOP_INVALID_MOVE_TEST )  {
    
    Board       board;
    Bishop      piece    = Bishop( WHITE, &board );
    stPosition  dst_pos  = GetstPosition( 4, 5 );

    board.SetPiece( 4, 4, &piece );

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, BISHOP_INVALID_TRESPASS_MOVE_TEST )  {
    
    Board       board;
    Bishop      piece       = Bishop( BLACK, &board );
    Bishop      block_piece = Bishop( WHITE, &board );
    stPosition  dst_pos     = GetstPosition( 7, 7 );

    board.SetPiece( 4, 4, &piece );
    board.SetPiece( 5, 5, &block_piece );

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, BISHOP_CAPTURE_MOVE_TEST )  {
    
    Board       board;
    Bishop      piece          = Bishop( BLACK, &board );
    Bishop      captured_piece = Bishop( WHITE, &board );
    stPosition  dst_pos        = GetstPosition( 5, 5 );

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 5, 5, &captured_piece );

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, BISHOP_INVALID_CAPTURE_MOVE_TEST )  {
    
    Board       board;
    Bishop      piece          = Bishop( WHITE, &board );
    Bishop      captured_piece = Bishop( WHITE, &board ); // same color
    stPosition  dst_pos        = GetstPosition( 5, 5 );

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 5, 5, &captured_piece );

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, false );
}