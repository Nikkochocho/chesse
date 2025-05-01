#include <iostream>
#include "board.h"


int main( int argc, char **argv ) {

    CheckBoard    board;

    board.NewBoard();

    do  {
    
    board.Print();
    std :: cout << std :: endl;
    
    char src_input[2];
    char dst_input[2];

    std :: cin >> src_input;
    std :: cin >> dst_input;

    char src_r = src_input[0];
    char src_c = src_input[1];
    char dst_r = dst_input[0];
    char dst_c = dst_input[1];

    board.Move( src_r , src_c, dst_r, dst_c );
    continue;
    
    } while ( !board.IsCheckmate() );


    return 0;
}