#ifndef __IBOARD_H__
#define __IBOARD_H__

#include "ipiece.h"


class IBoard  {

    public:

    virtual IPiece* GetPiece( int dst_r, int dst_c ) = 0;
    virtual void SetPiece( int row, int col, IPiece* piece ) = 0;
    virtual void Init( void ) = 0;
};

#endif // __IBOARD_H__