#include "board.h"
#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "pawn.h"


void Board :: Clear( void )  {

    for ( int col = 0; col < m_board.size(); col++ )   {

        for ( int row = 0; row < m_board[col].size(); row++ )  {
            
            m_board[col][row] = nullptr;
        }
    }   
}

Board :: Board( void )  {

    Clear();
}

Board :: ~Board( void )  {

}

IPiece* Board :: GetPromotion( Pieces piece, Color color )  {

    IPiece *promoted_piece;

    switch ( piece )  {

        case QUEEN:
            promoted_piece = new Queen( color, this );
            break;

        case BISHOP:
            promoted_piece = new Bishop( color, this );
            break;

        case KNIGHT:
            promoted_piece = new Knight( color, this );
            break;

        case ROOK:
            promoted_piece = new Rook( color, this );
            break;
    }

    return promoted_piece;
}

IPiece* Board :: GetPiece( int dst_c, int dst_r )  {

    return m_board[dst_c][dst_r];
}

void Board :: SetPiece( int col, int row, IPiece *piece )  {

    if ( piece != nullptr )  {
        
        piece -> Position().col = col;
        piece -> Position().row = row;
    }

    m_board[col][row] = piece;
}

void Board :: RemovePiece( int col, int row )  {

    IPiece *piece = m_board[col][row];

    if ( piece != nullptr )  {

        delete piece;
        m_board[col][row] = nullptr;
    }
}

void Board :: Init( void )  {

    Clear();

    for ( int col = 0; col < MAX_COLS; col++ ) {

        SetPiece( col, 1, new Pawn( Color :: WHITE, this ) );
        SetPiece( col, 6, new Pawn( Color :: BLACK, this ) );
    }

    const char *pieceOrder = "RNBQKBNR";

    for ( int col = 0; col < MAX_COLS; col++ ) {

        switch ( pieceOrder[col] ) {

            case 'R': 
                SetPiece( col, 0, new Rook( Color :: WHITE, this ) ); 
                SetPiece( col, 7, new Rook( Color :: BLACK, this ) );
                break;

            case 'N': 
                SetPiece( col, 0, new Knight( Color :: WHITE, this ) ); 
                SetPiece( col, 7, new Knight( Color :: BLACK, this ) );
                break;

            case 'B': 
                SetPiece( col, 0, new Bishop( Color :: WHITE, this ) ); 
                SetPiece( col, 7, new Bishop( Color :: BLACK, this ) ); 
                break;

            case 'Q': 
                SetPiece( col, 0, new Queen( Color :: WHITE, this ) ); 
                SetPiece( col, 7, new Queen( Color :: BLACK, this ) ); 
                break;

            case 'K': 
                SetPiece( col, 0, new King( Color :: WHITE, this ) ); 
                SetPiece( col, 7, new King( Color :: BLACK, this ) );
                break;
        }
    }
}