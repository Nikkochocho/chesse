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

        return IsFree( dst_col, dst_row );
    }

    return false;
}

bool Bishop :: KingCheck( void )  {

    stPosition MainposAsc, MainposDesc, SecposAsc, SecposDesc;

    MainposAsc =  MainposDesc = SecposAsc = SecposDesc = m_position;

    CalcDiagonals( MainposAsc, MainposDesc, true ); //main diagonal
    CalcDiagonals( SecposAsc, SecposDesc, false ); //secondary diagonal

    return ( ( IsFree( MainposAsc.col, MainposAsc.row, true ) || IsFree( MainposDesc.col, MainposDesc.row, true ) ) ||
             ( IsFree( SecposAsc.col, SecposAsc.row, true ) || IsFree( SecposDesc.col, SecposDesc.row, true ) ) );
}

void Bishop :: Print( void )  {

    std :: cout << 'B';
}