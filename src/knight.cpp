#include <iostream>
#include "knight.h"


Knight :: Knight( Color color, IBoard *boardVision )  {

    this -> m_type = KNIGHT;
    this -> m_color = color;
    this -> m_BoardVision = boardVision;
}

Knight :: ~Knight( void )  {

}

bool Knight :: Check( int src_col, int src_row, int dst_col, int dst_row )  {
    
    int         jump_r = abs( dst_row - src_row );
    int         jump_c = abs( dst_col - src_col );
    IPiece      *target = m_BoardVision -> GetPiece( dst_col, dst_row );
    bool        ret = ( ( jump_r == 1 && jump_c == 2 ) || ( jump_r == 2 && jump_c == 1 ) );

    if ( ret )  {

        return CanMove( target );
    }

    return ret;
}

bool Knight :: CheckVision( int src_col, int src_row )  {

    const int     col_number[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    const int     row_number[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    bool          ret = false;
    IPiece        *piece;

    for ( int i = 0; i < 8; i++ ) {

        piece = m_BoardVision -> GetPiece(( src_col + col_number[i] ), ( src_row + row_number[i] ) );

        if ( piece != nullptr && piece -> GetType() == KING && piece -> GetColor() != m_color )  {

            piece -> SetStatus( CHECK );
            ret = true;
            break;
        }
    }

    return ret;
}

void Knight :: Print( void )  {

    std :: cout << 'N';
}
