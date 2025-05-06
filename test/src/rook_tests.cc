#include "rook_tests.h"
#include "board.h"
#include "rook.h"


TEST( chesse_tests, ROOK_HORIZONTAL_MOVE_TEST )  {
    
    Board       board;
    Rook        piece = Rook( WHITE, &board );
    bool        ret   = piece.Check( 0, 0, 5, 0 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, ROOK_VERTICAL_MOVE_TEST )  {
    
    Board       board;
    Rook        piece = Rook( BLACK, &board );
    bool        ret   = piece.Check( 0, 0, 0, 5 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, ROOK_INVALID_MOVE_TEST )  {
    
    Board       board;
    Rook        piece = Rook( BLACK, &board );
    bool        ret   = piece.Check( 0, 0, 2, 2 );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, ROOK_INVALID_TRESPASS_HORIZONTAL_MOVE_TEST )  {
    
    Board       board;
    Rook        piece = Rook( BLACK, &board );
    Rook        block_piece = Rook( WHITE, &board );

    board.SetPiece( 2, 0, &block_piece);

    bool        ret   = piece.Check( 0, 0, 5, 0 );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, ROOK_INVALID_TRESPASS_VERTICAL_MOVE_TEST )  {
    
    Board       board;
    Rook        piece = Rook( BLACK, &board );
    Rook        block_piece = Rook( WHITE, &board );

    board.SetPiece( 0, 2, &block_piece);

    bool        ret   = piece.Check( 0, 0, 0, 5 );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, ROOK_CAPTURE_MOVE_TEST )  {
    
    Board       board;
    Rook        piece = Rook( WHITE, &board );
    Rook        block_piece = Rook( BLACK, &board );

    board.SetPiece( 2, 0, &block_piece);

    bool        ret   = piece.Check( 0, 0, 2, 0 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, ROOK_INVALID_CAPTURE_MOVE_TEST )  {
    
    Board       board;
    Rook        piece = Rook( WHITE, &board );
    Rook        block_piece = Rook( WHITE, &board ); //same color

    board.SetPiece( 0, 2, &block_piece);

    bool        ret   = piece.Check( 0, 0, 0, 2 );
    
    EXPECT_EQ ( ret, false );
}