#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "boardConstants.h"
#include "queen.h"

int MoveQueen(CHESSB c, int x1, int y1, int x2, int y2) {

    int returnValue=1;
    int x, y;
    int move;
    // check if move is valid
    if (x1 != x2 && y1 != y2 && abs(x1-x2) != abs(y1-y2)) {
        printf("Invalid move. The Queen can only move diagonally, horizontally, or vertically.\n");
        returnValue=0;
    } else if (x1 == x2) { // move vertical
        int yAxis = (y2 > y1) ? 1 : -1;
        x = x1;
        y = y1 + yAxis;
        while (y != y2) {
            if (c[x][y]) {
                printf("Invalid move. There are pieces in the way.\n");
                returnValue=0;
            }
            y += yAxis;
        }
    } else if (y1 == y2) { // move horizontal
        int xAxis = (x2 > x1) ? 1 : -1;
        x = x1 + xAxis;
        y = y1;
        while (x != x2) {
            if (c[x][y]) {
                printf("Invalid move. There are pieces in the way.\n");
                returnValue=0;
            }
            x += xAxis;
        }
    } else { // check diagonal for pieces
        int xAxis = (x1 < x2) ? 1 : -1;
        int yAxis = (y1 < y2) ? 1 : -1;
        x = x1 + xAxis;
        y = y1 + yAxis;
        while(x != x2 && y != y2) {
            if(c[x][y]){
                printf("Invalid move. There are pieces in the way.\n");
                returnValue=0;
            }
            x += xAxis;
            y += yAxis;
        }
    }
    // if the space is empty or is a different color, move
    if (!c[x2][y2] || c[x2][y2]->Color != c[x1][y1]->Color) {
        returnValue = 1;
        move=1;
    }
    return returnValue;
}

