#ifndef __BOARD_H__
#define __BOARD_H__

#include "boardvision.h"
#include "ipiece.h"
#include "empty.h"
#include <array>

#define MAX_ROWS 8
#define MAX_COLS 8
#define KNIGHT_MOVES 8


typedef std :: array<std :: array<IPiece*, MAX_COLS>, MAX_ROWS> ArrayBoard;

class CheckBoard : public BoardVision  {

    ArrayBoard m_board;
    bool       m_onCheck[2];
    bool       m_checkmate;

    void Put( char row, char col, IPiece* piece );
    void ClearBoard( void );

    int GetColIndex( char ch );
    int GetRowIndex( char ch );

    bool IsValid( int src_r, int src_c, int dst_r, int dst_c );
    IPiece* GetPiece( int dst_r, int dst_c ) override;


    public:
    
    CheckBoard( void );
    ~CheckBoard( void );

    void NewBoard( void );
    bool Move( char src_row, char src_col, char dst_row, char dst_col );
    bool IsCheckmate( void );
    void Print( void );
};

#endif // __BOARD_H__