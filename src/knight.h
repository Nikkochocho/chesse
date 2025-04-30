#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "piece.h"


class Knight : public Piece {

    public :

    Knight ( Color color, BoardVision *boardVision );
    ~Knight ( void );

    void Movement ( void );
    bool Check( int src_row, int src_col, int dst_row, int dst_col );
    void Print( void );
};

#endif // __KNIGHT_H__