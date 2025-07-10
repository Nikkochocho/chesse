/*
 * chesse
 * Copyright (C) 2025  Lara H. Ferreira.
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "pawn_tests.h"
#include "rook_tests.h"
#include "knight_tests.h"
#include "bishop_tests.h"
#include "queen_tests.h"
#include "king_tests.h"
#include "test_helper.h"


/**
 * Main entry point for tests.
 * @param argc Parameter arguments counter;
 * @param argv Parameter arguments vector;
 */
int main( int argc, char *argv[] ) {

    testing :: InitGoogleTest( &argc, argv );

    return RUN_ALL_TESTS();
}
