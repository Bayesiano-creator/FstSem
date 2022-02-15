#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Recibe n, el grado del polinomio, y x, el punto a evaluar,
//y regresa el polinomio con n tÃ©rminos evaluado en x
double P(int n, double x){
    double res = 1.0;
    int i;
    for (i=0; i<n; i++){
        res = 1.0 + x*res/((double)(n-i));
    }

    return res;
}

//Recibe un valor con punto flotante y regresa su valor absoluto
double absoluto(double x){
    if (x >= 0.0 ) return x;
    else return -x;
}

int main(int arg, char *argv[]){

    //Recibe el nombre del archivo con los ejemplos a probar
    if (arg != 2){
        printf("Hubo un error con los parametros del programa.");
        return 0;
    }
    char *name = argv[1];

    FILE *F = fopen(name, "r");

    int n;
    double x, y1, y2;
    printf("\n");
    
    //itera mientras aun haya ejemplos
    while (fscanf(F,"%d %lf\n", &n, &x) != EOF){
        y1 = P(n,-x*x);
        y2 = exp(-x*x);
        printf("Grado: %d, valor de prueba x: %lf \n", n, x);
        printf("Polinomio: %lf,  usando exp de math.h: %lf \n", y1, y2);
        printf("error absoluto: %lf \n\n", absoluto(y1 - y2));
    }

    fclose(F);
}