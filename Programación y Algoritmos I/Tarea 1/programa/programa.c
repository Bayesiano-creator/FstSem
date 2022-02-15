#include<stdio.h>
#include<stdlib.h>

int main(void){
    int a,b,c,d,x,y;

    //Se lee la entrada-------------------

    printf("Introducir Fraccion 1: ");
    scanf("%d/%d", &a, &b);

    printf("Introducir Fraccion 2: ");
    scanf("%d/%d", &c, &d);
    printf("\n");

    //Se calcula la fracción resultante----
    
    x = a*d + b*c;
    y = b*d;

    //Se imprime el resultado--------------

    printf("%d/%d + %d/%d = %d/%d", a, b, c, d, x, y);

    return 0;
}