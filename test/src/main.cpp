#include "pawn_tests.h"
#include "rook_tests.h"
#include "knight_tests.h"
#include "bishop_tests.h"
#include "queen_tests.h"
#include "king_tests.h"
#include "gameplay_tests.h"


/**
 * Main entry point for tests.
 * @param argc Parameter arguments counter;
 * @param argv Parameter arguments vector;
 */
int main( int argc, char *argv[] ) {

    testing :: InitGoogleTest( &argc, argv );

    return RUN_ALL_TESTS();
}
