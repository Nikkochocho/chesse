#include <iostream>
#include "king.h"


King :: King( Color color, BoardVision *boardVision )  {

    this -> m_color = color;
    this -> m_BoardVision = boardVision;
}

King :: ~King( void )  {

    
}

void King :: Movement( void )  {

}

bool King :: Check( int src_row, int src_col, int dst_row, int dst_col )  {

    int         str_row = ( m_color == WHITE ) ? 0 : 7;
    int         str_col = 4;
    IPiece*     target = m_BoardVision -> GetPiece( dst_row, dst_col );
    bool        castling = ( ( dst_col - src_col == 2 ) || ( dst_col - src_col  == -3 ) );
    bool        ret = ( ( ( target == nullptr ) || ( target -> GetColor() != m_color ) ) &&
                        ( ( ( abs( dst_row - src_row ) <= 1 ) && ( abs( dst_col - src_col ) <= 1 ) ) ) &&
                        ( ( abs( dst_row - src_row ) == abs( dst_col - src_col ) ) || 
                          ( dst_row == src_row || dst_col == src_col ) ) );

    if ( castling && ( src_row == str_row ) && ( src_col == str_col ) && ( dst_row == src_row ) )  {

        IPiece* castle_room;

        for (int i = 0; i < ( abs( dst_col - src_col ) ); i++)  {

            castle_room = m_BoardVision -> GetPiece(src_row, (src_col + (i + 1)));

            if ( castle_room != nullptr ) break;
        }

        if ( castle_room == nullptr )  {

            IPiece* check_rook = m_BoardVision -> GetPiece( dst_row, ( dst_col + 1 ));
            bool    can_castle = ( ( m_color == check_rook -> GetColor() ) && ( check_rook -> Print() == 'R' ) );
            
            return can_castle;
        }
    }

    return ret;
}

char King :: Print( void )  {

    return 'K';
}
