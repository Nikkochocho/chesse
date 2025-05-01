#ifndef __KING_H__
#define __KING_H__

#include "piece.h"


class King : public Piece {

    public :

    King ( Color color, BoardVision *boardVision );
    ~King ( void );

    void Movement ( void );
    bool Check( int src_row, int src_col, int dst_row, int dst_col );
    char Print( void );
};

#endif // __KING_H__