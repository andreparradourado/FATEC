/*
6 - FAÇA UMA FUNÇÃO QUE RECEBE A ALTURA E O SEXO DE UMA PESSOA E RETORNA O SEU PESO IDEAL. 
PARA HOMENS, CALCULAR O PESO IDEAL USANDO A FÓRMULA PESO IDEAL = 72.7 X ALTURA - 58
PARA MULHERES, CALCULAR O PESO IDEAL USANDO A FÓRMULA PESO IDEAL = 62.1 X ALTURA - 44.7
*/


// -- IMPORTAÇÃO DE BIBLIOTECAS
#include <conio.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// -- DECLARAÇÃO DE FUNÇÕES AUXILIARES
float calcPesoIdeal(char *, float*);


// -- FUNÇÃO PRINCIPAL
int main(){
    char sexo = 'U';
    float altura = 0;
    printf("DIGITE O SEU SEXO: \"M\" OU \"F\": ");
    fflush(stdin);
    sexo = getchar();
    //while (sexo != ('M' && 'F')){
    while ((sexo != ('F') && (sexo != ('M')) && sexo != ('f') && sexo != ('m')) ){
        printf("\nDIGITE O SEU SEXO: \"M\" OU \"F\": ");
        fflush(stdin);
        sexo = getchar();
    };
    printf("DIGITE A SUA ALTURA: ");
    scanf("%f", &altura);
    printf("SEU PESO IDEAL E: %.2f", calcPesoIdeal(&sexo, &altura));   
};


// -- DEFINIÇÃO DE FUNÇÕES AUXILIARES
float calcPesoIdeal(char *sexo, float *altura){
    int pesoideal = 0;
    if (*sexo == 'M' || *sexo == 'm'){
        pesoideal = ((72.7 * *altura)-58);
        return pesoideal; 
    }
    else {
        pesoideal = ((62.1 * *altura)-44.7);
        return pesoideal;  
    };
};