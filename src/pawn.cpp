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

#include <iostream>
#include "pawn.h"


/**
 * @brief Constructor. Initialize all class data.
 */
Pawn :: Pawn( Color color, IBoard *boardVision )  {
    
    this -> m_type        = PAWN;
    this -> m_color       = color;
    this -> m_BoardVision = boardVision;
}

/**
 * @brief Destructor. Finalize all class data.
 */
Pawn :: ~Pawn( void )  {
    
}

bool Pawn :: CanSet( IPiece* target )  {
 
    return ( target != nullptr ) && ( target -> GetColor() != m_color );
} 

/**
 * @brief Checks if new position is valid under the piece's moveset.
 * @param dst_pos New position.
 */
bool Pawn :: CanMove( stPosition dst_pos )  {
    
    int         direction     = ( m_color == WHITE ) ? 1 : -1;
    int         enpassant_row = ( m_color == WHITE ) ? 4 : 3;
    int         promotion_row = ( m_color == WHITE ) ? ( MAX_SIZE - 1 ) : MIN_SIZE;
    int         dist_row      = ( m_movementCount == 0 ) ? 2 : 1;
    IPiece      *target       = m_BoardVision -> GetPiece( dst_pos.col, dst_pos.row );
    IPiece      *side_piece   = m_BoardVision -> GetPiece( dst_pos.col, dst_pos.row + ( direction * -1 ) );
    bool        ret           = false;

    if ( ( abs( dst_pos.col - m_position.col ) == 1 ) && ( dst_pos.row == m_position.row + direction ) )  { 

        if ( ( CanSet( side_piece ) && ( side_piece -> GetType() == PAWN ) && ( side_piece -> GetMovementCount() == 1 ) ) &&
             ( ( target == nullptr ) && ( m_position.row == enpassant_row ) ) ) {

            this -> SetStatus( ENPASSANT );
            return true; // en passant capture
        }  

        ret = CanSet( target ); // default capture
    }
    else  {

        if ( ( target != nullptr ) || ( ( ( dst_pos.row - m_position.row ) == 2 ) && ( side_piece != nullptr ) ) )  {

            return false;
        }

        ret = ( ( dst_pos.col == m_position.col ) && 
                ( ( dst_pos.row == m_position.row + direction ) || ( dst_pos.row == m_position.row + ( dist_row * direction ) ) ) );
    }

    if ( ret && ( dst_pos.row == promotion_row ) )  {

        this -> SetStatus( PROMOTION );
    }

    return ret; 
}

/**
 * @brief Checks if piece has any possible movement available. 
 */
bool Pawn :: MovementCheck( void )  {

    stPosition pos;
    int        row = ( m_color == WHITE ) ? 1 : -1;
    bool       ret = false;

    pos.row = m_position.row + row;

    if ( ( pos.row >= MIN_SIZE ) && ( pos.row < MAX_SIZE ) )  {
        
        for ( int col = -1; col < 2; col++ )  {

            pos.col = m_position.col + col;
            
            if ( !m_BoardVision -> IsValid( pos.col, pos.row ) )  {

                continue;
            }

            IPiece *target = m_BoardVision -> GetPiece( ( pos.col ), ( pos.row ) );

            ret = ( col == 0 ) ? ( target == nullptr ) : CanSet( target );

            if ( ret )  {

                this -> m_availablePos = pos;
                break;
            }
        }
    }

    return ret;
}

// LCOV_EXCL_START
/**
 * @brief Prints piece's text representation.
 */
void Pawn :: Print( void )  {

    std :: cout << 'P';
}
// LCOV_EXCL_STOP