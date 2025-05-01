#ifndef __PIECE_H__
#define __PIECE_H__

#include "boardvision.h"


class Piece : public IPiece  {

    protected:
    
    Color       m_color;
    BoardVision *m_BoardVision;

    public:

    virtual void Movement( void );
    virtual bool Check( int src_row, int src_col, int dst_row, int dst_col );

    virtual char Print( void );

    virtual Color GetColor( void );
};

#endif // __PIECE_H__