/*
5 - FAÇA UMA FUNÇÃO QUE LEIA 20 VALORES INTEIROS EM UM VETOR, DEPOIS ENVIE ESTE VETOR PARA OUTRA FUNÇÃO QUE RETORNARÁ O MAIOR VALOR.
*/


// -- IMPORTAÇÃO DE BIBLIOTECAS
#include <conio.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// -- DECLARAÇÃO DE CONSTANTES
#define TAM 5


// -- DECLARAÇÃO DE FUNÇÕES AUXILIARES
void leVetores(int *);
int maiorDoVetor(int *);


// -- FUNÇÃO PRINCIPAL
int main(){
    int vvetor[TAM];  
    leVetores(vvetor);
    printf("O MAIOR VALOR E %i", maiorDoVetor(vvetor));
};


// -- DEFINIÇÃO DE FUNÇÕES AUXILIARES
void leVetores(int *vetor){
    int i = 0,
        n = 1;
    for (i = 0; i < TAM; i++){
        printf("DIGITE O %i VALOR DO VETOR: ", n);
        fflush(stdin);
        scanf("%i", &vetor[i]);
        printf("ULTIMO VETOR DIGITADO: POSICAO: %i, VALOR: %i\n", n, vetor[i]);
        n++;
    };
};


int maiorDoVetor(int *vetor){
    int maior_valor,
        i = 0;
    maior_valor = vetor[i];
    for (i = 0; i < TAM; i++){
        if(vetor[i] > maior_valor){
            maior_valor = vetor[i];           
        };
    };
    return maior_valor;
};