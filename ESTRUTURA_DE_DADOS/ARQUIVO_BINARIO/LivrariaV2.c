#include <stdio.h>
#include <string.h>
#include <time.h>

#define LIVROS "Livros.dat"
#define CLIENTES "Clientes.dat"
#define VENDAS "Vendas.dat"

struct reg_livro{
  int codigo; //Codigo do Livro
  char titulo[50]; //Titulo do Livro
  float preco; //Preço do Livro
};

struct reg_cliente{
  int codigo;
  char nome[50];
  char fone[14];
  char email[40];
};

struct reg_venda{
  int codigo;
  int cod_cliente; //Código do cliente que comprou o Livro
  int cod_livro;  //Código do Livro vendido
  int qtde;
  float valor_venda; //Isso é necessário quando houve desconto
  char data_venda[11];
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

void cadastrarCliente(){
  FILE *fpcliente;
  struct reg_cliente cliente;
  char opc;

  //Solicitar os dados do Cliente
  printf("\nDigite o Codigo: ");
  fflush(stdin); scanf("%i",&cliente.codigo);
  printf("Digite o Nome: ");
  fflush(stdin); gets(cliente.nome);
  printf("Digite o Telefone: ");
  fflush(stdin); gets(cliente.fone);
  printf("Digite o Email: ");
  fflush(stdin); gets(cliente.email);

  //Pedir confirmação se deseja gravar
  printf("\nGravar?(S/N) ");
  fflush(stdin); scanf("%c",&opc);
  if ((opc!='S')&&(opc!='s')){
    printf("\nOperacao Cancelada!");
    return;
  }

  //Gravar os dados no Arquivo
  //-> Abrir o Arquivo
  fpcliente = fopen(CLIENTES,"ab");
  //-> Gravar
  fwrite(&cliente,sizeof(cliente),1,fpcliente);
  //-> Fechar
  fclose(fpcliente);

  printf("\nCliente Cadastrado com Sucesso.");

}//Fim cadastrarCliente()

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

void consultarParteIncialNomeCliente(){
  FILE *fpcliente;
  struct reg_cliente cliente;
  char parteinicial[30];
  int achou=0;


  //Solcitar a Parte Inicial do Nome
  printf("\nDigite a parte inicial do Nome: ");
  fflush(stdin); gets(parteinicial);

  //Abrir o Arquivo de Livros
  fpcliente = fopen(CLIENTES,"rb");

  //Ler registro por registro e comparar se aparece a PARTE INICIAL DO NOME
  while (fread(&cliente,sizeof(cliente),1,fpcliente)==1){
      if (strncmp(cliente.nome,parteinicial,strlen(parteinicial))==0){
        achou++;
        if (achou==1){
          printf("\Codigo Nome                                Fone           Email               ");
        }
        printf("\n%-6i %-35s %-14s %-20s",cliente.codigo,cliente.nome,cliente.fone,cliente.email);
      }
  }

  if (achou==0){
    printf("\nNenhum Cliente Encontrado com esta parte Inicial do Nome.");
  }

  //Fechar o Arquivo
  fclose(fpcliente);

}//Fim consultarParteIncialNomeCliente()

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

void listarTodosClientes(){
  FILE *fpcliente;
  struct reg_cliente cliente;

  //Abrir o Arquivo
  fpcliente = fopen(CLIENTES,"rb");

  printf("\n      * * *  Relatorio de Todos os Clientes  * * *\n");
  printf("\nCodigo Nome                                Fone           Email                    ");
  //Ler registro por registro
  while (fread(&cliente,sizeof(cliente),1,fpcliente)==1){
    //Mostrar na Tela
    printf("\n%-6i %-35s %-14s %-25s",cliente.codigo,cliente.nome,cliente.fone,cliente.email);
  }


  //Fechar arquivo
  fclose(fpcliente);

}//Fim listarTodosClientes()

struct reg_cliente localizarClientePeloCodigo(int codcli){
  FILE *fpcliente;
  struct reg_cliente cliente;
  int achou=0;

  //Abrir o Arquivo
  fpcliente = fopen(CLIENTES,"rb");

  //Localizar o CLIENTE que tenha o código procurado
  achou=0;
  while ((achou==0)&&(fread(&cliente,sizeof(cliente),1,fpcliente)==1)){
    if (cliente.codigo == codcli){
      achou=1;
    }
  }

  if (!achou){ //Não encontrou nenhum cliente com o código procurado
    cliente.codigo = -1; //sinaliza que NÃO ACHOU O CLIENTE COM O CÓDIGO PROCURADO
  }

  fclose(fpcliente);

  return cliente;
}//Fim localizarClientePeloCodigo()

void efetuarVenda(){
  FILE *fpcliente, *fplivro, *fpvenda;
  struct reg_cliente cliente;
  struct reg_livro livro;
  struct reg_venda venda;
  int codcli, codliv, codvenda;
  int achou,qtde;
  char op;
  struct tm *datalocal;
  time_t t;
  char hora[9];

  //Solicitar o Codigo da Venda
  printf("\nDigite o Codigo da Venda: ");
  fflush(stdin); scanf("%i",&codvenda);

  //Solicitar o Código do Cliente
  printf("\nDigite o Codigo do Cliente: ");
  fflush(stdin); scanf("%i",&codcli);

  //Abrir o Arquivo
  fpcliente = fopen(CLIENTES,"rb");

  //Localizar o CLIENTE que tenha o código procurado
  achou=0;
  while ((achou==0)&&(fread(&cliente,sizeof(cliente),1,fpcliente)==1)){
    if (cliente.codigo == codcli){
      printf("\nCodigo: %i",cliente.codigo);
      printf("\nNome: %s",cliente.nome);
      printf("\nFone: %s",cliente.fone);
      achou=1;
    }
  }

  //if (achou==0)
  if (!achou){
    printf("\n cliente NAO Localizado!!");
    fclose(fpcliente);
    return;  //Retorna para o Menu Principal
  }

  //Se localizou o cliente, pedir confirmação
  printf("\nConfirma Cliente(S/N)? ");
  fflush(stdin); scanf("%c",&op);

  if ((op=='N')||(op=='n')){
    printf("\n cliente NAO Confirmado!!");
    fclose(fpcliente);
    return;  //Retorna para o Menu Principal
  }

  //Solicitar o Código do Livro a ser vendido
  printf("\nDigite o Codigo do Livro: ");
  fflush(stdin); scanf("%i",&codliv);

  //Abrir o Arquivo
  fplivro = fopen(LIVROS,"rb");

  //Localizar o Livro que tenha o código procurado
  achou=0;
  while ((achou==0)&&(fread(&livro,sizeof(livro),1,fplivro)==1)){
    if (livro.codigo == codliv){
      printf("\nCodigo: %i",livro.codigo);
      printf("\nTitulo: %s",livro.titulo);
      printf("\nPreco: %5.2f",livro.preco);
      achou=1;
    }
  }

  //if (achou==0)
  if (!achou){
    printf("\n Livro NAO Localizado!!");
    fclose(fplivro);
    return; //Retorna para o Menu Principal
  }

  //Fechar o Arquivo
  fclose(fplivro);

  //Pedir confirmação
  printf("\nConfirma Livro(S/N)? ");
  fflush(stdin); scanf("%c",&op);

  if ((op=='N')||(op=='n')){
    printf("\n Livro NAO Confirmado!!");
    fclose(fplivro);
    return;  //Retorna para o Menu Principal
  }

  //Solicitar a Qtde
  printf("\nDigite a Qtde: ");
  fflush(stdin); scanf("%i",&qtde);

  printf("\nValor da venda deste Livro: %5.2f",livro.preco*qtde);

  //Confirmar a Venda
  printf("\nConfirma Venda(S/N)? ");
  fflush(stdin); scanf("%c",&op);

  if ((op=='N')||(op=='n')){
    printf("\n Venda NAO Confirmada!!");
    return;  //Retorna para o Menu Principal
  }

  //Gravar a Venda
  venda.codigo = codvenda;
  venda.cod_cliente = cliente.codigo;
  venda.cod_livro = livro.codigo;
  venda.qtde = qtde;
  venda.valor_venda = livro.preco*qtde;

  t = time(NULL);
  datalocal = localtime(&t);
  sprintf(venda.data_venda,"%d/%d/%d",datalocal->tm_mday,datalocal->tm_mon+1,datalocal->tm_year+1900);
  //sprintf(hora,"%d:%d:%d",datalocal->tm_hour,datalocal->tm_min,datalocal->tm_sec);


  fpvenda = fopen(VENDAS,"ab");
  fwrite(&venda,sizeof(venda),1,fpvenda);
  fclose(fpvenda);

  printf("\nVenda registrada com Sucesso.");

}//Fim efetuarVenda()

void listarVendas(){
  FILE *fpvendas;
  struct reg_venda venda;
  struct reg_cliente cliente;


  //Abrir Arquivo de Vendas
  fpvendas = fopen(VENDAS,"rb");

  //Ler registro por registro e mostrar na tela
  while (fread(&venda,sizeof(venda),1,fpvendas)==1){
    printf("\nCodigo da Venda: %i",venda.codigo);
    cliente = localizarClientePeloCodigo(venda.cod_cliente);
    if (cliente.codigo==-1){ //Cliente NÃO localizado
      strcpy(cliente.nome,"NÃO LOCALIZADO!");
    }
    printf("\nCliente %i - %s",venda.cod_cliente,cliente.nome);
    printf("\nCodigo do Livro: %i",venda.cod_livro);
    printf("\nQuantidade: %i",venda.qtde);
    printf("\nValor da Venda: %5.2f",venda.valor_venda);
    printf("\nData da Venda: %s",venda.data_venda);
    printf("\n----------------------------------------------------------------------------");
  }

  //Fechar Arquivo de Vendas
  fclose(fpvendas);

}//Fim listarVendas()


void listarVendasTXT(){
  FILE *fpvendas, *fprelvendastxt;
  struct reg_venda venda;
  struct reg_cliente cliente;
  char saida[200];


  //Abrir Arquivo de Vendas
  fpvendas = fopen(VENDAS,"rb");
  fprelvendastxt = fopen("RelatorioVendas.txt","w");

  fputs("       * * *  LIVRARIA DO SABER * * * \n",fprelvendastxt);
  fputs("    ---------RELATORIO DE VENDAS-------------\n",fprelvendastxt);
  fputs("Codigo Cliente                                      Livro Valor     Data        \n",fprelvendastxt);


  //Ler registro por registro e gravar no arquivo texto
  while (fread(&venda,sizeof(venda),1,fpvendas)==1){
    //printf("\nCodigo da Venda: %i",venda.codigo);
    cliente = localizarClientePeloCodigo(venda.cod_cliente);
    if (cliente.codigo==-1){ //Cliente NÃO localizado
      strcpy(cliente.nome,"NÃO LOCALIZADO!");
    }
    //printf("\nCliente %i - %s",venda.cod_cliente,cliente.nome);
    //printf("\nCodigo do Livro: %i",venda.cod_livro);
    //printf("\nQuantidade: %i",venda.qtde);
    //printf("\nValor da Venda: %5.2f",venda.valor_venda);
    //printf("\nData da Venda: %s",venda.data_venda);
    //printf("\n----------------------------------------------------------------------------");
    sprintf(saida,"%-6i %-3i-%-40s %-5i R$ %-5.2f %-10s\n",venda.codigo,cliente.codigo,cliente.nome,venda.cod_livro,venda.valor_venda,venda.data_venda);

    //printf("%s",saida);

    fputs(saida,fprelvendastxt);
  }


  //Fechar Arquivo de Vendas
  fclose(fpvendas);
  fclose(fprelvendastxt);

  printf("\nRelatorio de Vendas gravado no Arquivo Texto com Sucesso.");

}//Fim listarVendasTXT()


main(){
  int op;

  do{

    printf("\n\n    # # #  Livraria do Saber  # # # \n");
    printf("\n 1) Cadastro de Livros");
    printf("\n 111) Cadastro de Clientes");
    printf("\n 2) Listar Todos os Livros");
    printf("\n 222) Listar Todos os Clientes");
    printf("\n 3) Consultar Livro pelo Codigo");
    printf("\n 444)Consultar Cliente pela Parte inicial do Nome");
    printf("\n 4) Consultar Livro pelo Titulo");
    printf("\n 5) Consultar Livro por Palavra-Chave no Titulo");
    printf("\n 6) Alterar dados de um Livro");
    printf("\n 7) Excluir um Livro");
    printf("\n 8) Efetuar Venda");
    printf("\n 9) Listar Vendas");
    printf("\n 10) Listar Vendas em Arquivo TXT");
    printf("\n 0) Sair");
    printf("\n\n opcao-> ");
    fflush(stdin); scanf("%i",&op);

    switch(op){
      case 1: //Cadastrar um novo Livro
        cadastrarLivro();
        break;
      case 111: //Cadastrar Cliente
        cadastrarCliente();
        break;
      case 2: //Listar Livros
        listarTodosLivros();
        break;
      case 222: //Listar Clientes
        listarTodosClientes();
        break;
      case 3: //Consulta Livro pelo Codigo
        consultarPeloCodigo();
        break;
      case 4: //Consulta Livro pelo Titulo
        consultarPeloTitulo();
        break;
      case 444: //Consulta Cliente pela parte Inicial do Nome
        consultarParteIncialNomeCliente();
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
      case 8: //Efetuar Venda de Livros
        efetuarVenda();
        break;
      case 9: //Listar Vendas
        listarVendas();
        break;
      case 10: //Listar Vendas em arquivo TXT
        listarVendasTXT();
        break;


    }

  }while(op!=0);


}//Fim main()
