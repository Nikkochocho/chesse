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


/**
 * @brief Sets all board positions to null.
 */
void Board :: Clear( void )  {

    for ( int col = MIN_SIZE; col < m_board.size(); col++ )   {

        for ( int row = MIN_SIZE; row < m_board[col].size(); row++ )  {
            
            m_board[col][row] = nullptr;
        }
    }   
}

/**
 * @brief Constructor. Initialize all class data.
 */
Board :: Board( void )  {

    Clear();
}

/**
 * @brief Destructor. Finalize all class data.
 */
Board :: ~Board( void )  {

}

/**
 * @brief Column and Row values viability verification.
 * @param col X axis position.
 * @param row Y axis position.
 */
bool Board :: IsValid( int col, int row )  {

    if ( ( col >= MIN_SIZE ) && ( col < MAX_SIZE ) && ( row >= MIN_SIZE ) && ( row < MAX_SIZE ) )  {

        return true;
    }

    return false;
}

/**
 * @brief Sets the new promoted piece on board.
 * @param piece Promoted piece's type.
 * @param color Promoted piece's color.
 * @return Promoted piece's IPiece object.
 */
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

/** 
 * @brief Gets an IPiece object based on coordenates.
 * @param col X axis position.
 * @param row Y axis position.
 * @return IPiece object.
 */
IPiece* Board :: GetPiece( int col, int row )  {

    if ( IsValid( col, row ) )  {

        return m_board[col][row];
    }

    return nullptr;
}

/**
 * @brief Sets IPiece object on board.
 * @param col X axis position.
 * @param row Y axis position.
 * @param piece IPiece object.
 */
void Board :: SetPiece( int col, int row, IPiece *piece )  {

    if ( piece != nullptr )  {
        
        piece -> Position().col = col;
        piece -> Position().row = row;
    }

    m_board[col][row] = piece;
}

/**
 * @brief Removes and deletes piece from board.
 * @param col X axis position.
 * @param row Y axis position.
 */
void Board :: RemovePiece( int col, int row )  {

    IPiece *piece = m_board[col][row];

    if ( piece != nullptr )  {

        m_board[col][row] = nullptr;
        //delete piece;
    }
}

/**
 * @brief Initializes board default configuration.
 */
void Board :: Init( void )  {

    Clear();

    for ( int col = MIN_SIZE; col < MAX_SIZE; col++ ) {

        SetPiece( col, 1, new Pawn( Color :: WHITE, this ) );
        SetPiece( col, 6, new Pawn( Color :: BLACK, this ) );
    }

    const char *pieceOrder = "RNBQKBNR";

    for ( int col = MIN_SIZE; col < MAX_SIZE; col++ ) {

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