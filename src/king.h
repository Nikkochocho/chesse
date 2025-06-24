#ifndef __KING_H__
#define __KING_H__

#include "piece.h"


class King : public Piece {

    public :

    King ( Color color, IBoard *boardVision );
    virtual ~King ( void );

    bool CanMove( int dst_col, int dst_row );
    bool KingCheck( void );
    void Print( void );
};

#endif // __KING_H__