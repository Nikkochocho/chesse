#ifndef __GAMEPLAY_H__
#define __GAMEPLAY_H__

#include <map>
#include "iboard.h"
#include "ipiece.h"
#include "player.h"


typedef std :: map<PlayerNumber, Player*> PlayerMap;

class GamePlay {

    IBoard       *m_board;
    PlayerMap    m_players;
    bool         m_checkmate;
    bool         m_promotion = false;
    PlayerNumber m_turn      = PLAYER_1;

    int GetColIndex( char ch );
    int GetRowIndex( char ch );
    void InitPieces( void );
    void ChangeTurn( void );
    void SpecialCases( IPiece *piece );
    void InsertChanges( stPosition pos, IPiece *piece, PlayerNumber opponent, bool IsReverse );
    bool IsValid( int src_c, int src_r, int dst_c, int dst_r );
    bool VirtualMovement( IPiece *piece, int dst_c, int dst_r, PlayerNumber opponent );
    bool KingEscape( void );

    public:
    
    GamePlay( IBoard *board );
    ~GamePlay( void );

    void NewGame( void );
    bool Move( char src_col, char src_row, char dst_col, char dst_row );
    bool HasPromotion( void );
    bool Promote( char dst_col, char dst_row, Pieces piece_type );
    bool IsCheckmate( void );
    PlayerNumber GetTurn( void );
    void Print( void );
};

#endif // __GAMEPLAY_H__