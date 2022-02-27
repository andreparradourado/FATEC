/*
8 - FAÇA UMA FUNÇÃO QUE LÊ UMA MATRIZ 3X3 DE INTEIROS.
9 - FAÇA UMA FUNÇÃO QUE RECEBE UMA MATRIZ 3X3 DE INTEIROS E RETORNA A SOMA DE SEUS ELEMENTOS.
*/


// -- IMPORTAÇÃO DE BIBLIOTECAS
#include <conio.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// -- DECLARAÇÃO DE CONSTANTES
#define ROWS 3
#define COLUMNS 3


// -- DECLARAÇÃO DE VARIÁVEIS
int matriz[ROWS][COLUMNS];
int i = 0,
    j = 0,
    total_matriz = 0;


// -- DECLARAÇÃO DE FUNÇÕES AUXILIARES
void leMatriz();
void mostraMatriz();
int somaMatriz(int);


// -- FUNÇÃO PRINCIPAL
int main(){
    leMatriz();
    mostraMatriz();
    printf("A SOMA TOTAL E %i", somaMatriz(matriz[ROWS][COLUMNS]));
};


// -- DEFINIÇÃO DE FUNÇÕES AUXILIARES
void leMatriz(){
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLUMNS; j++){
            printf("\nDIGITE O VALOR DA %i COLUNA DA %i LINHA: ", j+1, i+1);
            scanf("%i", &matriz[i][j]);
        };
    };

};
void mostraMatriz(){
    printf("\n");
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLUMNS; j++){
            if((i == 1 && j == 0) || (i == 2 && j == 0))
                printf("\n");
            printf("%i ",matriz[i][j]);
        };
    };
    printf("\n\n");
};
int somaMatriz(int x){
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLUMNS; j++){
            total_matriz = (total_matriz + matriz[i][j]);
        };
    };
    return total_matriz;
};
