#include "player.h"


Player :: Player( Color color )  {

    this -> m_color = color;
}

Player :: ~Player( void )  {

    m_pieces.clear();
}

void Player :: Add( IPiece *piece )  {

    m_pieces.push_back( piece );
}

void Player :: Remove( IPiece *piece )  {

    m_pieces.remove( piece );
}

IPiece* Player :: GetKing( void )  {

    return m_king;
}

void Player :: SetKing( IPiece *piece )  {

    this -> m_king = piece;
}

IPiece* Player :: GetAttacker( void )  {

    return m_attacker;
}

void Player :: SetAttacker( IPiece *piece )  {

    this -> m_attacker = piece;
}

bool Player :: GetCheckStatus( void )  {

    return m_oncheck;
}

void Player :: SetCheckStatus( bool check )  {

    this -> m_oncheck = check;
}

bool Player :: CheckPieces( IPiece *piece )  {

    for ( std :: list< IPiece* > :: iterator it = m_pieces.begin(); it != m_pieces.end(); it++ )  {

        if ( *it == piece )  {

            return true;
        }
    }

    return false;
}

bool Player :: CanCheck( void ) {

    for ( std :: list< IPiece* > :: iterator it = m_pieces.begin(); it != m_pieces.end(); it++ )  {

        IPiece *pPiece = *it; 

        if ( pPiece -> KingCheck() )  {
            
            return true;
        }
    }

    return false;
}

bool Player :: CanCatch( void )  {

    for ( std :: list< IPiece* > :: iterator it = m_pieces.begin(); it != m_pieces.end(); it++ )  {

        IPiece *pPiece = *it; 

        if ( pPiece -> CanMove( m_attacker -> Position().col, m_attacker -> Position().row ) )  {
            
            return true;
        }
    }

    return false;
}

bool Player :: CanBlock( void )  {

    int itr_col        = 0;
    int itr_row        = 0;
    int col_iterations = 0;
    int row_iterations = 0;
    int dist_col       = ( m_king -> Position().col ) - ( m_attacker -> Position().col );
    int dist_row       = ( m_king -> Position().row ) - ( m_attacker -> Position().row );

    if ( dist_col != 0 )  {

        itr_col = ( dist_col > 0 ) ? 1 : -1;
    }
    
    if ( dist_row != 0 )  { 

        itr_row = ( dist_row > 0 ) ? 1 : -1;
    }

    while ( ( row_iterations !=  dist_row ) || ( col_iterations !=  dist_col ) )  {

        row_iterations += itr_row;
        col_iterations += itr_col;

        for ( std :: list< IPiece* > :: iterator it = m_pieces.begin(); it != m_pieces.end(); it++ )  {

            IPiece    *pPiece = *it; 
            int       col_pos = pPiece -> Position().col + col_iterations;
            int       row_pos = pPiece -> Position().row + row_iterations;

            if ( pPiece -> CanMove( col_pos, row_pos ) )  {
                
                return true;
            }
        }
    }

    return false;
}