/* ESERCITAZIONE 9 */
#include <stdio.h>

void graphMatrix();
    void visualizzaMatrix();
void graphPath();
    void createPathMatrix();
void TTT();
    void inizializzaField();
    void visualizzaField();
    int setTale(int,int,int);

/* DICHIARAZIONI VARIABILI */
    /* GLOBAL DECLARE */
    int choosen;

    /* ESERCIZIO #1 */
        #define MATRIX_SIZE 5
        int matrix[MATRIX_SIZE][MATRIX_SIZE];
        int edges[MATRIX_SIZE][2];
        int edge1,edge2,e,n;
    /* ESERCIZIO #2 */
        #define ADJACENCY_DIM 5
        int adjacencyMatrix[ADJACENCY_DIM][ADJACENCY_DIM] = {{0,1,0,1,0},{1,0,0,1,0},{0,0,0,0,1},{1,1,0,0,1},{0,0,1,1,0}};
        int pathMatrix[ADJACENCY_DIM][ADJACENCY_DIM];
        int edge[ADJACENCY_DIM-1][2];
        int s,step_succ,step,f=0;
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
    for(e=0;e<MATRIX_SIZE;e++){
        printf("Insert the edge %d of the graph\n",e);
        scanf("%d %d",&edge1,&edge2);
        matrix[edge1-1][edge2-1] = 1;
        matrix[edge2-1][edge1-1] = 1;
        edges[e][0] = edge1;
        edges[e][1] = edge2;
    }
    visualizzaMatrix();
}

void visualizzaMatrix(){
    printf("{");
    for(e=0;e<MATRIX_SIZE;e++){
            printf("(%d,%d)",edges[e][0],edges[e][1]);
    }
    printf("}\n");
    for(e=0;e<MATRIX_SIZE;e++){
        for(n=0;n<MATRIX_SIZE;n++){
            printf("%d ",matrix[e][n]);
        }
        printf("\n");
    }

}

/* (Graph path) */
void graphPath(){
     printf("Insert step %d\n",s);
     scanf("%d",&step);
     edge[s][0] = step;
     for(s=0;s<3;s++){
        printf("Insert step %d\n",s);
        scanf("%d",&step);
        edge[s][1] = step;
        if((s+1)<(ADJACENCY_DIM-2)){
            edge[s+1][0] = step;
        }
     }
     createPathMatrix();

     for(e=0;e<ADJACENCY_DIM;e++){
        for(n=0;n<ADJACENCY_DIM;n++){
            printf("%d ",adjacencyMatrix[e][n]);
        }
        printf("\n");
     }
     printf("\n");
     printf("{");
     for(e=0;e<(ADJACENCY_DIM-2);e++){
            printf("(%d,%d)",edge[e][0],edge[e][1]);
     }
     printf("}\n");
     for(e=0;e<ADJACENCY_DIM;e++){
        for(n=0;n<ADJACENCY_DIM;n++){
            printf("%d ",pathMatrix[e][n]);
        }
        printf("\n");
     }
     if(equalPathMatrixes()){
        printf("The path is valid\n");
     }else{
        printf("The path is invalid\n");
     }
}

void createPathMatrix(){
    for(e=0;e<(ADJACENCY_DIM-2);e++){
        pathMatrix[edge[e][0]-1][edge[e][1]-1] = 1;
        pathMatrix[edge[e][1]-1][edge[e][0]-1] = 1;
    }
}

int equalPathMatrixes(){
    for(e=0;e<ADJACENCY_DIM;e++){
        for(i=0;i<ADJACENCY_DIM;i++){
            if(pathMatrix[e][i]!=adjacencyMatrix[e][i]){
                return 0;
            }
        }
    }
    return 1;
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
