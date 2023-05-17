#ifndef PIECES_H
#define PIECES_H
#include "boardConstants.h"

void PrintPiece(PIECE *p);
void DeletePiece(PIECE *p);
void DeleteChessBoardPiece(CHESSB c, int x, int y);
void MoveChessBoardPiece(CHESSB c, int x1, int y1, int x2, int y2);
int piece_value(CHESSB c, int x1, int y1, int x2, int y2);

#endif
