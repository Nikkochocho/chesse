#include <iostream>
#include "bishop.h"


Bishop :: Bishop( Color color, IBoard *boardVision )  {

    this -> m_type        = BISHOP;
    this -> m_color       = color;
    this -> m_BoardVision = boardVision;
}

Bishop :: ~Bishop( void )  {

}

bool Bishop :: CanMove( int dst_col, int dst_row )  {

    if ( abs( dst_col - m_position.col ) == abs( dst_row - m_position.row ) )  {

        return CanReach( dst_col, dst_row );
    }

    return false;
}

bool Bishop :: MovementCheck( bool king_check )  {

    stPosition MainposAsc, MainposDesc, SecposAsc, SecposDesc;

    MainposAsc =  MainposDesc = SecposAsc = SecposDesc = m_position;

    CalcDiagonals( MainposAsc, MainposDesc, true, king_check ); //main diagonal
    CalcDiagonals( SecposAsc, SecposDesc, false, king_check ); //secondary diagonal

    return ( ( CanReach( MainposAsc.col, MainposAsc.row, king_check ) || CanReach( MainposDesc.col, MainposDesc.row, king_check ) ) ||
             ( CanReach( SecposAsc.col, SecposAsc.row, king_check ) || CanReach( SecposDesc.col, SecposDesc.row, king_check ) ) );
}

// LCOV_EXCL_START
void Bishop :: Print( void )  {

    std :: cout << 'B';
}
// LCOV_EXCL_STOP