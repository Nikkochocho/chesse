#include "queen_tests.h"
#include "board.h"
#include "queen.h"


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

TEST( chesse_tests, CAPTURED_QUEEN_STATUS_CHECK ) {

    Board       board;
    Queen       piece = Queen( WHITE, &board );
    Queen       captured_piece = Queen( BLACK, &board );

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 1, 1, &captured_piece );
    piece.CanMove( 1, 1 );

    bool        ret   = ( captured_piece.GetStatus() == CAPTURED ) ;

    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, INVALID_CAPTURED_QUEEN_STATUS_CHECK ) {

    Board       board;
    Queen       piece = Queen( WHITE, &board );
    Queen       captured_piece = Queen( WHITE, &board ); //same color

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 1, 1, &captured_piece );
    piece.CanMove( 1, 1 );

    bool        ret   = ( captured_piece.GetStatus() == CAPTURED ) ;

    EXPECT_EQ ( ret, false );
}