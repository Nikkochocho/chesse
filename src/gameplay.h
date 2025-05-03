#ifndef __GAMEPLAY_H__
#define __GAMEPLAY_H__

#include "iboard.h"
#include "ipiece.h"


class GamePlay {

    bool       m_Promotion = false;
    bool       m_onCheck[2];
    bool       m_checkmate;
    IBoard*    m_board;

    bool IsValid( int src_r, int src_c, int dst_r, int dst_c );

    int GetColIndex( char ch );
    int GetRowIndex( char ch );

    public:
    
    GamePlay( IBoard* board );
    ~GamePlay( void );

    void NewGame( void );
    bool Move( char src_row, char src_col, char dst_row, char dst_col );
    bool HasPromotion( void );
    bool IsCheckmate( void );
    void Print( void );
};

#endif // __GAMEPLAY_H__