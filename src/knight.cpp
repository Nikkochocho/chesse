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
#include "knight.h"


/**
 * @brief Constructor. Initialize all class data.
 */
Knight :: Knight( Color color, IBoard *boardVision )  {

    this -> m_type        = KNIGHT;
    this -> m_color       = color;
    this -> m_BoardVision = boardVision;
}

/**
 * @brief Destructor. Finalize all class data.
 */
Knight :: ~Knight( void )  {

}

/**
 * @brief Checks if new position is valid under the piece's moveset.
 * @param dst_pos New position.
 */
bool Knight :: CanMove( stPosition dst_pos )  {
    
    IPiece      *target = m_BoardVision -> GetPiece( dst_pos.col, dst_pos.row );
    int         jump_c  = abs( dst_pos.col - m_position.col );
    int         jump_r  = abs( dst_pos.row - m_position.row );
    bool        ret     = ( ( jump_c == 1 && jump_r == 2 ) || ( jump_c == 2 && jump_r == 1 ) );

    if ( ret )  {

        return CanSet( target );
    }

    return ret;
}

/**
 * @brief By default, checks if piece has any possible movement available. 
 * If king_check is true, inspects if piece can check the opponents' king.
 * @param king_check Verification type. Optional parameter, false by default. 
 */
bool Knight :: MovementCheck( bool king_check )  {

    IPiece        *target;
    int           col, row;
    const int     col_number[MAX_SIZE] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    const int     row_number[MAX_SIZE] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    bool          ret           = false;

    for ( int i = MIN_SIZE; i < MAX_SIZE; i++ ) {

        col = m_position.col + col_number[i];
        row = m_position.row + row_number[i];

        if ( ( col < MIN_SIZE || col >= MAX_SIZE ) || ( row < MIN_SIZE || row >= MAX_SIZE ) )  {

            continue;
        }
        else  {

            target = m_BoardVision -> GetPiece( col, row );

            if ( !king_check )  {

                ret = CanSet( target );
            }
            else if ( IsOpponentKing( target ) )  {

                return true;
            }

            if ( ret )  {

                this -> m_availablePos.col = col;
                this -> m_availablePos.row = row;
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
void Knight :: Print( void )  {

    std :: cout << 'N';
}
// LCOV_EXCL_STOP