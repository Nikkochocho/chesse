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

#include "queen_tests.h"
#include "board.h"
#include "queen.h"
#include "king.h"


TEST( chesse_tests, QUEEN_HORIZONTAL_FORWARD_MOVE_TEST )  {
    
    Board       board;
    Queen        piece = Queen( WHITE, &board );

    board.SetPiece( 0, 0, &piece );

    bool        ret   = piece.CanMove( 5, 0 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, QUEEN_HORIZONTAL_BACKWARD_MOVE_TEST )  {
    
    Board       board;
    Queen       piece = Queen( WHITE, &board );

    board.SetPiece( 5, 0, &piece );

    bool        ret   = piece.CanMove( 0, 0 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, QUEEN_VERTICAL_FORWARD_MOVE_TEST )  {
    
    Board       board;
    Queen       piece = Queen( BLACK, &board );

    board.SetPiece( 0, 0, &piece );

    bool        ret   = piece.CanMove( 0, 5 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, QUEEN_VERTICAL_BACKWARD_MOVE_TEST )  {
    
    Board       board;
    Queen       piece = Queen( BLACK, &board );

    board.SetPiece( 0, 5, &piece );

    bool        ret   = piece.CanMove( 0, 0 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, QUEEN_PRIMARY_DIAGONAL_FORWARD_MOVE_TEST )  {
    
    Board       board;
    Queen       piece = Queen( WHITE, &board );

    board.SetPiece( 4, 4, &piece );

    bool        ret   = piece.CanMove( 7, 7 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, QUEEN_PRIMARY_DIAGONAL_BACKWARD_MOVE_TEST )  {
    
    Board       board;
    Queen       piece = Queen( BLACK, &board );

    board.SetPiece( 7, 7, &piece );

    bool        ret   = piece.CanMove( 4, 4 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, QUEEN_SECONDARY_DIAGONAL_FORWARD_MOVE_TEST )  {
    
    Board       board;
    Queen       piece = Queen( WHITE, &board );

    board.SetPiece( 4, 4, &piece );

    bool        ret   = piece.CanMove( 1, 7 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, QUEEN_SECONDARY_DIAGONAL_BACKWARD_MOVE_TEST )  {
    
    Board       board;
    Queen       piece = Queen( BLACK, &board );

    board.SetPiece( 4, 4, &piece );

    bool        ret   = piece.CanMove( 7, 1 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, QUEEN_INVALID_MOVE_TEST )  {
    
    Board       board;
    Queen       piece = Queen( WHITE, &board );

    board.SetPiece( 0, 0, &piece );

    bool        ret   = piece.CanMove( 1, 2 );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, QUEEN_INVALID_TRESPASS_MOVE_TEST )  {
    
    Board       board;
    Queen       piece = Queen( BLACK, &board );
    Queen       block_piece = Queen( WHITE, &board );

    board.SetPiece( 4, 4, &piece );
    board.SetPiece( 5, 5, &block_piece );

    bool        ret   = piece.CanMove( 7, 7 );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, QUEEN_CAPTURE_MOVE_TEST )  {
    
    Board       board;
    Queen       piece = Queen( WHITE, &board );
    Queen       captured_piece = Queen( BLACK, &board );

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 5, 0, &captured_piece );

    bool        ret   = piece.CanMove( 5, 0 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, QUEEN_FAILED_CAPTURE_MOVE_TEST )  {
    
    Board       board;
    Queen       piece = Queen( WHITE, &board );
    Queen       captured_piece = Queen( WHITE, &board ); //same color

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 5, 0, &captured_piece );

    bool        ret   = piece.CanMove( 5, 0 );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, QUEEN_HORIZONTAL_CHECK_KING ) {
    
    Board       board;
    Queen       piece = Queen( WHITE, &board );
    King        king  = King( BLACK, &board );

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 2, 0, &king );

    bool        ret   = ( piece.MovementCheck( true ) && ( king.GetStatus() == CHECK ) );

    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, QUEEN_VERTICAL_CHECK_KING ) {
    
    Board       board;
    Queen       piece = Queen( WHITE, &board );
    King        king  = King( BLACK, &board );

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 0, 2, &king );

    bool        ret   = ( piece.MovementCheck( true ) && ( king.GetStatus() == CHECK ) );

    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, QUEEN_CHECK_KING_PRIMARY_DIAGONAL_ASC ) {
    
    Board       board;
    Queen       piece = Queen( WHITE, &board );
    King        king  = King( BLACK, &board );

    board.SetPiece( 2, 2, &piece );
    board.SetPiece( 4, 4, &king );

    bool        ret   = ( piece.MovementCheck( true ) && ( king.GetStatus() == CHECK ) );

    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, QUEEN_CHECK_KING_PRIMARY_DIAGONAL_DESC ) {
    
    Board       board;
    Queen       piece = Queen( WHITE, &board );
    King        king  = King( BLACK, &board );

    board.SetPiece( 2, 2, &piece );
    board.SetPiece( 0, 0, &king );

    bool        ret   = ( piece.MovementCheck( true ) && ( king.GetStatus() == CHECK ) );

    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, QUEEN_CHECK_KING_SECONDARY_DIAGONAL_ASC ) {
    
    Board       board;
    Queen       piece = Queen( WHITE, &board );
    King        king  = King( BLACK, &board );

    board.SetPiece( 2, 2, &piece );
    board.SetPiece( 0, 4, &king );

    bool        ret   = ( piece.MovementCheck( true ) && ( king.GetStatus() == CHECK ) );

    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, QUEEN_CHECK_KING_SECONDARY_DIAGONAL_DESC ) {
    
    Board       board;
    Queen       piece = Queen( WHITE, &board );
    King        king  = King( BLACK, &board );

    board.SetPiece( 2, 2, &piece );
    board.SetPiece( 4, 0, &king );

    bool        ret   = ( piece.MovementCheck( true ) && ( king.GetStatus() == CHECK ) );

    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, INVALID_QUEEN_CHECK_KING ) {
    
    Board       board;
    Queen       piece = Queen( BLACK, &board );
    King        king  = King( BLACK, &board ); //same color

    board.SetPiece( 2, 2, &piece );
    board.SetPiece( 4, 0, &king );

    bool        ret   = ( piece.MovementCheck( true ) && ( king.GetStatus() == CHECK ) );

    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, FAILED_QUEEN_CHECK_KING ) {
    
    Board       board;
    Queen       piece = Queen( BLACK, &board );
    Queen       block_piece = Queen( WHITE, &board );
    King        king  = King( WHITE, &board ); 

    board.SetPiece( 2, 2, &piece );
    board.SetPiece( 3, 1, &block_piece );
    board.SetPiece( 4, 0, &king );

    bool        ret   = ( piece.MovementCheck( true ) && ( king.GetStatus() == CHECK ) );

    EXPECT_EQ ( ret, false );
}