#ifndef __TEST_HELPER_H__
#define __TEST_HELPER_H__

#include "gameplay.h"


void LongCastleMove( GamePlay& game );
void ShortCastleMove( GamePlay& game );
void PromotionMove( GamePlay& game );
void PawnCheck( GamePlay& game );
void RookCheck( GamePlay& game );
void KnightCheck( GamePlay& game );
void BishopCheck( GamePlay& game );
void QueenCheck( GamePlay& game );
void Checkmate( GamePlay& game );

#endif // __TEST_HELPER_H__