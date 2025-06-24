#include "rook_tests.h"
#include "board.h"
#include "rook.h"
#include "king.h"


TEST( chesse_tests, ROOK_HORIZONTAL_FORWARD_MOVE_TEST )  {
    
    Board       board;
    Rook        piece = Rook( WHITE, &board );

    board.SetPiece( 0, 0, &piece );

    bool        ret   = piece.CanMove( 5, 0 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, ROOK_HORIZONTAL_BACKWARD_MOVE_TEST )  {
    
    Board       board;
    Rook        piece = Rook( WHITE, &board );

    board.SetPiece( 5, 0, &piece );

    bool        ret   = piece.CanMove( 0, 0 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, ROOK_VERTICAL_FORWARD_MOVE_TEST )  {
    
    Board       board;
    Rook        piece = Rook( BLACK, &board );

    board.SetPiece( 0, 0, &piece );

    bool        ret   = piece.CanMove( 0, 5 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, ROOK_VERTICAL_BACKWARD_MOVE_TEST )  {
    
    Board       board;
    Rook        piece = Rook( BLACK, &board );

    board.SetPiece( 0, 5, &piece );

    bool        ret   = piece.CanMove( 0, 0 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, ROOK_INVALID_MOVE_TEST )  {
    
    Board       board;
    Rook        piece = Rook( BLACK, &board );

    board.SetPiece( 0, 0, &piece );

    bool        ret   = piece.CanMove( 2, 2 );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, ROOK_INVALID_TRESPASS_MOVE_TEST )  {
    
    Board       board;
    Rook        piece = Rook( BLACK, &board );
    Rook        block_piece = Rook( WHITE, &board );

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 2, 0, &block_piece );

    bool        ret   = piece.CanMove( 5, 0 );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, ROOK_CAPTURE_MOVE_TEST )  {
    
    Board       board;
    Rook        piece = Rook( WHITE, &board );
    Rook        captured_piece = Rook( BLACK, &board );

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 2, 0, &captured_piece );

    bool        ret   = piece.CanMove( 2, 0 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, ROOK_INVALID_CAPTURE_MOVE_TEST )  {
    
    Board       board;
    Rook        piece = Rook( WHITE, &board );
    Rook        captured_piece = Rook( WHITE, &board ); //same color

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 0, 2, &captured_piece );

    bool        ret   = piece.CanMove( 0, 2 );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, CAPTURED_ROOK_STATUS_CHECK ) {

    Board       board;
    Rook        piece = Rook( WHITE, &board );
    Rook        captured_piece = Rook( BLACK, &board );

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 0, 1, &captured_piece );
    piece.CanMove( 0, 1 );

    bool        ret   = ( captured_piece.GetStatus() == CAPTURED ) ;

    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, INVALID_CAPTURED_ROOK_STATUS_CHECK ) {

    Board       board;
    Rook        piece = Rook( WHITE, &board );
    Rook        captured_piece = Rook( WHITE, &board ); //same color

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 0, 1, &captured_piece );
    piece.CanMove( 0, 1 );

    bool        ret   = ( captured_piece.GetStatus() == CAPTURED ) ;

    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, ROOK_HORIZONTAL_CHECK_KING ) {
    
    Board       board;
    Rook        piece = Rook( WHITE, &board );
    King        king = King( BLACK, &board );

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 2, 0, &king );

    bool        ret   = ( piece.KingCheck() && ( king.GetStatus() == CHECK ) );

    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, ROOK_VERTICAL_CHECK_KING ) {
    
    Board       board;
    Rook        piece = Rook( WHITE, &board );
    King        king = King( BLACK, &board );

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 0, 2, &king );

    bool        ret   = ( piece.KingCheck() && ( king.GetStatus() == CHECK ) );

    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, INVALID_ROOK_CHECK_KING ) {
    
    Board       board;
    Rook        piece = Rook( WHITE, &board );
    King        king = King( WHITE, &board ); //same color

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 2, 0, &king );

    bool        ret   = ( piece.KingCheck() && ( king.GetStatus() == CHECK ) );

    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, FAILED_ROOK_CHECK_KING ) {
    
    Board       board;
    Rook        piece = Rook( BLACK, &board );
    Rook        block_piece = Rook( WHITE, &board );
    King        king = King( WHITE, &board ); //same color

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 1, 0, &block_piece );
    board.SetPiece( 2, 0, &king );

    bool        ret   = ( piece.KingCheck() && ( king.GetStatus() == CHECK ) );

    EXPECT_EQ ( ret, false );
}