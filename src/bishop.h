#ifndef __BISHOP_H__
#define __BISHOP_H__

#include "piece.h"


class Bishop : public Piece {

    public :

    Bishop ( Color color, IBoard *boardVision );
    virtual ~Bishop ( void );

    bool Check( int src_col, int src_row, int dst_col, int dst_row );
    void Print( void );
};

#endif // __BISHOP_H__