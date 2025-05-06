#ifndef __ROOK_H__
#define __ROOK_H__

#include "piece.h"


class Rook : public Piece {

    public :

    Rook ( Color color, IBoard *boardVision );
    ~Rook ( void );

    bool Check( int src_col, int src_row, int dst_col, int dst_row );
    void Print( void );
};

#endif // __ROOK_H__