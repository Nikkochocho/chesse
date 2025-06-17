#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "ipiece.h"
#include <list>

typedef std :: list<IPiece*> PieceList;

class Player  {

    PieceList    m_pieces;
    Color        m_color;
    

    public:

    Player( Color color );
    ~Player( void );

    void Add( IPiece *piece );
    void Remove( IPiece *piece );
    bool CheckPieces( IPiece *piece );
    bool CanCheck( void );
};

#endif // __PLAYER_H__