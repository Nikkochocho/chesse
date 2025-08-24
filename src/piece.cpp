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

#include "piece.h"


/**
 * @brief Returns axis line max positions.
 * @param Xpos X axis position.
 * @param Ypos Y axis position.
 * @param isAsc Position type. 
 * true for crescent and false for decrescent. 
 * @param check Validation type. 
 */
void Piece :: GetAxisLine( stPosition& Xpos, stPosition& Ypos, bool isAsc, bool check )  {

    if ( check )  {

        Xpos.col = ( isAsc ) ?  ( MAX_SIZE - 1 ) : MIN_SIZE;
        Ypos.row = ( isAsc ) ?  ( MAX_SIZE - 1 ) : MIN_SIZE;
    }
    else  {

        int col = ( isAsc ) ? ( m_position.col + 1 ) : ( m_position.col - 1 );
        int row = ( isAsc ) ? ( m_position.row + 1 ) : ( m_position.row - 1 );

        Xpos.col = ( ( col < MAX_SIZE ) && ( col >= MIN_SIZE ) ) ? col : m_position.col;
        Ypos.row = ( ( row < MAX_SIZE ) && ( row >= MIN_SIZE ) ) ? row : m_position.row;
    }
}

/**
 * @brief Returns main and secondary diagonal max positions.
 * @param posAsc Diagonal crescent position.
 * @param posDesc Diagonal decrescent position.
 * @param diagonal Diagonal type. true for main and false for secondary.
 * @param check Returns on first iteration if true.
 */
void Piece :: GetDiagonals( stPosition& posAsc, stPosition& posDesc, bool main, bool check )  {

    bool asc, desc;
    int direction   = main ? 1 : -1; // Default main diagonal; else secondary diagonal
    int minAsc      = main ? -1 : 0;
    int minDesc     = main ? 0 : -1;
    int maxAsc      = main ? 7 : 8;
    int maxDesc     = main ? 8 : 7;

    asc = desc = true;

    while ( asc || desc )  {

        if ( ( ( posAsc.col < maxAsc ) && ( posAsc.col > minAsc ) ) && ( posAsc.row < ( MAX_SIZE - 1 ) ) )  {

            posAsc.col += direction;
            posAsc.row++;
        }
        else asc = false;

        if ( ( ( posDesc.col > minDesc ) && ( posDesc.col < maxDesc ) ) && ( posDesc.row > MIN_SIZE ) )  {

            posDesc.col += ( direction * -1 );
            posDesc.row--;
        }
        else desc = false;

        if ( !check )  {

            break;
        }
    }
}

/**
 * @brief Checks if target is the opponent player's king.
 * @param target IPiece object.
 */
bool Piece :: IsOpponentKing( IPiece *target )  {

    return ( ( target != nullptr ) && 
             ( target -> GetType() == KING && target -> GetColor() != m_color ) );
}

/**
 * @brief Returns if piece can reach next position or check opponent's king.
 * @param dst_pos New position.
 * @param check Validation type. If true inspects if piece can check opponent's king;
 * if false checks if piece can reach new position.
 */
bool Piece :: CanReach( stPosition dst_pos, bool check )  { 

    stPosition   dist;
    int          itr_col  = 0;
    int          itr_row  = 0;

    dist.col = dst_pos.col - m_position.col;
    dist.row = dst_pos.row - m_position.row;

    if ( ( dist.col == 0 ) && ( dist.row == 0 ) )  {

        return false;
    }

    if ( dist.col != 0 )  {

        itr_col = ( dist.col > 0 ) ? 1 : -1;
    }
    
    if ( dist.row != 0 )  { 

        itr_row = ( dist.row > 0 ) ? 1 : -1;
    }

    return IterationCheck( dist, itr_col, itr_row, check );
}

/**
 * @brief Inspects on each iteration if piece's move is trespassing or
 * if it can check opponent's king.
 * @param dist distance between current and next position.
 * @param itr_col column iterator; Value of 1 or -1.
 * @param itr_row row iterator; Value of 1 or -1.
 * @param check Validation type. If true inspects if piece can check opponent's king;
 * if false checks if piece can reach new position.
 */
bool Piece :: IterationCheck( stPosition dist, int itr_col, int itr_row, bool check )  {

    int        col_iterations = 0;
    int        row_iterations = 0;
    bool       ret            = ( check ) ? false : true; // default return

    while ( ( col_iterations != dist.col ) || ( row_iterations != dist.row ) )  {

        row_iterations += itr_row;
        col_iterations += itr_col;
        
        IPiece *target = m_BoardVision -> GetPiece( ( m_position.col + col_iterations ), ( m_position.row + row_iterations ) );
        
        if ( check && IsOpponentKing( target ) )  {

            target -> SetStatus( CHECK );
            return true;
        }
        
        if ( ( !check ) && ( col_iterations ==  dist.col ) && ( row_iterations ==  dist.row ) )  {

            this -> m_availablePos.col = m_position.col + col_iterations;
            this -> m_availablePos.row = m_position.row + row_iterations;
            return CanSet( target );
        }
        
        if ( target != nullptr )  {

            return false;
        }
    }

    return ret;
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

/**
 * @brief Returns if piece can set on a target position.
 * @param target IPiece object.
 */
bool Piece :: CanSet( IPiece* target )  {

    return ( ( target == nullptr ) || ( ( target != nullptr ) && ( target -> GetColor() != m_color ) ) );
} 

// LCOV_EXCL_START
/**
 * @brief Checks if new position is valid under the piece's moveset.
 * @param dst_pos New position.
 */
bool Piece :: CanMove( stPosition dst_pos )  {

    return false;
}

/**
 * @brief By default, checks if piece has any possible movement available. 
 * If king_check is true, inspects if piece can check the opponents' king.
 * @param king_check Verification type. Optional parameter, false by default. 
 */
bool Piece :: MovementCheck( bool king_check )  {

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

    return m_state;
}

/**
 * @brief Sets piece's status change.
 * @param state status.
 */
void Piece :: SetStatus( Status state )  {

    m_state = state;
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