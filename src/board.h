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

    void SetPiece( int row, int col, IPiece* piece );
    IPiece* GetPiece( int dst_r, int dst_c );
    void Init( void );
};

#endif  // __BOARD_H__