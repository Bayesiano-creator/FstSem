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

    int a,b,n_d;
    char digits[100];
    printf("\n");
    
    //itera mientras aun haya ejemplos
    while (fscanf(F,"%d %d", &a, &b) != EOF){
        if (b > 36) {
            printf("No hay suficientes simbolos para representar la base.\n\n");
            continue;
        }

        printf("Numero decimal: %d\n", a);
        
        n_d = 0;
        while (a>0){
            digits[n_d++] = a%b;
            a /= b;
        }
        
        printf("En base %d: ", b);
        int i = 0;
        for (i=n_d - 1; i>=0; i--){
            if (digits[i] <= 9){
                printf("%d", digits[i]);
            }
            else {
                printf("%c", 'A' + (digits[i] - 10));
            }
        }
        printf("\n\n");
    }

    fclose(F);

    return 0;
}