#ifndef __IPIECE_H__
#define __IPIECE_H__

#include "defs.h"


class IPiece  {

    public:

    virtual int GetMovementCount( void ) = 0;
    virtual void SetMovementCount( void ) = 0;
    virtual bool CanSet( IPiece *target ) = 0;
    virtual bool CanMove( int dst_col, int dst_row ) = 0;
    virtual bool KingCheck( void ) = 0;

    virtual void Print( void ) = 0;
    
    virtual Pieces GetType( void ) = 0;
    virtual Color GetColor( void ) = 0;
    virtual Status GetStatus( void ) = 0;
    virtual void SetStatus( Status state ) = 0;
    virtual stPosition& Position( void ) = 0;
};

#endif // __IPIECE_H__