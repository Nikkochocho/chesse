#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "piece.h"


class Knight : public Piece {

    public :

    Knight ( Color color, IBoard *boardVision );
    virtual ~Knight ( void );

    bool Check( int dst_col, int dst_row );
    bool CheckVision( void );
    void Print( void );
};

#endif // __KNIGHT_H__