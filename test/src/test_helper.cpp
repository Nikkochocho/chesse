#include "test_helper.h"


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