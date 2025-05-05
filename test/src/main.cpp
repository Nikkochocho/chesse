#include "pawn_tests.h"


/**
 * Main entry point for tests.
 * @param argc Parameter arguments counter;
 * @param argv Parameter arguments vector;
 */
int main( int argc, char *argv[] ) {

    testing :: InitGoogleTest( &argc, argv );

    return RUN_ALL_TESTS();
}
