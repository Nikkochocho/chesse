#ifndef __PIECE_H__
#define __PIECE_H__

#include "iboard.h"


class Piece : public IPiece  {

    protected:
    
    int         m_MovementCount = 0;
    Pieces      m_type;
    Color       m_color;
    IBoard *m_BoardVision;

    public:

    void Movement( void );
    int GetMovementCount( void );
    bool CanMove( IPiece* target );
    bool IsFree( int src_row, int src_col, int dst_row, int dst_col );
    virtual bool Check( int src_row, int src_col, int dst_row, int dst_col );

    virtual void Print( void );

    virtual Color GetColor( void );

    Pieces GetType( void );
};

#endif // __PIECE_H__