#ifndef __BOARDVISION_H__
#define __BOARDVISION_H__

#include "ipiece.h"


class BoardVision  {

    public :

    virtual IPiece* GetPiece( int dst_r, int dst_c ) = 0;  
};

#endif // __BOARDVISION_H__