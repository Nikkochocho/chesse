#ifndef __PAWN_H__
#define __PAWN_H__

#include "piece.h"


class Pawn : public Piece  {

    public:

    Pawn( Color color, IBoard *boardVision );
    virtual ~Pawn( void );
    
    bool CanMove( int dst_col, int dst_row );
    bool MovementCheck( bool king_check );
    void Print( void );
};

#endif // __PAWN_H__