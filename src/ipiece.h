#ifndef __IPIECE_H__
#define __IPIECE_H__

#include "defs.h"


class IPiece  {

    public:

    virtual void Movement( void ) = 0;
    virtual bool Check( int src_row, int src_col, int dst_row, int dst_col ) = 0;

    virtual void Print( void ) = 0;
    virtual Color GetColor( void ) = 0;
};

#endif //__IPIECE_H__