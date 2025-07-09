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

void PawnCheck( GamePlay& game )  {

    game.Move( 'd', '2', 'd', '4' );
    game.Move( 'e', '7', 'e', '5' );
    game.Move( 'd', '4', 'e', '5' );
    game.Move( 'f', '7', 'f', '6' );
    game.Move( 'e', '5', 'f', '6' );
    game.Move( 'a', '7', 'a', '6' );
    game.Move( 'f', '6', 'f', '7' );
}

void RookCheck( GamePlay& game )  {

    game.Move( 'd', '2', 'd', '4' );
    game.Move( 'e', '7', 'e', '5' );
    game.Move( 'd', '4', 'e', '5' );
    game.Move( 'f', '7', 'f', '6' );
    game.Move( 'a', '2', 'a', '4' );
    game.Move( 'f', '6', 'e', '5' );
    game.Move( 'a', '1', 'a', '3' );
    game.Move( 'a', '7', 'a', '6' );
    game.Move( 'a', '3', 'e', '3' );
    game.Move( 'e', '5', 'e', '4' );
    game.Move( 'e', '3', 'e', '4' );
}

void KnightCheck( GamePlay& game )  {

    game.Move( 'b', '1', 'c', '3' );
    game.Move( 'e', '7', 'e', '5' );
    game.Move( 'c', '3', 'e', '4' );
    game.Move( 'd', '7', 'd', '6' );
    game.Move( 'e', '4', 'f', '6' );
}

void BishopCheck( GamePlay& game )  {

    game.Move( 'd', '2', 'd', '4' );
    game.Move( 'e', '7', 'e', '5' );
    game.Move( 'd', '4', 'e', '5' );
    game.Move( 'f', '8', 'b', '4' );
}

void QueenCheck( GamePlay& game )  {

    game.Move( 'f', '2', 'f', '4' );
    game.Move( 'e', '7', 'e', '5' );
    game.Move( 'e', '2', 'e', '4' );
    game.Move( 'd', '8', 'h', '4' );
}

void Checkmate( GamePlay& game )  {

    game.Move( 'e', '2', 'e', '4' );
    game.Move( 'e', '7', 'e', '5' );
    game.Move( 'g', '1', 'f', '3' );
    game.Move( 'b', '8', 'c', '6' );
    game.Move( 'f', '1', 'c', '4' );
    game.Move( 'd', '7', 'd', '6' );
    game.Move( 'b', '1', 'c', '3' );
    game.Move( 'c', '8', 'g', '4' );
    game.Move( 'f', '3', 'e', '5' );
    game.Move( 'g', '4', 'd', '1' );
    game.Move( 'c', '4', 'f', '7' );
    game.Move( 'e', '8', 'e', '7' );
    game.Move( 'c', '3', 'd', '5' );
}

void Stalemate( GamePlay& game )  {

    game.Move( 'c', '2', 'c', '4' );
    game.Move( 'h', '7', 'h', '5' );
    game.Move( 'h', '2', 'h', '4' );
    game.Move( 'a', '7', 'a', '5' );
    game.Move( 'd', '1', 'a', '4' );
    game.Move( 'a', '8', 'a', '6' );
    game.Move( 'a', '4', 'a', '5' );
    game.Move( 'a', '6', 'h', '6' );
    game.Move( 'a', '5', 'c', '7' );
    game.Move( 'f', '7', 'f', '6' );
    game.Move( 'c', '7', 'd', '7' );
    game.Move( 'e', '8', 'f', '7' );
    game.Move( 'd', '7', 'b', '7' );
    game.Move( 'd', '8', 'd', '3' );
    game.Move( 'b', '7', 'b', '8' );
    game.Move( 'd', '3', 'h', '7' );
    game.Move( 'b', '8', 'c', '8' );
    game.Move( 'f', '7', 'g', '6' );
    game.Move( 'c', '8', 'e', '6' );
}