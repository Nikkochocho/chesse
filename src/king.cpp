#include <iostream>
#include "king.h"


King :: King( Color color, IBoard *boardVision )  {

    this -> m_type = KING;
    this -> m_color = color;
    this -> m_BoardVision = boardVision;
}

King :: ~King( void )  {

    
}

bool King :: Check( int src_row, int src_col, int dst_row, int dst_col )  {

    IPiece*     target = m_BoardVision -> GetPiece( dst_row, dst_col );
    bool        castling = ( ( dst_col - src_col == 2 ) || ( dst_col - src_col  == -3 ) );
    bool        ret = ( CanMove(target) && ( ( abs( dst_row - src_row ) <= 1 ) && ( abs( dst_col - src_col ) <= 1 ) ) &&
                        ( ( abs( dst_row - src_row ) == abs( dst_col - src_col ) ) || 
                          ( dst_row == src_row || dst_col == src_col ) ) );

    if ( castling && ( m_MovementCount == 0 ) && ( dst_row == src_row ) && ( IsFree( src_row, src_col, dst_row, dst_col ) ) )  {

        int     iterator = abs( dst_col - src_col ) == 2 ? 1 : -1;
        IPiece* castle_room = m_BoardVision -> GetPiece( src_row, ( dst_col + iterator ) );

        if ( IsFree( src_row, src_col, dst_row, dst_col) && ( castle_room -> GetType() == ROOK ) )  {

            return ( ( m_color == castle_room -> GetColor() ) && ( castle_room -> GetMovementCount() == 0) );
        }
    }

    return ret;
}

void King :: Print( void )  {

    std :: cout << 'K';
}
