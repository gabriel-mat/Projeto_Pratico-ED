#include <stdio.h>
#include <stdlib.h>
#include "API/fila/fila.h"
#include "API/deque/deque.h"

deque *construir_piramide(unsigned n_discos);

int main(){
    deque *P;

    P = construir_piramide(10); 

    imprime_deque(P);
    return 0;   
}

deque *construir_piramide(unsigned n_discos){
    deque *D = (deque *)malloc(sizeof(deque));

    inicializa_deque(D, 10);
    for(unsigned i = n_discos; i >= 1; i--)
        insereI(D, i);

    return D;
}