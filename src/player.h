#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "ipiece.h"
#include <list>

typedef std :: list<IPiece*> PieceList;

class Player  {

    PieceList    m_pieces;
    Color        m_color;
    IPiece       *m_king;
    IPiece       *m_attacker = nullptr;
    bool         m_oncheck = false;
    

    public:

    Player( Color color );
    ~Player( void );

    void Add( IPiece *piece );
    void Remove( IPiece *piece );
    IPiece* GetKing( void );
    void SetKing( IPiece *piece );
    void SetAttacker( IPiece *piece );
    bool GetCheckStatus( void );
    void SetCheckStatus( bool check );
    bool CheckPieces( IPiece *piece );
    bool MovePieces( void );
    bool CanCheck( void );
    bool CanCatch( void );
    bool CanBlock( void );
};

#endif // __PLAYER_H__