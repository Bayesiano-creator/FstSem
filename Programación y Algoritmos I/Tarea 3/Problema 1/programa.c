#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Funcion que recibe un entero y regresa un entero
//con los mismo digitos pero invertidos
int invert(int x){
    int b = 0;
    while (x > 0){
        b *= 10;
        b += x%10;
        x /= 10;
    }
    return b;
}

int main(int arg, char *argv[]){

    //Recibe el nombre del archivo con los ejemplos a probar
    if (arg != 2){
        printf("Hubo un error con los parametros del programa.");
        return 0;
    }
    char *name = argv[1];

    FILE *F = fopen(name, "r");

    int a,b;
    printf("\n");
    
    //itera mientras aun haya ejemplos
    while (fscanf(F,"%d", &a) != EOF){
        b = invert(a);
        if (a == b) printf("El numero %d es palindromo\n", a);
        else printf("El numero %d no es palindromo\n", a);
    }
    printf("\n");
    fclose(F);

    return 0;
}