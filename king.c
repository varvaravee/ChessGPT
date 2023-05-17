#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
//test
#include "boardConstants.h"
//#include "Castle.h"
#include "king.h"

//extern int turn;
int move;

int MoveKing(CHESSB c, int x1, int y1, int x2, int y2,int turn) {
    int returnValue=1;
    //assert(c[x1][y1]); // check if the source position has a piece
    PIECE *p = c[x1][y1];
    PIECE *wK = c[x1][y1];
    PIECE *bK = c[x1][y1];

    // check if the move is legal
    //side, up/down, diag
    if (!((abs(x2 - x1) == 1 && abs(y2 - y1) == 0) || (abs(x2 - x1) == 0 && abs(y2 - y1) == 1) || (abs(x2 - x1) == 1 && abs(y2 - y1) == 1))) {
        printf("Invalid Move.\n");
        returnValue=0;
    }
    if (!c[x2][y2] || c[x2][y2]->Color != c[x1][y1]->Color) {
        // Move the King
        if (p == c[4][0]) {
//            wK->pieceMoved = true;
        } else if (p == c[4][7]){
//            bK->pieceMoved = true;
        } else if (abs(x1 - x2) == 2){ //Castle
            turn = (turn == 0)?1:0;
            move = 1;
            //Castle(c, x1, y1, x2, y2);
        }

    }
    return returnValue;
}

/*
void isKingChecked(CHESSB c) {
    int kingX, kingY;
    //PIECE *king;
    int otherTeamColor = turn == 0 ? 1 : 0;
    // find location of king of current color
    // check all spots, if found break
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            PIECE *p = c[x][y];
            // if the king is found set the position to kingX and kingY
            if (p && p->Charac == 4 && p->Color == turn) {
                kingX = x;
                kingY = y;
                //king = p;
                break;
            }
        }
    }
    // check if any opposing piece can capture the king
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            PIECE *p = c[x][y];
            if (p && p->Color == otherTeamColor) {
                // check if piece has a valid move to king's square
                switch (p->Charac) {
                    case 0:  // pawn
                        if ((p->Color == 0 && x == kingX - 1 && y == kingY - 1) || (p->Color == 0 && x == kingX + 1 && y == kingY - 1) ||
                            (p->Color == 1 && x == kingX - 1 && y == kingY + 1) || (p->Color == 1 && x == kingX + 1 && y == kingY + 1)) {
                            printf("The king is checked! Move the king or another piece to get out of check!");
                            return;
                        }
                    case 1:  // rook
                        if (x == kingX || y == kingY) {
                            int xAxis = x > kingX ? -1 : 1; //move x direction
                            int yAxis = y > kingY ? -1 : 1; //move y direction
                            int i = x + xAxis;
                            int j = y + yAxis;
                            while (i != kingX || j != kingY) { //check for pieces in the way
                                if (c[i][j]) {
                                    break;
                                }
                                i += xAxis;
                                j += yAxis;
                            }
                            if (i == kingX && j == kingY) { // if there's no pieces
                                printf("The king is checked! Move the king or another piece to get out of check!");
                                return;
                            }
                        }
                    case 2:  // knight
                        if ((abs(x - kingX) == 2 && abs(y - kingY) == 1) ||
                            (abs(x - kingX) == 1 && abs(y - kingY) == 2)) {
                            printf("The king is checked! Move the king or another piece to get out of check!");
                            return;
                        }
                    case 3:  // bishop
                        if (abs(x - kingX) == abs(y - kingY)) {
                            int xAxis = x > kingX ? -1 : 1;
                            int yAxis = y > kingY ? -1 : 1;
                            int i = x + xAxis;
                            int j = y + yAxis;
                            //check for pieces in the way
                            while (i != kingX && j != kingY) {
                                if (c[i][j]) {
                                    break;
                                }
                                i += xAxis;
                                j += yAxis;
                            }
                            if (i == kingX && j == kingY) {
                                printf("The king is checked! Move the king or another piece to get out of check!");
                                return;
                            }
                        }
                    case 4:  // king
                        if ((abs(x - kingX) <= 1 && abs(y - kingY) <= 1) && !(x == kingX && y == kingY)) {
                            printf("The king is checked! Move the king or another piece to get out of check!");
                            return;
                        }
                    case 5:  // queen
                        if (x == kingX || y == kingY || abs(x - kingX) == abs(y - kingY)) { //check horizontal, vertical, diagonal
                            if (x == kingX || y == kingY) { // horizontal/vertical
                                int xAxis = x > kingX ? -1 : 1;
                                int yAxis = y > kingY ? -1 : 1;
                                int i = x + xAxis;
                                int j = y + yAxis;
                                while (i != kingX || j != kingY) {
                                    if (c[i][j]) {
                                        break;
                                    }
                                    i += xAxis;
                                    j += yAxis;
                                }
                                if (i == kingX && j == kingY) {
                                    printf("The king is checked! Move the king or another piece to get out of check!");
                                    return;
                                }
                            } else { // diagonal
                                int xAxis = x > kingX ? -1 : 1;
                                int yAxis = y > kingX ? -1 : 1;
                                int i = x + xAxis;
                                int j = y + yAxis;
                                while (i != kingX && j != kingY) {
                                    if (c[i][j]) {
                                        break;
                                    }
                                    i += xAxis;
                                    j += yAxis;
                                }
                                if (i == kingX && j == kingY) {
                                    printf("The king is checked! Move the king or another piece to get out of check!");
                                    return;
                                }
                            }
                        }
                    }
                }
            }
        }
    }*/