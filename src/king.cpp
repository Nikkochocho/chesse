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
#include "king.h"


/**
 * @brief Constructor. Initialize all class data.
 */
King :: King( Color color, IBoard *boardVision )  {

    this -> m_type        = KING;
    this -> m_color       = color;
    this -> m_BoardVision = boardVision;
}

/**
 * @brief Destructor. Finalize all class data.
 */
King :: ~King( void )  {
    
}

/**
 * @brief Checks if new position is valid under the piece's moveset.
 * @param dst_pos New position.
 */
bool King :: CanMove( stPosition dst_pos )  {

    IPiece    *target      = m_BoardVision -> GetPiece( dst_pos.col, dst_pos.row );
    bool      castling     = ( ( abs( dst_pos.col - m_position.col ) == 2 ) && ( dst_pos.row == m_position.row ) );
    bool      is_default   = ( ( m_movementCount == 0 ) && ( this -> GetStatus() == NORMAL ) );
    bool      default_move = ( ( abs( dst_pos.col - m_position.col ) <= 1 ) && ( abs( dst_pos.row - m_position.row ) <= 1 ) );

    if ( ( castling ) && ( is_default ) && ( CanReach( dst_pos ) ) )  {

        int      col_pos       = ( dst_pos.col - m_position.col == 2 ) ? 1 : -2;
        Status   castle_type   = ( col_pos == 1 ) ? SHORTCASTLE : LONGCASTLE;
        IPiece   *piece        = m_BoardVision -> GetPiece( ( dst_pos.col + col_pos ), m_position.row );

        if ( ( target == nullptr ) && ( piece != nullptr ) && ( piece -> GetType() == ROOK ) )  {

            bool valid_rook = ( ( piece -> GetMovementCount() == 0 ) && ( m_color == piece -> GetColor() ) );

            if ( ( m_BoardVision -> GetPiece( ( dst_pos.col - 1 ), m_position.row ) != nullptr ) || ( !valid_rook ) )  {

                return false;
            }

            this -> SetStatus( castle_type );
            return true;
        }
    }

    return ( ( default_move ) && ( CanSet( target ) ) );
}

/**
 * @brief By default, checks if piece has any possible movement available. 
 * If king_check is true, inspects if piece can check the opponents' king.
 * @param king_check Verification type. Optional parameter, false by default. 
 */
bool King :: MovementCheck( bool king_check )  {

    return false;
}

// LCOV_EXCL_START
/**
 * @brief Prints piece's text representation.
 */
void King :: Print( void )  {

    std :: cout << 'K';
}
// LCOV_EXCL_STOP