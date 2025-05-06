#include <iostream>
#include "king.h"


King :: King( Color color, IBoard *boardVision )  {

    this -> m_type = KING;
    this -> m_color = color;
    this -> m_BoardVision = boardVision;
}

King :: ~King( void )  {

    
}

bool King :: Check( int src_col, int src_row, int dst_col, int dst_row )  {

    IPiece*     target = m_BoardVision -> GetPiece( dst_col, dst_row );
    bool        castling = ( ( dst_col - src_col == 2 ) || ( dst_col - src_col  == -3 ) );
    bool        ret = ( CanMove(target) && ( ( abs( dst_row - src_row ) <= 1 ) && ( abs( dst_col - src_col ) <= 1 ) ) &&
                        ( ( abs( dst_row - src_row ) == abs( dst_col - src_col ) ) || 
                          ( dst_row == src_row || dst_col == src_col ) ) );

    if ( castling && ( m_MovementCount == 0 ) && ( dst_row == src_row ) && ( IsFree( src_col, src_row, dst_col, dst_row ) ) )  {

        int     iterator = abs( dst_col - src_col ) == 2 ? 1 : -1;
        IPiece* castle_room = m_BoardVision -> GetPiece( ( dst_col + iterator ), src_row );
        Status   castle_type = iterator == 1 ? SHORTCASTLE : LONGCASTLE;

        if ( IsFree( src_col, src_row, dst_col, dst_row ) && ( castle_room -> GetType() == ROOK ) )  {

            this -> SetStatus( castle_type );
            return ( ( m_color == castle_room -> GetColor() ) && ( castle_room -> GetMovementCount() == 0) );
        }
    }

    return ret;
}

void King :: Print( void )  {

    std :: cout << 'K';
}
