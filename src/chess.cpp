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

#include <iostream>
#include "gameplay.h"
#include "board.h"
#include "helper.h"


int main( int argc, char **argv ) {

    Board         board;
    GamePlay      game( &board );
    char          promotion;

    game.NewGame();

    do  {
    
        const char *color = ( game.GetTurn() == PLAYER_1 ) ? "white" : "black";
        game.Print();
        std :: cout << std :: endl;
        std :: cout << color << " turn:" << std :: endl;
        
        char src_input[2];
        char dst_input[2];

        std :: cin >> src_input;
        std :: cin >> dst_input;

        char src_c = src_input[0];
        char src_r = src_input[1];
        char dst_c = dst_input[0];
        char dst_r = dst_input[1];

        if ( game.Move( src_c , src_r, dst_c, dst_r ) )  {

            if ( game.HasPromotion() )  {

                std :: cin >> promotion;

                Pieces piece_type = Conversion( promotion );

                while ( piece_type == UNSET )  {

                    std :: cin >> promotion;
                    piece_type = Conversion( promotion );
                }

                game.Promote( dst_c, dst_r, piece_type );
            }
        }
        
    } while ( ( !game.IsCheckmate() ) && ( !game.IsStalemate() ) );

    game.Print();

    const char* res = ( game.IsCheckmate() ) ? "CHECKMATE" : "STALEMATE";

    std :: cout << res << std :: endl;

    return 0;
}