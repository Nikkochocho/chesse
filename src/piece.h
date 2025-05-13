#ifndef __PIECE_H__
#define __PIECE_H__

#include "iboard.h"


class Piece : public IPiece  {

    protected:
    
    int         m_MovementCount = 0;
    Pieces      m_type;
    Color       m_color;
    Status      m_state = NORMAL;
    IBoard      *m_BoardVision;

    public:

    void Movement( void );
    int GetMovementCount( void );
    bool CanMove( IPiece *target );
    bool IsFree( int src_col, int src_row, int dst_col, int dst_row );
    virtual bool Check( int src_col, int src_row, int dst_col, int dst_row );

    virtual void Print( void );

    Color GetColor( void );
    Pieces GetType( void );
    Status GetStatus( void );
    void SetStatus( Status state );
};

#endif // __PIECE_H__