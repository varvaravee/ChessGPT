#include "boardConstants.h"
#include "knight.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

/*
void MoveKnight(CHESSB c, int x1, int y1, int x2, int y2)
{
                int x2x1 = x2 - x1;
                int y2y1 = y2 - y1;
                int cond = 0;
    
                if(x2x1 == 1 || x2x1 == -1)
                {
                    if(y2y1 == 2 || y2y1 == -2)
                    {
                        cond = 1;
  
                        MoveChessBoardPiece(c, x1, y1, x2, y2);
                        turn = (turn == 0) ? 1 : 0;
                    }
                }
                
                else if(x2x1 == 2 || x2x1 == -2)
                {
                    if(y2y1 == 1 || y2y1 == -1)
                    {
                        cond = 1;
                        
                        MoveChessBoardPiece(c, x1, y1, x2, y2);
                        turn = (turn == 0) ? 1 : 0;
                    }
                }
    
                if(cond == 0)
                {
                    printf("\nInvalid move\n");
                }
}*/

/*
int legalmove()
{
    switch(p->pieceType)
    {
        case Pawn:
            return MovePawn
            break;
        case Knight:
            return MoveKnight
            break;
        default:
            return 0;
            break;
    }
}*/

int MoveKnight(CHESSB c, int x1, int y1, int x2, int y2)
{
                int returnValue=1;
                int x2x1 = x2 - x1;
                int y2y1 = y2 - y1;
                int cond = 0;

                if(x2x1 == 1 || x2x1 == -1)
                {
                    if(y2y1 == 2 || y2y1 == -2)
                    {
                        cond = 1;

                        returnValue=1;
                    }
                }

                else if(x2x1 == 2 || x2x1 == -2)
                {
                    if(y2y1 == 1 || y2y1 == -1)
                    {
                        cond = 1;

                        returnValue=1;
                    }
                }

                if(cond == 0)
                {
                        returnValue=0;
                }

    return returnValue;
}


