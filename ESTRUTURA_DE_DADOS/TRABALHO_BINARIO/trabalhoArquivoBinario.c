// -- INCLUSAO DE BIBLIOTECAS AUXILIARES
#include <conio.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


// -- ROTULOS
// ESTRUTURA DO ROTULO >> #define ROTULO_DESEJADO INFORMACAO_QUE_SUBSTITUIRA_O_ROTULO
#define AUTORES "Autores.dat"
#define CATEGORIAS "Categorias.dat"
#define EDITORAS "Editoras.dat"
#define LIVROS "Livros.dat"


// -- DECLARACAO E DEFINICAO DE STRUCTS
struct reg_autor{
    int cod;
    char nome[20],
         sobrenome[30];
};
typedef struct reg_autor reg_autor; // ESTRUTURA DO TYPEDEF >> typedef struct NOME_DA_STRUCT APELIDO_PARA_"STRUCT_E_NOME_DA_STRUCT";

struct reg_categoria{
    int cod;
    char desc[20];
};
typedef struct reg_categoria reg_categoria;
                             
struct reg_editora{
    int cod;
    char nome[20],
         contato[20],
         fone[14],
         email[40];
};
typedef struct reg_editora reg_editora;

struct reg_livro{
    char titulo[50];
    float preco;
    int cod,
        cod_autor_1,
        cod_autor_2,
        cod_autor_3,
        cod_autor_4,
        cod_ctg,
        cod_editora;
    int edicao,
        ano_pub,
        qtd_est;
};
typedef struct reg_livro reg_livro;


// -- DECLARACAO DE FUNCOES AUXILIARES
void atualizarDatabases();  // GERENCIA ARQUIVOS .dat
void vgets(char *x);        // FUNCAO QUE NORMALIZA TODAS AS DIGITACOES PARA MAIUSCULO, EVITANDO ERROS DE BUSCA POR DIFERENCA DE CAIXAS
void geraCabecalhoPadrao(); // GERA CABECALHO PADRAO PARA EXERCICIOS DE CONSULTA/RELATORIO


// -- DECLARACAO DE FUNCOES "EXERCICIOS"
void cadastrarAutor();
void cadastrarCategoria();
void cadastrarEditora();
void cadastrarLivro();
void listarAutores();
void listarCategorias();
void listarEditoras();
void listarLivros();
void excluirCategoria();
void consultarLivro();
void consultarAutor();
void relatarLivrosPorCategoria();
void relatarLivrosPorAutor();
void relatarEstoqueEmArqTexto();
void relatarMaiorValorCategoria();


// -- DECLARACAO DE VARIAVEIS GLOBAIS
/*
- O SISTEMA GERA O CODIGO AUTOMATICO PARA O USUARIO NAO SE PREOCUPAR COM NUMEROS E/OU SOBREPOSICAO DE CODIGOS.
- ESTES CONTADORES FAZEM A LEITURA DOS ARQUIVOS .DAT JA GERADOS PELO PROPRIO SISTEMA PARA TER CIENCIA DOS ULTIMOS CODIGOS CADASTRADOS.
*/
int cont_cod_autores = 0;
int cont_cod_categorias = 0;
int cont_cod_editoras = 0;
int cont_cod_livros = 0;


// -- LOGICA DO PROGRAMA PRINCIPAL
int main(){
    int op = 100;
    atualizarDatabases();
    do{
        system("cls");
        printf("\n>> SISTEMA DE CONTROLE DE LIVRARIA");
        printf("\n>> ANDRE - VINICIUS");
        printf("\n\n -- MENU");
        printf("\n 1. CADASTRAR AUTOR");
        printf("\n 2. CADASTRAR CATEGORIA");
        printf("\n 3. CADASTRAR EDITORA");
        printf("\n 4. CADASTRAR LIVRO");
        printf("\n 5. LISTAR AUTORES");
        printf("\n 6. LISTAR CATEGORIAS");
        printf("\n 7. LISTAR EDITORAS");
        printf("\n 8. LISTAR LIVROS");
        printf("\n 9. EXCLUIR CATEGORIA");
        printf("\n10. CONSULTAR LIVRO - POR PALAVRA-CHAVE NO TITULO");
        printf("\n11. CONSULTAR AUTOR - POR PARTE INICIAL DO NOME");
        printf("\n12. RELATORIO DE LIVROS - POR CATEGORIA");
        printf("\n13. RELATORIO DE LIVROS - POR AUTOR");
        printf("\n14. (GERA ARQUIVO TEXTO) RELATORIO DE ESTOQUE ABAIXO DE: [QTD]");
        printf("\n15. RELATORIO DE MAIOR(ES) VALOR(ES) DE CATEGORIA");
        printf("\n 0. FECHAR O PROGRAMA");
        printf("\n\n >> DIGITE O NUMERO DA OPCAO SELECIONADA: ");
        fflush(stdin);
        scanf("%i", &op);
        switch(op){
            case 0:
                op = 100;
                system("cls");
                break;
            case 1:
                cadastrarAutor();
                break;
            case 2:
                cadastrarCategoria();
                break;
            case 3:
                cadastrarEditora();
                break;
            case 4:
                cadastrarLivro();
                break;
            case 5:
                listarAutores();
                break;
            case 6:
                listarCategorias();
                break;
            case 7:
                listarEditoras();
                break;
            case 8:
                listarLivros();
                break;
            case 9:
                excluirCategoria();
                break;
            case 10:
                consultarLivro();
                break;
            case 11:
                consultarAutor();
                break;
            case 12:
                relatarLivrosPorCategoria();
                break;
            case 13:
                relatarLivrosPorAutor();
                break;
            case 14:
                relatarEstoqueEmArqTexto();
                break;
            case 15:
                relatarMaiorValorCategoria();
                break;
            default:
                printf("\nOPCAO INVALIDA! APERTA QUALQUER TECLA P/ RETORNAR AO MENU. >> ");
                system("pause");
                break;
        };
    } while(op != 100);    
};


// -- DEFINICAO DE FUNCOES AUXILIARES
// -- 1. CADASTRAR AUTOR
void cadastrarAutor(){
    FILE *dat_autor;
    char confirma;
    //struct reg_autor autor;
             reg_autor autor; // TYPEDEF DE STRUCT REG_AUTOR
    system("cls");
    printf(">> SISTEMA DE CONTROLE DE LIVRARIA\n");
    printf("\n>> CADASTRAR AUTOR <<\n");        
    printf("\nCODIGO DO AUTOR: %i", cont_cod_autores + 1);
    printf("\nDIGITE O SOBRENOME DO AUTOR: ");
    vgets(autor.sobrenome);
    printf("DIGITE O NOME DO AUTOR: ");
    vgets(autor.nome);
    printf("\nCONFIRMA O CADASTRAMENTO (S/N)? : ");
    fflush(stdin);
    confirma = getche();

    do{
        switch(confirma){
            case 'S': break;
            case 's': break;
            case 'N': break;
            case 'n': break;
            default:
                printf("\nOPCAO INVALIDA, DIGITE 'S' OU 'N': ");
                fflush(stdin);
                confirma = getche();
                break;
        };
    } while (confirma != 'S' && confirma != 's' && confirma != 'N' && confirma != 'n');

    if(confirma == 'S' || confirma == 's'){
        cont_cod_autores++;
        autor.cod = cont_cod_autores;
        dat_autor = fopen(AUTORES, "ab");
        fwrite(&autor, sizeof(autor), 1, dat_autor);
        fclose(dat_autor);
        printf("\n\nCADASTRO DE AUTOR REALIZADO COM SUCESSO! ");
    }
    else{
        printf("\n\nOPERACAO CANCELADA! ");
    };

    printf("\n");
    system("pause");
    return;
};

// -- 2. CADASTRAR CATEGORIA
void cadastrarCategoria(){
    FILE *dat_categoria;
    reg_categoria categoria;
    char confirma = 'n';
    system("cls");
    printf(">> SISTEMA DE CONTROLE DE LIVRARIA\n");
    printf("\n>> CADASTRAR CATEGORIA <<\n");  
    printf("\nCODIGO DA CATEGORIA: %i", cont_cod_categorias + 1);
    printf("\nDIGITE O NOME DA CATEGORIA: ");
    vgets(categoria.desc);
    printf("\nCONFIRMA O CADASTRAMENTO (S/N)? : ");
    fflush(stdin);
    confirma = getche();

    do{ 
        switch(confirma){
            case 'S': break;
            case 's': break;
            case 'N': break;
            case 'n': break;
            default:
                printf("\nOPCAO INVALIDA, DIGITE 'S' OU 'N': ");
                fflush(stdin);
                confirma = getche();
                break;
        };
    } while (confirma != 'S' && confirma != 's' && confirma != 'N' && confirma != 'n');

    if(confirma == 'S' || confirma == 's'){
        cont_cod_categorias++;
        categoria.cod = cont_cod_categorias;
        dat_categoria = fopen(CATEGORIAS, "ab");
        fwrite(&categoria, sizeof(categoria), 1, dat_categoria);
        fclose(dat_categoria);
        printf("\n\nCADASTRO DE CATEGORIA REALIZADO COM SUCESSO! ");
    }
    else{
        printf("\n\nOPERACAO CANCELADA! ");
    };

    printf("\n");
    system("pause");
    return;
};

// -- 3. CADASTRAR EDITORA
void cadastrarEditora(){
    FILE *dat_editora;
    reg_editora editora;
    char confirma = 'n';
    system("cls");
    printf(">> SISTEMA DE CONTROLE DE LIVRARIA\n");
    printf("\n>> CADASTRAR EDITORA <<\n");
    printf("\nCODIGO DA EDITORA: %i", cont_cod_editoras + 1);
    printf("\nDIGITE O NOME DA EDITORA: ");
    vgets(editora.nome);
    printf("DIGITE O CONTATO DA EDITORA: ");
    vgets(editora.contato);
    printf("DIGITE O TELEFONE DA EDITORA: ");
    vgets(editora.fone);
    printf("DIGITE O E-MAIL DA EDITORA: ");
    vgets(editora.email);
    printf("CONFIRMA O CADASTRAMENTO (S/N)? : ");
    fflush(stdin);
    confirma = getche();

    do{ 
        switch(confirma){
            case 'S': break;
            case 's': break;
            case 'N': break;
            case 'n': break;
            default:
                printf("\nOPCAO INVALIDA, DIGITE 'S' OU 'N': ");
                fflush(stdin);
                confirma = getche();
                break;
        };
    } while (confirma != 'S' && confirma != 's' && confirma != 'N' && confirma != 'n');

    if(confirma == 'S' || confirma == 's'){
        cont_cod_editoras++;
        editora.cod = cont_cod_editoras;
        dat_editora = fopen(EDITORAS, "ab");
        fwrite(&editora, sizeof(editora), 1, dat_editora);
        fclose(dat_editora);
        printf("\n\nCADASTRO REALIZADO COM SUCESSO! ");
    }
    else{
        printf("\n\nOPERACAO CANCELADA! ");
    };

    printf("\n");
    system("pause");
    return;
};

// -- 4. CADASTRAR LIVRO
void cadastrarLivro(){
    FILE *dat_livro;
    reg_livro livro;
    char confirma = 'n';
    system("cls");
    printf(">> SISTEMA DE CONTROLE DE LIVRARIA\n");
    printf("\n>> CADASTRAR LIVRO <<\n");
    printf("\nCODIGO DO LIVRO: %i", cont_cod_livros + 1);
    printf("\nDIGITE O TITULO DO LIVRO: ");
    vgets(livro.titulo);
    printf("DIGITE O PRECO DO LIVRO: ");
    fflush(stdin);
    scanf("%f", &livro.preco);
    printf("DIGITE O CODIGO DO AUTOR 1 DO LIVRO: ");
    fflush(stdin);
    scanf("%i", &livro.cod_autor_1);
    if (livro.cod_autor_1 > cont_cod_autores){
        printf("\nCOD INEXISTENTE, CONSULTE NO MENU UM VALIDO! ");
        system("pause");
        return;
    };
    printf("DIGITE O CODIGO DO AUTOR 2 DO LIVRO (0 - SE NAO HOUVER): ");
    fflush(stdin);
    scanf("%i", &livro.cod_autor_2);
    if (livro.cod_autor_2 > cont_cod_autores){
        printf("\nCOD INEXISTENTE, CONSULTE NO MENU UM VALIDO! ");
        system("pause");
        return;
    };
    printf("DIGITE O CODIGO DO AUTOR 3 DO LIVRO (0 - SE NAO HOUVER): ");
    fflush(stdin);
    scanf("%i", &livro.cod_autor_3);
    if (livro.cod_autor_3 > cont_cod_autores){
        printf("\nCOD INEXISTENTE, CONSULTE NO MENU UM VALIDO! ");
        system("pause");
       return;
    };
    printf("DIGITE O CODIGO DO AUTOR 4 DO LIVRO (0 - SE NAO HOUVER): ");
    fflush(stdin);
    scanf("%i", &livro.cod_autor_4);
    if (livro.cod_autor_4 > cont_cod_autores){
        printf("\nCOD INEXISTENTE, CONSULTE NO MENU UM VALIDO! ");
        system("pause");
       return;
    };
    printf("DIGITE O CODIGO DA CATEGORIA DO LIVRO: ");
    fflush(stdin);
    scanf("%i", &livro.cod_ctg);
    if (livro.cod_ctg > cont_cod_categorias){
        printf("\nCOD INEXISTENTE, CONSULTE NO MENU UM VALIDO! ");
        system("pause");
        return;
    }; 

    printf("DIGITE O CODIGO DA EDITORA DO LIVRO: ");
    fflush(stdin);
    scanf("%i", &livro.cod_editora);
    if (livro.cod_editora > cont_cod_editoras){
        printf("\nCOD INEXISTENTE, CONSULTE NO MENU UM VALIDO! ");
        system("pause");
        return;
    };
    printf("DIGITE A EDICAO DO LIVRO: ");
    fflush(stdin);
    scanf("%i", &livro.edicao);
    printf("DIGITE O ANO DA PUBLICACAO DO LIVRO: ");
    fflush(stdin);
    scanf("%i", &livro.ano_pub);
    printf("DIGITE A QUANTIDADE EM ESTOQUE DO LIVRO: ");
    fflush(stdin);
    scanf("%i", &livro.qtd_est);
    printf("CONFIRMA O CADASTRAMENTO (S/N)? : ");
    fflush(stdin);
    confirma = getche();
    do{ 
        switch(confirma){
            case 'S': break;
            case 's': break;
            case 'N': break;
            case 'n': break;
            default:
                printf("\nOPCAO INVALIDA, DIGITE 'S' OU 'N': ");
                fflush(stdin);
                confirma = getche();
                break;
        };
    } while (confirma != 'S' && confirma != 's' && confirma != 'N' && confirma != 'n');

    if(confirma == 'S' || confirma == 's'){
        cont_cod_livros++;
        livro.cod = cont_cod_livros;
        dat_livro = fopen(LIVROS, "ab");
        fwrite(&livro, sizeof(livro), 1, dat_livro);
        fclose(dat_livro);
        printf("\n\nCADASTRO REALIZADO COM SUCESSO! ");
    }
    else{
        printf("\n\nOPERACAO CANCELADA! ");
    };

    printf("\n");
    system("pause");
    return;
};

// -- 5. LISTAR AUTORES
void listarAutores(){
    FILE *dat_autor;
    reg_autor autor;
    system("cls");
    printf(">> SISTEMA DE CONTROLE DE LIVRARIA\n");
    printf("\n>> LISTA DE AUTORES <<\n");
    printf("\nCOD  \tNOME                \tSOBRENOME                     \n");
    dat_autor = fopen(AUTORES, "rb");
    while(fread(&autor, sizeof(autor), 1, dat_autor) == 1){
        printf("%-5i\t", autor.cod);
        printf("%-20s\t", autor.nome);
        printf("%-30s\n", autor.sobrenome);
    };
    fclose(dat_autor);
    printf("\n");
    system("pause");
    return;
};

// -- 6. LISTAR CATEGORIAS
void listarCategorias(){
    FILE *dat_categoria;
    reg_categoria categoria;
    dat_categoria = fopen(CATEGORIAS, "rb");
    system("cls");
    printf(">> SISTEMA DE CONTROLE DE LIVRARIA\n");
    printf("\n>> LISTA DE CATEGORIAS <<\n");
    printf("\nCOD  \tCATEGORIA           \n"); 
    while(fread(&categoria, sizeof(categoria), 1, dat_categoria) == 1){
        printf("%-5i\t", categoria.cod);
        printf("%-20s\n", categoria.desc);
    };
    fclose(dat_categoria);
    printf("\n");
    system("pause");
    return;
};

// -- 7. LISTAR EDITORAS
void listarEditoras(){
    FILE *dat_editora;
    reg_editora editora;
    dat_editora = fopen(EDITORAS, "rb");
    system("cls");
    printf(">> SISTEMA DE CONTROLE DE LIVRARIA\n");
    printf("\n>> LISTA DE EDITORAS <<\n");
    printf("\nCOD   ");
    printf("\tNOME                ");
    printf("\tCONTATO             ");
    printf("\tFONE          ");
    printf("\tEMAIL                                   \n");
    while(fread(&editora, sizeof(editora), 1, dat_editora) == 1){
        printf("%-5i\t", editora.cod);
        printf("%-20s\t", editora.nome);
        printf("%-20s\t", editora.contato);
        printf("%-14s\t", editora.fone);
        printf("%-40s\n", editora.email);
    };
    fclose(dat_editora);
    printf("\n");
    system("pause");
    return;
};

// -- 8. LISTAR LIVROS
void listarLivros(){
    FILE *dat_livro;
    reg_livro livro;

    system("cls");
    printf(">> SISTEMA DE CONTROLE DE LIVRARIA\n");
    printf("\n>> LISTA DE LIVROS <<\n");
    printf("\nCOD  ");
    printf("\tTITULO                                            ");
    printf("\tPRECO ");
    printf("\tAUT1");  
    printf("\tAUT2");  
    printf("\tAUT3");  
    printf("\tAUT4");  
    printf("\tCOD CATEGORIA");
    printf("\tCOD EDITORA");
    printf("\tEDICAO");
    printf("\tANO");
    printf("\tQTD\n");

    dat_livro = fopen(LIVROS, "rb");

    while(fread(&livro, sizeof(livro), 1, dat_livro) == 1){
        printf("%-5i",livro.cod);
        printf("\t%-50s",livro.titulo);
        printf("\t%-6.2f",livro.preco);
        printf("\t%-4i",livro.cod_autor_1);
        printf("\t%-4i",livro.cod_autor_2);
        printf("\t%-4i",livro.cod_autor_3);
        printf("\t%-4i",livro.cod_autor_4);
        printf("\t%-13i",livro.cod_ctg);
        printf("\t%-11i",livro.cod_editora);
        printf("\t%-6i",livro.edicao);
        printf("\t%-4i",livro.ano_pub);
        printf("\t%-3i\n",livro.qtd_est);
    };

    fclose(dat_livro);
    printf("\n");
    system("pause");
    return;
};

// -- 9. EXCLUIR CATEGORIA
void excluirCategoria(){
    FILE *dat_categoria,
         *dat_categoria_new;
    char confirma = 'n';
    int achou = 0,
        codigo = 0;
    reg_categoria categoria;

    system("cls");
    printf(">> SISTEMA DE CONTROLE DE LIVRARIA\n");
    printf("\n>> EXCLUIR CATEGORIA <<\n");
    printf("\nDIGITE O CODIGO DA CATEGORIA P/ EXCLUSAO: ");
    fflush(stdin);
    scanf("%i", &codigo);

    dat_categoria = fopen(CATEGORIAS, "rb");
    while(fread(&categoria, sizeof(categoria), 1, dat_categoria) == 1){
        if(codigo == categoria.cod){
            printf("CODIGO: %i\n", categoria.cod);
            printf("CATEGORIA: %s\n", categoria.desc);
            achou = 1;
        };
    };
    fclose(dat_categoria);

    if(achou == 0){
        printf("\nCATEGORIA NAO ENCONTRADA! \n");
        system("pause");
        return;
    };

    printf("\nCONFIRMA EXCLUSAO? (S/n)");
    printf("\nDIGITE A OPCAO: ");
    fflush(stdin);
    confirma = getche();
    if(confirma != 'S' && confirma != 's'){
        printf("\n\nEXCLUSAO CANCELADA! \n");
        system("pause");
        return;
    };

    dat_categoria = fopen(CATEGORIAS, "rb");
    dat_categoria_new = fopen("Categorias_new.dat", "wb");
    while(fread(&categoria, sizeof(categoria), 1, dat_categoria) == 1){
        if(codigo != categoria.cod){
            fwrite(&categoria, sizeof(categoria), 1, dat_categoria_new);
        };
    };
    fclose(dat_categoria);
    fclose(dat_categoria_new);
    system("del Categorias.dat");
    system("ren Categorias_new.dat Categorias.dat");
    printf("\n\nEXCLUSAO REALIZADA COM SUCESSO! ");
    printf("\n");
    system("pause");
    return;
};

// -- 10. CONSULTAR LIVRO - POR PALAVRA-CHAVE NO TITULO
void consultarLivro(){
    FILE *dat_autor,
         *dat_categoria,
         *dat_editora,
         *dat_livro;
    reg_autor autor;
    reg_categoria categoria;
    reg_editora editora;
    reg_livro livro;
    char keyword[30] ="";
    int achou = 0;

    system("cls");
    printf(">> SISTEMA DE CONTROLE DE LIVRARIA\n");
    printf("\n>> CONSULTAR LIVRO POR PALAVRA-CHAVE NO TITULO <<\n");
    printf("\nDIGITE A PALAVRA-CHAVE P/ PROCURAR NO TITULO: ");
    vgets(keyword);
    printf("\n");
    geraCabecalhoPadrao();

    dat_livro = fopen(LIVROS,"rb");
    while(fread(&livro, sizeof(livro), 1, dat_livro) == 1){
        if(strstr(livro.titulo, keyword)!=NULL){
            achou = 1;
            printf("%-3i", livro.cod);
            printf("\t%-50s", livro.titulo);
            printf("\t%-6.2f", livro.preco);

            dat_autor = fopen(AUTORES, "rb");
            while(fread(&autor, sizeof(autor), 1, dat_autor) == 1){
                if(livro.cod_autor_1 == autor.cod){
                    printf("\t%-20s", autor.nome);
                };
            };
            fclose(dat_autor);

            dat_autor = fopen(AUTORES, "rb");
            if(livro.cod_autor_2 == 0){
                printf("\t                    ");
            }
            else{
                while(fread(&autor, sizeof(autor), 1, dat_autor) == 1){
                    if(livro.cod_autor_2 == autor.cod){
                        printf("\t%-20s", autor.nome);
                    }
                };
            };
            fclose(dat_autor);

            dat_autor = fopen(AUTORES, "rb");
            if(livro.cod_autor_3 == 0){
                printf("\t                    ");
            }
            else{
                while(fread(&autor, sizeof(autor), 1, dat_autor) == 1){
                    if(livro.cod_autor_3 == autor.cod){
                        printf("\t%-20s", autor.nome);
                    }
                };
            };
            fclose(dat_autor);

            dat_autor = fopen(AUTORES, "rb");
            if(livro.cod_autor_4 == 0){
                printf("\t                    ");
            }
            else{
                while(fread(&autor, sizeof(autor), 1, dat_autor) == 1){
                    if(livro.cod_autor_4 == autor.cod){
                        printf("\t%-20s", autor.nome);

                    }
                };
            };
            fclose(dat_autor);

            dat_categoria = fopen(CATEGORIAS, "rb");
            while(fread(&categoria, sizeof(categoria), 1, dat_categoria) == 1){
                if(livro.cod_ctg == categoria.cod){
                    printf("\t%-20s", categoria.desc);

                };
            };
            fclose(dat_categoria);

            dat_editora = fopen(EDITORAS, "rb");
            while(fread(&editora, sizeof(editora), 1, dat_editora) == 1){
                if(livro.cod_editora == editora.cod){
                    printf("\t%-20s", editora.nome);

                };
            };
            fclose(dat_editora);
            printf("\t%-6i", livro.edicao);  
            printf("\t%-6i", livro.ano_pub);     
            printf("\t%-3i\n", livro.qtd_est);
        };
    };
    if(achou == 0){
        printf("\nNAO FORAM ENCONTRADOS RESULTADOS!");
    };

    fclose(dat_livro);
    printf("\n");
    system("pause");
};

// -- 11. CONSULTAR AUTOR - POR PARTE INICIAL DO NOME
void consultarAutor(){
    FILE *dat_autor;
    char parte_inicial[30] ="";
    int achou = 0;

    dat_autor = fopen(AUTORES,"rb");
    reg_autor autor;

    system("cls");
    printf(">> SISTEMA DE CONTROLE DE LIVRARIA\n");
    printf("\n>> CONSULTAR AUTOR POR PARTE INICIAL DO NOME <<\n");
    printf("\nDIGITE A PARTE INICIAL DO NOME DO AUTOR: ");
    vgets(parte_inicial);

    printf("\n");
    printf("COD");
    printf("\tNOME                ");
    printf("\tSOBRENOME                     \n");

    while(fread(&autor, sizeof(autor), 1, dat_autor) == 1){
        if(strstr(autor.nome, parte_inicial) != NULL){
            achou = 1;
            printf("%-3i", autor.cod);
            printf("\t%-20s", autor.nome);
            printf("\t%-30s\n", autor.sobrenome);

        }
    };
    if(achou == 0){
        printf("\nNAO FORAM ENCONTRADOS RESULTADOS!\n");
    };

    fclose(dat_autor);
    printf("\n");
    system("pause");
};

// -- 12. RELATORIO DE LIVROS POR CATEGORIA
void relatarLivrosPorCategoria(){
    FILE *dat_autor,
         *dat_categoria,
         *dat_editora,
         *dat_livro;
    
    int opcao = 0;

    reg_autor autor;
    reg_categoria categoria;
    reg_editora editora;
    reg_livro livro;

    system("cls");
    printf(">> SISTEMA DE CONTROLE DE LIVRARIA\n");
    printf("\n>> RELATORIO DE LIVROS POR CATEGORIA <<\n");
    printf("\nESCOLHA 1 CATEGORIA P/ GERAR RELATORIO: \n");
    printf("COD");
    printf("\tCATEGORIA           \n");
    dat_categoria = fopen(CATEGORIAS, "rb");
    while(fread(&categoria, sizeof(categoria), 1, dat_categoria) == 1){
        printf("%-3i",categoria.cod);
        printf("\t%-20s\n",categoria.desc);
    };
    fclose(dat_categoria);
    printf("\nDIGITE O COD DA CATEGORIA DESEJADA: ");
    fflush(stdin);
    scanf("%i", &opcao);
    if(opcao > cont_cod_categorias){
        printf("\nOPCAO INVALIDA! \n");
        system("pause");
        return;
    };
    
    geraCabecalhoPadrao();

    dat_categoria = fopen(CATEGORIAS,"rb");
    while(fread(&categoria, sizeof(categoria), 1, dat_categoria) == 1){
        if(opcao == categoria.cod){
            dat_livro = fopen(LIVROS,"rb");
            while(fread(&livro, sizeof(livro), 1, dat_livro) == 1){
                if(categoria.cod == livro.cod_ctg){
                    printf("%-3i", livro.cod);
                    printf("\t%-50s", livro.titulo);
                    printf("\t%-6.2f", livro.preco);

                    dat_autor = fopen(AUTORES, "rb");
                    while(fread(&autor, sizeof(autor), 1, dat_autor) == 1){
                        if(livro.cod_autor_1 == autor.cod){
                            printf("\t%-20s", autor.nome);
                        };
                    };
                    fclose(dat_autor);

                    dat_autor = fopen(AUTORES, "rb");
                    if(livro.cod_autor_2 == 0){
                        printf("\t                    ");
                    }
                    else{
                        while(fread(&autor, sizeof(autor), 1, dat_autor) == 1){
                            if(livro.cod_autor_2 == autor.cod){
                                printf("\t%-20s", autor.nome);
                            }
                        };
                    };
                    fclose(dat_autor);

                    dat_autor = fopen(AUTORES, "rb");
                    if(livro.cod_autor_3 == 0){
                        printf("\t                    ");
                    }
                    else{
                        while(fread(&autor, sizeof(autor), 1, dat_autor) == 1){
                            if(livro.cod_autor_3 == autor.cod){
                                printf("\t%-20s", autor.nome);
                            }
                        };
                    };
                    fclose(dat_autor);

                    dat_autor = fopen(AUTORES, "rb");
                    if(livro.cod_autor_4 == 0){
                        printf("\t                    ");
                    }
                    else{
                        while(fread(&autor, sizeof(autor), 1, dat_autor) == 1){
                            if(livro.cod_autor_4 == autor.cod){
                                printf("\t%-20s", autor.nome);

                            }
                        };
                    };
                    fclose(dat_autor);

                    printf("\t%-20s", categoria.desc);
      
                    dat_editora = fopen(EDITORAS, "rb");
                    while(fread(&editora, sizeof(editora), 1, dat_editora) == 1){
                        if(livro.cod_editora == editora.cod){
                            printf("\t%-20s", editora.nome);

                        };
                    };
                    fclose(dat_editora);
                    printf("\t%-6i", livro.edicao);  
                    printf("\t%-6i", livro.ano_pub);     
                    printf("\t%-3i\n", livro.qtd_est);        
                };
            };
            fclose(dat_livro);
        };
    };

    fclose(dat_categoria);
    printf("\n");
    system("pause");
};

// -- 13. RELATORIO DE LIVROS POR AUTOR
void relatarLivrosPorAutor(){
    FILE *dat_autor,
         *dat_categoria,
         *dat_editora,
         *dat_livro;
    int opcao = 0;
    int existente = 0;

    reg_autor autor;
    reg_categoria categoria;
    reg_editora editora;
    reg_livro livro;

    system("cls");
    printf(">> SISTEMA DE CONTROLE DE LIVRARIA\n");
    printf("\n>> RELATORIO DE LIVROS POR AUTOR <<\n");
    printf("COD");
    printf("\tNOME                ");
    printf("\tSOBRENOME                     \n");

    dat_autor = fopen(AUTORES, "rb");
    while(fread(&autor, sizeof(autor), 1, dat_autor) == 1){
        printf("%-3i",autor.cod);
        printf("\t%-20s",autor.nome);
        printf("\t%-30s\n",autor.sobrenome);
    };
    fclose(dat_autor);

    printf("\nDIGITE O COD DO AUTOR p/ GERAR RELATORIO: ");
    fflush(stdin);
    scanf("%i", &opcao);
    if(opcao > cont_cod_autores){
        printf("\nOPCAO INVALIDA! \n");
        system("pause");
        return;
    };
    
    geraCabecalhoPadrao();

    dat_livro = fopen(LIVROS, "rb");
    while(fread(&livro, sizeof(livro), 1, dat_livro) == 1){
        if((livro.cod_autor_1 == opcao) ||
           (livro.cod_autor_2 == opcao) ||
           (livro.cod_autor_3 == opcao) ||
           (livro.cod_autor_4 == opcao)) {
            printf("%-3i", livro.cod);
            printf("\t%-50s", livro.titulo);
            printf("\t%-6.2f", livro.preco);

            dat_autor = fopen(AUTORES, "rb");
            while(fread(&autor, sizeof(autor), 1, dat_autor) == 1){
                if(livro.cod_autor_1 == autor.cod){
                    printf("\t%-20s", autor.nome);
                };
            };
            fclose(dat_autor);

            dat_autor = fopen(AUTORES, "rb");
            if(livro.cod_autor_2 == 0){
                printf("\t                    ");
            }
            else{
                while(fread(&autor, sizeof(autor), 1, dat_autor) == 1){
                    if(livro.cod_autor_2 == autor.cod){
                        printf("\t%-20s", autor.nome);
                    }
                };
            };
            fclose(dat_autor);

            dat_autor = fopen(AUTORES, "rb");
            if(livro.cod_autor_3 == 0){
                printf("\t                    ");
            }
            else{
                while(fread(&autor, sizeof(autor), 1, dat_autor) == 1){
                    if(livro.cod_autor_3 == autor.cod){
                        printf("\t%-20s", autor.nome);
                    }
                };
            };
            fclose(dat_autor);

            dat_autor = fopen(AUTORES, "rb");
            if(livro.cod_autor_4 == 0){
                printf("\t                    ");
            }
            else{
                while(fread(&autor, sizeof(autor), 1, dat_autor) == 1){
                    if(livro.cod_autor_4 == autor.cod){
                        printf("\t%-20s", autor.nome);
                    }
                };
            };
            fclose(dat_autor);

            dat_categoria = fopen(CATEGORIAS, "rb");
            while(fread(&categoria, sizeof(categoria), 1, dat_categoria) == 1){
                if(livro.cod_ctg == categoria.cod){
                    printf("\t%-20s", categoria.desc);
                };
            };
            fclose(dat_categoria);

            dat_editora = fopen(EDITORAS, "rb");
            while(fread(&editora, sizeof(editora), 1, dat_editora) == 1){
                if(livro.cod_editora == editora.cod){
                    printf("\t%-20s", editora.nome);
                };
            };
            fclose(dat_editora);

            printf("\t%-6i", livro.edicao);
            printf("\t%-6i", livro.ano_pub);
            printf("\t%-3i\n", livro.qtd_est);
            existente = 1;
        };
    };
    if (existente == 0){
        printf("\nAINDA NAO HA LIVROS CADASTRADOS P/ ESSE AUTOR! \n");
    };
    fclose(dat_livro);
    printf("\n");
    system("pause");
};

// -- 14. RELATORIO DE ESTOQUE EM ARQUIVO TEXTO
void relatarEstoqueEmArqTexto(){
    FILE *dat_arqtexto,
         *dat_autor,
         *dat_categoria,
         *dat_editora,
         *dat_livro;
    int qtd = 0;
    reg_autor autor;
    reg_categoria categoria;
    reg_editora editora;
    reg_livro livro;

    system("cls");
    printf(">> SISTEMA DE CONTROLE DE LIVRARIA\n");
    printf("\n>> RELATORIO DE ESTOQUE CRITICO (GERA ARQUIVO TEXTO) <<\n");
    printf("\nDIGITE A QUANTIDADE P/ VERIFICAR O ESTOQUE CRITICO: ");
    fflush(stdin);
    scanf("%i", &qtd);

    dat_arqtexto = fopen("RelatorioEstoqueCritico.txt", "w");
    printf("\n -- LISTA DE LIVROS COM ESTOQUE IGUAL OU ABAIXO DE %i", qtd);
    fprintf(dat_arqtexto,"\n -- LISTA DE LIVROS COM ESTOQUE IGUAL OU ABAIXO DE %i", qtd);
    printf("\nCOD");
    fprintf(dat_arqtexto,"\nCOD");
    printf("\tTITULO                                            ");
    fprintf(dat_arqtexto, "\tTITULO                                            ");
    printf("\tPRECO ");
    fprintf(dat_arqtexto, "\tPRECO ");
    printf("\tAUTOR 1             ");  
    fprintf(dat_arqtexto, "\tAUTOR 1             ");
    printf("\tAUTOR 2             ");  
    fprintf(dat_arqtexto, "\tAUTOR 2             ");    
    printf("\tAUTOR 3             "); 
    fprintf(dat_arqtexto, "\tAUTOR 3             ");
    printf("\tAUTOR 4             ");  
    fprintf(dat_arqtexto, "\tAUTOR 4             ");
    printf("\tCATEGORIA           ");
    fprintf(dat_arqtexto, "\tCATEGORIA           ");
    printf("\tEDITORA             ");
    fprintf(dat_arqtexto, "\tEDITORA             ");
    printf("\tEDICAO");
    fprintf(dat_arqtexto, "\tEDICAO");
    printf("\tANO ");
    fprintf(dat_arqtexto, "\tANO ");
    printf("\tQTD\n");
    fprintf(dat_arqtexto,"\tQTD\n");

    dat_livro = fopen(LIVROS, "rb");
    while(fread(&livro, sizeof(livro), 1, dat_livro) == 1){
        if(livro.qtd_est <= qtd){
            printf("%-3i", livro.cod);
            fprintf(dat_arqtexto, "%-3i", livro.cod);        
            printf("\t%-50s", livro.titulo);
            fprintf(dat_arqtexto, "\t%-50s", livro.titulo);
            printf("\t%-6.2f", livro.preco);
            fprintf(dat_arqtexto,"\t%-6.2f", livro.preco); 

            dat_autor = fopen(AUTORES, "rb");
            while(fread(&autor, sizeof(autor), 1, dat_autor) == 1){
                if(livro.cod_autor_1 == autor.cod){
                    printf("\t%-20s", autor.nome);
                    fprintf(dat_arqtexto, "\t%-20s", autor.nome);
                };
            };
            fclose(dat_autor);

            dat_autor = fopen(AUTORES, "rb");
            if(livro.cod_autor_2 == 0){
                printf("\t                    ");
                fprintf(dat_arqtexto, "\t                    ");
            }
            else{
                while(fread(&autor, sizeof(autor), 1, dat_autor) == 1){
                    if(livro.cod_autor_2 == autor.cod){
                        printf("\t%-20s", autor.nome);
                        fprintf(dat_arqtexto, "\t%-20s", autor.nome);
                    }
                };
            };
            fclose(dat_autor);

            dat_autor = fopen(AUTORES, "rb");
            if(livro.cod_autor_3 == 0){
                printf("\t                    ");
                fprintf(dat_arqtexto, "\t                    ");
            }
            else{
                while(fread(&autor, sizeof(autor), 1, dat_autor) == 1){
                    if(livro.cod_autor_3 == autor.cod){
                        printf("\t%-20s", autor.nome);
                        fprintf(dat_arqtexto, "\t%-20s", autor.nome);
                    }
                };
            };
            fclose(dat_autor);

            dat_autor = fopen(AUTORES, "rb");
            if(livro.cod_autor_4 == 0){
                printf("\t                    ");
                fprintf(dat_arqtexto, "\t                    ");
            }
            else{
                while(fread(&autor, sizeof(autor), 1, dat_autor) == 1){
                    if(livro.cod_autor_4 == autor.cod){
                        printf("\t%-20s", autor.nome);
                        fprintf(dat_arqtexto, "\t%-20s", autor.nome);
                    }
                };
            };
            fclose(dat_autor);

            dat_categoria = fopen(CATEGORIAS, "rb");
            while(fread(&categoria, sizeof(categoria), 1, dat_categoria) == 1){
                if(livro.cod_ctg == categoria.cod){
                    printf("\t%-20s", categoria.desc);
                    fprintf(dat_arqtexto, "\t%-20s", categoria.desc);
                };
            };
            fclose(dat_categoria);

            dat_editora = fopen(EDITORAS, "rb");
            while(fread(&editora, sizeof(editora), 1, dat_editora) == 1){
                if(livro.cod_editora == editora.cod){
                    printf("\t%-20s", editora.nome);
                    fprintf(dat_arqtexto, "\t%-20s", editora.nome);
                };
            };
            fclose(dat_editora);

            printf("\t%-6i", livro.edicao);
            fprintf(dat_arqtexto,"\t%-6i", livro.edicao);       
            printf("\t%-6i", livro.ano_pub);
            fprintf(dat_arqtexto,"\t%-6i", livro.ano_pub);            
            printf("\t%-3i\n", livro.qtd_est);
            fprintf(dat_arqtexto,"\t%-3i\n", livro.qtd_est);        
        };
    };
    fclose(dat_livro);
    fclose(dat_arqtexto);
    printf("\n");
    system("pause");
};

// -- 15. RELATORIO DE MAIOR(ES) VALOR(ES) DAS CATEGORIAS
void relatarMaiorValorCategoria(){
    FILE *dat_autor,
         *dat_categoria,
         *dat_editora,
         *dat_livro;
    
    int opcao = 0;
    float maior_valor = 0;

    reg_autor autor;
    reg_categoria categoria;
    reg_editora editora;
    reg_livro livro;

    system("cls");
    printf(">> SISTEMA DE CONTROLE DE LIVRARIA\n");
    printf("\n>> RELATORIO DE MAIOR(ES) VALOR(ES) DAS CATEGORIAS <<\n");
    printf("COD");
    printf("\tCATEGORIA           \n");
    dat_categoria = fopen(CATEGORIAS, "rb");
    while(fread(&categoria, sizeof(categoria), 1, dat_categoria) == 1){
        printf("%-3i",categoria.cod);
        printf("\t%-20s\n",categoria.desc);
    };
    fclose(dat_categoria);
    printf("\nDIGITE O COD DA CATEGORIA DESEJADA: ");
    fflush(stdin);
    scanf("%i", &opcao);
    
    geraCabecalhoPadrao();

    dat_livro = fopen(LIVROS, "rb");
    while(fread(&livro, sizeof(livro), 1, dat_livro) == 1){
        if(livro.cod_ctg == opcao){
            if(livro.preco > maior_valor){
                maior_valor = livro.preco;
            };
        };
    };
    fclose(dat_livro);

    dat_livro = fopen(LIVROS, "rb");
    while(fread(&livro, sizeof(livro), 1, dat_livro) == 1){
        if((livro.preco == maior_valor) && (livro.cod_ctg == opcao)){
            printf("%-3i", livro.cod);
            printf("\t%-50s", livro.titulo);
            printf("\t%-6.2f", livro.preco);

            dat_autor = fopen(AUTORES, "rb");
            while(fread(&autor, sizeof(autor), 1, dat_autor) == 1){
                if(livro.cod_autor_1 == autor.cod){
                    printf("\t%-20s", autor.nome);
                };
            };
            fclose(dat_autor);

            dat_autor = fopen(AUTORES, "rb");
            if(livro.cod_autor_2 == 0){
                printf("\t                    ");
            }
            else{
                while(fread(&autor, sizeof(autor), 1, dat_autor) == 1){
                    if(livro.cod_autor_2 == autor.cod){
                        printf("\t%-20s", autor.nome);
                    }
                };
            };
            fclose(dat_autor);

            dat_autor = fopen(AUTORES, "rb");
            if(livro.cod_autor_3 == 0){
                printf("\t                    ");
            }
            else{
                while(fread(&autor, sizeof(autor), 1, dat_autor) == 1){
                    if(livro.cod_autor_3 == autor.cod){
                        printf("\t%-20s", autor.nome);
                    }
                };
            };
            fclose(dat_autor);

            dat_autor = fopen(AUTORES, "rb");
            if(livro.cod_autor_4 == 0){
                printf("\t                    ");
            }
            else{
                while(fread(&autor, sizeof(autor), 1, dat_autor) == 1){
                    if(livro.cod_autor_4 == autor.cod){
                        printf("\t%-20s", autor.nome);
                    }
                };
            };
            fclose(dat_autor);

            dat_categoria = fopen(CATEGORIAS, "rb");
            while(fread(&categoria, sizeof(categoria), 1, dat_categoria) == 1){
                if(livro.cod_ctg == categoria.cod){
                    printf("\t%-20s", categoria.desc);
                };
            };
            fclose(dat_categoria);

            dat_editora = fopen(EDITORAS, "rb");
            while(fread(&editora, sizeof(editora), 1, dat_editora) == 1){
                if(livro.cod_editora == editora.cod){
                    printf("\t%-20s", editora.nome);
                };
            };
            fclose(dat_editora);

            printf("\t%-6i", livro.edicao);
            printf("\t%-6i", livro.ano_pub);
            printf("\t%-3i\n", livro.qtd_est);
        };
    };
    fclose(dat_livro);
    printf("\n");
    system("pause");
};

// -- CRIACAO, VERIFICACAO E ATUALIZACAO DE ARQUIVOS .dat
// ATUALIZA OS VALORES DOS CONTADORES QUE ARMAZEM A QUANTIDADE DE REGISTROS DE CADA ARQUIVO .DAT
void atualizarDatabases(){
    FILE *dat_autor,
         *dat_categoria,
         *dat_editora,
         *dat_livro;

    reg_autor autor;
    reg_categoria categoria;
    reg_editora editora;
    reg_livro livro;

    if ((dat_autor = fopen(AUTORES, "rb")) == NULL){
        dat_autor = fopen(AUTORES, "wb");
        fclose(dat_autor);
    }
    else{
        fseek(dat_autor, -(sizeof(autor)), 2);
        fread(&autor, sizeof(autor), 1, dat_autor);
        cont_cod_autores = autor.cod;
        fclose(dat_autor);                 
    };
    
    if ((dat_categoria = fopen(CATEGORIAS, "rb")) == NULL){
        dat_categoria = fopen(CATEGORIAS, "wb");
        fclose(dat_categoria);
    }
    else{
        fseek(dat_categoria, -(sizeof(categoria)), 2);
        fread(&categoria, sizeof(categoria), 1, dat_categoria);
        cont_cod_categorias = categoria.cod;
        fclose(dat_categoria);                 
    };

    if ((dat_editora = fopen(EDITORAS, "rb")) == NULL){
        dat_editora = fopen(EDITORAS, "wb");
        fclose(dat_editora);
    }
    else{
        fseek(dat_editora, -(sizeof(editora)), 2);
        fread(&editora, sizeof(editora), 1, dat_editora);
        cont_cod_editoras = editora.cod;
        fclose(dat_editora);                 
    };

    if ((dat_livro = fopen(LIVROS, "rb")) == NULL){
        dat_livro = fopen(LIVROS, "wb");
        fclose(dat_livro);
    }
    else{
        fseek(dat_livro, -(sizeof(livro)), 2);
        fread(&livro, sizeof(livro), 1, dat_livro);
        cont_cod_livros = livro.cod;
        printf("\n%i", livro.cod);
        printf("\n%s", livro.titulo);
        printf("\n%i", livro.cod_autor_1);
        printf("\n%i", livro.cod_autor_2);
        printf("\n%i", livro.cod_autor_3);
        printf("\n%i", livro.cod_autor_4);
        printf("\n%i", livro.cod_ctg);
        printf("\n%i", livro.cod_editora);
        printf("\n%i", livro.ano_pub);
        printf("\n%i", livro.edicao);
        printf("\n%f", livro.preco);
        printf("\n%i", livro.qtd_est);
        fclose(dat_livro);                 
    };  
};

// -- FUNCAO QUE GERA CABECALHO DAS CONSULTAS E RELATORIOS
void geraCabecalhoPadrao(){
    printf("\n");
    printf("COD");
    printf("\tTITULO                                            ");
    printf("\tPRECO ");
    printf("\tAUTOR 1             ");  
    printf("\tAUTOR 2             ");  
    printf("\tAUTOR 3             "); 
    printf("\tAUTOR 4             ");  
    printf("\tCATEGORIA           ");
    printf("\tEDITORA             ");
    printf("\tEDICAO");
    printf("\tANO ");
    printf("\tQTD\n");
    return;
};

// -- FUNCAO QUE RECEBE STRING E CONVERTE P/ CARACTER MAIUSCULO CASO AINDA NAO SEJA
void vgets(char *x){
    fflush(stdin);
    gets(x);
    x = strupr(x);
    return;
};