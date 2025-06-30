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
        
    } while ( !game.IsCheckmate() );

    game.Print();
    std :: cout << "CHECKMATE"<< std :: endl;

    return 0;
}