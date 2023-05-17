#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>


#include "pawn.h"
#include "boardConstants.h"

//int turn;

int MovePawn(CHESSB c, int x1, int y1, int x2, int y2){
        int returnValue = 1;


        if((c[x1][y1]->Charac == 0) && (c[x1][y1]->Color == 0))
        {
                if((y1 == 6) && (y2 == 7))
                {
                    returnValue = 2;
                    return returnValue;
                }
                
                if(c[x1][x2])
                {
                    returnValue = 1;
                    return returnValue;
                }
                
                if((y2 == (y1+1)) && (x2==x1)){
                    returnValue = 1;
                    return returnValue;
                }
            
                if((c[x2][y2]->Color != 0) && ((x2 == x1 - 1) || (x2 == x1 + 1)) && (y2 == y1 + 1))
                {
                    returnValue = 1;
                    return returnValue;
                }

        }

        if((c[x1][y1]->Charac == 0) && (c[x1][y1]->Color == 1))
        {
                
                //move up 2
                if((y1 == 6) && (y2 == 7))
                {
                    returnValue = 2;
                    return returnValue;
                } 
                else if((y2 == (y1-2)) && c[x1][6] && (x2==x1) && !c[x1][y2+1]){
                    returnValue = 1;
                    return returnValue;
                }
                else if((y2 == (y1-1)) && (x2==x1)){
                    returnValue = 1;
                    return returnValue;
                }

        }

        returnValue = 0;
        return returnValue;
}

/*int MovePawnAI(CHESSB c, int x1, int y1){
        int returnValue;
        int max;

        if((c[x1][y1]->Charac == 0) && (c[x1][y1]->Color == 0))
        {

                //move up 2
                if(y1 == 6) 
                {
                    returnValue = 1; 
                    return returnValue;
                }
                
                if(c[x1+1][y1+1])
                {
                    if(c[x1+1][y1+1]->Heavy >= c[x1][y1]->Heavy)
                    {
                        
                    }
                        
                    
                }
                
                 if((y2 == (y1+1)) && (x2==x1)){
                    returnValue = 1;
                    return returnValue;
                }
            
                if((c[x2][y2]->Color != 0) && ((x2 == x1 - 1) || (x2 == x1 + 1)) && (y2 == y1 + 1))
                {
                    returnValue = 1;
                    return returnValue;
                }

        }

        if((c[x1][y1]->Charac == 0) && (c[x1][y1]->Color == 1))
        {
                
                //move up 2
                if((y1 == 6) && (y2 == 7))
                {
                    returnValue = 2;
                    return returnValue;
                } 
                else if((y2 == (y1-2)) && c[x1][6] && (x2==x1) && !c[x1][y2+1]){
                    returnValue = 1;
                    return returnValue;
                }
                else if((y2 == (y1-1)) && (x2==x1)){
                    returnValue = 1;
                    return returnValue;
                }

        }

        returnValue = 0;
        return returnValue;
}
*/
