#ifndef __PIECE_H__
#define __PIECE_H__

#include "iboard.h"


class Piece : public IPiece  {

    protected:
    
    int         m_MovementCount = 0;
    stPosition  m_position;
    Color       m_color;
    Pieces      m_type;
    Status      m_state = NORMAL;
    IBoard      *m_BoardVision;

    
    void CalcDiagonals( stPosition& posAsc, stPosition& posDesc, bool diagonal );
    bool IsFree( int dst_col, int dst_row, bool check = false );

    private:

    bool TrespassCheck( int dist_col, int dist_row, int itr_col, int itr_row, bool check );
    bool IsOpponentKing( IPiece *target ) ;

    public:

    int GetMovementCount( void );
    void SetMovementCount( void );
    bool CanSet( IPiece *target );

    virtual bool CanMove( int dst_col, int dst_row );
    virtual bool KingCheck( void );
    virtual void Print( void );
   
    Pieces GetType( void );
    Color GetColor( void );
    Status GetStatus( void );
    void SetStatus( Status state );
    stPosition& Position( void );
};

#endif // __PIECE_H__