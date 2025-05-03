#include "board.h"
#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "pawn.h"


void Board :: Clear( void )  {

    for( int row = 0; row < m_board.size(); row++ )   {
        for( int col = 0; col < m_board[row].size(); col++ )  {
            m_board[row][col] = nullptr;
        }
    }   
}

Board :: Board( void )  {

    Clear();
}

Board :: ~Board( void )  {

}

void Board :: SetPiece( int row, int col, IPiece* piece )  {

    m_board[row][col] = piece;
}

IPiece* Board :: GetPiece( int dst_r, int dst_c )  {

    return m_board[dst_r][dst_c];
}

void Board :: Init( void )  {

    Clear();

    for ( int col = 0; col < MAX_COLS; col++ ) {

        SetPiece( 1, col, new Pawn( Color :: WHITE, this ) );
        SetPiece( 6, col, new Pawn( Color :: BLACK, this ) );
    }

    const char* pieceOrder = "RNBQKBNR";

    for ( int col = 0; col < MAX_COLS; col++ ) {

        switch ( pieceOrder[col] ) {

            case 'R': SetPiece( 0, col, new Rook( Color :: WHITE, this ) ); break;
            case 'N': SetPiece( 0, col, new Knight( Color :: WHITE, this ) ); break;
            case 'B': SetPiece( 0, col, new Bishop( Color :: WHITE, this ) ); break;
            case 'Q': SetPiece( 0, col, new Queen( Color :: WHITE, this ) ); break;
            case 'K': SetPiece( 0, col, new King( Color :: WHITE, this ) ); break;
        }

        switch ( pieceOrder[col] ) {

            case 'R': SetPiece( 7, col, new Rook( Color :: BLACK, this ) ); break;
            case 'N': SetPiece( 7, col, new Knight( Color :: BLACK, this ) ); break;
            case 'B': SetPiece( 7, col, new Bishop( Color :: BLACK, this ) ); break;
            case 'Q': SetPiece( 7, col, new Queen( Color :: BLACK, this ) ); break;
            case 'K': SetPiece( 7, col, new King( Color :: BLACK, this ) ); break;
        }
    }
}
