#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>


#include "isKingChecked.h"

int isKingChecked(CHESSB c,int turn) {
    int returnValue=0; //default value for isKingChecked is 0=false

    int kingX, kingY;

    int otherTeamColor = turn == 0 ? 1 : 0;

    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            PIECE *p = c[x][y];
           
            if (p && p->Charac == 4 && p->Color == turn) {
                kingX = x;
                kingY = y;
                //king = p;
                break;
            }
        }
    }

  
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            PIECE *p = c[x][y];
            if (p && p->Color == otherTeamColor) {
               
                switch (p->Charac) {
                    case 0:  // pawn
                        if ((p->Color == 0 && x == kingX - 1 && y == kingY - 1) || (p->Color == 0 && x == kingX + 1 && y == kingY - 1) ||
                            (p->Color == 1 && x == kingX - 1 && y == kingY + 1) || (p->Color == 1 && x == kingX + 1 && y == kingY + 1)) {
                                returnValue=1;

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
                                returnValue=1;

                            }
                        }
                    case 2:  // knight
                        if ((abs(x - kingX) == 2 && abs(y - kingY) == 1) ||
                            (abs(x - kingX) == 1 && abs(y - kingY) == 2)) {
                            returnValue=1;

                        }
                    case 3:  // bishop
                        if (abs(x - kingX) == abs(y - kingY)) {
                            int xAxis = x > kingX ? -1 : 1;
                            int yAxis = y > kingY ? -1 : 1;
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
                                returnValue=1;

                            }
                        }
                    case 5:  // king
                        if ((abs(x - kingX) <= 1 && abs(y - kingY) <= 1) && !(x == kingX && y == kingY)) {
                            returnValue=1;

                        }
                    case 4:  // queen
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
                                    returnValue=1;

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
                                    returnValue=1;

                                }
                            }
                        }
                    }
                }
            }
        }
        return returnValue;
}
