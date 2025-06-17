#ifndef __GAMEPLAY_H__
#define __GAMEPLAY_H__

#include "iboard.h"
#include "ipiece.h"
#include "player.h"
#include <map>

typedef std :: map<PlayerNumber, Player*> PlayerMap;

class GamePlay {

    bool         m_promotion = false;
    bool         m_checkmate;
    IBoard       *m_board;
    PlayerMap    m_players;
    PlayerNumber m_turn = PLAYER_1;


    bool IsValid( int src_c, int src_r, int dst_c, int dst_r );

    int GetColIndex( char ch );
    int GetRowIndex( char ch );

    void InitPieces( void );
    void ChangeTurn( void );

    public:
    
    GamePlay( IBoard *board );
    ~GamePlay( void );

    void NewGame( void );
    bool Move( char src_col, char src_row, char dst_col, char dst_row );
    bool HasPromotion( void );
    bool Promote( char dst_col, char dst_row, char promotion );
    bool IsCheckmate( void );
    PlayerNumber GetTurn( void );
    void Print( void );
};

#endif // __GAMEPLAY_H__