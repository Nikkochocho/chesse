#ifndef __ROOK_H__
#define __ROOK_H__

#include "piece.h"

class Rook : public Piece {

    public :

    Rook ( Color color );
    ~Rook ( void );

    void Movement ( void );
    bool Check( int src_row, int src_col, int dst_row, int dst_col );
    void Print( void );
};

#endif // __ROOK_H__