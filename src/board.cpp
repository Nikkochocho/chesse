#include <iostream>
#include "board.h"


CheckBoard :: CheckBoard( void )  {

    ClearBoard();
}

CheckBoard :: ~CheckBoard( void )  {
    
}

int CheckBoard :: GetColIndex(char ch)  {

    return ch - 'a';
}

int CheckBoard :: GetRowIndex(char ch)  {

    return ch - '0' - 1;
}

void CheckBoard :: ClearBoard( void )  {

    for( int row = 0; row < board.size(); row++ )   {
        for( int col = 0; col < board[row].size(); col++ )  {
            board[row][col] = nullptr;
        }
    }
}

void CheckBoard :: Put(char row, char col, Piece* piece)  {

    int  c = GetColIndex(col);
    int  r = GetRowIndex(row);

    board[r][c] = piece;
}

bool CheckBoard :: Move(char src_row, char src_col, char dst_row, char dst_col )  {

    // TODO: Checar limites do board 
    // TODO: Checar se origem é o mesmo que destino
    int  src_c = GetColIndex(src_col);
    int  src_r = GetRowIndex(src_row);
    int  dst_c = GetColIndex(dst_col);
    int  dst_r = GetRowIndex(dst_row);

    if( src_c > 0 && src_c < MAX_COLS ) {
        
        Piece *piece = board[src_r][src_c];

        if ( ( piece != nullptr ) && piece -> Check( src_r, src_c, dst_r, dst_c ))  {
            //TODO: mover

            return true;
        }
    }

    return false;
}

void CheckBoard :: Print( void )  {

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