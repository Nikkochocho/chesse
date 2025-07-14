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

#include "pawn_tests.h"
#include "board.h"
#include "pawn.h"
#include "king.h"
#include "test_helper.h"


// GENERAL TESTS
TEST( chesse_tests, PAWN_INVALID_ROW_MOVE ) {
    
    Board       board;
    Pawn        piece   = Pawn( WHITE, &board );
    stPosition  dst_pos = GetstPosition( 0, 0 );

    board.SetPiece( 0, 1, &piece );

    bool        ret   = piece.CanMove( dst_pos );

    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, PAWN_INVALID_COLUMN_MOVE ) {
    
    Board       board;
    Pawn        piece   = Pawn( BLACK, &board );
    stPosition  dst_pos = GetstPosition( 1, 0 );

    board.SetPiece( 0, 0, &piece );

    bool        ret   = piece.CanMove( dst_pos );

    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, PAWN_INVALID_TRESPASS_MOVE ) {
    
    Board       board;
    Pawn        piece       = Pawn( WHITE, &board );
    Pawn        block_piece = Pawn( BLACK, &board );
    stPosition  dst_pos     = GetstPosition( 0, 1 );

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 0, 1, &block_piece);

    bool        ret   = piece.CanMove( dst_pos );

    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, PAWN_INVALID_DOUBLE_TRESPASS_MOVE ) {
    
    Board       board;
    Pawn        piece       = Pawn( WHITE, &board );
    Pawn        block_piece = Pawn( BLACK, &board );
    stPosition  dst_pos     = GetstPosition( 0, 2 );

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 0, 1, &block_piece);

    bool        ret   = piece.CanMove( dst_pos );

    EXPECT_EQ ( ret, false );
}

// WHITE PAWN TESTS
TEST( chesse_tests, WHITE_PAWN_ONE_STEP_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece   = Pawn( WHITE, &board );
    stPosition  dst_pos = GetstPosition( 0, 1 );

    board.SetPiece( 0, 0, &piece );

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, WHITE_PAWN_TWO_STEPS_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece   = Pawn( WHITE, &board );
    stPosition  dst_pos = GetstPosition( 0, 2 );

    board.SetPiece( 0, 0, &piece );

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, WHITE_PAWN_FAILED_TWO_STEPS_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece   = Pawn( WHITE, &board );
    stPosition  dst_pos = GetstPosition( 0, 2 );

    board.SetPiece( 0, 0, &piece );

    piece.AddMovementCount(); // sets movement to 1;

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, WHITE_PAWN_CAPTURE_RIGHT_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece          = Pawn( WHITE, &board );
    Pawn        captured_piece = Pawn( BLACK, &board );
    stPosition  dst_pos        = GetstPosition( 1, 1 );

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 1, 1, &captured_piece);

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, WHITE_PAWN_CAPTURE_LEFT_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece          = Pawn( WHITE, &board );
    Pawn        captured_piece = Pawn( BLACK, &board );
    stPosition  dst_pos        = GetstPosition( 0, 1 );

    board.SetPiece( 1, 0, &piece );
    board.SetPiece( 0, 1, &captured_piece);

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, WHITE_PAWN_INVALID_CAPTURE_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece          = Pawn( WHITE, &board );
    Pawn        captured_piece = Pawn( WHITE, &board ); // same color
    stPosition  dst_pos        = GetstPosition( 1, 1 );

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 1, 1, &captured_piece);

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, WHITE_PAWN_FAILED_CAPTURE_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece   = Pawn( WHITE, &board );
    stPosition  dst_pos = GetstPosition( 0, 1 );

    board.SetPiece( 1, 0, &piece );

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, WHITE_PAWN_PROMOTION_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece   = Pawn( WHITE, &board );
    stPosition  dst_pos = GetstPosition( 0, 7 );

    board.SetPiece( 0, 6, &piece );
    piece.CanMove( dst_pos );

    bool        ret   = ( piece.GetStatus() == PROMOTION );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, WHITE_PAWN_CHECK_KING_RIGHT ) {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );
    King        king  = King( BLACK, &board ); // same color

    board.SetPiece( 1, 0, &piece );
    board.SetPiece( 2, 1, &king );

    bool        ret   = ( piece.MovementCheck( true ) && ( king.GetStatus() == CHECK ) );

    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, WHITE_PAWN_CHECK_KING_LEFT ) {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );
    King        king  = King( BLACK, &board ); //same color

    board.SetPiece( 1, 0, &piece );
    board.SetPiece( 0, 1, &king );

    bool        ret   = ( piece.MovementCheck( true ) && ( king.GetStatus() == CHECK ) );

    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, INVALID_WHITE_PAWN_CHECK_KING ) {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );
    King        king  = King( WHITE, &board ); //same color

    board.SetPiece( 1, 0, &piece );
    board.SetPiece( 2, 1, &king );

    bool        ret   = ( piece.MovementCheck( true ) && ( king.GetStatus() == CHECK ) );

    EXPECT_EQ ( ret, false );
}

// BLACK PAWN TESTS
TEST( chesse_tests, BLACK_PAWN_ONE_STEP_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece   = Pawn( BLACK, &board );
    stPosition  dst_pos = GetstPosition( 0, 6 );

    board.SetPiece( 0, 7, &piece );

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, BLACK_PAWN_TWO_STEPS_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece   = Pawn( BLACK, &board );
    stPosition  dst_pos = GetstPosition( 0, 5 );

    board.SetPiece( 0, 7, &piece );

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, BLACK_PAWN_FAILED_TWO_STEPS_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece   = Pawn( BLACK, &board );
    stPosition  dst_pos = GetstPosition( 0, 5 );

    board.SetPiece( 0, 7, &piece );

    piece.AddMovementCount(); // sets movement to 1;

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, BLACK_PAWN_CAPTURE_RIGHT_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece          = Pawn( BLACK, &board );
    Pawn        captured_piece = Pawn( WHITE, &board );
    stPosition  dst_pos        = GetstPosition( 0, 0 );

    board.SetPiece( 1, 1, &piece );
    board.SetPiece( 0, 0, &captured_piece );

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, BLACK_PAWN_CAPTURE_LEFT_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece          = Pawn( BLACK, &board );
    Pawn        captured_piece = Pawn( WHITE, &board );
    stPosition  dst_pos        = GetstPosition( 1, 0 );

    board.SetPiece( 0, 1, &piece );
    board.SetPiece( 1, 0, &captured_piece );

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, BLACK_PAWN_INVALID_CAPTURE_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece          = Pawn( BLACK, &board );
    Pawn        captured_piece = Pawn( BLACK, &board ); // same color
    stPosition  dst_pos        = GetstPosition( 0, 0 );

    board.SetPiece( 1, 1, &piece );
    board.SetPiece( 0, 0, &captured_piece );

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, BLACK_PAWN_FAILED_CAPTURE_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece   = Pawn( BLACK, &board );
    stPosition  dst_pos = GetstPosition( 1, 0 );

    board.SetPiece( 0, 1, &piece );

    bool        ret   = piece.CanMove( dst_pos );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, BLACK_PAWN_PROMOTION_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece   = Pawn( BLACK, &board );
    stPosition  dst_pos = GetstPosition( 0, 0 );

    board.SetPiece( 0, 1, &piece );
    piece.CanMove( dst_pos );

    bool        ret   = ( piece.GetStatus() == PROMOTION );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, BLACK_PAWN_CHECK_KING_RIGHT ) {
    
    Board       board;
    Pawn        piece = Pawn( BLACK, &board );
    King        king  = King( WHITE, &board ); 

    board.SetPiece( 1, 1, &piece );
    board.SetPiece( 0, 0, &king );

    bool        ret   = ( piece.MovementCheck( true ) && ( king.GetStatus() == CHECK ) );

    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, BLACK_PAWN_CHECK_KING_LEFT ) {
    
    Board       board;
    Pawn        piece = Pawn( BLACK, &board );
    King        king  = King( WHITE, &board ); 

    board.SetPiece( 1, 1, &piece );
    board.SetPiece( 2, 0, &king );

    bool        ret   = ( piece.MovementCheck( true ) && ( king.GetStatus() == CHECK ) );

    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, INVALID_BLACK_PAWN_CHECK_KING ) {
    
    Board       board;
    Pawn        piece = Pawn( BLACK, &board );
    King        king  = King( BLACK, &board ); 

    board.SetPiece( 1, 1, &piece );
    board.SetPiece( 0, 0, &king );

    bool        ret   = ( piece.MovementCheck( true ) && ( king.GetStatus() == CHECK ) );

    EXPECT_EQ ( ret, false );
}

// SPECIAL MOVES
TEST( chesse_tests, PAWN_EN_PASSANT_CAPTURE_RIGHT_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece          = Pawn( WHITE, &board );
    Pawn        captured_piece = Pawn( BLACK, &board );
    stPosition  dst_pos        = GetstPosition( 1, 5 );

    board.SetPiece( 0, 4, &piece );
    board.SetPiece( 1, 4, &captured_piece );
    captured_piece.AddMovementCount();

    piece.CanMove( dst_pos );

    bool        ret   = ( piece.GetStatus() == ENPASSANT );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, PAWN_EN_PASSANT_CAPTURE_LEFT_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece          = Pawn( BLACK, &board );
    Pawn        captured_piece = Pawn( WHITE, &board );
    stPosition  dst_pos        = GetstPosition( 0, 2 );

    board.SetPiece( 1, 3, &piece );
    board.SetPiece( 0, 3, &captured_piece );
    captured_piece.AddMovementCount();

    piece.CanMove( dst_pos );

    bool        ret   = ( piece.GetStatus() == ENPASSANT );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, PAWN_INVALID_EN_PASSANT_ROW_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece          = Pawn( WHITE, &board );
    Pawn        captured_piece = Pawn( BLACK, &board );
    stPosition  dst_pos        = GetstPosition( 0, 6 );

    board.SetPiece( 1, 5, &piece );
    board.SetPiece( 0, 5, &captured_piece );
    captured_piece.AddMovementCount();

    piece.CanMove( dst_pos );

    bool        ret   = ( piece.GetStatus() == ENPASSANT );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, PAWN_FAILED_EN_PASSANT_CAPTURE_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece          = Pawn( BLACK, &board );
    Pawn        captured_piece = Pawn( WHITE, &board );
    stPosition  dst_pos        = GetstPosition( 0, 2 );

    board.SetPiece( 1, 3, &piece );
    board.SetPiece( 0, 3, &captured_piece );
    // m_movement = 0;

    piece.CanMove( dst_pos );

    bool        ret   = ( piece.GetStatus() == ENPASSANT );
    
    EXPECT_EQ ( ret, false );
}