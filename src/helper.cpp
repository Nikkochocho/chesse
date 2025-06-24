#include "helper.h"

Pieces Conversion( char promotion )  {

    Pieces piece_type;

    switch ( promotion )  {

        case 'Q': 
            piece_type = QUEEN; 
            break; 

        case 'B': 
            piece_type = BISHOP; 
            break;

        case 'N': 
            piece_type = KNIGHT; 
            break;

        case 'R':
            piece_type = ROOK; 
            break;

        default:
            piece_type = UNSET;
            break;
    }

    return piece_type;
}