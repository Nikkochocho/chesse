#ifndef __PAWN_H__
#define __PAWN_H__

#include "piece.h"


class Pawn : public Piece  {

    int     m_bMovement;

    public:

    Pawn( Color color, BoardVision *boardVision );
    ~Pawn( void );

    virtual void Movement ( void );
    virtual bool Check( int src_row, int src_col, int dst_row, int dst_col );
    virtual char Print( void );
};

#endif // __PAWN_H__