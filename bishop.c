#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "boardConstants.h"
#include "bishop.h"

int MoveBishop(CHESSB c, int x1, int y1, int x2, int y2) {

     int returnValue=1;
     int X,Y;
    // Check if the move is diagonal
    if (abs(x2 - x1) != abs(y2 - y1)){
        printf("This is not a diagonal move.\n");
        returnValue = 0;
        return returnValue;
    }
    else if ((c[x1][y1]->Charac == 3) && ((c[x1][y1]->Color == 0)||(c[x1][y1]->Color == 1)))
    {
        
        if(y2 > y1)
        {
            if(x2 > x1)
            {
                X = x1 + 1;
                Y = y1 + 1;
                for(int i = x1; i < x2; i++)
                {
                    if(c[X][Y]){
                            if((X != x2) && (Y != y2))
                            {
                                returnValue = 0;
                                return returnValue; 
                            }
                        
                    }
                    X++;
                    Y++;
                }
                returnValue = 1;
                return returnValue;
            }
            else if(x2 < x1)
            {
                X = x1 - 1;
                Y = y1 + 1;
                for(int i = x2; i < x1; i++)
                {
                    if(c[X][Y]){
                         if((X != x2) && (Y != y2))
                            {
                                returnValue = 0;
                                return returnValue; 
                            }
                    }
                    X--;
                    Y++;
                }
                returnValue = 1;
                return returnValue;
            }
        }
        else if(y1 > y2)
        {
         if(x2 > x1)
            {
                X = x1 + 1;
                Y = y1 - 1;
                for(int i = x1; i < x2; i++)
                {
                    if(c[X][Y]){
                        if((X != x2) && (Y != y2))
                            {
                                returnValue = 0;
                                return returnValue; 
                            }
                    }
                    X++;
                    Y--;
                }
                returnValue = 1;
                return returnValue;
            }
            else if(x2 < x1)
            {
                X = x1 - 1;
                Y = y1 + 1;
                for(int i = x2; i < x1; i++)
                {
                    if(c[X][Y]){
                        if((X != x2) && (Y != y2))
                            {
                                returnValue = 0;
                                return returnValue; 
                            }
                    }
                    X--;
                    Y--;
                }
                returnValue = 1;
                return returnValue;
            }
            
            
           
        }
    }
}
