#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "piece.h"


class Knight : public Piece {

    public :

    Knight ( Color color, IBoard *boardVision );
    virtual ~Knight ( void );

    bool Check( int src_col, int src_row, int dst_col, int dst_row );
    void Print( void );
};

#endif // __KNIGHT_H__