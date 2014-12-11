/* Copyright 2014-2015        *
 * coded by Kevin Wiederstein */

#include <stdio.h>
#include <stdlib.h>

/* DICHIARAZIONE VARIABILI */
	/* esercizio 1 */
	#define RATE_DIM 12
	const double interestRates[RATE_DIM] = {0.2,-0.6,0.3,0.6,-0.4,0.1,0.5,-0.85,-0.7,0.2,0.1,0.0};
	double credito=4500,interesse=2.5;
	int i;
	/* esercizio 2 */
	#define SHALLOW_DIM 4
    #define COURSE_DIM  5
	const int shallowsX[SHALLOW_DIM] = { 3 , 1 , 2 , 0 };
	const int shallowsY[SHALLOW_DIM] = { 0 , 1 , 3 , 4 };
	const int courseY[COURSE_DIM]    = { 0 , 1 , 2 , 3 , 4};
    int courseX[COURSE_DIM];
    int randSeed,j;
    int flag[2]={-1,-1};
	/* esercizio 3 */
	#define DUNGEON_DIM 	10
	const char tiles[DUNGEON_DIM]	     = {'n','s','n','s','e','t','n','n','e','d'};
	const int effects[DUNGEON_DIM] 	     = { 0 , 3 , 0 , 3 , 3 , 0 , 0 , 0 , 6 , 3 };
    int playerPosition[2]                = { 0 , 0 };
    int movRand = 0,Rand = 0,RandEnemy = 0,RandOpponent = 0,RandUnlock = 0,RandLock = 0,turn=0,exitDungeon = 1;
/* ####################### */

void bankAccount();
void boatCourse();
void dungeon();
void dungeon_do(char,int,int);

int main(){
	int choose;
	printf("Choose the part to execute:\n\t1 \t: Part 1 (Bank Account)\n\t2 \t: Part 2 (Boat course)\n\t3 \t: Part 3 (Dungeon)\n\tother \t: Exit\n\n");
	scanf("%d",&choose);
	if(choose==1){
		bankAccount();
	}else if(choose==2){
		boatCourse();
	}else if(choose==3){
		dungeon();
	}
	return 0;
}

/* (Bank Account) */
void bankAccount(){
	for(i=0;i<RATE_DIM;i++){
		interesse = interesse + interestRates[i];
		credito = credito + ((credito*interesse)/100);
		printf("Month %d balance is %f\n",i,credito);
	}
}

/* (Boat Course) */
void boatCourse(){
printf("Insert the random generator seed\n");
    scanf("%d",&randSeed);
    srand(randSeed);
    printf("Boat course:\n");
    for(j=0;j<COURSE_DIM;j++){
        courseX[j] = 0 + rand() % 5;
        if(shallowsX[j] == courseX[j] && shallowsY[j] == courseY[j]){flag[0]=shallowsX[j];flag[1]=shallowsY[j];}
        printf("(%d,%d)\n",courseX[j],courseY[j]);}
    printf("Shallows:\n");
    for(j=0;j<SHALLOW_DIM;j++){printf("(%d,%d)\n",shallowsY[j],shallowsX[j]);}
    if(flag[0] != -1 && flag[1] != -1){
        printf("The boat will run ashore at (%d,%d)\n",flag[0],flag[1]);
    }else{printf("The boat course is valid\n");}
}

/* (Dungeon) */
void dungeon(){
    printf("Insert the random generator seed\n");
    scanf("%d",&randSeed);
    srand(randSeed);
    /* start game */
    while(exitDungeon){
        movRand = (1 + rand() % 3);
        playerPosition[turn] = playerPosition[turn] + movRand;
        printf("Player %d moving by %d tiles\n",turn,movRand);
        if(playerPosition[turn] == 0){
            printf("Player %d is at the dungeon entrance\n",turn);
        }else if(playerPosition[turn] >= 9){
            printf("Player %d has exited the dungeon\n",turn);
        }else{
            dungeon_do((tiles[playerPosition[turn]]),effects[playerPosition[turn]],turn);
            printf("Player %d position: %d\n",turn,playerPosition[turn]);
            printf("Player %d current tile: %c\n",turn,tiles[playerPosition[turn]]);
        }
        printf("**********\n");
        if(turn==1){turn = 0;}else{turn = 1;}
        if((playerPosition[0] >= 9) ||  (playerPosition[1] >= 9)){exitDungeon = 0;}
    }
    printf("Player %d has won\n");
}

/* (execute Dungeon Position with effect) */
void dungeon_do(char c,int effect,int turn){
    if(c=='n'){
        printf("Player %d is on a normal tile\n",turn);
    }else if(c=='s'){
        Rand = (0 + rand() % (effect+effect+1))-effect-1;
        printf("Player %d is sliding by %d tiles\n",turn,Rand);
        if((playerPosition[turn] + Rand)<(0)){playerPosition[turn] = 0;}else{playerPosition[turn] = playerPosition[turn] + Rand;}
    }else if(c=='e'){
        RandOpponent = 1 + rand() % effect;
        RandEnemy    = 1 + rand() % 7;
        if(RandEnemy >= RandOpponent){
            printf("Player %d has defeated an enemy: Player rolled %d Enemy rolled %d\n",turn,RandEnemy,RandOpponent);
        }else{
            printf("Player %d was defeated by an enemy: Player rolled %d Enemy rolled %d\n",turn,RandEnemy,RandOpponent);
            playerPosition[turn] = -1;
        }
    }else if(c=='t'){
        Rand = 0 + rand() % (playerPosition[turn]-1);
        printf("Player %d has activated a trap and is going back to tile %d\n",turn,Rand);
        playerPosition[turn] = 1;
    }else if(c=='d'){
        RandLock      = 1 + rand() % 7;
        RandUnlock    = 1 + rand() % 7;
        if(RandUnlock >= RandLock){
            printf("Player %d has unclocked a door and is advancing to the next tile: Player rolled %d Lock level was %d\n",turn,RandUnlock,RandLock);
            playerPosition[turn] = playerPosition[turn] + 1;
        }else{
            printf("Player %d has not been able to open the lock and loses a turn\n");
        }
    }else{printf("ERROR: invalid tile type\n");}
}
