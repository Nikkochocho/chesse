#ifndef __IPIECE_H__
#define __IPIECE_H__

#include "defs.h"


class IPiece  {

    public:

    virtual void Movement( void ) = 0;
    virtual int GetMovementCount( void ) = 0;
    virtual bool CanMove( IPiece *target ) = 0;
    virtual bool IsFree( int src_col, int src_row, int dst_col, int dst_row ) = 0;
    virtual bool Check( int src_col, int src_row, int dst_col, int dst_row ) = 0;

    virtual void Print( void ) = 0;
    virtual Color GetColor( void ) = 0;
    virtual Pieces GetType( void ) = 0;
    virtual Status GetStatus( void ) = 0;
    virtual void SetStatus( Status state ) = 0;
};

#endif // __IPIECE_H__