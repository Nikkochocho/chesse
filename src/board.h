#ifndef __BOARD_H__
#define __BOARD_H__

#include "iboard.h"
#include <array>

typedef std :: array<std :: array<IPiece*, MAX_COLS>, MAX_ROWS> ArrayBoard;


class Board : public IBoard  {

    ArrayBoard        m_board;

    
    void Clear( void );

    public:

    Board( void );
    virtual ~Board( void );

    IPiece* GetPromotion( Pieces piece, Color color );
    IPiece* GetPiece( int dst_r, int dst_c );
    void SetPiece( int row, int col, IPiece* piece );
    void Init( void );
};

#endif  // __BOARD_H__