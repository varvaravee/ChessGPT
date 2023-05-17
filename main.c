#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>


#include "boardConstants.h"
#include "pawn.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"
#include "queen.h"
#include "king.h"
#include "isKingChecked.h"

#include "moveAI.h"


//display main menu and prompt user for choice of side

int main()
{
        CHESSB c;

        EmptyChessBoard(c);

        DefaultChessBoard(c);

        DisplayChessBoardWhite(c);
                                        //DisplayChessBoardBlack(c);
                                        //

        printf("\nWelcome to ChessGPT! The world's smartest and funniest chess program!\n");
        printf("************************************************************************\n\n");
        //prototypes

        //void mainMenu();


        //calls mainMenu
        //mainMenu();

        //***Function***

        //mainMenu function
        //int mainMenu()
        {
                int choice=0;
                //do while loop that presents menu until exit of application
                while (choice!=3) {
                        printf("Please make a selection from the main menu below.\n\n");
                        printf("1. Start a game!\n");
                        printf("2. Tell a joke.\n");
                        printf("3. Exit program :( \n");

                        scanf(" %d", &choice);

                        //validate input and start game if input is 1
                        if (choice == 1)
                        {
                                int playerSide;
                                int turn = 0;
                                printf("\nGreat choice! Please select your preferences for the color ");
                                printf("of your pieces.\n");
                                printf("Input 0 for white pieces or 1 for black pieces. White pieces move first.\n");               

                                scanf(" %d", &playerSide);
                                //assign playerside to turn and board side

                                if (playerSide==0)
                                {

                                        while (turn==playerSide){
                                                DisplayChessBoardWhite(c);

                                                if (isKingChecked(c,turn)==1){
                                                        if (isCheckMate(c,turn)==0){
                                                                printf("Your king is in check, please get your king out of check.\n\n");
                                                        }
                                                        else {
                                                                printf("You have been checkmated, white side loses. Better luck next time!\n\n");
                                                                DeleteChessBoard(c);
                                                                return 0;
                                                        }
                                                }
                                                else{
                                                int x1, y1, x2, y2;
                                                //checks if the move is within the board and if there's a piece at x1,y1
                                                //if the input is not 2 characters or is not within bounds or there's no piece at the input, then
                                                // give an error message, clear the input, and re loop
                                                printf("Enter the location of the piece you want to move as two numbers (beginning with 0) separated by a comma (x1,y1): ");
                                                if (scanf("%d,%d", &x1, &y1) != 2 || x1 < 0 || x1 > 7 || y1 < 0 || y1 > 7 || !c[x1][y1]) {
                                                        printf("Please try again. Position not found.\n");
                                                        while (getchar() != '\n'); // Clear input buffer
                                                        continue;
                                                }

                                                //checks to see if the user chooses the right color
                                                if (c[x1][y1] && c[x1][y1]->Color == !turn){
                                                        printf("Wrong color chosen.\n");
                                                        while (getchar() != '\n'); // Clear input buffer
                                                        continue;
                                                }

                                                //if the color is correct, ask for the new position x2,y2
                                                //        //same condition as x1,y1 + if there's a piece at x2,y2 we need to check its color
                                                //                //if the color is the same ask user for a new move, if the color is different allow move (capture)
                                                if (c[x1][y1] && c[x1][y1]->Color == turn) {
                                                        printf("Enter the location of where you would like to move your piece as two numbers separated by a comma (x2,y2): ");
                                                        if (scanf("%d,%d", &x2, &y2) != 2 || x2 < 0 || x2 > 7 || y2 < 0 || y2 > 7 ||
                                                                (c[x2][y2] && c[x1][y1]->Color == c[x2][y2]->Color)) {
                                                                printf("Please try again. Position not found.\n");
                                                                while (getchar() != '\n'); // Clear input buffer
                                                                continue;
                                                        }
                                                }

                                                PIECE *p = c[x1][y1];

                                                // return value test variables
                                                int testTrue=1;
                                                int testFalse=0;
                                                if (p->Charac == 0){

                                                        //if pawn can move there by rules
                                                        if (MovePawn(c, x1, y1,x2, y2)==testTrue) {

                                                                //move pawn to new spot
                                                                MoveChessBoardPiece(c, x1, y1, x2, y2);

                                                                //if move does not put own king in check, change the turn to other color
                                                                if (isKingChecked(c,turn)==testFalse){

                                                                        turn = (turn ==0) ?1:0;


                                                                        }

                                                                //if the move does put the king in check, move piece back, and do not change the turn
                                                                else {
                                                                        printf("This move puts your king in check. Your piece will be moved back.\n\n");
                                                                        MoveChessBoardPiece(c, x2, y2, x1, y1);
                                                                }

                                                                }
                                                        else if(MovePawn(c,x1,y1,x2,y2) == 2)
                                                        {
                                                                        int R,T;
                                                                        char Pro;
                                                                        printf("Promote the pawn, type R , N , B , Q:  ");
                                                                        scanf(" %c", &Pro);
                                                                        printf("\n");
                                                                        if(Pro == 'R')
                                                                        {
                                                                            T = 1;
                                                                        }
                                                                         else if(Pro == 'N')
                                                                        {
                                                                             T = 2; 
                                                                        }
                                                                        else if(Pro == 'B')
                                                                        {
                                                                            T = 3;
                                                                        }
                                                                         else if(Pro == 'Q')
                                                                        {
                                                                            T = 5;
                                                                        }
                                                                        else{
                                                                                printf("Incorrect Input\n");
                                                                        }
                    
                                                                        PIECE *p;
                                                                        p = NewPiece(R,T);
                                                                        c[x2][y2] = p;
                                                                        DeleteChessBoardPiece(c,x1,y1);
                                                        }
                                                        else {
                                                                        printf("Please review the rules for moving a pawn and try again.\n");
                                                                }

                                                } else if (p->Charac == 1){

                                                        //if rook can move there by rules
                                                        if(MoveRook(c, x1, y1,x2, y2)==testTrue){

                                                                //move rook to new spot
                                                                MoveChessBoardPiece(c, x1, y1, x2, y2);

                                                                //if move does not put king in check, change turn to other color
                                                                if (isKingChecked(c,turn)==testFalse){
                                                                        turn = (turn ==0) ?1:0;

                                                                        }

                                                                //if move puts king in check, move piece back, dont change turn
                                                                else{
                                                                        printf("This move puts your king in check. Your piece will be moved back.\n\n");
                                                                        MoveChessBoardPiece(c, x2, y2, x1, y1);
                                                                }
                                                                }
                                                        else{
                                                                        printf("Please review the rules for moving a rook and try again.\n");
                                                                }



                                                } else if (p->Charac == 2){

                                                        //if knight can move there by rules
                                                        if(MoveKnight(c, x1, y1,x2, y2)==testTrue){

                                                                //move rook to new spot
                                                                MoveChessBoardPiece(c, x1, y1, x2, y2);

                                                                //if move does not put king in check, change turn to other color
                                                                if (isKingChecked(c,turn)==testFalse){
                                                                        turn = (turn ==0) ?1:0;

                                                                        }

                                                                //if move puts king in check, move piece back, dont change turn
                                                                else{
                                                                        printf("This move puts your king in check. Your piece will be moved back.\n\n");
                                                                        MoveChessBoardPiece(c, x2, y2, x1, y1);
                                                                }}
                                                        else{
                                                                        printf("Please review the rules for moving a rook and try again.\n");
                                                                }

                                                } else if (p->Charac == 3){

                                                        //if bishop can move there by rules
                                                        if(MoveBishop(c, x1, y1,x2, y2)==testTrue){

                                                                //move bishop to new spot
                                                                MoveChessBoardPiece(c, x1, y1, x2, y2);

                                                                //if move does not put king in check, change turn to other color
                                                                if (isKingChecked(c,turn)==testFalse){
                                                                        turn = (turn ==0) ?1:0;

                                                                        }

                                                                //if move puts king in check, move piece back, dont change turn
                                                                else{
                                                                        printf("This move puts your king in check. Your piece will be moved back.\n\n");
                                                                        MoveChessBoardPiece(c, x2, y2, x1, y1);
                                                                }}
                                                        else{
                                                                        printf("Please review the rules for moving a bishop and try again.\n");
                                                                }
                                                } else if (p->Charac == 5){

                                                        //if king can move there by rules
                                                        if(MoveKing(c, x1, y1,x2, y2,turn)==testTrue){

                                                                //move king to new spot
                                                                MoveChessBoardPiece(c, x1, y1, x2, y2);

                                                                //if move does not put king in check, change turn to other color
                                                                if (isKingChecked(c,turn)==testFalse){
                                                                        turn = (turn ==0) ?1:0;

                                                                        }

                                                                //if move puts king in check, move piece back, dont change turn
                                                                else{
                                                                        printf("This move puts your king in check. Your piece will be moved back.\n\n");
                                                                        MoveChessBoardPiece(c, x2, y2, x1, y1);
                                                                }}
                                                        else{
                                                                        printf("Please review the rules for moving a king and try again.\n");
                                                                }
                                                } else if (p->Charac == 4){

                                                        //if queen can move there by rules
                                                        if(MoveQueen(c, x1, y1,x2, y2)==testTrue){

                                                                //move queen to new spot
                                                                MoveChessBoardPiece(c, x1, y1, x2, y2);

                                                                //if move does not put king in check, change turn to other color
                                                                if (isKingChecked(c,turn)==testFalse){
                                                                        turn = (turn ==0) ?1:0;
                                                                        }

                                                                //if move puts king in check, move piece back, dont change turn
                                                                else{
                                                                        printf("This move puts your king in check. Your piece will be moved back.\n\n");
                                                                        MoveChessBoardPiece(c, x2, y2, x1, y1);
                                                                }}
                                                        else{
                                                                        printf("Please review the rules for moving a queen and try again.\n");
                                                                }

                                                }
                                                        DisplayChessBoardWhite(c);
                                                        // AI makes move
                                                        moveAI(c,turn);
                                                        turn = (turn ==0) ?1:0;

                                        }
                                }

                                }

                                else if (playerSide == 1)
                                {
                                        // AI makes move
                                        //moveAI(c);
                                        turn = (turn ==0) ?1:0;

                                        while (turn==playerSide){

                                                DisplayChessBoardWhite(c);
                                                if (isKingChecked(c,turn)==1){
                                                        if (isCheckMate(c,turn)==0){
                                                                printf("Your king is in check, please get your king out of check.\n\n");
                                                        }
                                                        else {
                                                                printf("You have been checkmated, black side loses. Better luck next time!\n\n");
                                                                DeleteChessBoard(c);
                                                                return 0;
                                                        }
                                                }
                                                else {

                                                int x1, y1, x2, y2;
                                                        //checks if the move is within the board and if there's a piece at x1,y1
                                                        //if the input is not 2 characters or is not within bounds or there's no piece at the input, then
                                                        //give an error message, clear the input, and re loop
                                                printf("Enter the location of the piece you want to move as two numbers(beginning with 0) separated by a comma (x1,y1): ");
                                                if (scanf("%d,%d", &x1, &y1) != 2 || x1 < 0 || x1 > 7 || y1 < 0 || y1 > 7 || !c[x1][y1]) {
                                                        printf("Please try again. Position not found.\n");
                                                        while (getchar() != '\n'); // Clear input buffer
                                                        continue;
                                                }

                                                //checks to see if the user chooses the right color
                                                if (c[x1][y1] && c[x1][y1]->Color == !turn){
                                                        printf("Wrong color chosen.\n");
                                                        while (getchar() != '\n'); // Clear input buffer
                                                        continue;
                                                }

                                                //if the color is correct, ask for the new position x2,y2
                                                //        //same condition as x1,y1 + if there's a piece at x2,y2 we need to check its color
                                                //                //if the color is the same ask user for a new move, if the color is different allow move (capture)
                                                if (c[x1][y1] && c[x1][y1]->Color == turn) {
                                                        printf("Enter the location of where you would like to move your piece as two numbers separated by a comma (x2,y2): ");
                                                        if (scanf("%d,%d", &x2, &y2) != 2 || x2 < 0 || x2 > 7 || y2 < 0 || y2 > 7 ||
                                                                (c[x2][y2] && c[x1][y1]->Color == c[x2][y2]->Color)) {
                                                                printf("Please try again. Position not found.\n");
                                                                while (getchar() != '\n'); // Clear input buffer
                                                                continue;
                                                        }
                                                }

                                                PIECE *p = c[x1][y1];

                                                // return value test variables
                                                int testTrue=1;
                                                int testFalse=0;
                                                if (p->Charac == 0){

                                                        //if pawn can move there by rules
                                                        if (MovePawn(c, x1, y1,x2, y2)==testTrue) {

                                                                //move pawn to new spot
                                                                MoveChessBoardPiece(c, x1, y1, x2, y2);

                                                                //if move does not put own king in check, change the turn to other color
                                                                if (isKingChecked(c,turn)==testFalse){

                                                                        turn = (turn ==0) ?1:0;

                                                                        }

                                                                //if the move does put the king in check, move piece back, and do not change the turn
                                                                else {
                                                                        printf("This move puts your king in check. Your piece will be moved back.\n\n");
                                                                        MoveChessBoardPiece(c, x2, y2, x1, y1);
                                                                }}
                                                        else {
                                                                        printf("Please review the rules for moving a pawn and try again.\n");
                                                                }

                                                } else if (p->Charac == 1){

                                                        //if rook can move there by rules
                                                        if(MoveRook(c, x1, y1,x2, y2)==testTrue){

                                                                //move rook to new spot
                                                                MoveChessBoardPiece(c, x1, y1, x2, y2);

                                                                //if move does not put king in check, change turn to other color
                                                                if (isKingChecked(c,turn)==testFalse){
                                                                        turn = (turn ==0) ?1:0;

                                                                        }

                                                                //if move puts king in check, move piece back, dont change turn
                                                                else{
                                                                        printf("This move puts your king in check. Your piece will be moved back.\n\n");
                                                                        MoveChessBoardPiece(c, x2, y2, x1, y1);
                                                                }}
                                                        else{
                                                                        printf("Please review the rules for moving a rook and try again.\n");
                                                                }

                                                } else if (p->Charac == 2){

                                                        //if knight can move there by rules
                                                        if(MoveKnight(c, x1, y1,x2, y2)==testTrue){

                                                                //move rook to new spot
                                                                MoveChessBoardPiece(c, x1, y1, x2, y2);

                                                                //if move does not put king in check, change turn to other color
                                                                if (isKingChecked(c,turn)==testFalse){
                                                                        turn = (turn ==0) ?1:0;

                                                                        }

                                                                //if move puts king in check, move piece back, dont change turn
                                                                else{
                                                                        printf("This move puts your king in check. Your piece will be moved back.\n\n");
                                                                        MoveChessBoardPiece(c, x2, y2, x1, y1);
                                                                }}
                                                        else{
                                                                        printf("Please review the rules for moving a rook and try again.\n");
                                                                }



                                                } else if (p->Charac == 3){

                                                        //if bishop can move there by rules
                                                        if(MoveBishop(c, x1, y1,x2, y2)==testTrue){

                                                                //move bishop to new spot
                                                                MoveChessBoardPiece(c, x1, y1, x2, y2);

                                                                //if move does not put king in check, change turn to other color
                                                                if (isKingChecked(c,turn)==testFalse){
                                                                        turn = (turn ==0) ?1:0;

                                                                        }

                                                                //if move puts king in check, move piece back, dont change turn
                                                                else{
                                                                        printf("This move puts your king in check. Your piece will be moved back.\n\n");
                                                                        MoveChessBoardPiece(c, x2, y2, x1, y1);
                                                                }}
                                                        else{
                                                                        printf("Please review the rules for moving a bishop and try again.\n");
                                                                }
                                                } else if (p->Charac == 5){

                                                        //if king can move there by rules
                                                        if(MoveKing(c, x1, y1,x2, y2,turn)==testTrue){

                                                                //move king to new spot
                                                                MoveChessBoardPiece(c, x1, y1, x2, y2);

                                                                //if move does not put king in check, change turn to other color
                                                                if (isKingChecked(c,turn)==testFalse){
                                                                        turn = (turn ==0) ?1:0;
                                                                        }

                                                                //if move puts king in check, move piece back, dont change turn
                                                                else{
                                                                        printf("This move puts your king in check. Your piece will be moved back.\n\n");
                                                                        MoveChessBoardPiece(c, x2, y2, x1, y1);
                                                                }}
                                                        else{
                                                                        printf("Please review the rules for moving a king and try again.\n");
                                                                }
                                                } else if (p->Charac == 4){

                                                        //if queen can move there by rules
                                                    if(MoveQueen(c, x1, y1,x2, y2)==testTrue)
                {

                                                                //move queen to new spot
                                                                MoveChessBoardPiece(c, x1, y1, x2, y2);
                }

                                                                //if move does not put king in check, change turn to other color
                                                                if (isKingChecked(c,turn)==testFalse){
                                                                        turn = (turn ==0) ?1:0;

                                                                        }

                                                                //if move puts king in check, move piece back, dont change turn
                                                                else{
                                                                        printf("This move puts your king in check. Your piece will be moved back.\n\n");
                                                                        MoveChessBoardPiece(c, x2, y2, x1, y1);
                                                                }}
                                                        else{
                                                                printf("Please review the rules for moving a queen and try again.\n");
                                                        }
                                        }
                                        DisplayChessBoardWhite(c);
                                        // AI makes move
                                        //moveAI(c);
                                        turn = (turn ==0) ?1:0;


                                }
                        }

                                else
                                {
                                        printf("\nOops! That is not a valid selection. Please enter a 0 or 1.\n\n");
                                        scanf(" %d", &playerSide);
                                }




                        }

                        else if (choice == 2)
                        {
                                printf("Knock knock!\n");
                                printf("Who's there?\n");
                                printf("Your mom!\n");
                                printf("Ok go play some chess now.\n");
                        }

                        else if (choice == 3)
                        {

                                printf("Thanks for playing! Have a great day!\n");
                                printf("Exiting program.\n");
                        }

                        else
                        {
                                printf("\nYou have selected a wrong number. You will be returned to the main menu.\n");
                        }
                }
                return 1;

        }

        return 0;

}



