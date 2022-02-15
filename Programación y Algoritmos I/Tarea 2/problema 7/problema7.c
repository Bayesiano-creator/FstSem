#include<stdio.h>
#include<stdlib.h>

//Recibe dos enteros positivos y regresa su gcd
int gcd(int a, int b){
    int m;
    if (a <= b) m = a;
    else m = b;

    int i, g;
    for (i = 1; i<= m; i++){
        if (a%i == 0 && b%i == 0) g = i;
    }

    return g;
}

int main(int arg, char *argv[]){

    //Recibe el nombre del archivo con los ejemplos a probar
    if (arg != 2){
        printf("Hubo un error con los parametros del programa.");
        return 0;
    }
    char *name = argv[1];

    FILE *F = fopen(name, "r");

    int a,b,x,y,g;
    printf("\n");
    
    //itera mientras aun haya ejemplos
    while (fscanf(F,"%d/%d", &a, &b) != EOF){
        g = gcd(abs(a), abs(b));
        x = abs(a)/g;
        y = abs(b)/g;

        printf("%d/%d = ", a, b);
        if (a*b < 0) printf("-");
        printf("%d", x);
        if (y != 1) printf("/%d", y); 
        printf("\n\n");
    }

    fclose(F);

    return 0;
}