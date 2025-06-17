#ifndef __PAWN_H__
#define __PAWN_H__

#include "piece.h"


class Pawn : public Piece  {


    public:

    Pawn( Color color, IBoard *boardVision );
    virtual ~Pawn( void );
    
    bool Check( int dst_col, int dst_row );
    bool CheckVision( void );
    void Print( void );
};

#endif // __PAWN_H__