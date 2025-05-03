#ifndef __BISHOP_H__
#define __BISHOP_H__

#include "piece.h"


class Bishop : public Piece {

    public :

    Bishop ( Color color, IBoard *boardVision );
    ~Bishop ( void );

    bool Check( int src_row, int src_col, int dst_row, int dst_col );
    void Print( void );
};

#endif // __BISHOP_H__