#ifndef __QUEEN_H__
#define __QUEEN_H__

#include "piece.h"


class Queen : public Piece {

    public :

    Queen ( Color color, BoardVision *boardVision );
    ~Queen ( void );

    void Movement ( void );
    bool Check( int src_row, int src_col, int dst_row, int dst_col );
    void Print( void );
};

#endif // __QUEEN_H__