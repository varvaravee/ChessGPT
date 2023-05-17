#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "boardConstants.h"
#include "rook.h"



int MoveRook(CHESSB c, int x1, int y1, int x2, int y2) 
{

    int returnValue=1;

// Check if the move is horizontal or vertical
    if (x1 != x2 && y1 != y2) {
        printf("Invalid move.\n");
        returnValue=0;
    }
    if ((c[x1][y1]->Charac == 1) && ((c[x1][y1]->Color == 0) || (c[x1][y1]->Color == 1)))
    {
        if (x2 == x1)
        {
         
            if(y2 > y1)
            {
                for(int y = y1+1; y <= y2; y++)
                {
                    if(c[x2][y])
                    {
                        if(y2 != y)
                        {
                            returnValue = 0;
                            return returnValue;
                        }
                    }

                }
                returnValue = 1;
                return returnValue;
            }
            else if(y2 < y1)
            {
                for(int y = y1-1; y >= y2; y--)
                {
                 
                    if(c[x2][y])
                    {
                        if(y2 != y)
                        {
                            returnValue = 0;
                            return returnValue;
                        }
                    }

                }
                returnValue = 1;
                return returnValue;
            }
            
        }
        if (y2 == y1)
        {
            if(x2 > x1)
            {
                for(int x = x1+1; x <= x2; x++)
                {
                    if(c[x][y2])
                    {
                        if(x2 != x)
                        {
                            returnValue = 0;
                            return returnValue;
                        }
                    }
                    
                }
                returnValue = 1;
                return returnValue;
            }
            else if(x2 < x1)
            {
                for(int x = x1-1; x >= x2; x--)
                {
                    if(c[x][y2])
                    {
                        if(x2 != x)
                        {
                            returnValue = 0;
                            return returnValue;
                        }
                    
                    }
                }
                returnValue = 1;
                return returnValue;
            }    
        }
    }
    /*
    else if((c[x1][y1]->Charac == 1) && (c[x1][y1]->Color == 1))
    {
        if (x2 == x1)
            {
         
                if(y2 > y1)
                {
                    for(int y = y1+1; y <= y2; y++)
                    {
                        if(c[x2][y])
                        {
                            if(y2 != y)
                            {
                                returnValue = 0;
                                return returnValue;
                            }
                        }

                    }
                returnValue = 1;
                return returnValue;
            }
            else if(y2 < y1)
            {
                for(int y = y1-1; y >= y2; y--)
                {
                 
                    if(c[x2][y])
                    {
                        if(y2 != y)
                        {
                            returnValue = 0;
                            return returnValue;
                        }
                    }

                }
                returnValue = 1;
                return returnValue;
            }
            
        }
        if (y2 == y1)
        {
            if(x2 > x1)
            {
                for(int x = x1+1; x <= x2; x++)
                {
                    if(c[x][y2])
                    {
                        if(x2 != x)
                        {
                            returnValue = 0;
                            return returnValue;
                        }
                    }
                    
                }
                returnValue = 1;
                return returnValue;
            }
            else if(x2 < x1)
            {
                for(int x = x1-1; x >= x2; x--)
                {
                    if(c[x][y2])
                    {
                        if(x2 != x)
                        {
                            returnValue = 0;
                            return returnValue;
                        }
                    
                    }
                }
                returnValue = 1;
                return returnValue;
            }    
        }
    
    }
    */
}
