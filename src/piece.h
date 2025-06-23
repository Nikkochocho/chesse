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

    void CalcDiagonals( stPosition& posAsc, stPosition& posDesc, bool diagonal );

    private:

    bool TrespassCheck( int dist_col, int dist_row, int itr_col, int itr_row, bool check );
    bool KingCheck( IPiece *target ) ;

    public:

    void Movement( void );
    int GetMovementCount( void );
    bool CanMove( IPiece *target );
    bool IsFree( int dst_col, int dst_row, bool check = false );
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