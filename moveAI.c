#include <stdio.h>
#include <assert.h>
#include "moveAI.h"
#include <stdlib.h>
#include <time.h>


void moveAI(CHESSB c,int turn)
{

        //var checks if AI moved
        int moveSuccess=0;
        int x2,y2,x1,y1;
        PIECE *p;
        while(moveSuccess==0)
        {
                
            for(int x = 0; x < 8; x++){
                    for (int y = 0; y < 8; y++)
                    {
                            x1 = x;
                            y1 = y;
                            printf("%d %d", x1 , y1);
                            
                            p=c[x1][y1];

                
            
                                if (c[x1][y1] && (c[x1][y1]->Color==turn))
                                {
                                    for(int x = 0; x < 8; x++)
                                    {
                                        for (int y = 0; y < 8; y++)
                                        {
                                                x2 = x;
                                                y2 = y;
                            
                                            if (p->Charac==0 )
                                            {
                                                if (MovePawn(c, x1, y1, x2, y2)==1)
                                                {
                                                 MoveChessBoardPiece(c, x1, y1, x2, y2);
                                                    if (isKingChecked(c,turn)==1)
                                                    {
                                                        MoveChessBoardPiece(c, x2, y2, x1, y1);
                                                    }
                                                    else moveSuccess=1;

                                                }
                                            }
                                            else if (p->Charac==1 )
                                            {
                        //      printf("(%d,%d) to ", x1, y1);
                        //      printf("(%d,%d)", x2, y2);


                                if (MoveRook(c, x1, y1, x2, y2)==1)
                                {
                                        MoveChessBoardPiece(c, x1, y1, x2, y2);
                                        if (isKingChecked(c,turn)==1)
                                        {
                                                MoveChessBoardPiece(c, x2, y2, x1, y1);
                                        }
                                        else
                                                moveSuccess=1;

                                }


                        }
                                            else if (p->Charac==2 )
                                            {
                        //      printf("(%d,%d) to ", x1, y1);
                        //      printf("(%d,%d)", x2, y2);


                                if (MoveKnight(c, x1, y1, x2, y2)==1)
                                {
                                        MoveChessBoardPiece(c, x1, y1, x2, y2);
                                        if (isKingChecked(c,turn)==1)
                                        {
                                                MoveChessBoardPiece(c, x2, y2, x1, y1);
                                        }
                                        else
                                                moveSuccess=1;

                                }


                        }
                                            else if (p->Charac==3 )
                                            {

                        //      printf("(%d,%d) to ", x1, y1);
                        //      printf("(%d,%d)", x2, y2);


                                if (MoveBishop(c, x1, y1, x2, y2)==1)
                                {
                                        MoveChessBoardPiece(c, x1, y1, x2, y2);
                                        if (isKingChecked(c,turn)==1)
                                        {
                                                MoveChessBoardPiece(c, x2, y2, x1, y1);
                                        }
                                        else
                                                moveSuccess=1;

                                }
                        }
                                            else if (p->Charac==5)
                                            {
                        //      printf("(%d,%d) to ", x1, y1);
                        //      printf("(%d,%d)", x2, y2);


                                if (MoveKing(c, x1, y1, x2, y2,turn) ==1)
                                {
                                        MoveChessBoardPiece(c, x1, y1, x2, y2);
                                        if (isKingChecked(c,turn)==1)
                                        {
                                                MoveChessBoardPiece(c, x2, y2, x1, y1);
                                        }
                                        else
                                                moveSuccess=1;

                                }


                        }
                                            else if (p->Charac==4 )
                                            {
                        //      printf("(%d,%d) to ", x1, y1);
                        //      printf("(%d,%d)", x2, y2);


                                if (MoveQueen(c, x1, y1, x2, y2)==1)
                                {
                                        MoveChessBoardPiece(c, x1, y1, x2, y2);
                                        if (isKingChecked(c,turn)==1)
                                        {
                                                MoveChessBoardPiece(c, x2, y2, x1, y1);
                                        }
                                        else
                                                moveSuccess=1;

                                }


                        }
                
                
                                        }
                                    }
                                }
                            }
        }
    moveSuccess = 0;    
    }
}
