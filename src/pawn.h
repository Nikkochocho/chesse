#ifndef __PAWN_H__
#define __PAWN_H__

#include "piece.h"


class Pawn : public Piece  {


    public:

    Pawn( Color color, IBoard *boardVision );
    virtual ~Pawn( void );
    
    bool Check( int src_col, int src_row, int dst_col, int dst_row );
    void Print( void );
};

#endif // __PAWN_H__