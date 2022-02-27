#include <stdio.h>

#define LIVROS "Livros.dat"


struct reg_livro{
  int codigo; //Codigo do Livro
  char titulo[50]; //Titulo do Livro
  float preco; //Preço do Livro
};

void cadastrarLivro(){
  FILE *fplivro;
  struct reg_livro livro;
  char opc;


  //Entrada das informações sobre o Livro
  printf("\n--Cadastro de Livro--");
  printf("\nDigite o Codigo: ");
  fflush(stdin); scanf("%i",&livro.codigo);
  printf("Digite o Titulo: ");
  fflush(stdin); gets(livro.titulo);
  printf("Digite o Preco: ");
  fflush(stdin); scanf("%f",&livro.preco);

  //Pedir confirmação se deseja gravar
  printf("\nGravar?(S/N) ");
  fflush(stdin); scanf("%c",&opc);
  if ((opc!='S')&&(opc!='s')){
    printf("\nOperacao Cancelada!");
    return;
  }

  //Gravar os dados no Arquivo
  //-> Abrir o Arquivo
  fplivro = fopen("Livros.dat","ab");
  //-> Gravar
  fwrite(&livro,sizeof(livro),1,fplivro);
  //-> Fechar
  fclose(fplivro);

  printf("\nLivro Cadastrado com Sucesso.");

}//Fim cadastrarLivro()

void listarTodosLivros(){
  FILE *fplivro;
  struct reg_livro livro;

  //Abrir o Arquivo
  fplivro = fopen(LIVROS,"rb");

  printf("\n      * * *  Relatorio de Todos os Livros  * * *\n");
  printf("\nCodigo Titulo                         Preco");
  //Ler registro por registro
  while (fread(&livro,sizeof(livro),1,fplivro)==1){
    //Mostrar na Tela
    printf("\n%-6i %-30s %5.2f",livro.codigo,livro.titulo, livro.preco);

  }


  //Fechar arquivo
  fclose(fplivro);

}//Fim listarTodosLivros()

void consultarPeloCodigo(){
  FILE *fplivro;
  struct reg_livro livro;
  int cod, achou=0;

  //Solicitar o codigo do Livro
  printf("\nDigite o Codigo do Livro a ser Localizado: ");
  fflush(stdin); scanf("%i",&cod);

  //Abrir o Arquivo
  fplivro = fopen(LIVROS,"rb");

  //Localizar o Livro que tenha o código procuradp
  while ((achou==0)&&(fread(&livro,sizeof(livro),1,fplivro)==1)){
    //printf("\nLivro->%i",livro.codigo);
    if (livro.codigo == cod){
      printf("\nCodigo: %i",livro.codigo);
      printf("\nTitulo: %s",livro.titulo);
      printf("\nPreco: %5.2f",livro.preco);
      achou=1;
    }
  }

  //if (achou==0)
  if (!achou)
    printf("\n Livro NAO Localizado!!");

  //Fechar o Arquivo
  fclose(fplivro);

}//Fim consultarPeloCodigo()

void consultarPeloTitulo(){
  FILE *fplivro;
  struct reg_livro livro;
  int achou=0;
  char tit[50];

  //Solicitar o Titulo do Livro
  printf("\nDigite o Titulo do Livro a ser Localizado: ");
  fflush(stdin); gets(tit);

  //Abrir o Arquivo
  fplivro = fopen(LIVROS,"rb");

  //Localizar o Livro que tenha o título procurado
  while ((achou==0)&&(fread(&livro,sizeof(livro),1,fplivro)==1)){
    //printf("\nLivro->%i",livro.codigo);
    if (strcmp(livro.titulo,tit)==0){  //Strings iguais - Achei o Livro
      printf("\nCodigo: %i",livro.codigo);
      printf("\nTitulo: %s",livro.titulo);
      printf("\nPreco: %5.2f",livro.preco);
      achou=1;
    }
  }

  //if (achou==0)
  if (!achou)
    printf("\n Livro NAO Localizado!!");

  //Fechar o Arquivo
  fclose(fplivro);

}//Fim consultarPeloTitulo()

void consultarPalavraTitulo(){
  FILE *fplivro;
  struct reg_livro livro;
  char palavra[30];
  int achou=0;


  //Solcitar a Palavra-Chave
  printf("\nDigite a Palavra-Chave: ");
  fflush(stdin); gets(palavra);

  //Abrir o Arquivo de Livros
  fplivro = fopen(LIVROS,"rb");

  //Ler registro por registro e comparar se aparece a palavra no titulo e mostrar
  while (fread(&livro,sizeof(livro),1,fplivro)==1){
      if (strstr(livro.titulo,palavra)!=NULL){
        achou++;
        if (achou==1){
          printf("\nCodigo Titulo                         Preco");
        }
        printf("\n%-6i %-30s %5.2f",livro.codigo,livro.titulo, livro.preco);
      }
  }

  if (achou==0){
    printf("\nNenhum Livro Encontrado com a palavra %s no Titulo.",palavra);
  }

  //Fechar o Arquivo
  fclose(fplivro);

}//consultarPalavraTitulo()

void alterarLivro(){
  FILE *fplivro;
  struct reg_livro livro;
  int cod, achou=0;
  char opc;

  //Solicitar o codigo do Livro a ser Alterado
  printf("\nDigite o Codigo do Livro a ser ALTERADO: ");
  fflush(stdin); scanf("%i",&cod);

  //Abrir o Arquivo
  fplivro = fopen(LIVROS,"rb+");

  //Localizar o Livro que tenha o código procuradO
  while ((achou==0)&&(fread(&livro,sizeof(livro),1,fplivro)==1)){
    //printf("\nLivro->%i",livro.codigo);
    if (livro.codigo == cod){
      printf("\nCodigo: %i",livro.codigo);
      printf("\nTitulo: %s",livro.titulo);
      printf("\nPreco: %5.2f",livro.preco);
      achou=1;
    }
  }

  //if (achou==0)
  if (!achou){
    printf("\n Livro NAO Localizado!!");
    //Fechar o Arquivo
    fclose(fplivro);
    return;
  }

  //Pedir os novos dados
  printf("\nDeseja alterar o Titulo?(S/N) ");
  fflush(stdin);  scanf("%c",&opc);
  if ((opc=='S')||(opc=='s')){
    printf("\nDigite o novo Titulo: ");
    fflush(stdin); gets(livro.titulo);
  }
  printf("\nDeseja alterar o Preco?(S/N) ");
  fflush(stdin);  scanf("%c",&opc);
  if ((opc=='S')||(opc=='s')){
    printf("\nDigite o novo Preco: ");
    fflush(stdin); scanf("%f",&livro.preco);
  }

  //Confirmar Alteração e Gravar
  printf("\nGravar Alteracoes?(S/N) ");
  fflush(stdin);  scanf("%c",&opc);
  if ((opc!='S')&&(opc!='s')){
    printf("\nAlteracao Cancelada.");
    fclose(fplivro);
    return;
  }

  //Gravar alteracao no Arquivo
  //Voltar o ponteiro no arquivo para o registro anterior
  fseek(fplivro,-sizeof(livro),1);
  fwrite(&livro,sizeof(livro),1,fplivro); //Gravou o registro com os dados alterados
  fclose(fplivro);

  //Mostrar mensagem de feedback para o usuário
  printf("\nLivro Alterado com Sucesso.");

} //Fim alterarLivro()

void excluirLivro(){
  FILE *fplivro, *fplivrosnew;
  struct reg_livro livro;
  int cod, achou=0;
  char opc;

  //Solicitar o codigo do Livro a ser Excluido
  printf("\nDigite o Codigo do Livro a ser EXCLUIDO: ");
  fflush(stdin); scanf("%i",&cod);

  //Abrir o Arquivo
  fplivro = fopen(LIVROS,"rb");

  //Localizar o Livro que tenha o código procuradO
  while ((achou==0)&&(fread(&livro,sizeof(livro),1,fplivro)==1)){
    //printf("\nLivro->%i",livro.codigo);
    if (livro.codigo == cod){
      printf("\nCodigo: %i",livro.codigo);
      printf("\nTitulo: %s",livro.titulo);
      printf("\nPreco: %5.2f",livro.preco);
      achou=1;
    }
  }

    //Fechar o Arquivo
    fclose(fplivro);


  //if (achou==0)
  if (!achou){
    printf("\n Livro NAO Localizado!!");
    return;
  }

  //Confirmar EXCLUSÃO
  printf("\nConfirma Exclusao?(S/N) ");
  fflush(stdin);  scanf("%c",&opc);
  if ((opc!='S')&&(opc!='s')){
    printf("\nEXCLUSAO Cancelada.");
    return;
  }

  //Excluir o Registro do Livro

  //Copiar todos os registros (menos aquele a ser removido) para um arquivo temporario
  fplivro = fopen(LIVROS,"rb");
  fplivrosnew = fopen("livrosnew.dat","wb");
  while(fread(&livro,sizeof(livro),1,fplivro)==1){ //Le do arquivo original
    if (livro.codigo!=cod)
      fwrite(&livro,sizeof(livro),1,fplivrosnew); //Grava no arquivo temporario
  }
  fclose(fplivro);
  fclose(fplivrosnew);

  system("del livros.dat"); //Remove o arquivo Original
  system("ren livrosnew.dat Livros.dat"); //Renomeia o temporario para o nome do Original

  printf("\nLivro Excluido com Sucesso.");
}//Fim excluirLvro()


main(){
  int op;

  do{

    printf("\n\n    # # #  Livraria do Saber  # # # \n");
    printf("\n 1) Cadastro de Livros");
    printf("\n 2) Listar Todos os Livros");
    printf("\n 3) Consultar Livro pelo Codigo");
    printf("\n 4) Consultar Livro pelo Titulo");
    printf("\n 5) Consultar Livro por Palavra-Chave no Titulo");
    printf("\n 6) Alterar dados de um Livro");
    printf("\n 7) Excluir um Livro");
    printf("\n 0) Sair");
    printf("\n\n opcao-> ");
    fflush(stdin); scanf("%i",&op);

    switch(op){
      case 1: //Cadastrar um novo Livro
        cadastrarLivro();
        break;
      case 2: //Listar Livros
        listarTodosLivros();
        break;
      case 3: //Consulta Livro pelo Codigo
        consultarPeloCodigo();
        break;
      case 4: //Consulta Livro pelo Titulo
        consultarPeloTitulo();
        break;
      case 5: //Consulta Livro por Palavra chave no Titulo
        consultarPalavraTitulo();
        break;
      case 6:  //Alterar Livro
        alterarLivro();
        break;
      case 7: //Excluir Livro
        excluirLivro();
        break;

    }

  }while(op!=0);


}//Fim main()
