/*
F10 - FAÇA UMA FUNÇÃO QUE LÊ E RETORNA UM REGISTRO CONTENDO CÓDIGO, DESCRIÇÃO, PREÇO E TIPO (C-CALÇA, B-BLUSA E G-GRAVATA).
F11 - FAÇA UMA FUNÇÃO QUE RECEBE UM REGISTRO E EXIBE SEUS DADOS.
12 - FAÇA UMA FUNÇÃO QUE RECEBA UM VETOR DE REGISTRO, CALCULE E RETORNE O PREÇO MÉDIO DAS CALÇAS.
13 - FAÇA UMA FUNÇÃO QUE RECEBA UM VETOR DE REGISTRO E EXIBA TODAS AS BLUSAS COM PREÇO INFERIOR A R$50,00.
14 - FAÇA UMA FUNÇÃO QUE RECEBE UM VETOR DE REGISTRO E RETORNA O REGISTRO COM O PRODUTO MAIS CARO.
*/


// -- IMPORTAÇÃO DE BIBLIOTECAS
#include <conio.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// -- DECLARAÇÃO DE CONSTANTES
#define DESC 30
#define QTD_PRODUTOS 5


// -- DECLARAÇÃO DE STRUCTS
struct registro {
    int codigo;
    char desc[DESC];
    char tipo;
    float preco;
};
//typedef struct registro registro; // -- COM TYPEDEF


// -- DECLARAÇÃO DE FUNÇÕES AUXILIARES
int menu();
void cadastrarProduto(struct registro prods[], int *);
void exibeRegistro(struct registro prods[], int );
void exibeTodosRegistros(struct registro prods[], int);

/*
float precoMedioCalcas();
void blusasAte50();
float produtoMaisCaro();
*/


// -- FUNÇÃO PRINCIPAL
int main(){
    int count_prods = 0;
    struct registro prods[QTD_PRODUTOS];
    while(1){
        switch(menu()){
            case 1:
                cadastrarProduto(prods, &count_prods);
                break;
            case 2:
                exibeTodosRegistros(prods, count_prods);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                break;
        };
    };
};


// -- DEFINIÇÃO DE FUNÇÕES AUXILIARES
int menu(){
    int opcao_menu = 0;
    system("cls");
    printf("\n\n\t-- MENU --");
    printf("\n\t[1] -- CADASTRAR PRODUTO");
    printf("\n\t[2] -- LISTAR TODOS OS REGISTROS");
    printf("\n\t[3] -- CALCULAR PRECO MEDIO DAS CALCAS");
    printf("\n\t[4] -- MOSTRAR BLUSAS ABAIXO DE R$50");
    printf("\n\t[5] -- MOSTRAR PRODUTO MAIS CARO");
    do{
        printf("\n\n\t->DIGITE O NUMERO DA OPCAO ESCOLHIDA: ");
        fflush(stdin);
        scanf("%i", &opcao_menu);
        switch(opcao_menu){
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 5: break;
            default:
                opcao_menu = 0;
                printf("\n\tOPCAO INVALIDA!");
                break;
        };
    } while ((opcao_menu == 0) || (opcao_menu > 5));
    printf("\tOPCAO DIGITADA >> %i", opcao_menu);
    return opcao_menu;
};

void cadastrarProduto(registro prods[], int *count_prods){
    if(*count_prods >= QTD_PRODUTOS){
        printf("\tMAXIMO DE PRODUTOS REGISTRADO!");
    }
    else{
        struct registro produto;

        printf("\n\tDIGITE O CODIGO(6-DIG): ");
        fflush(stdin);
        scanf("%i", &produto.codigo);
        printf("\t%i", produto.codigo);

        printf("\n\tDIGITE A DESCRICAO: ");
        fflush(stdin);
        gets(produto.desc);
        printf("\t%s", produto.desc);

        printf("\n\tDIGITE O TIPO: ");
        fflush(stdin);
        produto.tipo = getchar();
        printf("\t%c", produto.tipo);

        printf("\n\tDIGITE O PRECO: ");
        fflush(stdin);
        scanf("%f", &produto.preco);
        printf("\t%.2f", produto.preco);

        prods[*count_prods] = produto;
        exibeRegistro(prods, *count_prods);
        printf("\t%i\t", *count_prods);
        *count_prods = *count_prods + 1;
        printf("\t%i\t", *count_prods);
        system("pause");
    };
};


void exibeRegistro(registro prods[], int count_prods){
    printf("\n\n\tCODIGO: %-10i", prods[count_prods].codigo);
    printf("\tTIPO: %-10c", prods[count_prods].tipo);
    printf("\tDESC: %-10s", prods[count_prods].desc);
    printf("\tPRECO:  R$%-10.2f", prods[count_prods].preco);
};

void exibeTodosRegistros(registro prods[], int count_prods){
    int i = 0;
    for (i = 0; i < count_prods; i++){
        exibeRegistro(prods, i);
    };
    system("pause");
};

