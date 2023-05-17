#ifndef BOARDCONSTANTS_H
#define BOARDCONSTANTS_H

//extern int turn;
//static int move;

typedef struct Piece PIECE;

typedef PIECE *CHESSB[8][8];

struct Piece{
    int Color;
    int Charac;
    int Heavy;
};

PIECE *NewPiece(int Color, int Charac);

void PrintPiece(PIECE *p);

void DeletePiece(PIECE *p);

void PrintChessBoard(CHESSB c);

void EmptyChessBoard(CHESSB c);

void DefaultChessBoard(CHESSB c);

void DeleteChessBoardPiece(CHESSB c, int x, int y);

void DeleteChessBoard(CHESSB c);

void MoveChessBoardPiece(CHESSB c, int x1, int y1, int x2, int y2);

void DisplayChessBoardWhite(CHESSB c);

void DisplayChessBoardBlack(CHESSB c);

int isCheckMate(CHESSB c,int turn);

#endif