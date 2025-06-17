#ifndef __PIECE_H__
#define __PIECE_H__

#include "iboard.h"


class Piece : public IPiece  {

    protected:
    
    int         m_MovementCount = 0;
    stPosition  m_position;
    Pieces      m_type;
    Color       m_color;
    Status      m_state = NORMAL;
    IBoard      *m_BoardVision;

    public:

    void Movement( void );
    int GetMovementCount( void );
    bool CanMove( IPiece *target );
    bool IsFree( int dst_col, int dst_row );
    virtual bool Check( int dst_col, int dst_row );
    virtual bool CheckVision( void );

    virtual void Print( void );
   
    stPosition& Position( void );
    Color GetColor( void );
    Pieces GetType( void );
    Status GetStatus( void );
    void SetStatus( Status state );
};

#endif // __PIECE_H__