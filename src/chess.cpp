#include <iostream>
#include "board.h"
#include "knight.h"
#include "pawn.h"
#include "rook.h"
#include "bishop.h"


int main( int argc, char **argv ) {
    
    CheckBoard    board;
    Pawn*         p1 = new Pawn(Color :: WHITE, &board);
    Pawn*         p2 = new Pawn(Color :: WHITE, &board);
    Pawn*         p3 = new Pawn(Color :: WHITE, &board);
    Knight*       k1 = new Knight(Color :: WHITE, &board);
    Rook*         r1 = new Rook(Color :: BLACK, &board);
    Bishop*       b1 = new Bishop(Color :: BLACK, &board);

    board.Put('7', 'a', p1);
    board.Put('7', 'd', p2);
    board.Put('7', 'g', p3);
    board.Put('7', 'b', k1);
    board.Put('5', 'b', r1);
    board.Put('2', 'b', b1);


    board.Print();
    std :: cout << std :: endl;

    board.Move('7', 'd', '6', 'd');
    board.Move('5', 'b', '5', 'e');
    board.Move('7', 'b', '5', 'c');
    board.Move('7', 'a', '5', 'a');
    board.Move('2', 'b', '3', 'c');

    board.Print();
    std :: cout << std :: endl;

    board.Move('6', 'd', '5', 'e');
    board.Move('5', 'a', '4', 'a');
    board.Move('5', 'c', '6', 'e');
    board.Move('3', 'c', '4', 'b');
    board.Print();

    delete p1;
    delete p2;
    delete p3;
    delete k1;
    delete r1;
    delete b1;

    return 0;
}