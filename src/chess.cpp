#include <iostream>
#include "board.h"
#include "knight.h"
#include "pawn.h"
#include "rook.h"


int main( int argc, char **argv ) {
    
    // std :: string Nf; //horsey pos
    // std :: string pawn;
    // std :: string Nf_pos[8];
    // int board_virtual[8][8];
    // int Nfrow, pawnrow[8];
    // char Nfcol, pawncol[8];
    CheckBoard    board;
    Pawn*         p1 = new Pawn(Color :: WHITE);
    Pawn*         p2 = new Pawn(Color :: WHITE);
    Pawn*         p3 = new Pawn(Color :: WHITE);
    Knight*       k1 = new Knight(Color :: WHITE);
    Rook*         r1 = new Rook(Color :: WHITE);

    board.put_board('7', 'a', p1);
    board.put_board('7', 'd', p2);
    board.put_board('7', 'g', p3);
    board.put_board('7', 'b', k1);
    board.put_board('5', 'c', r1);


    board.print_board();

    board.move('5', 'c', '5', 'd');

    delete p1;
    delete p2;
    delete p3;
    delete k1;
    delete r1;

    // do {
    //     std :: cin >> Nf;

    //     if (Nf == "0") break;
    //     // Nfrow = get_row_index(Nf[0]);
    //     // Nfcol = get_col_index(Nf[1]);

    //     for (int i = 0; i < 8; i++){
    //         std :: cin >> pawn;
    //         pawnrow[i] = pawn[0];
    //         pawncol[i] = pawn[1];
    //     }
    // }
    // while (Nf != "0");
    return 0;
}