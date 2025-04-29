#include <iostream>
#include "board.h"


CheckBoard :: CheckBoard( void )  {

    clear_board();
}

CheckBoard :: ~CheckBoard( void )  {
    
}

int CheckBoard :: get_col_index(char ch)  {

    return ch - 'a';
}

int CheckBoard :: get_row_index(char ch)  {

    return ch - '0' - 1;
}

void CheckBoard :: clear_board( void )  {

    for( int row = 0; row < board.size(); row++ )   {
        for( int col = 0; col < board[row].size(); col++ )  {
            board[row][col] = nullptr;
        }
    }
}

void CheckBoard :: put_board(char row, char col, Piece* piece)  {

    int  c = get_col_index(col);
    int  r = get_row_index(row);

    board[r][c] = piece;
}

void CheckBoard :: move(char src_row, char src_col, char dst_row, char dst_col )  {

    // TODO: Checar limites do board 
    // TODO: Checar se origem é o mesmo que destino
    int  src_c = get_col_index(src_col);
    int  src_r = get_row_index(src_row);
    int  dst_c = get_col_index(dst_col);
    int  dst_r = get_row_index(dst_row);


    Piece *piece = board[src_r][src_c];

    if (piece -> Check( src_r, src_c, dst_r, dst_c ))  {
        //TODO: mover
    }
}

void CheckBoard :: print_board( void )  {

    for(int cc = 0; cc < (MAX_COLS * 2) + 1; cc++)  {
        std :: cout << "-";
    }
    std :: cout << std ::endl;
    
    for(int row = (MAX_ROWS - 1); row >= 0; row--)  {

        std :: cout << "|";

        for(int col = 0; col < MAX_COLS; col++)  {

            if(board[row][col] != nullptr)  {
                board[row][col] -> Print();
            }
            else  {
                std :: cout << " ";    
            }

            std :: cout << "|";

            if(col == (MAX_COLS - 1))
                std :: cout << std ::endl;
        }

        for(int cc = 0; cc < (MAX_COLS * 2) + 1; cc++)  {
            std :: cout << "-";
        }

        std :: cout << std ::endl;
    }
}