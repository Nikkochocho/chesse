#ifndef __ROOK_H__
#define __ROOK_H__

#include "piece.h"


class Rook : public Piece {

    public :

    Rook ( Color color, IBoard *boardVision );
    virtual ~Rook ( void );

    bool CanMove( int dst_col, int dst_row );
    bool MovementCheck( bool king_check );
    void Print( void );
};

#endif // __ROOK_H__