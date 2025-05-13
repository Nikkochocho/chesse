#include "pawn_tests.h"
#include "board.h"
#include "pawn.h"


//GENERAL TESTS
TEST( chesse_tests, PAWN_INVALID_ROW_MOVE ) {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );

    bool        ret   = piece.Check( 0, 1, 0, 0 );

    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, PAWN_INVALID_COLUMN_MOVE ) {
    
    Board       board;
    Pawn        piece = Pawn( BLACK, &board );

    bool        ret   = piece.Check( 0, 0, 1, 0 );

    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, PAWN_INVALID_TRESPASS_MOVE ) {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );
    Pawn        block_piece = Pawn( BLACK, &board );

    board.SetPiece( 0, 1, &block_piece);

    bool        ret   = piece.Check( 0, 0, 0, 1 );

    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, PAWN_INVALID_DOUBLE_TRESPASS_MOVE ) {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );
    Pawn        block_piece = Pawn( BLACK, &board );

    board.SetPiece( 0, 1, &block_piece);

    bool        ret   = piece.Check( 0, 0, 0, 2 );

    EXPECT_EQ ( ret, false );
}

//WHITE PAWN TESTS
TEST( chesse_tests, WHITE_PAWN_ONE_STEP_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );
    bool        ret   = piece.Check( 0, 0, 0, 1 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, WHITE_PAWN_TWO_STEPS_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );
    bool        ret   = piece.Check( 0, 0, 0, 2 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, WHITE_PAWN_FAILED_TWO_STEPS_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );

    piece.Movement(); //sets movement to 1;

    bool        ret   = piece.Check( 0, 0, 0, 2 );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, WHITE_PAWN_CAPTURE_RIGHT_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );
    Pawn        captured_piece = Pawn( BLACK, &board );

    board.SetPiece( 1, 1, &captured_piece);

    bool        ret   = piece.Check( 0, 0, 1, 1 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, WHITE_PAWN_CAPTURE_LEFT_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );
    Pawn        captured_piece = Pawn( BLACK, &board );

    board.SetPiece( 0, 1, &captured_piece);

    bool        ret   = piece.Check( 1, 0, 0, 1 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, WHITE_PAWN_INVALID_CAPTURE_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );
    Pawn        captured_piece = Pawn( WHITE, &board ); //same color

    board.SetPiece( 1, 1, &captured_piece);

    bool        ret   = piece.Check( 0, 0, 1, 1 );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, WHITE_PAWN_FAILED_CAPTURE_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );
    bool        ret   = piece.Check( 1, 0, 0, 1 );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, WHITE_PAWN_PROMOTION_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );

    piece.Check( 0, 6, 0, 7 );

    bool        ret   = ( piece.GetStatus() == PROMOTION );
    
    EXPECT_EQ ( ret, true );
}

//BLACK PAWN TESTS
TEST( chesse_tests, BLACK_PAWN_ONE_STEP_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( BLACK, &board );
    bool        ret   = piece.Check( 0, 7, 0, 6 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, BLACK_PAWN_TWO_STEPS_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( BLACK, &board );
    bool        ret   = piece.Check( 0, 7, 0, 5 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, BLACK_PAWN_FAILED_TWO_STEPS_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( BLACK, &board );

    piece.Movement(); //sets movement to 1;

    bool        ret   = piece.Check( 0, 7, 0, 5 );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, BLACK_PAWN_CAPTURE_RIGHT_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( BLACK, &board );
    Pawn        captured_piece = Pawn( WHITE, &board );

    board.SetPiece( 0, 0, &captured_piece );

    bool        ret   = piece.Check( 1, 1, 0, 0 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, BLACK_PAWN_CAPTURE_LEFT_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( BLACK, &board );
    Pawn        captured_piece = Pawn( WHITE, &board );

    board.SetPiece( 1, 0, &captured_piece );

    bool        ret   = piece.Check( 0, 1, 1, 0 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, BLACK_PAWN_INVALID_CAPTURE_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( BLACK, &board );
    Pawn        captured_piece = Pawn( BLACK, &board ); //same color

    board.SetPiece( 0, 0, &captured_piece );

    bool        ret   = piece.Check( 1, 1, 0, 0 );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, BLACK_PAWN_FAILED_CAPTURE_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( BLACK, &board );

    bool        ret   = piece.Check( 0, 1, 1, 0 );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, BLACK_PAWN_PROMOTION_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( BLACK, &board );

    piece.Check( 0, 1, 0, 0 );

    bool        ret   = ( piece.GetStatus() == PROMOTION );
    
    EXPECT_EQ ( ret, true );
}

//SPECIAL MOVES
TEST( chesse_tests, PAWN_EN_PASSANT_CAPTURE_RIGHT_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );
    Pawn        captured_piece = Pawn( BLACK, &board );

    board.SetPiece( 1, 4, &captured_piece );
    captured_piece.Movement();

    piece.Check( 0, 4, 1, 5 );

    bool        ret   = ( piece.GetStatus() == ENPASSANT );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, PAWN_EN_PASSANT_CAPTURE_LEFT_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( BLACK, &board );
    Pawn        captured_piece = Pawn( WHITE, &board );

    board.SetPiece( 0, 3, &captured_piece );
    captured_piece.Movement();

    piece.Check( 1, 3, 0, 2 );

    bool        ret   = ( piece.GetStatus() == ENPASSANT );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, PAWN_INVALID_EN_PASSANT_ROW_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );
    Pawn        captured_piece = Pawn( BLACK, &board );

    board.SetPiece( 0, 5, &captured_piece );
    captured_piece.Movement();

    piece.Check( 1, 5, 0, 6 );

    bool        ret   = ( piece.GetStatus() == ENPASSANT );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, PAWN_FAILED_EN_PASSANT_CAPTURE_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( BLACK, &board );
    Pawn        captured_piece = Pawn( WHITE, &board );

    board.SetPiece( 0, 3, &captured_piece );
    //m_moviment = 0;

    piece.Check( 1, 3, 0, 2 );

    bool        ret   = ( piece.GetStatus() == ENPASSANT );
    
    EXPECT_EQ ( ret, false );
}