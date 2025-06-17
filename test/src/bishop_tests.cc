#include "bishop_tests.h"
#include "board.h"
#include "bishop.h"


TEST( chesse_tests, BISHOP_PRIMARY_DIAGONAL_FORWARD_MOVE_TEST )  {
    
    Board       board;
    Bishop      piece = Bishop( WHITE, &board );

    board.SetPiece( 4, 4, &piece );

    bool        ret   = piece.Check( 7, 7 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, BISHOP_PRIMARY_DIAGONAL_BACKWARD_MOVE_TEST )  {
    
    Board       board;
    Bishop      piece = Bishop( BLACK, &board );

    board.SetPiece( 7, 7, &piece );

    bool        ret   = piece.Check( 4, 4 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, BISHOP_SECONDARY_DIAGONAL_FORWARD_MOVE_TEST )  {
    
    Board       board;
    Bishop      piece = Bishop( WHITE, &board );

    board.SetPiece( 4, 4, &piece );

    bool        ret   = piece.Check( 1, 7 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, BISHOP_SECONDARY_DIAGONAL_BACKWARD_MOVE_TEST )  {
    
    Board       board;
    Bishop      piece = Bishop( BLACK, &board );

    board.SetPiece( 4, 4, &piece );

    bool        ret   = piece.Check( 7, 1 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, BISHOP_INVALID_MOVE_TEST )  {
    
    Board       board;
    Bishop      piece = Bishop( WHITE, &board );

    board.SetPiece( 4, 4, &piece );

    bool        ret   = piece.Check( 4, 5 );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, BISHOP_INVALID_TRESPASS_MOVE_TEST )  {
    
    Board       board;
    Bishop      piece = Bishop( BLACK, &board );
    Bishop      block_piece = Bishop( WHITE, &board );

    board.SetPiece( 4, 4, &piece );
    board.SetPiece( 5, 5, &block_piece );

    bool        ret   = piece.Check( 7, 7 );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, BISHOP_CAPTURE_MOVE_TEST )  {
    
    Board       board;
    Bishop      piece = Bishop( BLACK, &board );
    Bishop      captured_piece = Bishop( WHITE, &board );

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 5, 5, &captured_piece );

    bool        ret   = piece.Check( 5, 5 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, BISHOP_INVALID_CAPTURE_MOVE_TEST )  {
    
    Board       board;
    Bishop      piece = Bishop( WHITE, &board );
    Bishop      captured_piece = Bishop( WHITE, &board ); //same color

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 5, 5, &captured_piece );

    bool        ret   = piece.Check( 5, 5 );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, CAPTURED_BISHOP_STATUS_CHECK ) {

    Board       board;
    Bishop      piece = Bishop( WHITE, &board );
    Bishop      captured_piece = Bishop( BLACK, &board );

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 1, 1, &captured_piece );
    piece.Check( 1, 1 );

    bool        ret   = ( captured_piece.GetStatus() == CAPTURED ) ;

    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, INVALID_CAPTURED_BISHOP_STATUS_CHECK ) {

    Board       board;
    Bishop      piece = Bishop( WHITE, &board );
    Bishop      captured_piece = Bishop( WHITE, &board ); //same color

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 1, 1, &captured_piece );
    piece.Check( 1, 1 );

    bool        ret   = ( captured_piece.GetStatus() == CAPTURED ) ;

    EXPECT_EQ ( ret, false );
}