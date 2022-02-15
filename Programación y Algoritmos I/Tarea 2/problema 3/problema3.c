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

    int a,b,c,d,x,y;
    char operation;
    printf("\n");
    
    //itera mientras aun haya ejemplos
    while (fscanf(F,"%d/%d%c%d/%d", &a, &b, &operation, &c, &d) != EOF){
        switch (operation)
        {
        case '+':
            x = a*d + b*c;
            y = b*d;
            break;
        case '-':
            x = a*d - b*c;
            y = b*d;
            break;
        case '*':
            x = a*d;
            y = b*d;
            break;
        case '/':
            x = a*d;
            y = b*c;
            break;
        default:
            printf("No es una operacion valida\n\n");
            continue;
            break;
        }
        printf("%d/%d%c%d/%d=%d/%d \n\n", a, b, operation, c, d, x, y);
    }

    fclose(F);

    return 0;
}