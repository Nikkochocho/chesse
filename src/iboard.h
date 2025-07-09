#ifndef __IBOARD_H__
#define __IBOARD_H__

#include "ipiece.h"


class IBoard  {

    public:

    virtual bool IsValid( int col, int row ) = 0;
    virtual IPiece* GetPromotion( Pieces piece, Color color ) = 0;
    virtual IPiece* GetPiece( int dst_c, int dst_r ) = 0;
    virtual void SetPiece( int col, int row, IPiece *piece ) = 0;
    virtual void RemovePiece( int col, int row ) = 0;
    virtual void Init( void ) = 0;
};

#endif // __IBOARD_H__