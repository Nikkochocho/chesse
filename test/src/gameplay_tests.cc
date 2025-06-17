#include "gameplay_tests.h"
#include "gameplay.h"
#include "player.h"
#include "board.h"
//#include "pawn.h"


TEST( chesse_tests, CHECK_TURN_DEFAULT ) {
    
    Board       board;
    GamePlay    game( &board );

    game.NewGame();

    bool        ret   = game.GetTurn() == PLAYER_1;

    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, CHECK_TURN_CHANGE ) {
    
    Board       board;
    GamePlay    game( &board );

    game.NewGame();
    game.Move( 'e', '2', 'e', '3' );

    bool        ret   = game.GetTurn() == PLAYER_2;

    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, CHECK_INVALID_TURN_CHANGE ) {
    
    Board       board;
    GamePlay    game( &board );

    game.NewGame();
    game.Move( 'e', '2', 'e', '1' );

    bool        ret   = game.GetTurn() == PLAYER_2;

    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, MOVE_PIECE_VALID_POSITION ) {
    
    Board       board;
    GamePlay    game( &board );

    game.NewGame();

    bool        ret   = game.Move( 'b', '1', 'a', '3' ); //moves knight as example

    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, MOVE_PIECE_INVALID_POSITION ) {
    
    Board       board;
    GamePlay    game( &board );

    game.NewGame();

    bool        ret   = game.Move( 'e', '8', 'e', '9' ); //invalid king trespass move

    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, MOVE_PIECE_VALID_POSITION_CHECK_MOVEMENT ) {
    
    Board       board;
    GamePlay    game( &board );

    game.NewGame();
    game.Move('a','2','a','3'); //moves pawn as example

    bool        ret   = ( board.GetPiece( 0, 2 ) -> GetMovementCount() == 1 );

    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, MOVE_PIECE_INVALID_POSITION_CHECK_MOVEMENT ) {
    
    Board       board;
    GamePlay    game( &board );

    game.NewGame();
    game.Move('a','8','a','9'); //invalid rook trespass move

    bool        ret   = ( board.GetPiece( 0, 7 ) -> GetMovementCount() == 1 );

    EXPECT_EQ ( ret, false );
}

// TEST( chesse_tests, CHECK_PROMOTION_TRUE ) {
    
//     Board       board;
//     GamePlay    game( &board );
//     Pawn        piece = Pawn( WHITE, &board );

//     board.SetPiece( 0, 6, &piece );
//     game.Move( 'a', '7', 'a', '8' );

//     bool        ret   = game.HasPromotion();

//     EXPECT_EQ ( ret, true );
// }

// TEST( chesse_tests, CHECK_PROMOTION_FALSE ) {
    
//     Board       board;
//     GamePlay    game( &board );
//     Pawn        piece = Pawn( WHITE, &board );

//     board.SetPiece( 0, 5, &piece );
//     game.Move( 'a', '6', 'a', '7' );

//     bool        ret   = game.HasPromotion();

//     EXPECT_EQ ( ret, false );
// }

// TEST( chesse_tests, CHECK_PROMOTED_QUEEN ) {
    
//     Board       board;
//     GamePlay    game( &board );
//     Pawn        piece = Pawn( WHITE, &board );

//     board.SetPiece( 0, 6, &piece );
//     game.Move( 'a', '7', 'a', '8' );
//     game.Promote( 'a', '8', 'Q');

//     bool        ret   = ( board.GetPiece( 0, 7 ) -> GetType() == QUEEN );

//     EXPECT_EQ ( ret, true );
// }

// TEST( chesse_tests, CHECK_PROMOTED_BISHOP ) {
    
//     Board       board;
//     GamePlay    game( &board );
//     Pawn        piece = Pawn( WHITE, &board );

//     board.SetPiece( 0, 6, &piece );
//     game.Move( 'a', '7', 'a', '8' );
//     game.Promote( 'a', '8', 'B');

//     bool        ret   = ( board.GetPiece( 0, 7 ) -> GetType() == BISHOP );

//     EXPECT_EQ ( ret, true );
// }

// TEST( chesse_tests, CHECK_PROMOTED_KNIGHT ) {
    
//     Board       board;
//     GamePlay    game( &board );
//     Pawn        piece = Pawn( WHITE, &board );

//     board.SetPiece( 0, 6, &piece );
//     game.Move( 'a', '7', 'a', '8' );
//     game.Promote( 'a', '8', 'N');

//     bool        ret   = ( board.GetPiece( 0, 7 ) -> GetType() == KNIGHT );

//     EXPECT_EQ ( ret, true );
// }

// TEST( chesse_tests, CHECK_PROMOTED_ROOK ) {
    
//     Board       board;
//     GamePlay    game( &board );
//     Pawn        piece = Pawn( WHITE, &board );

//     board.SetPiece( 0, 6, &piece );
//     game.Move( 'a', '7', 'a', '8' );
//     game.Promote( 'a', '8', 'R');

//     bool        ret   = ( board.GetPiece( 0, 7 ) -> GetType() == ROOK );

//     EXPECT_EQ ( ret, true );
// }

// TEST( chesse_tests, CHECK_PROMOTED_INVALID ) {
    
//     Board       board;
//     GamePlay    game( &board );
//     Pawn        piece = Pawn( WHITE, &board );

//     board.SetPiece( 0, 6, &piece );
//     game.Move( 'a', '7', 'a', '8' );

//     bool        ret   = game.Promote( 'a', '8', 'L');;

//     EXPECT_EQ ( ret, false );
// }