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
#include "piece.h"


/**
 * @brief Returns if piece has any available position
 * on the X or Y axis.
 */
bool Piece :: AxisSet( void )  {

    stPosition pos;

    for ( int col = -1; col < 2; col++ )  {

        for ( int row = -1; row < 2; row++ )  {

            if ( abs( col ) == abs( row ) )  {

                continue;
            }

            pos.col = m_position.col + col;
            pos.row = m_position.row + row;

            if ( m_BoardVision -> IsValid( pos.col, pos.row ) )  {

                IPiece *target = m_BoardVision -> GetPiece( pos.col, pos.row );

                if ( CanSet( target ) )  {

                    m_availablePos = pos;
                    return true;
                }
            }
        }
    }

    return false;
}

/**
 * @brief Returns if piece has any diagonal position available.
 */
bool Piece :: DiagonalSet( void )  {

    stPosition pos;

    for ( int col = -1; col < 2; col++ )  {

        for ( int row = -1; row < 2; row++ )  {

            if ( col == 0 || row == 0 )  {

                continue;
            }

            pos.col = m_position.col + col;
            pos.row = m_position.row + row;

            if ( m_BoardVision -> IsValid( pos.col, pos.row ) )  {

                IPiece *target = m_BoardVision -> GetPiece( pos.col, pos.row );

                if ( CanSet( target ) )  {

                    m_availablePos = pos;
                    return true;
                }
            }
        }
    }

    return false;
}

/**
 * @brief Returns if piece can reach destiny position.
 * @param dst_pos New position.
 */
bool Piece :: CanReach( stPosition& dst_pos )  { 

    stPosition pos      = m_position;
    int        dist_col = dst_pos.col - m_position.col;
    int        dist_row = dst_pos.row - m_position.row;
    int        itr_col  = ( dist_col != 0 ) ? ( dist_col / abs( dist_col ) ) : 0;
    int        itr_row  = ( dist_row != 0 ) ? ( dist_row / abs( dist_row ) ) : 0;

    while ( ( pos.col != dst_pos.col ) || ( pos.row != dst_pos.row ) )  {

        pos.col += itr_col;
        pos.row += itr_row;
        
        IPiece *target = m_BoardVision -> GetPiece( pos.col, pos.row );
        
        if ( ( pos.col ==  dst_pos.col ) && ( pos.row ==  dst_pos.row ) && CanSet( target ) )  {

            return true;
        }
        
        if ( target != nullptr )  {

            return false;
        }
    }

    return false;
}

/**
 * @brief Returns if piece can set on a target position.
 * @param target IPiece object.
 */
bool Piece :: CanSet( IPiece* target )  {

    return ( ( target == nullptr ) || ( ( target != nullptr ) && ( target -> GetColor() != m_color ) ) );
}

/**
 * @brief Returns piece's current movement count.
 * @return Movement count.
 */
int Piece :: GetMovementCount( void )  {

    return this -> m_movementCount;
}

/**
 * @brief Adds to piece's movement count. 
 */
void Piece :: AddMovementCount( void ) {

    this -> m_movementCount++;
} 

// LCOV_EXCL_START
/**
 * @brief Checks if new position is valid under the piece's moveset.
 * @param dst_pos New position.
 */
bool Piece :: CanMove( stPosition& dst_pos )  {

    return false;
}

/**
 * @brief Checks if piece has any possible movement available. 
 */
bool Piece :: MovementCheck()  {

    return false;
}

/**
 * @brief Prints piece's text representation.
 */
void Piece :: Print( void ) {

}
// LCOV_EXCL_STOP
/**
 * @brief Returns piece's type.
 * @return Piece's type.
 */
Pieces Piece :: GetType( void )  { 

    return m_type;
}

/**
 * @brief Returns piece's color.
 * @return Piece's color.
 */
Color Piece :: GetColor( void )  {

    return m_color;
}

/**
 * @brief Returns piece's status.
 * @return Piece's status.
 */
Status Piece :: GetStatus( void )  {

    return m_status;
}

/**
 * @brief Sets piece's status change.
 * @param us status.
 */
void Piece :: SetStatus( Status status )  {

    m_status = status;
}

/**
 * @brief Gets and Sets piece's position.
 * @return Piece's position.
 */
stPosition& Piece :: Position( void )  {

    return m_position;
}

/**
 * @brief Gets and Sets piece's available position.
 * @return Piece's available position.
 */
stPosition& Piece :: AvailablePosition( void )  {

    return m_availablePos;
}