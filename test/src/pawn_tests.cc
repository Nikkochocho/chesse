#include "pawn_tests.h"
#include "board.h"
#include "pawn.h"
#include "king.h"


//GENERAL TESTS
TEST( chesse_tests, PAWN_INVALID_ROW_MOVE ) {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );

    board.SetPiece( 0, 1, &piece );

    bool        ret   = piece.CanMove( 0, 0 );

    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, PAWN_INVALID_COLUMN_MOVE ) {
    
    Board       board;
    Pawn        piece = Pawn( BLACK, &board );

    board.SetPiece( 0, 0, &piece );

    bool        ret   = piece.CanMove( 1, 0 );

    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, PAWN_INVALID_TRESPASS_MOVE ) {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );
    Pawn        block_piece = Pawn( BLACK, &board );

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 0, 1, &block_piece);

    bool        ret   = piece.CanMove( 0, 1 );

    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, PAWN_INVALID_DOUBLE_TRESPASS_MOVE ) {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );
    Pawn        block_piece = Pawn( BLACK, &board );

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 0, 1, &block_piece);

    bool        ret   = piece.CanMove( 0, 2 );

    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, CAPTURED_PAWN_STATUS_CHECK ) {

    Board       board;
    Pawn        piece = Pawn( WHITE, &board );
    Pawn        captured_piece = Pawn( BLACK, &board );

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 1, 1, &captured_piece );
    piece.CanMove( 1, 1 );

    bool        ret   = ( captured_piece.GetStatus() == CAPTURED ) ;

    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, INVALID_CAPTURED_PAWN_STATUS_CHECK ) {

    Board       board;
    Pawn        piece = Pawn( WHITE, &board );
    Pawn        captured_piece = Pawn( WHITE, &board ); //same color

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 1, 1, &captured_piece );
    piece.CanMove( 1, 1 );

    bool        ret   = ( captured_piece.GetStatus() == CAPTURED ) ;

    EXPECT_EQ ( ret, false );
}

//WHITE PAWN TESTS
TEST( chesse_tests, WHITE_PAWN_ONE_STEP_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );

    board.SetPiece( 0, 0, &piece );

    bool        ret   = piece.CanMove( 0, 1 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, WHITE_PAWN_TWO_STEPS_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );

    board.SetPiece( 0, 0, &piece );

    bool        ret   = piece.CanMove( 0, 2 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, WHITE_PAWN_FAILED_TWO_STEPS_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );

    board.SetPiece( 0, 0, &piece );

    piece.SetMovementCount(); //sets movement to 1;

    bool        ret   = piece.CanMove( 0, 2 );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, WHITE_PAWN_CAPTURE_RIGHT_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );
    Pawn        captured_piece = Pawn( BLACK, &board );

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 1, 1, &captured_piece);

    bool        ret   = piece.CanMove( 1, 1 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, WHITE_PAWN_CAPTURE_LEFT_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );
    Pawn        captured_piece = Pawn( BLACK, &board );

    board.SetPiece( 1, 0, &piece );
    board.SetPiece( 0, 1, &captured_piece);

    bool        ret   = piece.CanMove( 0, 1 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, WHITE_PAWN_INVALID_CAPTURE_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );
    Pawn        captured_piece = Pawn( WHITE, &board ); //same color

    board.SetPiece( 0, 0, &piece );
    board.SetPiece( 1, 1, &captured_piece);

    bool        ret   = piece.CanMove( 1, 1 );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, WHITE_PAWN_FAILED_CAPTURE_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );

    board.SetPiece( 1, 0, &piece );

    bool        ret   = piece.CanMove( 0, 1 );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, WHITE_PAWN_PROMOTION_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );

    board.SetPiece( 0, 6, &piece );
    piece.CanMove( 0, 7 );

    bool        ret   = ( piece.GetStatus() == PROMOTION );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, WHITE_PAWN_CHECK_KING_RIGHT ) {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );
    King        king = King( BLACK, &board ); //same color

    board.SetPiece( 1, 0, &piece );
    board.SetPiece( 2, 1, &king );

    bool        ret   = ( piece.KingCheck() && ( king.GetStatus() == CHECK ) );

    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, WHITE_PAWN_CHECK_KING_LEFT ) {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );
    King        king = King( BLACK, &board ); //same color

    board.SetPiece( 1, 0, &piece );
    board.SetPiece( 0, 1, &king );

    bool        ret   = ( piece.KingCheck() && ( king.GetStatus() == CHECK ) );

    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, INVALID_WHITE_PAWN_CHECK_KING ) {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );
    King        king = King( WHITE, &board ); //same color

    board.SetPiece( 1, 0, &piece );
    board.SetPiece( 2, 1, &king );

    bool        ret   = ( piece.KingCheck() && ( king.GetStatus() == CHECK ) );

    EXPECT_EQ ( ret, false );
}

//BLACK PAWN TESTS
TEST( chesse_tests, BLACK_PAWN_ONE_STEP_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( BLACK, &board );

    board.SetPiece( 0, 7, &piece );

    bool        ret   = piece.CanMove( 0, 6 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, BLACK_PAWN_TWO_STEPS_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( BLACK, &board );

    board.SetPiece( 0, 7, &piece );

    bool        ret   = piece.CanMove( 0, 5 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, BLACK_PAWN_FAILED_TWO_STEPS_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( BLACK, &board );

    board.SetPiece( 0, 7, &piece );

    piece.SetMovementCount(); //sets movement to 1;

    bool        ret   = piece.CanMove( 0, 5 );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, BLACK_PAWN_CAPTURE_RIGHT_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( BLACK, &board );
    Pawn        captured_piece = Pawn( WHITE, &board );

    board.SetPiece( 1, 1, &piece );
    board.SetPiece( 0, 0, &captured_piece );

    bool        ret   = piece.CanMove( 0, 0 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, BLACK_PAWN_CAPTURE_LEFT_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( BLACK, &board );
    Pawn        captured_piece = Pawn( WHITE, &board );

    board.SetPiece( 0, 1, &piece );
    board.SetPiece( 1, 0, &captured_piece );

    bool        ret   = piece.CanMove( 1, 0 );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, BLACK_PAWN_INVALID_CAPTURE_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( BLACK, &board );
    Pawn        captured_piece = Pawn( BLACK, &board ); //same color

    board.SetPiece( 1, 1, &piece );
    board.SetPiece( 0, 0, &captured_piece );

    bool        ret   = piece.CanMove( 0, 0 );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, BLACK_PAWN_FAILED_CAPTURE_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( BLACK, &board );

    board.SetPiece( 0, 1, &piece );

    bool        ret   = piece.CanMove( 1, 0 );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, BLACK_PAWN_PROMOTION_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( BLACK, &board );

    board.SetPiece( 0, 1, &piece );
    piece.CanMove( 0, 0 );

    bool        ret   = ( piece.GetStatus() == PROMOTION );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, BLACK_PAWN_CHECK_KING_RIGHT ) {
    
    Board       board;
    Pawn        piece = Pawn( BLACK, &board );
    King        king = King( WHITE, &board ); 

    board.SetPiece( 1, 1, &piece );
    board.SetPiece( 0, 0, &king );

    bool        ret   = ( piece.KingCheck() && ( king.GetStatus() == CHECK ) );

    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, BLACK_PAWN_CHECK_KING_LEFT ) {
    
    Board       board;
    Pawn        piece = Pawn( BLACK, &board );
    King        king = King( WHITE, &board ); 

    board.SetPiece( 1, 1, &piece );
    board.SetPiece( 2, 0, &king );

    bool        ret   = ( piece.KingCheck() && ( king.GetStatus() == CHECK ) );

    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, INVALID_BLACK_PAWN_CHECK_KING ) {
    
    Board       board;
    Pawn        piece = Pawn( BLACK, &board );
    King        king = King( BLACK, &board ); 

    board.SetPiece( 1, 1, &piece );
    board.SetPiece( 0, 0, &king );

    bool        ret   = ( piece.KingCheck() && ( king.GetStatus() == CHECK ) );

    EXPECT_EQ ( ret, false );
}

//SPECIAL MOVES
TEST( chesse_tests, PAWN_EN_PASSANT_CAPTURE_RIGHT_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );
    Pawn        captured_piece = Pawn( BLACK, &board );

    board.SetPiece( 0, 4, &piece );
    board.SetPiece( 1, 4, &captured_piece );
    captured_piece.SetMovementCount();

    piece.CanMove( 1, 5 );

    bool        ret   = ( piece.GetStatus() == ENPASSANT );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, PAWN_EN_PASSANT_CAPTURE_LEFT_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( BLACK, &board );
    Pawn        captured_piece = Pawn( WHITE, &board );

    board.SetPiece( 1, 3, &piece );
    board.SetPiece( 0, 3, &captured_piece );
    captured_piece.SetMovementCount();

    piece.CanMove( 0, 2 );

    bool        ret   = ( piece.GetStatus() == ENPASSANT );
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, PAWN_INVALID_EN_PASSANT_ROW_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( WHITE, &board );
    Pawn        captured_piece = Pawn( BLACK, &board );

    board.SetPiece( 1, 5, &piece );
    board.SetPiece( 0, 5, &captured_piece );
    captured_piece.SetMovementCount();

    piece.CanMove( 0, 6 );

    bool        ret   = ( piece.GetStatus() == ENPASSANT );
    
    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, PAWN_FAILED_EN_PASSANT_CAPTURE_MOVE_TEST )  {
    
    Board       board;
    Pawn        piece = Pawn( BLACK, &board );
    Pawn        captured_piece = Pawn( WHITE, &board );

    board.SetPiece( 1, 3, &piece );
    board.SetPiece( 0, 3, &captured_piece );
    //m_moviment = 0;

    piece.CanMove( 0, 2 );

    bool        ret   = ( piece.GetStatus() == ENPASSANT );
    
    EXPECT_EQ ( ret, false );
}