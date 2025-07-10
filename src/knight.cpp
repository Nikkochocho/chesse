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


Knight :: Knight( Color color, IBoard *boardVision )  {

    this -> m_type        = KNIGHT;
    this -> m_color       = color;
    this -> m_BoardVision = boardVision;
}

Knight :: ~Knight( void )  {

}

bool Knight :: CanMove( int dst_col, int dst_row )  {
    
    IPiece      *target = m_BoardVision -> GetPiece( dst_col, dst_row );
    int         jump_c  = abs( dst_col - m_position.col );
    int         jump_r  = abs( dst_row - m_position.row );
    bool        ret     = ( ( jump_c == 1 && jump_r == 2 ) || ( jump_c == 2 && jump_r == 1 ) );

    if ( ret )  {

        return CanSet( target );
    }

    return ret;
}

bool Knight :: MovementCheck( bool king_check )  {

    IPiece        *piece;
    int           col, row;
    const int     col_number[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    const int     row_number[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    bool          ret           = false;

    for ( int i = 0; i < 8; i++ ) {

        col = m_position.col + col_number[i];
        row = m_position.row + row_number[i];

        if ( ( col < 0 || col > 7 ) || ( row < 0 || row > 7 ) )  {

            continue;
        }
        else  {

            piece = m_BoardVision -> GetPiece( col, row );

            if ( !king_check )  {

                this -> m_availablePos.col = col;
                this -> m_availablePos.row = row;
                ret = CanSet( piece );
            }
            else if ( ( piece != nullptr ) && ( ( piece -> GetType() == KING ) && ( piece -> GetColor() != m_color ) ) )  {

                piece -> SetStatus( CHECK );
                ret = true;
            }

            if ( ret )  {

                break;
            }
        }
    }

    return ret;
}

// LCOV_EXCL_START
void Knight :: Print( void )  {

    std :: cout << 'N';
}
// LCOV_EXCL_STOP