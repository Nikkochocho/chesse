#ifndef __PAWN_H__
#define __PAWN_H__

#include "piece.h"


class Pawn : public Piece  {


    public:

    Pawn( Color color, IBoard *boardVision );
    ~Pawn( void );
    
    virtual bool Check( int src_row, int src_col, int dst_row, int dst_col );
    virtual void Print( void );
};

#endif // __PAWN_H__