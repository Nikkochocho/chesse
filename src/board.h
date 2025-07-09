#ifndef __BOARD_H__
#define __BOARD_H__

#include "iboard.h"
#include <array>

typedef std :: array< std :: array<IPiece*, MAX_COLS>, MAX_ROWS> ArrayBoard;


class Board : public IBoard  {

    ArrayBoard    m_board;


    void    Clear( void );

    public:

    Board( void );
    virtual ~Board( void );

    bool IsValid( int col, int row );
    IPiece* GetPromotion( Pieces piece, Color color );
    IPiece* GetPiece( int dst_c, int dst_r );
    void SetPiece( int col, int row, IPiece *piece );
    void RemovePiece( int col, int row );
    void Init( void );
};

#endif  // __BOARD_H__