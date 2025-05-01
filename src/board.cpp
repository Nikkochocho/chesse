#include <iostream>
#include "board.h"
#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "pawn.h"


CheckBoard :: CheckBoard( void )  {

    ClearBoard();
}

CheckBoard :: ~CheckBoard( void )  {
    
}

void CheckBoard :: Put( char row, char col, IPiece* piece )  {

    int  c = GetColIndex( col );
    int  r = GetRowIndex( row );

    m_board[r][c] = piece;
}

void CheckBoard :: ClearBoard( void )  {

    for( int row = 0; row < m_board.size(); row++ )   {
        for( int col = 0; col < m_board[row].size(); col++ )  {
            m_board[row][col] = nullptr;
        }
    }
    
    m_onCheck[PLAYER_1] = m_onCheck[PLAYER_2] = false;
    m_checkmate = false;
}

int CheckBoard :: GetColIndex( char ch )  {

    return ch - 'a';
}

int CheckBoard :: GetRowIndex( char ch )  {

    return ch - '0' - 1;
}

bool CheckBoard :: IsValid( int src_r, int src_c, int dst_r, int dst_c )  {

    if( src_r >= 0 && src_r < MAX_ROWS && src_c >= 0 && src_c < MAX_COLS &&
        dst_r >= 0 && dst_r < MAX_ROWS && dst_c >= 0 && dst_c < MAX_COLS &&
        dst_r != src_r || dst_c != src_c )  {

            return true;
        }

    return false;
}

IPiece* CheckBoard :: GetPiece( int dst_r, int dst_c )  {

    return m_board[dst_r][dst_c];
}

void CheckBoard :: NewBoard( void )  {

    ClearBoard();

    for ( char col = 'a'; col <= 'h'; col++ ) {

        Put( '2', col, new Pawn( Color :: WHITE, this ) );
        Put( '7', col, new Pawn( Color :: BLACK, this ) );
    }

    const char* pieceOrder = "RNBQKBNR";

    for ( int i = 0; i < 8; i++ ) {

        char col = 'a' + i;

        switch ( pieceOrder[i] ) {

            case 'R': Put( '1', col, new Rook( Color :: WHITE, this ) ); break;
            case 'N': Put( '1', col, new Knight( Color :: WHITE, this ) ); break;
            case 'B': Put( '1', col, new Bishop( Color :: WHITE, this ) ); break;
            case 'Q': Put( '1', col, new Queen( Color :: WHITE, this ) ); break;
            case 'K': Put( '1', col, new King( Color :: WHITE, this ) ); break;
        }

        switch ( pieceOrder[i] ) {

            case 'R': Put( '8', col, new Rook( Color :: BLACK, this ) ); break;
            case 'N': Put( '8', col, new Knight( Color :: BLACK, this ) ); break;
            case 'B': Put( '8', col, new Bishop( Color :: BLACK, this ) ); break;
            case 'Q': Put( '8', col, new Queen( Color :: BLACK, this ) ); break;
            case 'K': Put( '8', col, new King( Color :: BLACK, this ) ); break;
        }
    }
}

bool CheckBoard :: Move( char src_row, char src_col, char dst_row, char dst_col )  {

    int  src_c = GetColIndex( src_col );
    int  src_r = GetRowIndex( src_row );
    int  dst_c = GetColIndex( dst_col );
    int  dst_r = GetRowIndex( dst_row );

    if( IsValid( src_r, src_c, dst_r, dst_c ) ) {
        
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

bool CheckBoard :: IsCheckmate( void )  {

    return m_checkmate;
}

void CheckBoard :: Print( void )  {
    
    int count = 0;

    for(int i = 0; i < ( MAX_COLS * 2 ) + 1; i++)  {

        if ( i % 2 != 0 )  {

            char output = 'a' + count;
            std :: cout << output;
            count++;
            continue;
        }

        std :: cout << " ";
    }

    std :: cout << std ::endl;

    for(int cc = 0; cc < ( MAX_COLS * 2 ) + 1; cc++)  {

        std :: cout << "-";
    }
    std :: cout << std ::endl;
    
    for(int row = ( MAX_ROWS - 1 ); row >= 0; row--)  {

        std :: cout << "|";

        for(int col = 0; col < MAX_COLS; col++)  {

            if( m_board[row][col] != nullptr )  {

                std :: cout << m_board[row][col] -> Print();
            }
            else  {

                std :: cout << " ";    
            }

            std :: cout << "|";

            if( col == ( MAX_COLS - 1 ) ) std :: cout << std ::endl;
        }

        for(int cc = 0; cc < (MAX_COLS * 2) + 1; cc++)  {

            std :: cout << "-";
        }

        std :: cout << std ::endl;
    }
}