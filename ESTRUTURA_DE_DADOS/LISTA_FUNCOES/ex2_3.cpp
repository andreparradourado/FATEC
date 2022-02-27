/*
2 - FAÇA UMA FUNÇÃO QUE RECEBE AS MEDIDAS DOS LADOS DE UM RETÂNGULO, CALCULE E RETORNE O VALOR DA SUA ÁREA (BASE X ALTURA).
3 - FAÇA UMA FUNÇÃO QUE RECEBE AS MEDIDAS DOS LADOS DE UM RETÂNGULO, CALCULE E RETORNE O VALOR DO SEU PERÍMETRO (SOMA DE TODOS OS LADOS, OU, 2XBASE + 2XALTURA).
*/


// -- IMPORTAÇÃO DE BIBLIOTECAS
#include <conio.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// -- DECLARAÇÃO DE FUNÇÕES AUXILIARES
float calcArea(float *, float *, float *);
float calcPerimetro(float *, float *, float *);


// -- FUNÇÃO PRINCIPAL
int main(){
    float base = 0, altura = 0, area  = 0, perimetro = 0;
    printf("\n\tDIGITE A MEDIDA DA BASE DO RETANGULO: ");
    fflush(stdin);
    scanf("%f", &base);
    printf("\n\tDIGITE A MEDIDA DA ALTURA DO RETANGULO: ");
    fflush(stdin);
    scanf("%f", &altura);
    printf("\n\tO PERIMETRO DESTE RETANGULO E: %.2f\n", calcPerimetro(&base, &altura, &perimetro));  
    printf("\n\tA AREA DESTE RETANGULO E: %.2f\n\n", calcArea(&base, &altura, &area));
};


// -- DEFINIÇÃO DE FUNÇÕES AUXILIARES
float calcPerimetro(float *base, float *altura, float *perimetro){
    *perimetro = ((2 * *base) + (2 * *altura));
    return *perimetro;
};

float calcArea(float *base, float *altura, float *area){
    *area = *base * *altura;
    return *area;
};