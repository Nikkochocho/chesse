#ifndef __QUEEN_H__
#define __QUEEN_H__

#include "piece.h"


class Queen : public Piece {

    public :

    Queen ( Color color, IBoard *boardVision );
    virtual ~Queen ( void );

    bool Check( int dst_col, int dst_row );
    bool CheckVision( void );
    void Print( void );
};

#endif // __QUEEN_H__