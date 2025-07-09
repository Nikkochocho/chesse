#ifndef __BISHOP_H__
#define __BISHOP_H__

#include "piece.h"


class Bishop : public Piece {

    public :

    Bishop ( Color color, IBoard *boardVision );
    virtual ~Bishop ( void );

    bool CanMove( int dst_col, int dst_row );
    bool MovementCheck( bool king_check );
    void Print( void );
};

#endif // __BISHOP_H__