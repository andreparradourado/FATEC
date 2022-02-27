/* 
1 - FAÇA UMA FUNÇAO QUE RECEBE UM VALOR INTEIRO E VERIFICA SE ESTE É PAR OU ÍMPAR. A FUNÇÃO DEVE RETORNAR 0 SE FOR PAR E 1 SE FOR ÍMPAR.
*/


// -- IMPORTAÇÃO DE BIBLIOTECAS
#include <conio.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// -- DECLARAÇÃO DE FUNÇÕES AUXILIARES
int parOuImpar(int, int);


// -- FUNÇÃO PRINCIPAL
int main(){
    unsigned short int valor = 0, teste = 0;
    printf("\n\tDIGITE UM VALOR INTEIRO: ");
    fflush(stdin);
    scanf("%i", &valor);
    if(parOuImpar(valor, teste) == 0)
        printf("\n\tO VALOR DIGITADO E PAR!\n\n");
    else if(parOuImpar(valor, teste) == 1)
        printf("\n\tO VALOR DIGITAL E IMPAR!\n\n");      
    else
        printf("\n\tERRO!");  
};


// -- DEFINIÇÃO DE FUNÇÕES AUXILIARES
int parOuImpar(int valorInteiro, int teste){
    teste = valorInteiro%2;
    return teste;
};