#ifndef __DEFS_H__
#define __DEFS_H__

#define MAX_COLS 8
#define MAX_ROWS 8


enum PlayerNumber  {

    PLAYER_1,
    PLAYER_2
};

enum Pieces  {

    KING,
    QUEEN,
    BISHOP,
    KNIGHT,
    ROOK,
    PAWN,
    UNSET
};

enum Color  {

    WHITE,
    BLACK
};

enum Status  {

    NORMAL,
    CAPTURED,
    LONGCASTLE,
    SHORTCASTLE,
    ENPASSANT,
    PROMOTION,
    CHECK
};

struct stPosition  {

    int         col;
    int         row;
};

#endif // __DEFS_H__