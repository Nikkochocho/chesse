#ifndef __DEFS_H__
#define __DEFS_H__

#define MAX_ROWS 8
#define MAX_COLS 8


enum Color {
    WHITE,
    BLACK
};

enum Player  {
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

enum Status  {
    NORMAL,
    LONGCASTLE,
    SHORTCASTLE,
    ENPASSANT,
    PROMOTION
};

#endif // __DEFS_H__