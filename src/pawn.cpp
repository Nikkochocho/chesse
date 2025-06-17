#include <iostream>
#include "pawn.h"


Pawn :: Pawn( Color color, IBoard *boardVision )  {
    
    this -> m_type = PAWN;
    this -> m_color = color;
    this -> m_BoardVision = boardVision;
}

Pawn :: ~Pawn( void )  {
    
}

bool Pawn :: Check( int src_col, int src_row, int dst_col, int dst_row )  {
    
    int         direction = ( m_color == WHITE ) ? 1 : -1;
    int         enpassant_row = ( m_color == WHITE ) ? 4 : 3;
    int         promotion_row = ( m_color == WHITE ) ? 7 : 0;
    IPiece      *target = m_BoardVision -> GetPiece( dst_col, dst_row );
    IPiece      *side_piece = m_BoardVision -> GetPiece( dst_col, dst_row + ( direction * -1 ) );
    bool        ret = ( ( target == nullptr ) &&
                        ( ( dst_col == src_col ) && ( dst_row == src_row + direction ) ) ); //default

    //first move
    if ( m_MovementCount == 0 )  { 

        ret = ( ( target == nullptr ) &&   
                ( ( dst_col == src_col && dst_row == src_row + direction ) ||
                  ( dst_col == src_col && dst_row == src_row + 2 * direction ) && ( side_piece == nullptr ) ) );
    }
    
    if ( dst_col != src_col )  { 

        if ( ( side_piece != nullptr ) && ( ( side_piece -> GetType() == PAWN ) && ( side_piece -> GetColor() != m_color ) ) && 
             ( target == nullptr ) && ( src_row == enpassant_row ) && ( side_piece -> GetMovementCount() == 1 ) )  {

            this -> SetStatus( ENPASSANT );
            return true; //en passant capture
        }  

        if ( ( target != nullptr ) && ( target -> GetColor() != m_color ) && 
            ( abs( dst_col -  src_col ) == 1 ) && ( dst_row == src_row + direction ) )  {

            target -> SetStatus( CAPTURED );
            ret = true; //capture
        }

    }

    if ( ( ret == true ) && ( dst_row == promotion_row ) )  {

        this -> SetStatus( PROMOTION );
    }

    return ret; 
}

bool Pawn :: CheckVision( int src_col, int src_row )  {

    int       direction = ( m_color == WHITE ) ? 1 : -1;
    int       col = 1;
    bool      ret = false;
    IPiece    *piece;

    for ( int i = 0; i < 2; i++ )  {

        piece = m_BoardVision -> GetPiece( ( src_col + col ), ( src_row + direction ) );

        if ( piece != nullptr && piece -> GetType() == KING && piece -> GetColor() != m_color )  {

            piece -> SetStatus( CHECK );
            ret = true;
            break;
        }

        col = -1;
    }

    return ret;
}

void Pawn :: Print( void )  {

    std :: cout << 'P';
}
