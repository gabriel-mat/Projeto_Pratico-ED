#include<stdio.h>

int main(){
    int elementosA = 3, elementosB = 1, elementosC = 1, espacos, discos;

    int pilhaA[5] = {1, 2, 3, 4, 5};
    int pilhaB[5] = {0, 0, 0, 0, 2};
    int pilhaC[5] = {0, 0, 0, 0, 1};

    printf("\n");
    for(int andar = 5; andar >= 1; andar--){
        printf("  ");
        espacos = 5 - pilhaA[5 - andar];
        while(espacos){
            printf(" ");
            espacos--;
        }
        discos = pilhaA[5 - andar];
        while(discos){
            printf("=");
            discos--;
        }
        printf("|");
        discos = pilhaA[5 - andar];
        while(discos){
            printf("=");
            discos--;
        }
        espacos = 5 - pilhaA[5 - andar];
        while(espacos){
            printf(" ");
            espacos--;
        }
        printf("  ");
        espacos = 5 - pilhaB[5 - andar];
        while(espacos){
            printf(" ");
            espacos--;
        }
        discos = pilhaB[5 - andar];
        while(discos){
            printf("=");
            discos--;
        }
        printf("|");
        discos = pilhaB[5 - andar];
        while(discos){
            printf("=");
            discos--;
        }
        espacos = 5 - pilhaB[5 - andar];
        while(espacos){
            printf(" ");
            espacos--;
        }
        printf("  ");
        espacos = 5 - pilhaC[5 - andar];

        while(espacos){
            printf(" ");
            espacos--;
        }
        discos = pilhaC[5 - andar];
        while(discos){
            printf("=");
            discos--;
        }
        printf("|");
        discos = pilhaC[5 - andar];
        while(discos){
            printf("=");
            discos--;
        }
        espacos = 5 - pilhaC[5 - andar];
        while(espacos){
            printf(" ");
            espacos--;
        }
        printf("\n");

    }

    return 0;

}