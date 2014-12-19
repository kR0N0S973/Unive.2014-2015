/* ESERCITAZIONE 9 */
#include <stdio.h>

void graphMatrix();
void graphPath();
void TTT();
    void inizializzaField();
    void visualizzaField();
    int setTale(int,int,int);

/* DICHIARAZIONI VARIABILI */
    /* GLOBAL DECLARE */
    int choosen;

    /* ESERCIZIO #1 */
        int edgeGraph;
    /* ESERCIZIO #2 */

    /* ESERCIZIO #3 */
        #define FIELD_SIZE 3
        int gameField[FIELD_SIZE][FIELD_SIZE];
        int i,j,turn = 1,row=0,TTT_error=0,TTT_win=(-1),TTT_lost=(-1),cmpp=-1,_x,_y,k=0,play=0;
        char c;
/* CLOSE DELCARE */

int main(){
    printf("Choose the part to execute:\n\t1 \t: Part 1 (Graph matrix)\n\t2 \t: Part 2 (Graph path)\n\t3 \t: Part 3 (Tic-tac-toe)\n\tother \t: Exit\n\n");
    scanf("%d",&choosen);
    if(choosen==1){
        graphMatrix();
    }else if(choosen==2){
        graphPath();
    }else if(choosen==3){
        TTT();
    }
    return 0;
}


/* (Graph matrix) */
void graphMatrix(){
    printf("Insert the edge %d of the graph\n");
    scanf("%d",&edgeGraph);
}

/* (Graph path) */
void graphPath(){

}

/* (Tic-tac-toe) */
void TTT(){
    inizializzaField();
    while(TTT_error != 1 && play<9){
        play = play + 1;
        cmpp=compareField();
        if(cmpp!=-1){
            TTT_error = 1;
        }else{
            if(turn==0){turn=1;}else{turn=0;}
            do{
                printf("Player %d turn: Insert the tile coordinates\n",turn);
                scanf("%d %d",&_x,&_y);
                k = setTale(_x,_y,turn);
            }while(k == 0);
            visualizzaField();
        }
    }
    if(TTT_error == 1){printf("Player %d wins!\n",turn);}else{printf("Draw!\n");};
}

int compareField(){
    /* controlla rows */
    for(i=0;i<FIELD_SIZE;i++){
        if(gameField[i][0] == gameField[i][1] && gameField[i][1] == gameField[i][2] && gameField[i][0] != -1){
            return gameField[i][0];
        }
    }
    /* controlla columns */
    for(i=0;i<FIELD_SIZE;i++){
        if(gameField[0][i] == gameField[1][i] && gameField[1][i] == gameField[2][i] && gameField[0][i] != -1){
            return gameField[0][i];
        }
    }

    /* first diagonal */
    if(gameField[0][0] == gameField[1][1] && gameField[1][1] == gameField[2][2]){
        return gameField[0][0];
    }

    /* second diagonal */
    if(gameField[0][2] == gameField[1][1] && gameField[1][1] == gameField[2][0]){
        return gameField[0][2];
    }
    return -1;
}

int setTale(int row,int column,int turn){
    if(gameField[row][column]==(-1)){
        gameField[row][column] = turn;
        return 1;
    }else{
        printf("The board tile is not empty. Please select an empty tile\n");
        return 0;
    }
}


void visualizzaField(){
    if(TTT_error==0){
        for(i=0;i<FIELD_SIZE;i++){
            for(j=0;j<FIELD_SIZE;j++){
                if(gameField[i][j]==0){
                    c = 'X';
                }else if(gameField[i][j]==1){
                    c = 'O';
                }else{c = '#';}
                printf("%c ",c);
            }
            printf("\n");
        }
    }
}

void inizializzaField(){
    for(i=0;i<FIELD_SIZE;i++){
        for(j=0;j<FIELD_SIZE;j++){
            gameField[i][j] = -1;
        }
    }
}
