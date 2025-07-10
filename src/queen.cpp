/*
 * chesse
 * Copyright (C) 2025  Lara H. Ferreira.
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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

bool Queen :: MovementCheck( bool king_check )  {

    stPosition MainposAsc, MainposDesc, SecposAsc, SecposDesc;
    MainposAsc =  MainposDesc = SecposAsc = SecposDesc = m_position;

    CalcDiagonals( MainposAsc, MainposDesc, true, king_check ); //main diagonal
    CalcDiagonals( SecposAsc, SecposDesc, false, king_check ); //secondary diagonal

    return ( ( CanReach( 7, m_position.row, king_check ) || CanReach( 0, m_position.row, king_check ) ) ||
             ( CanReach( m_position.col, 7, king_check ) || CanReach( m_position.col, 0, king_check ) ) ||
             ( CanReach( MainposAsc.col, MainposAsc.row, king_check ) || CanReach( MainposDesc.col, MainposDesc.row, king_check ) ) ||
             ( CanReach( SecposAsc.col, SecposAsc.row, king_check ) || CanReach( SecposDesc.col, SecposDesc.row, king_check ) ) );
}

// LCOV_EXCL_START
void Queen :: Print( void )  {

    std :: cout << 'Q';
}
// LCOV_EXCL_STOP