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


King :: King( Color color, IBoard *boardVision )  {

    this -> m_type        = KING;
    this -> m_color       = color;
    this -> m_BoardVision = boardVision;
}

King :: ~King( void )  {
    
}

bool King :: CanMove( int dst_col, int dst_row )  {

    IPiece      *target  = m_BoardVision -> GetPiece( dst_col, dst_row );
    bool        castling = ( abs( dst_col - m_position.col ) == 2 );
    bool        ret      =  ( ( ( abs( dst_col - m_position.col ) <= 1 ) && ( abs( dst_row - m_position.row ) <= 1 ) ) &&
                              ( ( abs( dst_col - m_position.col ) == abs( dst_row - m_position.row ) ) || 
                                ( dst_col == m_position.col || dst_row == m_position.row ) ) &&
                                ( CanSet( target ) ) );

    if ( castling && ( m_MovementCount == 0 ) && ( dst_row == m_position.row ) && CanReach( dst_col, dst_row ) && ( this -> GetStatus() != CHECK ) )  {

        int      rook_pos     = ( dst_col - m_position.col == 2 ) ? 1 : -2;
        Status   castle_type  = ( rook_pos == 1 ) ? SHORTCASTLE : LONGCASTLE;
        IPiece   *castle_room = m_BoardVision -> GetPiece( ( dst_col + rook_pos ), m_position.row );

        if ( ( target == nullptr ) && ( castle_room -> GetType() == ROOK ) )  {

            if ( castle_type == LONGCASTLE )  {

                IPiece   *between_castle = m_BoardVision -> GetPiece( ( dst_col - 1 ), m_position.row );

                if ( between_castle != nullptr )  {

                    return false;
                }
            }

            this -> SetStatus( castle_type );
            return ( ( m_color == castle_room -> GetColor() ) && ( castle_room -> GetMovementCount() == 0 ) );
        }
    }

    return ret;
}

bool King :: MovementCheck( bool king_check )  {

    return false;
}

// LCOV_EXCL_START
void King :: Print( void )  {

    std :: cout << 'K';
}
// LCOV_EXCL_STOP