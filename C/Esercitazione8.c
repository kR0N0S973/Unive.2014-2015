/* Copyright 2014-2015        *
 * coded by Kevin Wiederstein */

/* ####
	STRINGS OF EX.8
	"Choose the part to execute:\n\t1 \t: Part 1 (Bank Account)\n\t2 \t: Part 2 (Boat course)\n\t3 \t: Part 3 (Dungeon)\n\tother \t: Exit\n\n"
	"Month %d balance is %f\n"
	"Insert the random generator seed\n"
	"Boat course:\n"
	"(%d,%d)\n"
	"Shallows:\n"
	"(%d,%d)\n"
	"The boat will run ashore at (%d,%d)\n"
	"The boat course is valid\n"
	"Insert the random generator seed\n"
	"Player %d moving by %d tiles\n"
	"Player %d is on a normal tile\n"
	"Player %d is sliding by %d tiles\n"
	"Player %d has defeated an enemy: Player rolled %d Enemy rolled %d\n"
	"Player %d was defeated by an enemy: Player rolled %d Enemy rolled %d\n"
	"Player %d has activated a trap and is going back to tile %d\n"
	"Player %d has unclocked a door and is advancing to the next tile: Player rolled %d Lock level was %d\n"
	"Player %d has not been able to open the lock and loses a turn\n"
	"ERROR: invalid tile type\n"
	"Player %d is at the dungeon entrance\n"
	"Player %d has exited the dungeon\n"
	"Player %d position: %d\n"
	"Player %d current tile: %c\n"
	"**********\n"
	"Player %d has won\n"
	####
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* DICHIARAZIONE VARIABILI */
	/* esercizio 1 */
	#define RATE_DIM 12
	const double interestRates[RATE_DIM] = {0.2,-0.6,0.3,0.6,-0.4,0.1,0.5,-0.85,-0.7,0.2,0.1,0.0}; 
	double credito=4500,interesse=2.5;
	int i;
	/* esercizio 2 */
	#define SHALLOW_DIM 4
	const int shallowsX[SHALLOW_DIM] = {3,1,2,0};
	const int shallowsY[SHALLOW_DIM] = {0,1,3,4};
	/* esercizio 3 */
	#define TILES_DIM 	10
	#define EFFECTS_DIM 10
	const char tiles[TILES_DIM]		 = {'n','s','n','s','e','t','n','n','e','d'};
	const int effects[EFFECTS_DIM] 	 = {0,3,0,3,3,0,0,0,6,3};
/* ####################### */ 

void bankAccount();
void boatCourse();
void dungeon();

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
	for(i=0;i<12;i++){
		interesse = interesse + interestRates[i];
		credito = credito + ((credito*interesse)/100);
		printf("Month %d balance is %f\n",i,credito);
	}
}

/* (Boat Course) */
void boatCourse(){
	
}

/* (Dungeon) */
void dungeon(){
	
}
