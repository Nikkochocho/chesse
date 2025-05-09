#include "gameplay_tests.h"
#include "gameplay.h"
#include "board.h"
#include "pawn.h"


TEST( chesse_tests, MOVE_PIECE_VALID_POSITION ) {
    
    Board       board;
    GamePlay    game( &board );
    Pawn        piece = Pawn( WHITE, &board );

    board.SetPiece( 0, 6, &piece );

    bool        ret   = game.Move( 'a', '7', 'a', '8' );

    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, MOVE_PIECE_INVALID_POSITION ) {
    
    Board       board;
    GamePlay    game( &board );
    Pawn        piece = Pawn( WHITE, &board );

    board.SetPiece( 0, 7, &piece );

    bool        ret   = game.Move( 'a', '8', 'a', '9' );

    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, MOVE_PIECE_VALID_POSITION_CHECK_MOVEMENT ) {
    
    Board       board;
    GamePlay    game( &board );
    Pawn        piece = Pawn( WHITE, &board );

    board.SetPiece( 0, 6, &piece );
    game.Move( 'a', '7', 'a', '8' );

    bool        ret   = ( piece.GetMovementCount() == 1 );

    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, MOVE_PIECE_INVALID_POSITION_CHECK_MOVEMENT ) {
    
    Board       board;
    GamePlay    game( &board );
    Pawn        piece = Pawn( WHITE, &board );

    board.SetPiece( 0, 7, &piece );
    game.Move( 'a', '8', 'a', '9' );

    bool        ret   = ( piece.GetMovementCount() == 1 );

    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, CHECK_PROMOTION_TRUE ) {
    
    Board       board;
    GamePlay    game( &board );
    Pawn        piece = Pawn( WHITE, &board );

    board.SetPiece( 0, 6, &piece );
    game.Move( 'a', '7', 'a', '8' );

    bool        ret   = game.HasPromotion();

    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, CHECK_PROMOTION_FALSE ) {
    
    Board       board;
    GamePlay    game( &board );
    Pawn        piece = Pawn( WHITE, &board );

    board.SetPiece( 0, 5, &piece );
    game.Move( 'a', '6', 'a', '7' );

    bool        ret   = game.HasPromotion();

    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, CHECK_PROMOTED_QUEEN ) {
    
    Board       board;
    GamePlay    game( &board );
    Pawn        piece = Pawn( WHITE, &board );

    board.SetPiece( 0, 6, &piece );
    game.Move( 'a', '7', 'a', '8' );
    game.Promote( 'a', '8', 'Q');

    bool        ret   = ( board.GetPiece( 0, 7 ) -> GetType() == QUEEN );

    EXPECT_EQ ( ret, true );
}