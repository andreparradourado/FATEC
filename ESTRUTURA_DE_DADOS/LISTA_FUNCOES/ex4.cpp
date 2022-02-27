/*
4 - FAÇA UMA FUNÇÃO QUE RECEBE 3 VALORES INTEIROS E RETORNA O MAIOR VALOR.
*/


// -- IMPORTAÇÃO DE BIBLIOTECAS
#include <conio.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// -- DECLARAÇÃO DE FUNÇÕES AUXILIARES
int maiorValorDos3(int, int, int);


// -- FUNÇÃO PRINCIPAL
int main(){
    unsigned int valor1 = 0, valor2 = 0, valor3 = 0;
    printf("DIGITE O PRIMEIRO VALOR: ");
    fflush(stdin);
    scanf("%i", &valor1);
    printf("DIGITE O SEGUNDO VALOR: ");
    fflush(stdin);
    scanf("%i", &valor2);
    printf("DIGITE O TERCEIRO VALOR: ");
    fflush(stdin);
    scanf("%i", &valor3);
    printf("O MAIOR VALOR E: %i", maiorValorDos3(valor1, valor2, valor3));
};


// -- DEFINIÇÃO DE FUNÇÕES AUXILIARES
int maiorValorDos3(int valor1, int valor2, int valor3){
    int maior_valor  = 0;
    if (valor1 > valor2 && valor1 > valor3){
        maior_valor = valor1;
        return valor1;
    }   
    else if (valor2 > valor1 && valor2 > valor3){
        maior_valor = valor2;
        return maior_valor;
    }
    else {
        maior_valor = valor3;
        return maior_valor;
    };
};