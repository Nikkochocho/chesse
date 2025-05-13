#include "king_tests.h"
#include "board.h"
#include "king.h"
#include "rook.h"


TEST( chesse_tests, KING_HORIZONTAL_FORWARD_MOVE_TEST )  {
    
    Board       board;
    King        piece = King( WHITE, &board );
    bool        ret   = piece.Check( 0, 0, 1, 0 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, KING_HORIZONTAL_BACKWARD_MOVE_TEST )  {
    
    Board       board;
    King        piece = King( WHITE, &board );
    bool        ret   = piece.Check( 1, 0, 0, 0 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, KING_VERTICAL_FORWARD_MOVE_TEST )  {
    
    Board       board;
    King        piece = King( BLACK, &board );
    bool        ret   = piece.Check( 0, 0, 0, 1 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, KING_VERTICAL_BACKWARD_MOVE_TEST )  {
    
    Board       board;
    King        piece = King( BLACK, &board );
    bool        ret   = piece.Check( 0, 1, 0, 0 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, KING_PRIMARY_DIAGONAL_FORWARD_MOVE_TEST )  {
    
    Board       board;
    King        piece = King( WHITE, &board );
    bool        ret   = piece.Check( 4, 4, 5, 5 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, KING_PRIMARY_DIAGONAL_BACKWARD_MOVE_TEST )  {
    
    Board       board;
    King        piece = King( BLACK, &board );
    bool        ret   = piece.Check( 7, 7, 6, 6 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, KING_SECONDARY_DIAGONAL_FORWARD_MOVE_TEST )  {
    
    Board       board;
    King        piece = King( WHITE, &board );
    bool        ret   = piece.Check( 4, 4, 3, 5 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, KING_SECONDARY_DIAGONAL_BACKWARD_MOVE_TEST )  {
    
    Board       board;
    King        piece = King( BLACK, &board );
    bool        ret   = piece.Check( 4, 4, 5, 3 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, KING_INVALID_MOVE_TEST )  {
    
    Board       board;
    King        piece = King( BLACK, &board );
    bool        ret   = piece.Check( 0, 0, 0, 3 ); //exceeds 1 step
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, KING_CAPTURE_MOVE_TEST )  {
    
    Board       board;
    King        piece = King( WHITE, &board );
    King        captured_piece = King( BLACK, &board );

    board.SetPiece( 1, 0, &captured_piece );

    bool        ret   = piece.Check( 0, 0, 1, 0 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, KING_FAILED_CAPTURE_MOVE_TEST )  {
    
    Board       board;
    King        piece = King( WHITE, &board );
    King        captured_piece = King( WHITE, &board ); //same color

    board.SetPiece( 1, 0, &captured_piece );

    bool        ret   = piece.Check( 0, 0, 1, 0 );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, KING_INVALID_CASTLE_CAPTURE_MOVE_TEST )  {
    
    Board       board;
    King        piece = King( BLACK, &board );
    Rook        captured_piece = Rook( WHITE, &board );
    Rook        castle = Rook( BLACK, &board );

    board.SetPiece( 6, 0, &captured_piece );
    board.SetPiece( 7, 0, &castle );

    piece.Check( 4, 0, 6, 0 );

    bool        ret   = ( piece.GetStatus() == SHORTCASTLE );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, KING_SHORT_CASTLE_MOVE_TEST )  {
    
    Board       board;
    King        piece = King( BLACK, &board );
    Rook        castle = Rook( BLACK, &board );

    board.SetPiece( 7, 0, &castle );

    piece.Check( 4, 0, 6, 0 );

    bool        ret   = ( piece.GetStatus() == SHORTCASTLE );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, KING_INVALID_TRESPASS_SHORT_CASTLE_MOVE_TEST )  {
    
    Board       board;
    King        piece = King( BLACK, &board );
    King        block_piece = King( WHITE, &board );
    Rook        castle = Rook( BLACK, &board );

    board.SetPiece( 5, 0, &block_piece );
    board.SetPiece( 7, 0, &castle );

    piece.Check( 4, 0, 6, 0 );

    bool        ret   = ( piece.GetStatus() == SHORTCASTLE );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, KING_LONG_CASTLE_MOVE_TEST )  {
    
    Board       board;
    King        piece = King( WHITE, &board );
    Rook        castle = Rook( WHITE, &board );

    board.SetPiece( 0, 0, &castle );

    piece.Check( 4, 0, 2, 0 );

    bool        ret   = ( piece.GetStatus() == LONGCASTLE );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, KING_INVALID_LONG_CASTLE_MOVE_TEST )  {
    
    Board       board;
    King        piece = King( WHITE, &board );
    Rook        castle = Rook( WHITE, &board );

    board.SetPiece( 0, 0, &castle );

    piece.Check( 4, 0, 1, 0 );

    bool        ret   = ( piece.GetStatus() == LONGCASTLE );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, KING_INVALID_TRESPASS_LONG_CASTLE_MOVE_TEST )  {
    
    Board       board;
    King        piece = King( WHITE, &board );
    King        block_piece = King( WHITE, &board );
    Rook        castle = Rook( WHITE, &board );

    board.SetPiece( 1, 0, &block_piece );
    board.SetPiece( 0, 0, &castle );

    piece.Check( 4, 0, 2, 0 );

    bool        ret   = ( piece.GetStatus() == LONGCASTLE );
    
    EXPECT_EQ ( ret, false );
}

//add invalid check move later