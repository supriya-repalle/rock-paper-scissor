#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int compute(int choice, int compchoice){
    int res;
    //CHOICE FOR ROCK

    if(choice==1){
        if(compchoice==1){
            res = 0;
        }else if(compchoice==2){
            res = -1;
        }else if(compchoice==3){
            res = 1;
        }
    }
    //CHOICE FOR PAPER
    else if(choice==2){
        if(compchoice==2){
            res = 0;
        }else if(compchoice==3){
            res = -1;
        }else if(compchoice==1){
            res = 1;
        }   
    }
    //CHOICE FOR SCISSOR
    else if(choice==3){
        if(compchoice==3){
            res = 0;
        }else if(compchoice==1){
            res = -1;
        }else if(compchoice==2){
            res = 1;
        }   
    }
    return res;
}

int main(){
    int choice, compchoice, res, Score_for_User=0, Score_for_Computer=0;

    srand(time(NULL));
    while(1){
    printf("\n\nRock-1\nPaper-2\nScissor-3\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    compchoice = rand()%3+1;
    printf("Computer choice:%d\n",compchoice);
    
    res = compute(choice, compchoice);
    

    if(res==0){
        printf("DRAW");
    }else if(res==1){
        printf("WINNER WINNER");
        Score_for_User=Score_for_User+1;
    }else if(res== -1){
        printf("LOSER !BETTER LUCK NEXT TIME");
        Score_for_Computer=Score_for_Computer+1;
    }

    printf("THE SCORE AT THE END OF THE GAME  FOR Computer : %d",Score_for_Computer);
    printf("THE SCORE AT THE END OF THE GAME  FOR USER : %d\n",Score_for_User);

    }

}