/*
7 - FAÇA UMA FUNÇÃO QUE RECEBE UMA STRING E RETORNA A QUANTIDADE DE VOGAIS QUE A MESMA POSSUI.
*/


// -- IMPORTAÇÃO DE BIBLIOTECAS
#include <conio.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// -- DECLARAÇÃO DE CONSTANTES
#define TAM 50


// -- DECLARAÇÃO DE FUNÇÕES AUXILIARES
int contaVogais(char *);


// -- FUNÇÃO PRINCIPAL
int main(){
    char frase[TAM];
    printf("\n\tDIGITE UMA FRASE: ");
    gets(frase);
    printf("\tA FRASE POSSUI %i VOGAIS", contaVogais(frase));
};


// -- DEFINIÇÃO DE FUNÇÕES AUXILIARES
int contaVogais(char *x){
    int i = 0,
        count_vogais = 0;
    for(i = 0; i < strlen(x); i++){
        switch(x[i]){
            case 'A': count_vogais++; break;
            case 'a': count_vogais++; break;
            case 'E': count_vogais++; break;
            case 'e': count_vogais++; break;
            case 'I': count_vogais++; break;
            case 'i': count_vogais++; break;
            case 'O': count_vogais++; break;
            case 'o': count_vogais++; break;
            case 'U': count_vogais++; break;
            case 'u': count_vogais++; break;
            default: break;
        };
    };
    return count_vogais;
};