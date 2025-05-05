#include "pawn_tests.h"
#include "board.h"
#include "pawn.h"


//WHITE PAWN TESTS

TEST( chesse_tests, WHITE_PAWN_ONE_STEP_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );
    bool        ret   = piece.Check( 0, 0, 1, 0 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, WHITE_PAWN_TWO_STEPS_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );
    bool        ret   = piece.Check( 0, 0, 2, 0 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, WHITE_PAWN_FAILED_TWO_STEPS_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );

    piece.Movement(); //sets movement to 1;

    bool        ret   = piece.Check( 0, 0, 2, 0 );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, WHITE_PAWN_CAPTURE_RIGHT_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );
    Pawn        captured_piece = Pawn( BLACK, &board );

    board.SetPiece( 0, 0, &piece);
    board.SetPiece( 1, 1, &captured_piece);

    bool        ret   = piece.Check( 0, 0, 1, 1 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, WHITE_PAWN_CAPTURE_LEFT_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );
    Pawn        captured_piece = Pawn( BLACK, &board );

    board.SetPiece( 0, 1, &piece);
    board.SetPiece( 1, 0, &captured_piece);

    bool        ret   = piece.Check( 0, 1, 1, 0 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, WHITE_PAWN_FAILED_CAPTURE_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );
    Pawn        captured_piece = Pawn( WHITE, &board ); //same color

    board.SetPiece( 0, 0, &piece);
    board.SetPiece( 1, 1, &captured_piece);

    bool        ret   = piece.Check( 0, 0, 1, 1 );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, WHITE_PAWN_INVALID_CAPTURE_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );
    Pawn        captured_piece = Pawn( BLACK, &board );

    board.SetPiece( 0, 0, &piece);
    board.SetPiece( 0, 1, &captured_piece);

    bool        ret   = piece.Check( 0, 0, 0, 1 );
    
    EXPECT_EQ ( ret, false );
}
 
TEST( chesse_tests, WHITE_PAWN_INVALID_MOVE ) {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );

    bool        ret   = piece.Check( 1, 0, 0, 0 );

    EXPECT_EQ ( ret, false );
}

//BLACK PAWN TESTS

TEST( chesse_tests, BLACK_PAWN_ONE_STEP_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( BLACK, &board );
    bool        ret   = piece.Check( 7, 0, 6, 0 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, BLACK_PAWN_TWO_STEPS_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( BLACK, &board );
    bool        ret   = piece.Check( 7, 0, 5, 0 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, BLACK_PAWN_FAILED_TWO_STEPS_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( BLACK, &board );

    piece.Movement(); //sets movement to 1;

    bool        ret   = piece.Check( 7, 0, 5, 0 );
    
    EXPECT_EQ ( ret, false );
}

//SPECIAL MOVES

TEST( chesse_tests, PAWN_EN_PASSANT_CAPTURE_RIGHT_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );
    Pawn        captured_piece = Pawn( BLACK, &board );

    board.SetPiece( 4, 0, &piece);
    board.SetPiece( 4, 1, &captured_piece);
    captured_piece.Movement();

    bool        ret   = piece.Check( 4, 0, 4, 1 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, PAWN_EN_PASSANT_CAPTURE_LEFT_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( BLACK, &board );
    Pawn        captured_piece = Pawn( WHITE, &board );

    board.SetPiece( 3, 1, &piece);
    board.SetPiece( 3, 0, &captured_piece);
    captured_piece.Movement();

    bool        ret   = piece.Check( 3, 1, 3, 0 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, PAWN_QUEEN_PROMOTION_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );
    bool        ret   = piece.Check( 0, 0, 1, 0 );
    
    EXPECT_EQ ( ret, true );
}