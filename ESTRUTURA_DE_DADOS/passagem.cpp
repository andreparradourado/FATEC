// -- IMPORTAÇÃO DE BIBLIOTECAS
#include <conio.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// -- DECLARAÇÃO DE FUNÇÕES AUXILIARES
void trocaPorValor(int, int);
void trocaPorRef(int *, int *);


// -- FUNÇÃO PRINCIPAL
int main(){
    int a = 10, b = 20, c = 0;

    printf("\nANTES DE CHAMAR trocaPorValor: a=%d b=%d\n", a, b);
    trocaPorValor(a,b); // TROCA POR VALOR
    printf("DEPOIS DE CHAMAR trocaPorValor: a=%d b=%d\n", a, b);

    getch();
    printf("\nANTES DE CHAMAR trocaPorRef: a=%d b=%d\n", a, b);
    trocaPorRef(&a,&b); // TROCA POR REFERENCIA
    printf("DEPOIS DE CHAMAR trocaPorRef: a=%d b=%d\n", a, b);
};


// -- DEFINIÇÃO DE FUNÇÕES AUXILIARES
void trocaPorValor(int a, int b){
    int temp = a;
    a = b;
    b = temp;
};
void trocaPorRef(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
};