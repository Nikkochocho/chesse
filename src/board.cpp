#include <iostream>
#include "board.h"


CheckBoard :: CheckBoard( void )  {

    ClearBoard();
}

CheckBoard :: ~CheckBoard( void )  {
    
}

int CheckBoard :: GetColIndex( char ch )  {

    return ch - 'a';
}

int CheckBoard :: GetRowIndex( char ch )  {

    return ch - '0' - 1;
}

bool CheckBoard :: isValid( int src_r, int src_c, int dst_r, int dst_c )  {

    if( src_r >= 0 && src_r < MAX_ROWS && src_c >= 0 && src_c < MAX_COLS &&
        dst_r >= 0 && dst_r < MAX_ROWS && dst_c >= 0 && dst_c < MAX_COLS &&
        dst_r != src_r || dst_c != src_c)  {

            return true;
        }
    return false;
}

IPiece* CheckBoard :: GetPiece( int dst_r, int dst_c )  {

    return m_board[dst_r][dst_c];
}

void CheckBoard :: ClearBoard( void )  {

    for( int row = 0; row < m_board.size(); row++ )   {
        for( int col = 0; col < m_board[row].size(); col++ )  {
            m_board[row][col] = nullptr;
        }
    }
    
    m_onCheck = false;
}

void CheckBoard :: Put( char row, char col, IPiece* piece )  {

    int  c = GetColIndex(col);
    int  r = GetRowIndex(row);

    m_board[r][c] = piece;
}

bool CheckBoard :: Move( char src_row, char src_col, char dst_row, char dst_col )  {

    // TODO: Checar se origem é o mesmo que destino
    int  src_c = GetColIndex(src_col);
    int  src_r = GetRowIndex(src_row);
    int  dst_c = GetColIndex(dst_col);
    int  dst_r = GetRowIndex(dst_row);

    if( isValid( src_r, src_c, dst_r, dst_c ) ) {
        
        IPiece *piece = m_board[src_r][src_c];

        if ( ( piece != nullptr ) && piece -> Check( src_r, src_c, dst_r, dst_c ) )  {
            
            m_board[dst_r][dst_c] = piece;
            piece -> Movement();
            m_board[src_r][src_c] = nullptr;

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

            if(m_board[row][col] != nullptr)  {
                m_board[row][col] -> Print();
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