// -- INCLUSÃO DE BIBLIOTECAS
#include <conio.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// -- DECLARAÇÃO DE FUNÇÕES (EXERCÍCIOS)
void carregaArquivoTexto(FILE *arquivo, char nome_arquivo[50], char ch);   // EXERCICIO 1
void contaVogal(FILE *arquivo, char nome_arquivo[50], char ch);            // EXERCICIO 2
void converteParaI(FILE *arquivo, char nome_arquivo[50], char ch);         // EXERCICIO 3
void arquivoPrimeiraMaiusc(FILE *arquivo, char nome_arquivo[50], char ch); // EXERCICIO 4
void gravaFigura(FILE *arquivo, char nome_arquivo[50], char ch);           // EXERCICIO 5
void cebolinha(FILE *arquivo, char nome_arquivo[50], char ch);             // DESAFIO (CEBOLINHA)


// -- DECLARAÇÃO DE FUNÇÕES (RECORRENTES)
void abreArqPrincipalModoR(FILE *arquivo, char nome_arquivo[50]); // ABERTURA DE ARQUIVO PRINCIPAL NO MODO [R]ead
char upperOrLower(char x);                                        // CHECA O CASE DO 'R' E RETORNA O 'L' DE ACORDO
void gravarCh(char ch, FILE *arquivo);                            // GRAVA CH E O PRINTA NA TELA
void fimDeExercicio(FILE *arquivo);                               // 3 LINHAS PADRÃO UTILIZADAS NO FIM DE QUASE TODO EXERCICIO


// -- INÍCIO DE FUNÇÃO PRINCIPAL \/
int main(){

    // -- DECLARAÇÃO DE VARIÁVEIS INTERNAS DA FUNÇÃO PRINCIPAL
    char ch;                // DECLARAÇÃO DE VARIÁVEL DO TIPO CHARACTER
    char nome_arquivo[50];  // DECLARAÇÃO DE STRING COM 50 CARACTERES
    FILE *arquivo;          // DECLARAÇÃO DE PONTEIRO P/ UM ARQUIVO
    int op_menu = 10;       // DECLARAÇÃO DE VARIÁVEL PARA OSCILAR ENTRE MENU

    // -- INICIO DO SISTEMA
    system("cls"); // LIMPA O TERMINAL
    printf("\n-- FATEC LINS - PROF. ANTONIO SEABRA\n-- TRABALHO DE ESTRUTURA DE DADOS - 2/2021\n-- ANDRE PARRA && SAMARA VILELA\n\n"); // CABEÇALHO INICIAL                                                                    
    printf(">> DIGITE O NOME DO ARQUIVO TEXTO P/ SER REFERENCIA PRINCIPAL NO PROGRAMA: "); // IMPRIME PEDIDO DE DIGITAÇÃO DE ARQUIVO .TXT
    fflush(stdin);                                                                         // LIMPA BUFFER DE ENTRADA PRINCIPAL (NO CASO, TECLADO)
    gets(nome_arquivo);                                                                    // ARMAZENA A STRING DIGITADA EM nome_arquivo

    // O IF A SEGUIR TEM COMO CONDIÇÃO/PARÂMETRO O RETORNO DA FUNÇÃO fopen();
    // A FUNÇÃO fopen() SERVE PARA NOSSA PROGRAMAÇÃO ABRIR/MANIPULAR UM ARQUIVO TEXTO
    // A FUNÇÃO fopen() RECEBE 2 PARÂMETROS, 1º NOME DO ARQUIVO E 2º MODO DE ABERTURA/MANIPULAÇÃO
    // 1º PARÂMETRO: NOME DO ARQUIVO ENTRE ASPAS OU NOME DE STRING QUE CONTENHA O NOME DO ARQUIVO
    // 2º PARÂMETRO: MODO DE MANIPULAÇÃO, ALGUMA DAS OPÇÕES A SEGUIR: (A,R,W,AB,RB,WB,A+,R+,W+)
    // ARQUIVO ABERTO CORRETAMENTE -> RETORNA PONTEIRO OK, CASO CONTRÁRIO RETORNA PONTEIRO NULL
    if ( (arquivo = fopen(nome_arquivo,"r")) == NULL){  
        printf("\n\t>>ERRO<< NA ABERTURA DO ARQUIVO!\n\n"); // EM CASO DE ERRO, PRINTA AVISO NA TELA E APÓS ISSO ENCERRA APLICAÇÃO
        exit(0); // ENCERRA A APLICAÇÃO
    }
    else{
        fclose(arquivo);                    // FECHA ARQUIVO ABERTO COM A FUNÇÃO fopen();
        printf("\nARQUIVO >>VALIDO<<\n\n"); // PRINTA AVISO DE ARQUIVO VALIDO
        system("pause");                    // PAUSE DO SISTEMA
    };

    // -- GERENCIAMENTO DO SISTEMA
    // PRIMEIRAMENTE IRÁ LIMPAR A TELA E IMPRIMIR O MENU
    // ENTÃO AGUARDARÁ A OPÇÃO SER DIGITADA PELO USUÁRIO
    // EXECUTARÁ A FUNÇÃO CONTIDA DENTRO DA OPÇÃO DIGITADA PELO USUÁRIO
    // NÃO ENCERRARÁ O PROGRAMA ENQUANTO O USUÁRIO NÃO DIGITAR A OPÇÃO ZERO (0)
    do{
        system("cls");
        printf("\n-- MENU\n");
        printf("-- [1] - EXIBIR O CONTEUDO DO ARQUIVO TEXTO\n");
        printf("-- [2] - EXIBIR QTD DE VOGAIS NO ARQUIVO TEXTO\n");
        printf("-- [3] - TROCAR TODAS AS VOGAIS DO ARQUIVO TEXTO PELA LETRA \"I\"\n");
        printf("-- [4] - TROCAR A PRIMEIRA LETRA PARA MAIUSCULO E GRAVAR EM OUTRO ARQUIVO TEXTO\n");
        printf("-- [5] - IMPRIMIR FIGURA E GRAVAR EM OUTRO ARQUIVO TEXTO\n");
        printf("-- [6] - CEBOLINHA\n");
        printf("-- [0] - FECHAR PROGRAMA\n");
        printf("\n>> DIGITE O NUMERO DA OPCAO DESEJADA: ");
        fflush(stdin);
        scanf("%i", &op_menu); 
        switch(op_menu){
            case 0:
                op_menu = 0;
                break;
            case 1:
                carregaArquivoTexto(arquivo, nome_arquivo, ch);
                break;
            case 2:
                contaVogal(arquivo,nome_arquivo,ch);
                break;
            case 3:
                converteParaI(arquivo, nome_arquivo, ch);
                break;
            case 4:
                arquivoPrimeiraMaiusc(arquivo, nome_arquivo, ch);
                break;
            case 5:
                gravaFigura(arquivo, nome_arquivo, ch);
                break;
            case 6:
                cebolinha(arquivo, nome_arquivo, ch);
                break;
            default:
                printf("\nDIGITE UMA OPCAO VALIDA!\n\n");
                op_menu = 10;
                system("pause");
                break;
        };
    } while(op_menu != 0);
};
// -- FIM DE FUNÇÃO PRINCIPAL


// -- DEFINIÇÃO DE FUNÇÕES/EXERCÍCIOS

// - EX 1
// CARREGAR ARQUIVO TEXTO. NESSA OPÇÃO O SISTEMA DEVE SOLICITAR PARA O USUÁRIO O NOME DE UM ARQUIVO TEXTO E DEVERÁ EXIBIR SEU CONTEÚDO NA TELA;
// **O ARQUIVO TEXTO JÁ FOI DIGITADO INICIALMENTE, ENTÃO AQUI ESSA FUNÇÃO IRÁ APENAS EXIBIR O CONTEÚDO NA TELA
void carregaArquivoTexto(FILE *arquivo, char nome_arquivo[50], char ch){

    abreArqPrincipalModoR(arquivo, nome_arquivo); // FUNÇÃO RECORRENTE DE ABERTA DE ARQUIVO PRINCIPAL UTILIZADO NOS EXERCICIOS
    printf("\n"); // PRINTA UMA QUEBRA DE LINHA

    // WHILE + GETC UTILIZADO PARA LER TODOS OS CARACTERES DE UM ARQUIVO .TXT, REPOSICIONANDO O CURSOR PARA FRENTE CADA VEZ QUE VOLTA AO LAÇO DO WHILE
    while( (ch=getc(arquivo)) != EOF){  // IRÁ LER UM CARACTER INDIVIDUAL POR "VEZ" DO WHILE, ATÉ ENCONTRADOR O DELIMITADOR "EOF" DO ARQUIVO TEXTO
        printf("%c",ch);                // PRINTA CARACTER LIDO ATUALMENTE PELA FUNÇÃO GETC
    };
    
    fimDeExercicio(arquivo); // FUNÇÃO QUE CONTÉM 3 LINHAS RECORRENTES NO FINAL DE QUASE TODOS OS EXERCÍCIOS
};


// - EX 2
// QUANTIDADE DE CADA VOGAL NO ARQUIVO.
// NESSA OPÇÃO, O SISTEMA DEVERÁ MOSTRAR NA TELA A QUANTIDADE DE CADA VOGAL QUE APARECE NO ARQUIVO TEXTO CARREGADO NA OPÇÃO ANTERIOR.
void contaVogal(FILE *arquivo, char nome_arquivo[50], char ch){

    abreArqPrincipalModoR(arquivo, nome_arquivo); // FUNÇÃO RECORRENTE DE ABERTA DE ARQUIVO PRINCIPAL UTILIZADO NOS EXERCICIOS
    printf("\n"); // PRINTA UMA QUEBRA DE LINHA

    // DECLARAÇÃO DE VARIÁVEIS QUE IRÃO ARMAZENAR A QUANTIDADE/CONTAGEM DE VOGAL PARA CADA VOGAL
    int cont_a = 0,
        cont_e = 0,
        cont_i = 0,
        cont_o = 0,
        cont_u = 0;

    // WHILE + SWITCH QUE "VARRE" CADA CARACTER DO ARQUIVO E REALIZA A INCREMENTAÇÃO CASO FOR ALGUMA DAS VOGAIS
    while( (ch=getc(arquivo)) != EOF){
        switch(ch){
            case 'A': cont_a++; break;
            case 'a': cont_a++; break;
            case 'E': cont_e++; break;
            case 'e': cont_e++; break;
            case 'I': cont_i++; break;
            case 'i': cont_i++; break;
            case 'O': cont_o++; break;
            case 'o': cont_o++; break;
            case 'U': cont_u++; break;
            case 'u': cont_u++; break;
            default: break;
        };
    };

    // IMPRIME NA TELA O RESULTADO DA CONTAGEM DE VOGAIS INDIVIDUALMENTE, E DEPOIS O TOTAL
    printf("- A: %i\n", cont_a);
    printf("- E: %i\n", cont_e);
    printf("- I: %i\n", cont_i);
    printf("- O: %i\n", cont_o);
    printf("- U: %i\n", cont_u);
    printf("- TOTAL DE VOGAIS: %i", (cont_a+ cont_e + cont_i + cont_o +cont_u) );

    fimDeExercicio(arquivo); // FUNÇÃO QUE CONTÉM 3 LINHAS RECORRENTES NO FINAL DE QUASE TODOS OS EXERCÍCIOS
};


// - EX 3
// CONVERTE PARA I. NESSA OPÇÃO O SISTEMA DEVE LER O ARQUIVO TEXTO 
// ANTERIORMENTE CARREGADO, CARACTERE POR CARACTERE, E MOSTRAR NA TELA TODOS 
// OS CARACTERES, TROCANDO TODAS AS VOGAIS PELA VOGAL I.
void converteParaI(FILE *arquivo, char nome_arquivo[50], char ch){

    abreArqPrincipalModoR(arquivo, nome_arquivo); // FUNÇÃO RECORRENTE DE ABERTA DE ARQUIVO PRINCIPAL UTILIZADO NOS EXERCICIOS
    printf("\n"); // PRINTA UMA QUEBRA DE LINHA

    // WHILE + SWITCH QUE "VARRE" CADA CARACTER DO ARQUIVO E IMPRIME "I" NO LUGAR DE QUALQUER OUTRA VOGAL
    while( (ch=getc(arquivo)) != EOF){
        switch(ch){
            case 'A': printf("I"); break;
            case 'a': printf("i"); break;
            case 'E': printf("I"); break;
            case 'e': printf("i"); break;
            case 'O': printf("I"); break;
            case 'o': printf("i"); break;
            case 'U': printf("I"); break;
            case 'u': printf("i"); break;
            default: printf("%c", ch); break;
        };
    };

    fimDeExercicio(arquivo); // FUNÇÃO QUE CONTÉM 3 LINHAS RECORRENTES NO FINAL DE QUASE TODOS OS EXERCÍCIOS
};    


// - EX 4
// GRAVA ARQUIVO COM PRIMEIRA LETRA MAIÚSCULO. NESSA OPÇÃO O SISTEMA DEVERÁ CRIAR
// UM OUTRO ARQUIVO TEXTO COM O CONTEÚDO DO ARQUIVO TEXTO CARREGADO ANTERIORMENTE
// COM A PRIMEIRA LETRA DE CADA PALAVRA EM MAIÚSCULO. DICA: USAR O CÓDIGO ASCII.
void arquivoPrimeiraMaiusc(FILE *arquivo, char nome_arquivo[50], char ch){

    FILE *pri_maiusc;      // DECLARAÇÃO DE PONTEIRO PARA ARQUIVO UTILIZADO NESTE EXERCÍCIO
    char ch_anterior =' '; // DECLARAÇÃO DE VARIÁVEL QUE ARMAZENARÁ CARACTER ANTERIOR

    abreArqPrincipalModoR(arquivo, nome_arquivo); // FUNÇÃO RECORRENTE DE ABERTA DE ARQUIVO PRINCIPAL UTILIZADO NOS EXERCICIOS
    printf("\n"); // PRINTA UMA QUEBRA DE LINHA

    // CRIAÇÃO E ABERTURA DE ARQUIVO QUE SERÁ UTILIZADO NESTE EXERCICIO, O MODO UTILIZADO NO fopen() é o [w]rite (escrita/criação)
    if ( (pri_maiusc = fopen("pri_maiusc.txt","w")) == NULL) { 
        printf("Erro na abertura do arquivo.");
        exit(0);
    };

    // WHILE + IF QUE "VARRE" CADA CARACTER DO ARQUIVO E CASO SEJA A PRIMEIRA LETRA DE UMA PALAVRA, TRANSFORMA EM MAISCULO (SE AINDA NÃO FOR)
    // PARA TAL VERIFICAÇÃO, PRECISAMOS OLHAR SE O CARACTER ANTERIOR NÃO É UM ESPAÇO OU UMA QUEBRA DE LINHA
    while( (ch=getc(arquivo)) != EOF){
        if(ch_anterior == ' ' || ch_anterior == '\n'){
            if(ch >= 97 && ch <=122){
                ch = (ch - 32);
            };
        };
        putc(ch, pri_maiusc);
        printf("%c", ch);
        ch_anterior = ch;
    };

    fclose(pri_maiusc); // FECHA ARQUIVO ABERTO COM A FUNÇÃO fopen();
    fimDeExercicio(arquivo); // FUNÇÃO QUE CONTÉM 3 LINHAS RECORRENTES NO FINAL DE QUASE TODOS OS EXERCÍCIOS
};


// - EX 5
// GERA ARQUIVO FIGURA: NESSA OPÇÃO O SISTEMA DEVE CRIAR UM ARQUIVO TEXTO COM A SEGUINTE FIGURA:
void gravaFigura(FILE *arquivo, char nome_arquivo[50], char ch){
    
    // DECLARAÇÃO DE VARIÁVEIS INTERNAS DESSA FUNÇÃO
    FILE *figura;
    int linhas = 0,     // IRÁ RECEBER A QUANTIDADE DE LINHAS DIGITADA PELO USUÁRIO
        a = 0,          // VARIÁVEL CRIADA PARA SER UTILIZADA E INCREMENTADA DENTRO DE UM "FOR"
        b = 0,          // VARIÁVEL CRIADA PARA SER UTILIZADA E INCREMENTADA DENTRO DE UM "FOR"
        cont_linha = 0, // ARMAZENA A ÚLTIMA LINHA FEITA
        qtd_ast = 0,    // ARMAZENA A QUANTIDADE DE ASTERISCOS QUE DEVE SER IMPRESSO
        qtd_esp = 0;    // ARMAZENA A QUANTIDADE DE ESPAÇOS QUE DEVE SER IMPRESSO

    // CRIAÇÃO E ABERTURA DE ARQUIVO QUE SERÁ UTILIZADO NESTE EXERCICIO, O MODO UTILIZADO NO fopen() é o [w]rite (escrita/criação)
    if ( (figura = fopen("arquivo_figura.txt","w")) == NULL) { 
        printf("Erro na abertura do arquivo.");
        exit(0);
    };
    printf("\n"); //PRINTA UMA QUEBRA DE LINHA

    printf("DIGITE A QUANTIDADE DE LINHAS DA FIGURA: "); // PRINTA O CABEÇALHO
    fflush(stdin);        // LIMPA O BUFFER DO TECLADO
    scanf("%i", &linhas); // RECEBE A QUANTIDADE DE LINHAS DIGITADA PELO USUÁRIO
    printf("\n");         // PRINTA UMA QUEBRA DE LINHA

    for (a = 0; a < linhas; a++){       //ENTRA E "NAVEGA" PELAS LINHAS

        qtd_esp = linhas - cont_linha;  //CALCULA A QTD DE "ESPAÇO" QUE DEVERÁ SER GRAVADO NO ARQUIVO
        for(b = 1; b < qtd_esp; b++){   //LAÇO DE REPETIÇÃO QUE SERVE PARA GRAVAR A QTD DE "ESPAÇO" NECESSÁRIA
            printf(" ");
            putc(' ', figura);          //COMANDO DE GRAVAÇÃO DE CARACTER INDIVIDUAL EM ARQUIVO TIPO TEXTO
        };

        qtd_ast = a + cont_linha;       //CALCULA A QTD DE "ASTERISCO" QUE DEVERÁ SER GRAVADO NO ARQUIVO
                                        //QTD_AST = LINHA_ATUAL + CONT_LINHA
        for(b = 0; b <= qtd_ast; b++){  //LAÇO DE REPETIÇÃO QUE SERVE PARA GRAVAR A QTD DE "ASTERISCO" NECESSÁRIA
            printf("*");
            putc('*', figura);          //COMANDO DE GRAVAÇÃO DE CARACTER INDIVIDUAL EM ARQUIVO TIPO TEXTO
        };

        cont_linha++;                   //INCREMENTA A LINHA PARA A PRÓXIMA EXECUÇÃO DO FOR

        if(cont_linha < linhas){        //VERIFICA SE NÃO É A ÚLTIMA LINHA, SE NÃO FOR EXECUTA COMANDO ABAIXO
            printf("\n");
            putc('\n', figura);         //COMANDO DE GRAVAÇÃO DE "PULO DE LINHA" EM ARQUIVO TIPO TEXTO
        }
    };

    printf("\n\n");  //PRINTA UMA QUEBRA DE LINHA
    fclose(figura);  //FECHA ARQUIVO ABERTO COM A FUNÇÃO fopen();
    system("pause"); //GERA UMA PAUSA QUE AGUARDA QUALQUER TECLA SER PRESSIONADA P/ CONTINUAR
};

/*
         *
        ***
       *****
      *******
     *********
    ***********
   *************
  ***************
 *****************
*******************
OBS.: A QUANTIDADE DE LINHAS DEVE SER SOLICITADA PARA O USUÁRIO.


//1 LINHA
* -> 0 espaços

//     2 LINHAS
 *  -> 1 espaços
*** -> 0 espaços

//       3 LINHAS
  *   -> 2 espaços  
 ***  -> 1 espaços 
***** -> 0 espaços  

//         4 LINHAS -> (LINHAS - CONT_LINHA) = ESPAÇOS A SER PRINTADO     
   *    -> 1ª linha -> (4 - 1) = 3 espaços
  ***   -> 2ª linha -> (4 - 2) = 2 espaços
 *****  -> 3ª linha -> (4 - 3) = 1 espaços
******* -> 4ª linha -> (4 - 4) = 0 espaços

1 -> 1
2 -> 3
3 -> 5
4 -> 7
5 -> 9
6 -> 11
*/


// - EX 6 - DESAFIO CEBOLINHA
//NESTA OPÇÃO VOCÊ DEVE GERAR UM OUTRO ARQUIVO COM O NOME CEBOLINHA.TXT O QUAL TROCA O R PELO L COMO O PERSONAGEM CEBOLINHA.
//CEBOLINHA SÓ NÃO FALA ERRADO QUANDO A LETRA R É A ÚLTIMA DA PALAVRA SEGUIDA DE UMA VOGAL, TAIS COMO: "COMER", "DORMIR",
//APENAS TROCANDO AS LETRAS QUANDO O R ESTÁ NO MEIO OU NO INÍCIO DA PALAVRA.

void cebolinha(FILE *arquivo, char nome_arquivo[50], char ch){

    // DECLARAÇÃO DE VARIÁVEIS INTERNAS DESSA FUNÇÃO
    FILE *cebolinha;
    int flag_vogal = 0;    //0 - ANTERIOR NÃO É VOGAL, 1 - ANTERIOR É VOGAL
    char ch_prev = ' ',
         ch_current = ' ',
         ch_next = ' ';
    int cont = 0;
  
    abreArqPrincipalModoR(arquivo, nome_arquivo); // FUNÇÃO RECORRENTE DE ABERTA DE ARQUIVO PRINCIPAL UTILIZADO NOS EXERCICIOS
    printf("\n"); //PRINTA UMA QUEBRA DE LINHA

    if ( (cebolinha = fopen("cebolinha.txt","w")) == NULL) {  //ARQUIVO ABERTO CORRETAMENTE -> RETORNA PONTEIRO OK, CASO CONTRÁRIO RETORNA PONTEIRO NULL 
        printf("ERRO NA ABERTURA DO ARQUIVO.");
        exit(0);
    };

    while( ( ch = getc(arquivo)) != EOF){  //IRÁ EXIBIR CARACTER POR CARACTER DO ARQUIVO REFERENCIADO ATÉ O DELIMITADOR "EOF"
        ch_prev = ch_current;
        ch_current = ch_next;
        ch_next = ch;

        if (cont < 2){
            cont++;
        }
        else {
            if (ch_prev == ' ' || ch_prev == '\n'){
                gravarCh(ch_prev, cebolinha);
            }
            else if((ch_prev != ' ' || ch_prev != '\n') && (ch_current == ' ' || ch_current == '\n')){
                if(flag_vogal == 1){
                    gravarCh(ch_prev, cebolinha);
                }
                else{
                    if(ch_prev == 'r' || ch_prev == 'R'){
                        printf("%c", upperOrLower(ch_prev));
                        putc(upperOrLower(ch_prev), cebolinha);
                    }
                    else{
                        gravarCh(ch_prev, cebolinha);
                    }
                }
            }
            else{
                if((ch_current > 31 && ch_current < 65) || (ch_current > 90 && ch_current < 97) || ch_current > 122){
                    if(flag_vogal == 1){
                        gravarCh(ch_prev, cebolinha);
                    }
                    else{
                        if(ch_prev == 'r' || ch_prev == 'R'){
                            printf("%c", upperOrLower(ch_prev));
                            putc(upperOrLower(ch_prev), cebolinha);
                        }
                        else{
                            gravarCh(ch_prev, cebolinha);
                        };
                    };
                    flag_vogal = 0;
                }
                else{
                    if(ch_prev == 'A' || ch_prev == 'a' || ch_prev == 'E' || ch_prev == 'e' || ch_prev == 'I' || ch_prev == 'i' || ch_prev == 'O' || ch_prev == 'o' ||ch_prev == 'U' || ch_prev == 'u'){
                        flag_vogal = 1;
                    }
                    else{
                        flag_vogal = 0;
                    };
                    if(ch_prev == 'r' || ch_prev == 'R'){
                        printf("%c", upperOrLower(ch_prev));
                        putc(upperOrLower(ch_prev), cebolinha);
                    }
                    else{
                        gravarCh(ch_prev, cebolinha);
                    }
                }
            };
        };
    };


    if((ch_current > 64 && ch_current < 97) || (ch_current > 96 && ch_current < 123)){
        if((ch_next > 31 && ch_next < 65) || (ch_next > 90 && ch_next < 97) || ch_next > 122){
            if(flag_vogal == 1){
                gravarCh(ch_current, cebolinha);
            }
            else{
                if(ch_current == 'r' || ch_current == 'R'){
                    printf("%c", upperOrLower(ch_current));
                    putc(upperOrLower(ch_current), cebolinha);
                }
                else{
                    gravarCh(ch_current, cebolinha);
                }
            }
        }
        else{
            if(ch_current == 'r' || ch_current == 'R'){
                printf("%c", upperOrLower(ch_current));
                putc(upperOrLower(ch_current), cebolinha);
            }
            else{
                gravarCh(ch_current, cebolinha);
            }
        };
    }
    else{
        gravarCh(ch_current, cebolinha);
    }


    if(ch_current == 'A' || ch_current == 'a' || ch_current == 'E' || ch_current == 'e' || ch_current == 'I' || ch_current == 'i' || ch_current == 'O' || ch_current == 'o' ||ch_current == 'U' || ch_current == 'u'){
        flag_vogal = 1;
    }
    else{
        flag_vogal = 0;
    }
    

    if((ch_next > 64 && ch_next < 97) || (ch_next > 96 && ch_next < 123)){
        if(flag_vogal == 1){
            gravarCh(ch_next, cebolinha);
            flag_vogal == 0;
        }
        else{
            if(ch_next == 'r' || ch_next == 'R'){
                printf("%c", upperOrLower(ch_next));
                putc(upperOrLower(ch_next), cebolinha);
            }
            else{
                gravarCh(ch_next, cebolinha);
            }
        }
    }
    else{
        gravarCh(ch_next, cebolinha);
        flag_vogal = 0;
    }
    
    fclose(cebolinha); // FECHA ARQUIVO ABERTO COM A FUNÇÃO fopen();
    fimDeExercicio(arquivo); // FUNÇÃO QUE CONTÉM 3 LINHAS RECORRENTES NO FINAL DE QUASE TODOS OS EXERCÍCIOS
};


// -- FUNÇÃO QUE ABRE O ARQUIVO PRINCIPAL DO TRABALHO
void abreArqPrincipalModoR(FILE *arquivo, char nome_arquivo[50]){
    arquivo = fopen(nome_arquivo,"r");
};


// -- FUNÇÃO AUXILIAR QUE GRAVA CARACTERE E O IMPRIME NA TELA
void gravarCh(char ch, FILE *arquivo){
    printf("%c", ch);   // PRINTA CARACTER RECEBIDO COMO PARÂMETRO PELA FUNÇÃO
    putc(ch, arquivo);  // GRAVA CARACTER NO ARQUIVO RECEBIDO COMO PARÂMETRO
};


// -- FUNÇÃO DE FIM DE EXERCICIO
void fimDeExercicio(FILE *arquivo){
   printf("\n");    // PRINTA UMA QUEBRA DE LINHA
   fclose(arquivo); // FECHA ARQUIVO ABERTO COM A FUNÇÃO fopen();
   printf("\n");    // PRINTA UMA QUEBRA DE LINHA
   system("pause"); // GERA UMA PAUSA QUE AGUARDA QUALQUER TECLA SER PRESSIONADA P/ CONTINUAR 
};


// -- FUNÇÃO AUXILIAR QUE CHECA O CASE DO CARACTER "R"
char upperOrLower(char x){
    if ((x>=97)&&(x<=122))
    {
        return 'l';
    }
    else
    {
        return 'L';
    };
};

