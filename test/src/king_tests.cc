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

#include "king_tests.h"
#include "board.h"
#include "king.h"
#include "rook.h"
#include "test_helper.h"


TEST( chesse_tests, KING_HORIZONTAL_FORWARD_MOVE_TEST )  {
    
    Board       board;
    King        piece    = King( WHITE, &board );
    stPosition  dst_pos  = GetstPosition( 1, 0 );

    board.SetPiece( 0, 0, &piece );

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, KING_HORIZONTAL_BACKWARD_MOVE_TEST )  {
    
    Board       board;
    King        piece    = King( WHITE, &board );
    stPosition  dst_pos  = GetstPosition( 0, 0 );

    board.SetPiece( 1, 0, &piece );

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, KING_VERTICAL_FORWARD_MOVE_TEST )  {
    
    Board       board;
    King        piece    = King( BLACK, &board );
    stPosition  dst_pos  = GetstPosition( 0, 1 );

    board.SetPiece( 0, 0, &piece );

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, KING_VERTICAL_BACKWARD_MOVE_TEST )  {
    
    Board       board;
    King        piece = King( BLACK, &board );
    stPosition  dst_pos  = GetstPosition( 0, 0 );

    board.SetPiece( 0, 1, &piece );

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, KING_PRIMARY_DIAGONAL_FORWARD_MOVE_TEST )  {
    
    Board       board;
    King        piece    = King( WHITE, &board );
    stPosition  dst_pos  = GetstPosition( 5, 5 );

    board.SetPiece( 4, 4, &piece );

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, KING_PRIMARY_DIAGONAL_BACKWARD_MOVE_TEST )  {
    
    Board       board;
    King        piece    = King( BLACK, &board );
    stPosition  dst_pos  = GetstPosition( 6, 6 );

    board.SetPiece( 7, 7, &piece );

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, KING_SECONDARY_DIAGONAL_FORWARD_MOVE_TEST )  {
    
    Board       board;
    King        piece    = King( WHITE, &board );
    stPosition  dst_pos  = GetstPosition( 3, 5 );

    board.SetPiece( 4, 4, &piece );

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, KING_SECONDARY_DIAGONAL_BACKWARD_MOVE_TEST )  {
    
    Board       board;
    King        piece    = King( BLACK, &board );
    stPosition  dst_pos  = GetstPosition( 5, 3 );

    board.SetPiece( 4, 4, &piece );

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, KING_INVALID_MOVE_TEST )  {
    
    Board       board;
    King        piece    = King( BLACK, &board );
    stPosition  dst_pos  = GetstPosition( 0, 3 );

    board.SetPiece( 0, 0, &piece );

    bool        ret   = piece.CanMove( dst_pos ); // exceeds 1 step
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, KING_CAPTURE_MOVE_TEST )  {
    
    Board       board;
    King        piece          = King( WHITE, &board );
    King        captured_piece = King( BLACK, &board );
    stPosition  dst_pos        = GetstPosition( 1, 0 );

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 1, 0, &captured_piece );

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, KING_FAILED_CAPTURE_MOVE_TEST )  {
    
    Board       board;
    King        piece          = King( WHITE, &board );
    King        captured_piece = King( WHITE, &board ); // same color
    stPosition  dst_pos        = GetstPosition( 1, 0 );

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 1, 0, &captured_piece );

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, KING_INVALID_CASTLE_CAPTURE_MOVE_TEST )  {
    
    Board       board;
    King        piece          = King( BLACK, &board );
    Rook        captured_piece = Rook( WHITE, &board );
    Rook        castle         = Rook( BLACK, &board );
    stPosition  dst_pos        = GetstPosition( 6, 0 );

    board.SetPiece( 4, 0, &piece );
    board.SetPiece( 6, 0, &captured_piece );
    board.SetPiece( 7, 0, &castle );

    piece.CanMove( dst_pos );

    bool        ret   = ( piece.GetStatus() == SHORTCASTLE );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, KING_SHORT_CASTLE_MOVE_TEST )  {
    
    Board       board;
    King        piece    = King( BLACK, &board );
    Rook        castle   = Rook( BLACK, &board );
    stPosition  dst_pos  = GetstPosition( 6, 0 );

    board.SetPiece( 4, 0, &piece );
    board.SetPiece( 7, 0, &castle );

    piece.CanMove( dst_pos );

    bool        ret   = ( piece.GetStatus() == SHORTCASTLE );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, KING_INVALID_TRESPASS_SHORT_CASTLE_MOVE_TEST )  {
    
    Board       board;
    King        piece       = King( BLACK, &board );
    King        block_piece = King( WHITE, &board );
    Rook        castle      = Rook( BLACK, &board );
    stPosition  dst_pos     = GetstPosition( 6, 0 );

    board.SetPiece( 4, 0, &piece );
    board.SetPiece( 5, 0, &block_piece );
    board.SetPiece( 7, 0, &castle );

    piece.CanMove( dst_pos );

    bool        ret   = ( piece.GetStatus() == SHORTCASTLE );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, KING_LONG_CASTLE_MOVE_TEST )  {
    
    Board       board;
    King        piece    = King( WHITE, &board );
    Rook        castle   = Rook( WHITE, &board );
    stPosition  dst_pos  = GetstPosition( 2, 0 );

    board.SetPiece( 4, 0, &piece );
    board.SetPiece( 0, 0, &castle );

    piece.CanMove( dst_pos );

    bool        ret   = ( piece.GetStatus() == LONGCASTLE );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, KING_INVALID_LONG_CASTLE_MOVE_TEST )  {
    
    Board       board;
    King        piece    = King( WHITE, &board );
    Rook        castle   = Rook( WHITE, &board );
    stPosition  dst_pos  = GetstPosition( 1, 0 );

    board.SetPiece( 4, 0, &piece );
    board.SetPiece( 0, 0, &castle );

    piece.CanMove( dst_pos );

    bool        ret   = ( piece.GetStatus() == LONGCASTLE );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, KING_INVALID_TRESPASS_LONG_CASTLE_MOVE_TEST )  {
    
    Board       board;
    King        piece       = King( WHITE, &board );
    King        block_piece = King( WHITE, &board );
    Rook        castle      = Rook( WHITE, &board );
    stPosition  dst_pos     = GetstPosition( 2, 0 );

    board.SetPiece( 4, 0, &piece );
    board.SetPiece( 1, 0, &block_piece );
    board.SetPiece( 0, 0, &castle );

    piece.CanMove( dst_pos );

    bool        ret   = ( piece.GetStatus() == LONGCASTLE );
    
    EXPECT_EQ ( ret, false );
}