#include <iostream>
#include "gameplay.h"
#include "board.h"


int main( int argc, char **argv ) {

    Board       board;
    GamePlay    game( &board );
    int         turn = 0;
    char        promotion;

    game.NewGame();

    do  {
    
        const char* color = ( turn % 2 == 0 ) ? "white" : "black";
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
            
            turn++;

            if ( game.HasPromotion() )  {

                std :: cin >> promotion;

                while ( !game.Promote( dst_c, dst_r, promotion ) )
                    std :: cin >> promotion;
            }
        }
        
    } while ( !game.IsCheckmate() );


    return 0;
}