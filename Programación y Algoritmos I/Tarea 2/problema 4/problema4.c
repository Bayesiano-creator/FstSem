#include<stdio.h>
#include<stdlib.h>

int main(int arg, char *argv[]){

    //Recibe el nombre del archivo con los ejemplos a probar
    if (arg != 2){
        printf("Hubo un error con los parametros del programa.");
        return 0;
    }
    char *name = argv[1];

    FILE *F = fopen(name, "r");

    int a,b,x;
    printf("\n");
    
    //itera mientras aun haya ejemplos
    while (fscanf(F,"%d", &a) != EOF){
        b = 0;
        x = abs(a);
        while (x > 0){
            b *= 10;
            b += x%10;
            x /= 10;
        }
        if (a < 0) b = -b;
        printf("%d => %d \n\n", a, b);
    }

    fclose(F);

    return 0;
}