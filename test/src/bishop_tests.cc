#include "bishop_tests.h"
#include "board.h"
#include "bishop.h"


TEST( chesse_tests, BISHOP_PRIMARY_DIAGONAL_FORWARD_MOVE_TEST )  {
    
    Board       board;
    Bishop      piece = Bishop( WHITE, &board );
    bool        ret   = piece.Check( 4, 4, 7, 7 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, BISHOP_PRIMARY_DIAGONAL_BACKWARD_MOVE_TEST )  {
    
    Board       board;
    Bishop      piece = Bishop( BLACK, &board );
    bool        ret   = piece.Check( 7, 7, 4, 4 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, BISHOP_SECONDARY_DIAGONAL_FORWARD_MOVE_TEST )  {
    
    Board       board;
    Bishop      piece = Bishop( WHITE, &board );
    bool        ret   = piece.Check( 4, 4, 1, 7 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, BISHOP_SECONDARY_DIAGONAL_BACKWARD_MOVE_TEST )  {
    
    Board       board;
    Bishop      piece = Bishop( BLACK, &board );
    bool        ret   = piece.Check( 4, 4, 7, 1 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, BISHOP_INVALID_MOVE_TEST )  {
    
    Board       board;
    Bishop      piece = Bishop( WHITE, &board );
    bool        ret   = piece.Check( 4, 4, 4, 5 );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, BISHOP_INVALID_TRESPASS_MOVE_TEST )  {
    
    Board       board;
    Bishop      piece = Bishop( BLACK, &board );
    Bishop      block_piece = Bishop( WHITE, &board );

    board.SetPiece( 5, 5, &block_piece);

    bool        ret   = piece.Check( 4, 4, 7, 7 );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, BISHOP_CAPTURE_MOVE_TEST )  {
    
    Board       board;
    Bishop      piece = Bishop( BLACK, &board );
    Bishop      captured_piece = Bishop( WHITE, &board );

    board.SetPiece( 5, 5, &captured_piece);

    bool        ret   = piece.Check( 0, 0, 5, 5 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, BISHOP_INVALID_CAPTURE_MOVE_TEST )  {
    
    Board       board;
    Bishop      piece = Bishop( WHITE, &board );
    Bishop      captured_piece = Bishop( WHITE, &board ); //same color

    board.SetPiece( 5, 5, &captured_piece);

    bool        ret   = piece.Check( 0, 0, 5, 5 );
    
    EXPECT_EQ ( ret, false );
}