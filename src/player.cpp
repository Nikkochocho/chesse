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
#include "player.h"


/**
 * @brief Constructor. Initialize all class data.
 */
Player :: Player( Color color )  {

    this -> m_color = color;
}

/**
 * @brief Destructor. Finalize all class data.
 */
Player :: ~Player( void )  {

    m_pieces.clear();
}

/**
 * @brief Adds piece to player's list of pieces.
 * @param piece IPiece object.
 */
void Player :: Add( IPiece *piece )  {

    m_pieces.push_back( piece );
}

/**
 * @brief Removes piece from player's list of pieces.
 * @param piece IPiece object.
 */
void Player :: Remove( IPiece *piece )  {

    m_pieces.remove( piece );
}

/**
 * @brief Returns player's king.
 */
IPiece* Player :: GetKing( void )  {

    return m_king;
}

/**
 * @brief Sets player's king.
 * @param piece King piece.
 */
void Player :: SetKing( IPiece *piece )  {

    this -> m_king = piece;
}

/**
 * @brief Sets piece attacking player's king.
 * @param piece Attacker piece.
 */
void Player :: SetAttacker( IPiece *piece )  {

    this -> m_attacker = piece;
}

/**
 * @brief Returns player's current check status.
 */
bool Player :: GetCheckStatus( void )  {

    return m_oncheck;
}

/**
 * @brief Changes player's current check status.
 * @param check Check status.
 */
void Player :: SetCheckStatus( bool check )  {

    this -> m_oncheck = check;
}

/**
 * @brief Checks if piece belongs to player's list.
 * @param piece IPiece object.
 */
bool Player :: CheckPieces( IPiece *piece )  {

    for ( std :: list<IPiece*> :: iterator it = m_pieces.begin(); it != m_pieces.end(); it++ )  {

        if ( *it == piece )  {

            return true;
        }
    }

    return false;
}

/**
 * @brief Checks player's pieces movement viability.
 * @return List of available pieces.
 */
std :: list<IPiece*> Player :: MovePieces( void )  {

    std :: list<IPiece*> available_pieces;

    for ( std :: list< IPiece* > :: iterator it = m_pieces.begin(); it != m_pieces.end(); it++ )  {

        IPiece *pPiece = *it; 

        if ( pPiece -> MovementCheck( false ) )  {
            
            available_pieces.push_back( pPiece );
        }
    }

    return available_pieces;
}

/**
 * @brief Returns whether or not player can check opponent's king.
 */
bool Player :: CanCheck( void ) {

    for ( std :: list< IPiece* > :: iterator it = m_pieces.begin(); it != m_pieces.end(); it++ )  {

        IPiece *pPiece = *it; 

        if ( pPiece -> MovementCheck( true ) )  {  
            
            return true;
        }
    }

    return false;
}

/**
 * @brief Checks if player can catch current attacker.
 */
bool Player :: CanCatch( void )  {

    for ( std :: list<IPiece*> :: iterator it = m_pieces.begin(); it != m_pieces.end(); it++ )  {

        IPiece *pPiece = *it; 

        if ( pPiece == m_king )  {

            continue;
        }

        if ( pPiece -> CanMove( m_attacker -> Position() ) )  {
            
            return true;
        }
    }

    return false;
}

/**
 * @brief Checks if player can block current attack on king.
 */
bool Player :: CanBlock( void )  {

    stPosition attacker_pos = m_attacker -> Position();
    int        dist_col     = ( m_king -> Position().col ) - ( m_attacker -> Position().col );
    int        dist_row     = ( m_king -> Position().row ) - ( m_attacker -> Position().row );

    if ( m_attacker -> GetType() == KNIGHT )  {

        return false;
    }

    int itr_col  = ( dist_col != 0 ) ? ( dist_col / abs( dist_col ) ) : 0;
    int itr_row  = ( dist_row != 0 ) ? ( dist_row / abs( dist_row ) ) : 0;

    while ( ( attacker_pos.col !=  m_king -> Position().col ) || ( attacker_pos.row !=  m_king -> Position().row ) )  {

        attacker_pos.col += itr_col;
        attacker_pos.row += itr_row;

        for ( std :: list<IPiece*> :: iterator it = m_pieces.begin(); it != m_pieces.end(); it++ )  {

            IPiece    *pPiece = *it; 

            if ( pPiece == m_king )  {

                continue;
            }

            if ( pPiece -> CanMove( attacker_pos ) )  {
                
                return true;
            }
        }
    }

    return false;
}