#ifndef __BOARD_H__
#define __BOARD_H__

#include "piece.h"
#include <array>

#define MAX_ROWS 8
#define MAX_COLS 8
#define KNIGHT_MOVES 8


typedef std :: array<std :: array<Piece*, MAX_COLS>, MAX_ROWS> ArrayBoard;

class CheckBoard  {

    ArrayBoard board;

    public:
    
    CheckBoard( void );
    ~CheckBoard( void );

    int get_col_index( char ch );
    int get_row_index( char ch );

    void clear_board( void );
    void put_board( char row, char col, Piece* piece );
    void move( char src_row, char src_col, char dst_row, char dst_col);
    void print_board( void );
};

#endif // __BOARD_H__