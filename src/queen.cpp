#include <iostream>
#include "queen.h"


Queen :: Queen( Color color, IBoard *boardVision )  {

    this -> m_type        = QUEEN;
    this -> m_color       = color;
    this -> m_BoardVision = boardVision;
}

Queen :: ~Queen( void )  {

}

bool Queen :: CanMove( int dst_col, int dst_row )  {

    if ( ( abs( dst_col - m_position.col ) == abs( dst_row - m_position.row ) ) || 
         ( dst_col == m_position.col || dst_row == m_position.row ) )  {

        return CanReach( dst_col, dst_row );
    }

    return false;
}

bool Queen :: KingCheck( void )  {

    stPosition MainposAsc, MainposDesc, SecposAsc, SecposDesc;
    MainposAsc =  MainposDesc = SecposAsc = SecposDesc = m_position;

    CalcDiagonals( MainposAsc, MainposDesc, true ); //main diagonal
    CalcDiagonals( SecposAsc, SecposDesc, false ); //secondary diagonal

    return ( ( CanReach( 7, m_position.row, true ) || CanReach( 0, m_position.row, true ) ) ||
             ( CanReach( m_position.col, 7, true ) || CanReach( m_position.col, 0, true ) ) ||
             ( CanReach( MainposAsc.col, MainposAsc.row, true ) || CanReach( MainposDesc.col, MainposDesc.row, true ) ) ||
             ( CanReach( SecposAsc.col, SecposAsc.row, true ) || CanReach( SecposDesc.col, SecposDesc.row, true ) ) );
}

// LCOV_EXCL_START
void Queen :: Print( void )  {

    std :: cout << 'Q';
}
// LCOV_EXCL_STOP