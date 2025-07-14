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
    Pieces        piece_type;
    char          promotion;

    game.NewGame();

    do  {
    
        const char *color = ( game.GetTurn() == PLAYER_1 ) ? "WHITE" : "BLACK";
        game.Print();
        std :: cout << std :: endl;
        std :: cout << color << " TURN" << std :: endl;
        
        char src_input[2] = {0};
        char dst_input[2] = {0};

        do  {

            std :: cout << "Enter the piece's current coordinate:" << std :: endl;
            std :: cin >> src_input;
            std :: cout << "Enter the piece's desired coordinate:" << std :: endl;
            std :: cin >> dst_input;

        }  while ( !ValidInput( src_input ) && ( !ValidInput( dst_input ) ) );

        if ( game.Move( tolower( src_input[0] ), src_input[1], tolower( dst_input[0] ), dst_input[1] ) )  {

            if ( game.HasPromotion() )  {

                do  {

                    std :: cout << "Promote pawn to ( Q, B, N, R ):" << std :: endl;
                    std :: cin >> promotion;
                    piece_type = Conversion( promotion );

                }  while ( piece_type == UNSET );

                game.Promote( dst_input[0], dst_input[1], piece_type );
            }
        }
    }  while ( ( !game.IsCheckmate() ) && ( !game.IsStalemate() ) );

    game.Print();

    const char* res = ( game.IsCheckmate() ) ? "CHECKMATE" : "STALEMATE";

    std :: cout << res << std :: endl;

    return 0;
}