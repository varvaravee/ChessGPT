//adding function for stalemate
//checks if stalemate


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "boardConstants.h"

int isCheckMate(CHESSB c,int turn)
{
        char returnValue=0;

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






        return returnValue;
}
