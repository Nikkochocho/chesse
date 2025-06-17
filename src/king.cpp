#include <iostream>
#include "king.h"


King :: King( Color color, IBoard *boardVision )  {

    this -> m_type = KING;
    this -> m_color = color;
    this -> m_BoardVision = boardVision;
}

King :: ~King( void )  {

    
}

bool King :: Check( int dst_col, int dst_row )  {

    IPiece      *target = m_BoardVision -> GetPiece( dst_col, dst_row );
    bool        castling = ( abs( dst_col - m_position.col ) == 2 );
    bool        ret = ( CanMove( target ) && ( ( abs( dst_col - m_position.col ) <= 1 ) && ( abs( dst_row - m_position.row ) <= 1 ) ) &&
                        ( ( abs( dst_col - m_position.col ) || abs( dst_row - m_position.row ) ) || 
                          ( dst_col == m_position.col || dst_row == m_position.row ) ) );

    if ( castling && ( m_MovementCount == 0 ) && ( dst_row == m_position.row ) && IsFree( dst_col, dst_row ) )  {

        int      rook_pos = ( dst_col - m_position.col == 2 ) ? 1 : -2;
        Status   castle_type = ( rook_pos == 1 ) ? SHORTCASTLE : LONGCASTLE;
        IPiece   *castle_room = m_BoardVision -> GetPiece( ( dst_col + rook_pos ), m_position.row );

        if ( ( target == nullptr ) && ( castle_room -> GetType() == ROOK ) )  {

            if ( castle_type == LONGCASTLE )  {

                IPiece   *between_castle = m_BoardVision -> GetPiece( ( dst_col - 1 ), m_position.row );

                if ( between_castle != nullptr )  {

                    return false;
                }
            }

            this -> SetStatus( castle_type );
            return ( ( m_color == castle_room -> GetColor() ) && ( castle_room -> GetMovementCount() == 0 ) );
        }
    }

    return ret;
}

void King :: Print( void )  {

    std :: cout << 'K';
}
