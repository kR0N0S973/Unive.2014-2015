/* Kevin Wiederstein  * * * * *
 * Matricola: 852026  * * * * *
 * * ESERCITAZIONE 11 - C * * */

#include <stdio.h>
#define MAXDIM 20

void acquisisci(int[][MAXDIM],int);
void calcola(int[][MAXDIM],int,int*,int*); 
int searchInArray(int[][2],int,int);
int getMaxRow(int[],int);

int main(){
	int mat[MAXDIM][MAXDIM];
	int N,rmax = 0,cmax = 0;
	printf("Insert the matrix ( NxN ) size : ");
	scanf("%d",&N);
	if(N<21 && N>0){
		acquisisci(mat,N);
		calcola(mat,N,&rmax,&cmax);
		printf("\n   Row with more repetitions : %d \n",rmax);
		printf("Column with more repetitions : %d",cmax);
	}else{printf("N is bigger or smaller than max./min. matrix size ( %d )", MAXDIM);}
	return 0;
}

/* inizialize a NxN matrix */
void acquisisci(int m[][MAXDIM], int n){
	int j,k;
	for(j=0;j<n;j++){
		for(k=0;k<n;k++){
			scanf("%d",&m[j][k]);
		}
	}
}


/*   0 1 2 3 
 * 0 1 1 1 1 <
 * 1 1 2 4 6
 * 2 1 2 7 8
 * 3 8 2 6 8
 *   ^
 * changes rmax to 0 and cmax to 0
 * */
void calcola(int m[][MAXDIM], int n, int* rmax, int* cmax){
	int i, j, k ,maxr=0,countr=0,maxc=0,countc=0,riga_max,colonna_max;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				if(m[i][j] == m[i][k]){
					countr++;
				}
				if(m[j][i] == m[k][i]){
					countc++;
				}
			}
			if(countr>maxr){
					maxr=countr;
					riga_max=i;
			}
			if(countc>maxc){
					maxc=countc;
					colonna_max=i;
			}
			countr = 0;
			countc = 0;
		}
	}
	*rmax = riga_max;
	*cmax = colonna_max; 
}
