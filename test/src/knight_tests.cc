#include "knight_tests.h"
#include "board.h"
#include "knight.h"


TEST( chesse_tests, KNIGHT_ALL_VALID_MOVES_TEST )  {
    
    Board         board;
    Knight        piece = Knight( WHITE, &board );
    const int     x[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    const int     y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    int           Xknight, Yknight;
    bool          ret;

    Xknight = Yknight = 4;

    for ( int i = 0; i < 8; i++ ) {

        ret = piece.Check( Xknight, Yknight, ( Xknight + x[i] ), ( Yknight + y[i] ) );

        if ( !ret )
            break;
    }
    
    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, KNIGHT_INVALID_MOVE_TEST )  {

    Board         board;
    Knight        piece = Knight( WHITE, &board );

    bool          ret = piece.Check( 0, 0, 0, 1 );


    EXPECT_EQ ( ret, false );
}

TEST( chesse_tests, KNIGHT_JUMP_OVER_MOVE_TEST )  {

    Board         board;
    Knight        piece = Knight( BLACK, &board );
    Knight        enemy_piece = Knight( WHITE, &board );
    Knight        friendly_piece = Knight( BLACK, &board );

    board.SetPiece( 0, 1, &friendly_piece );
    board.SetPiece( 0, 2, &enemy_piece );
    //should be able to jump over both

    bool          ret = piece.Check( 0, 0, 1, 2 );


    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, KNIGHT_CAPTURE_MOVE_TEST )  {

    Board         board;
    Knight        piece = Knight( BLACK, &board );
    Knight        captured_piece = Knight( WHITE, &board );

    board.SetPiece( 1, 2, &captured_piece );

    bool          ret = piece.Check( 0, 0, 1, 2 );


    EXPECT_EQ ( ret, true );
}

TEST( chesse_tests, KNIGHT_INVALID_CAPTURE_MOVE_TEST )  {

    Board         board;
    Knight        piece = Knight( WHITE, &board );
    Knight        captured_piece = Knight( WHITE, &board ); //same color

    board.SetPiece( 1, 2, &captured_piece );

    bool          ret = piece.Check( 0, 0, 1, 2 );


    EXPECT_EQ ( ret, false );
}