#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "boardConstants.h"

PIECE *NewPiece(int Color, int Charac){
    PIECE *p;
    p=malloc(sizeof(PIECE));
    if(!p){
        perror("Out of memory\n");
        exit(10);
    }
    p->Color=Color;
    p->Charac=Charac;
    return p;
}

/*void PrintPiece(PIECE *p){
        if(!p){
            printf("The piece is empty.\n");
        }
        else{
        char ColorList[2][10]={"White","Black"};
    //    char CharacterList[6][10]={"Pawn","Rook","Knight","Bishop","King","Queen"};
    //    printf("Pcolor is %s; ",ColorList[p->Color]);
    //    printf("Pcharac is %s.\n",CharacterList[p->Charac]);
        }
}*/

void DeletePiece(PIECE *p){
    assert(p);
    free(p);
}

void DeleteChessBoardPiece(CHESSB c, int x, int y){
        assert(c[x][y]);
        PIECE *p;
        p=c[x][y];
        c[x][y]=NULL;
        DeletePiece(p);
}

void MoveChessBoardPiece(CHESSB c, int x1, int y1, int x2, int y2){
        assert(c[x1][y1]);
        PIECE *p;
        p=c[x1][y1];
        c[x1][y1]=NULL;
        if(c[x2][y2]){
                DeleteChessBoardPiece(c,x2,y2);
        }
        c[x2][y2]=p;
}

/*
int value(CHESSB c, int x1, int y1, int x2, int y2)
{
    
    int value = 0;
    
    switch(c[x1][y1])
    case King
        value = 30;
        break;
    case Queen
        value = 25;
        break;
    case Rook
        value = 20;
        break;
    case Bishop
        value = 15;
        break;
    case Knight
        value = 10;
        break;
    case Pawn
        value = 5;
        break;
}
*/
/*
int ai_move(CHESSB c, int x, int y)
{
    int i;
    int j;
    
    for(int y=0;y<8;y++)
    {
        for(int x=0;x<8;x++)
        {
                    
        }
                
    }
    
}*/