#include "gameplay_tests.h"
#include "gameplay.h"
#include "player.h"
#include "board.h"
#include "pawn.h"
#include "test_helper.h"


TEST( chesse_tests, CHECK_TURN_DEFAULT ) {
    
    Board       board;
    GamePlay    game( &board );

    game.NewGame();

    bool        ret   = ( game.GetTurn() == PLAYER_1 );

    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, CHECK_TURN_CHANGE ) {
    
    Board       board;
    GamePlay    game( &board );

    game.NewGame();
    game.Move( 'e', '2', 'e', '3' );

    bool        ret   = ( game.GetTurn() == PLAYER_2 );

    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, CHECK_INVALID_TURN_CHANGE ) {
    
    Board       board;
    GamePlay    game( &board );

    game.NewGame();
    game.Move( 'e', '2', 'e', '1' );

    bool        ret   = ( game.GetTurn() == PLAYER_2 );

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

TEST( chesse_tests, CHECK_PROMOTION_TRUE ) {
    
    Board       board;
    GamePlay    game( &board );
    Pawn        piece = Pawn( WHITE, &board );

    game.NewGame();
    game.Move( 'd', '2', 'd', '4' );
    game.Move( 'e', '7', 'e', '5' );
    game.Move( 'd', '4', 'e', '5' );
    game.Move( 'f', '7', 'f', '5' );
    game.Move( 'e', '5', 'f', '6' );
    game.Move( 'd', '7', 'd', '5' );
    game.Move( 'f', '6', 'g', '7' );
    game.Move( 'g', '8', 'e', '7' );
    game.Move( 'g', '7', 'h', '8' );

    bool        ret   = game.HasPromotion();

    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, CHECK_PROMOTION_FALSE ) {
    
    Board       board;
    GamePlay    game( &board );
    Pawn        piece = Pawn( WHITE, &board );

    game.NewGame();

    bool        ret   = game.HasPromotion();

    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, CHECK_PROMOTED_QUEEN ) {
    
    Board       board;
    GamePlay    game( &board );
    Pawn        piece = Pawn( WHITE, &board );

    game.NewGame();
    PromotionMove( game );
    game.Promote('h','8', QUEEN );

    bool        ret   = ( board.GetPiece( 7, 7 ) -> GetType() == QUEEN );

    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, CHECK_PROMOTED_BISHOP ) {
    
    Board       board;
    GamePlay    game( &board );
    Pawn        piece = Pawn( WHITE, &board );

    game.NewGame();
    PromotionMove( game );
    game.Promote('h','8', BISHOP );

    bool        ret   = ( board.GetPiece( 7, 7 ) -> GetType() == BISHOP );

    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, CHECK_PROMOTED_KNIGHT ) {
    
    Board       board;
    GamePlay    game( &board );
    Pawn        piece = Pawn( WHITE, &board );

    game.NewGame();
    PromotionMove( game );
    game.Promote('h','8', KNIGHT );

    bool        ret   = ( board.GetPiece( 7, 7 ) -> GetType() == KNIGHT );

    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, CHECK_PROMOTED_ROOK ) {
    
    Board       board;
    GamePlay    game( &board );

    game.NewGame();
    PromotionMove( game );
    game.Promote('h','8', ROOK );

    bool        ret   = ( board.GetPiece( 7, 7 ) -> GetType() == ROOK );

    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, PAWN_BLOCK_CHECK ) {
    
    Board       board;
    GamePlay    game( &board );

    game.NewGame();
    CheckKing( game );
    game.Move( 'c', '2', 'c', '3' );

    bool        ret   = ( board.GetPiece( 4, 0 ) -> GetStatus() == CHECK );

    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, ROOK_BLOCK_CHECK ) {
    
    Board       board;
    GamePlay    game( &board );

    game.NewGame();
    game.Move( 'a', '2', 'a', '4' );
    game.Move( 'a', '7', 'a', '5' );
    game.Move( 'a', '1', 'a', '3' );
    game.Move( 'b', '7', 'b', '6' );
    CheckKing( game );
    game.Move( 'a', '3', 'c', '3' );

    bool        ret   = ( board.GetPiece( 4, 0 ) -> GetStatus() == CHECK );

    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, KNIGHT_BLOCK_CHECK ) {
    
    Board       board;
    GamePlay    game( &board );

    game.NewGame();
    CheckKing( game );
    game.Move( 'b', '1', 'c', '3' );

    bool        ret   = ( board.GetPiece( 4, 0 ) -> GetStatus() == CHECK );

    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, BISHOP_BLOCK_CHECK ) {
    
    Board       board;
    GamePlay    game( &board );

    game.NewGame();
    CheckKing( game );
    game.Move( 'c', '1', 'd', '2' );

    bool        ret   = ( board.GetPiece( 4, 0 ) -> GetStatus() == CHECK );

    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, QUEEN_BLOCK_CHECK ) {
    
    Board       board;
    GamePlay    game( &board );

    game.NewGame();
    CheckKing( game );
    game.Move( 'd', '1', 'd', '2' );

    bool        ret   = ( board.GetPiece( 4, 0 ) -> GetStatus() == CHECK );

    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, KING_MOVE_OUT_CHECK ) {
    
    Board       board;
    GamePlay    game( &board );

    game.NewGame();
    game.Move( 'e', '2', 'e', '3' );
    game.Move( 'a', '7', 'a', '5' );
    CheckKing( game );
    game.Move( 'e', '1', 'e', '2' );

    bool        ret   = ( board.GetPiece( 4, 1 ) -> GetStatus() == CHECK );

    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, KING_MOVE_INTO_CHECK ) {
    
    Board       board;
    GamePlay    game( &board );

    game.NewGame();
    game.Move( 'e', '2', 'e', '3' );
    game.Move( 'a', '7', 'a', '5' );
    game.Move( 'e', '1', 'e', '2' );
    game.Move( 'h', '7', 'h', '5' );
    CheckKing( game );

    bool        ret   = game.Move( 'e', '2', 'e', '1' );

    EXPECT_EQ ( ret, false );
}