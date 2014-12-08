#import <stdio.h>

void solveEquation();
void solveFibonacci();
void solve42();

int main(){
    int choosen;
    printf("Choose the part to execute:\n\t1 \t: Part 1 (equation zeros)\n\t2 \t: Part 2 (Fibonacci sequence)\n\t3 \t: Part 3 (42)\n\tother \t: Exit\n\n");
    scanf("%d",&choosen);
    if(choosen==1){
        /* risolvi equazione di secondo grado */
        solveEquation();
    }else if(choosen==2){
        /* fibonacci */
        solveFibonacci();
    }else if(choosen==3){
        solve42();
    }else{printf("Exit.");}


    return 0;
} // main

/* funzione che trova la soluzione alla vita */
void solve42(){
    int n1,n2;
    do{
        printf("Enter an integer number\n");
        scanf("%d",&n1);
        printf("Enter another integer number\n");
        scanf("%d",&n2);
        printf("Sum is %d\n",(n1+n2));
    } while((n1+n2)!=42);
} // solve42

/* funzione che elabora fino all'ennesimo elemento fibonacci */
void solveFibonacci(){
    int n,i;
    float prec1,prec2,fb;
    prec1 = 1;
    prec2 = 2;
    printf("Insert the index of Fibonacci element\n");
    scanf("%d",&n);
    for(i=3;i<n;i++){
        fb= prec1+prec2;
        prec1=prec2;
        prec2=fb;
    }
    printf("Fibonacci(%d) = %f\n",n,fb);
} // solveFibonacci


/* funzione che risolve una equazione di secondo grado */
void solveEquation(){
    float delta,x1,x2,a,b,c;
    printf("Insert the coefficient a b c separated by spaces\n");
    scanf("%f %f %f",&a,&b,&c);
    delta = (b*b)-(4*a*c);

    if(a==0){
        printf("The equation degree is less than two\n");
    }else{
        printf("The equation (%f x^2 + %f x + %f = 0) has ",a,b,c);
        if(delta==0){
            printf("only one zero: %f\n", (-b/2*a));
        }else if(delta>0){
            printf("two zeros: %f, %f\n",(-b+sqrt(delta))/(2*a),(-b-sqrt(delta))/(2*a));
        }else if(delta<0){
            printf("no real zeros.\n");
        } // if delta
    } // if coeff A==0

} // solveEquation
