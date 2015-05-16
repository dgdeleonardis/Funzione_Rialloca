/* 
 * File:   main.c
 * Author: Studenti
 *
 * Created on 16 maggio 2015, 8.32
 */

#include <stdio.h>
#include <stdlib.h>

int* rialloca(int *array, int dimensioneCorrente);
/*
 * 
 */
int main(int argc, char** argv) {
    int dimensioneCorrente = 2;
    int *array;
    int i = 0;
    
    printf("NULL: %p\n", NULL);
    exit(0);
    
    array = (int*) malloc(dimensioneCorrente* sizeof(int));

    if(array == NULL) {
        printf("Impossibile allocare memoria dinamica\n");
        exit(1);
    }
    printf("Inserisci un numero : ");
    scanf("%d", array);
    i = 0;
    while(*(array + i) != 0) {
        if((dimensioneCorrente - 1) == i) {
            
            array = rialloca(array, dimensioneCorrente);
            dimensioneCorrente *= 2;
        }
        i++;
        printf("Inserisci un numero : ");
        scanf("%d", array + i);
        
    }
    i = 0;
    
    while(*(array + i)) {
    printf("Elemento %d : %d\n", i, *(array + i));
    i++;
    }
    
    return (EXIT_SUCCESS);
}

int* rialloca(int *array, int dimensioneCorrente){
    int *arrayNuovo;
    int i;
    arrayNuovo = (int*) malloc((dimensioneCorrente*2)* sizeof(int));
    for(i = 0; i < dimensioneCorrente; i++) {
        *(arrayNuovo + i) = *(array + i);
    }
    return arrayNuovo;
}