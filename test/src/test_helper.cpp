#include "test_helper.h"


void LongCastleMove( GamePlay& game )  {

    game.Move( 'b', '1', 'c', '3' );
    game.Move( 'e', '7', 'e', '5' );
    game.Move( 'b', '2', 'b', '3' );
    game.Move( 'd', '7', 'd', '6' );
    game.Move( 'c', '1', 'b', '2' );
    game.Move( 'f', '7', 'f', '6' );
    game.Move( 'e', '2', 'e', '3' );
    game.Move( 'f', '8', 'e', '7' );
    game.Move( 'd', '1', 'e', '2' );
    game.Move( 'b', '7', 'b', '6' );
    game.Move( 'e', '1', 'c', '1' );
}

void ShortCastleMove( GamePlay& game )  {

    game.Move( 'b', '2', 'b', '3' );
    game.Move( 'g', '8', 'f', '6' );
    game.Move( 'c', '2', 'c', '4' );
    game.Move( 'g', '7', 'g', '6' );
    game.Move( 'd', '2', 'd', '3' );
    game.Move( 'f', '8', 'g', '7' );
    game.Move( 'e', '2', 'e', '4' );
    game.Move( 'e', '8', 'g', '8' );
}

void PromotionMove( GamePlay& game )  {

    game.Move( 'd', '2', 'd', '4' );
    game.Move( 'e', '7', 'e', '5' );
    game.Move( 'd', '4', 'e', '5' );
    game.Move( 'f', '7', 'f', '5' );
    game.Move( 'e', '5', 'f', '6' );
    game.Move( 'd', '7', 'd', '5' );
    game.Move( 'f', '6', 'g', '7' );
    game.Move( 'g', '8', 'e', '7' );
    game.Move( 'g', '7', 'h', '8' );
}

void CheckKing( GamePlay& game )  {

    game.Move( 'd', '2', 'd', '4' );
    game.Move( 'e', '7', 'e', '5' );
    game.Move( 'd', '4', 'e', '5' );
    game.Move( 'f', '8', 'b', '4' );
}