/*
 * chesse
 * Copyright (C) 2025  Lara H. Ferreira.
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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

bool Board :: IsValid( int col, int row )  {

    if ( col >= 0 && col < MAX_COLS && row >= 0 && row < MAX_ROWS )  {

        return true;
    }

    return false;
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

    if ( IsValid( dst_c, dst_r ) )  {

        return m_board[dst_c][dst_r];
    }

    return nullptr;
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