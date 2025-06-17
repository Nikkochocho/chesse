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

bool Player :: CheckPieces( IPiece *piece )  {

    for ( std :: list<IPiece*> :: iterator it = m_pieces.begin(); it != m_pieces.end(); it++ )  {

        if ( *it == piece )  {

            return true;
        }
    }

    return false;
}

bool Player :: CanCheck( void ) {

    for ( std :: list<IPiece*> :: iterator it = m_pieces.begin(); it != m_pieces.end(); it++ )  {

        IPiece *pPiece = *it; 

        if ( pPiece -> CheckVision() )  {
            
            return true;
        }
    }

    return false;
}