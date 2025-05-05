#ifndef __PAWN_H__
#define __PAWN_H__

#include "piece.h"


class Pawn : public Piece  {


    public:

    Pawn( Color color, IBoard *boardVision );
    ~Pawn( void );
    
    bool Check( int src_row, int src_col, int dst_row, int dst_col );
    void Print( void );
};

#endif // __PAWN_H__