#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#define tam 100

      typedef struct _Cliente{
            int codigo;
            char nome[50];
            int telefone;
      }Cliente;

      typedef struct _Filme{
            int codigo;
            char nome[50];
            char genero;
            int duracao;
            float preco;
      }Filme;

     typedef struct _Emprestimo{
            int codigoEmprestimo;
            int codigoCliente;
            int codigoFilme;
            int dia;
            int mes;
            int ano;
            char codigoEntrega;
      }Emprestimo;


      void grava_Clientes(char *nome_arquivo,Cliente *c1,int nCli){
            int i;
            FILE *arquivo;
            arquivo = fopen (nome_arquivo,"w");
            if(!arquivo){
                        printf("\nErro ao abrir o arquivo!!!\n");
                        exit(1);
                  }
            fprintf(arquivo,"%d",nCli);
            for(i=0;i<nCli;i++){
                  //fprintf(arquivo,nCli,"\n",c1[i].codigo," $ ",c1[i].nome, " $ ", c1[i].telefone,"\n");
                  fprintf(arquivo,"\n %d $ %s $ %d $ ",c1[i].codigo,c1[i].nome,c1[i].telefone);
            }
            fclose(arquivo);
      }
      void grava_Filmes(char *nome_arquivo,Filme *f1,int nfil){
            int i;
            FILE *arquivo;
            arquivo = fopen (nome_arquivo,"w");
            if(!arquivo){
                        printf("\nErro ao abrir o arquivo!!!\n");
                        exit(1);
                  }
            fprintf(arquivo,"%d",nfil);
            for(i=0;i<nfil;i++){
                  fprintf(arquivo,"\n %d $ %s $ %c $ %d $ %f $ ",f1[i].codigo,f1[i].nome,f1[i].genero,f1[i].preco);
                  //fprintf(arquivo,,"\n ",f1[i].codigo," $ ",f1[i].nome, " $ ", f1[i].genero," $ ", f1[i].duracao," $ ",f1[i].preco,"\n");
                  //fprintf(arquivo,"\n %d  $  %s $ %c $ %d $ %f \n"   ,f1[i].codigo,f1[i].nome,f1[i].genero,f1[i].duracao,f1[i].preco);
            }
            fclose(arquivo);
      }
      void grava_Emprestimos(char *nome_arquivo,Emprestimo *e1,int nEmp){
            int i;
            FILE *arquivo;
            arquivo = fopen (nome_arquivo,"w");
            if(!arquivo){
                        printf("\nErro ao abrir o arquivo!!!\n");
                        exit(1);
                  }
            fprintf(arquivo,"%d",nEmp);
            for(i=0;i<nEmp;i++){
                  fprintf(arquivo,"\n %d $ %d $ %d $ %d $ %d $ %d $ %c $ ",e1[i].codigoEmprestimo,e1[i].codigoCliente,e1[i].codigoFilme,e1[i].dia,e1[i].mes,e1[i].ano,e1[i].codigoEntrega);
                  //fprintf(arquivo,nEmp,"\n",e1[i].codigoEmprestimo," $ ",e1[i].codigoCliente, " $ ", e1[i].codigoFilme," $ ", e1[i].dia," $ ",e1[i].mes," $ ",e1[i].ano," $ ",e1[i].codigoEntrega,"\n");
            }
            fclose(arquivo);
      }


      void lista_Filmes(Filme *f1,int nFilme,char gen){
            int i;
            for(i=0;i<nFilme;i++){
                  if(f1[i].genero == gen){
                  printf("\nCodigo: %d Nome: %s \nGenero: %c Duracao: %d \nPreco: %.2f \n", f1[i].codigo, f1[i].nome, f1[i].genero, f1[i].duracao,f1[i].preco);
                  }
            }
      }
      void info_Emprestimos(Emprestimo *e1,int nEmprestimo,int cod){
            int i;
            for(i=0;i<nEmprestimo;i++){
                  if(e1[i].codigoEmprestimo == cod){
                  printf("\nCodigo Emprestimo: %d Codigo do cliente: %d \nCodigo do Filme: %d \nData: %d/%d/%d \nCodigo entrega: %c \n", e1[i].codigoEmprestimo, e1[i].codigoCliente, e1[i].codigoFilme, e1[i].dia,e1[i].mes,e1[i].ano,e1[i].codigoEntrega);
                  }
            }
      }
      void info_Filmes(Filme *f1,int nFilme,int cod){
            int i;
            for(i=0;i<nFilme;i++){
                  if(f1[i].codigo == cod){
                  printf("\nCodigo: %d Nome: %s \nGenero: %c Duracao: %d \nPreco: %.2f \n", f1[i].codigo, f1[i].nome, f1[i].genero, f1[i].duracao,f1[i].preco);
                  }
            }
      }
      void lista_Emprestimos(Emprestimo *e1,int nEmprestimo,int cod){
            int i;
            for(i=0;i<nEmprestimo;i++){
                  if(e1[i].codigoCliente == cod){
                  printf("\nCodigo Emprestimo: %d Codigo do cliente: %d \nCodigo do Filme: %d \nData: %d/%d/%d \nCodigo entrega: %c \n", e1[i].codigoEmprestimo, e1[i].codigoCliente, e1[i].codigoFilme, e1[i].dia,e1[i].mes,e1[i].ano,e1[i].codigoEntrega);
                  }
            }
      }
      void lista_Atrasados(Emprestimo *e1,Cliente *c1,int nEmprestimo,int nCliente){
            int i,j;
            for(i=0;i<nEmprestimo;i++){
                  for(j=0;j<nCliente;j++){
                        if(e1[i].codigoCliente == c1[j].codigo && e1[i].codigoEntrega =='N'){
                        printf("\nCliente com atraso:\nCodigo Emprestimo: %d Codigo do cliente: %d \nCodigo do Filme: %d \nData: %d/%d/%d \nCodigo entrega: %c \n", e1[i].codigoEmprestimo, e1[i].codigoCliente, e1[i].codigoFilme, e1[i].dia,e1[i].mes,e1[i].ano,e1[i].codigoEntrega);
                        }
                  }
            }
      }

      void info_Clientes(Cliente *c1,int nCliente,int cod){
            int i;
            for(i=0;i<nCliente;i++){
                  if(c1[i].codigo == cod){
                  printf("\nCodigo: %d Nome: %s \nTelefone %d \n", c1[i].codigo, c1[i].nome, c1[i].telefone);
                  }
            }
      }
      void novoCliente(Cliente *c1,int *nCli){
            int n = *nCli;

            char nome[50];
            int telefone;
          c1[n].codigo = n;
          fflush(stdin);
          printf("\nDigite o nome do novo cliente: ");
                scanf("%s",&c1[n].nome);
                fflush(stdin);
          printf("\nDigite o telefone do novo cliente: ");
                scanf("%d",&c1[n].telefone);
                fflush(stdin);
                *nCli += 1;
    }
    void novoFilme(Filme *f1,int *nFil){
        int n = *nFil;
            f1[n].codigo = n;
            char nome[50];
            char genero;
            int duracao;
            float preco;
            printf("\nDigite o nome do novo filme: ");
                scanf("%s",&f1[n].nome);
                fflush(stdin);
          printf("\nDigite o genero do novo cliente: ");
                scanf("%c",&f1[n].genero);
                fflush(stdin);
                printf("\nDigite a duracao do novo filme: ");
                scanf("%c",&f1[n].duracao);
                fflush(stdin);
          printf("\nDigite o preco do novo filme: ");
                scanf("%f",&f1[n].preco);
                fflush(stdin);
                *nFil += 1;

    }
    int devolucao(Emprestimo *e1, int n,int n1){
        int i;
            for(i=0;i<n1;i++){
                  if(e1[i].codigoEntrega == 'N'){
                        e1[i].codigoEntrega = 'S';
                  }
            }

    }
    void novoEmprestimo(Emprestimo *e1,int *nEmp){
        int n = *nEmp;
            e1[n].codigoEmprestimo = n;
            int codigoCliente;
            int codigoFilme;
            int dia;
            int mes;
            int ano;
            char codigoEntrega = 'N';
            printf("\nDigite o codigo do novo filme: ");
                scanf("%d",&e1[n].codigoCliente);
                fflush(stdin);
            printf("\nDigite o dia da retirada: ");
                scanf("%d",&e1[n].dia);
                fflush(stdin);
            printf("\nDigite o mes da retirada: ");
                scanf("%d",&e1[n].mes);
                fflush(stdin);
            printf("\nDigite ano da retirada: ");
                scanf("%d",&e1[n].ano);
                fflush(stdin);
                *nEmp += 1;

    }


      //Funcao para capturar do arquivo e colocar no vetor
      int leEmprestimo(char *nome_arquivo, Emprestimo *e1){
            FILE *arquivo;
            char c;
            int i,n;
            printf("nome-arquivo %s", nome_arquivo);
            arquivo = fopen (nome_arquivo,"r");
                  if(!arquivo){
                        printf("\nErro ao abrir o arquivo!!!\n");
                        exit(1);
                  }
                  if(!feof(arquivo)){
                        fscanf(arquivo,"%d",&n);
                              for(i=0;i<n;i++){
                                    fscanf(arquivo,"%d",&e1[i].codigoEmprestimo);
                                          do{
                                                fscanf(arquivo,"%c", &c);
                                          }while(c != '$');
                                    fscanf(arquivo,"%d",&e1[i].codigoCliente);
                                          do{
                                                fscanf(arquivo,"%c", &c);
                                          }while(c != '$');

                                    fscanf(arquivo,"%d",&e1[i].codigoFilme);
                                          do{
                                                fscanf(arquivo,"%c", &c);
                                          }while(c != '$');
                                    fscanf(arquivo,"%d",&e1[i].dia);
                                          do{
                                                fscanf(arquivo,"%c", &c);
                                          }while(c != '$');
                                    fscanf(arquivo,"%d",&e1[i].mes);
                                          do{
                                                fscanf(arquivo,"%c", &c);
                                          }while(c != '$');
                                    fscanf(arquivo,"%d",&e1[i].ano);
                                          do{
                                                fscanf(arquivo,"%c", &c);
                                          }while(c != '$');
                                    fscanf(arquivo,"%c",&e1[i].codigoEntrega);
                                    fscanf(arquivo,"%c",&e1[i].codigoEntrega);
                                          do{
                                                fscanf(arquivo,"%c", &c);
                                          }while(c != '$');

                                    printf("\nCodigo Emprestimo: %d Codigo do cliente: %d \nCodigo do Filme: %d \nData: %d/%d/%d \nCodigo entrega: %c \n", e1[i].codigoEmprestimo, e1[i].codigoCliente, e1[i].codigoFilme, e1[i].dia,e1[i].mes,e1[i].ano,e1[i].codigoEntrega);
                              }
                }

            fclose(arquivo);
            return n;
      }


      int leFilmes(char *nome_arquivo, Filme *f1){
            FILE *arquivo;
            char c;
            int i,n,j;
            printf("nome-arquivo %s", nome_arquivo);
            arquivo = fopen (nome_arquivo,"r");
                  if(!arquivo){
                        printf("\nErro ao abrir o arquivo!!!\n");
                        exit(1);
                  }
                  if(!feof(arquivo)){
                        fscanf(arquivo,"%d",&n);
                              for(i=0;i<n;i++){
                                    fscanf(arquivo,"%d", &f1[i].codigo);
                                          do{
                                                fscanf(arquivo,"%c", &c);
                                          }while(c != '$');
                                          j = 0;
                                          do{
                                                fscanf(arquivo,"%c", &c);
                                                      if(c != '$')
                                                            f1[i].nome[j] = c;
                                                            j++;
                                          }while(c != '$');
                                                f1[i].nome[j] = '\0';

                                    fscanf(arquivo,"%c", &f1[i].genero);
                                    fscanf(arquivo,"%c", &f1[i].genero);
                                          do{
                                                fscanf(arquivo,"%c", &c);
                                          }while(c != '$');
                                    fscanf(arquivo,"%d",&f1[i].duracao);
                                          do{
                                                fscanf(arquivo,"%c", &c);
                                          }while(c != '$');
                                    fscanf(arquivo,"%f",&f1[i].preco);
                                          do{
                                                fscanf(arquivo,"%c", &c);
                                          }while(c != '$');
                    printf("\nCodigo: %d Nome: %s \nGenero: %c Duracao: %d \nPreco: %.2f \n", f1[i].codigo, f1[i].nome, f1[i].genero, f1[i].duracao,f1[i].preco);
                }
            }
            fclose(arquivo);
            return n;
      }


      int leCliente(char *nome_arquivo, Cliente *c1){
            FILE *arquivo;
            char c;
            int i,n,j;
            printf("nome-arquivo %s", nome_arquivo);
            arquivo = fopen (nome_arquivo,"r");
            if(!arquivo){
                  printf("\nErro ao abrir o arquivo!!!\n");
                  exit(1);
            }
            if(!feof(arquivo)){
                fscanf(arquivo,"%d",&n);
                for(i=0;i<n;i++){
                    fscanf(arquivo,"%d", &c1[i].codigo);
                    do{
                         fscanf(arquivo,"%c", &c);
                    }while(c != '$');
                    j = 0;
                    do{
                         fscanf(arquivo,"%c", &c);
                         if(c != '$')
                             c1[i].nome[j] = c;
                         j++;
                    }while(c != '$');
                    c1[i].nome[j] = '\0';
                    fscanf(arquivo,"%d", &c1[i].telefone);
                    do{
                         fscanf(arquivo,"%c", &c);
                    }while(c != '$');
                    printf("\n%d %s %d \n", c1[i].codigo, c1[i].nome, c1[i].telefone);
                }
            }
            fclose(arquivo);
            return n;
      }
      int main(int argc,char *argv[]){
            Cliente *c1;
            Emprestimo *e1;
            Filme *f1;
            int nCliente,nFilme,nEmprestimo;
            int opcao;

             c1 = (Cliente *) malloc (tam * sizeof( Cliente));
             e1 = (Emprestimo *) malloc (tam * sizeof( Emprestimo));
             f1 = (Filme *) malloc (tam * sizeof( Filme));

            do{
            printf("\nMenu\n");

            printf("\nQual das opcoes voce deseja?\n");
            printf("\n 1 - Passar as informacoes do arquivo de clientes para o vetor de clientes");
            printf("\n 2 - Passar as informacoes do arquivo de filmes para o vetor de filmes ");
            printf("\n 3 - Passar as informacoes do arquivo de emprestimos para o vetor de emprestimos");
            printf("\nWARNING!");
            printf("\nPara executar as opcoes abaixo eh preciso que as opcoes acima sejam executadas antes!");
            printf("\n 4  - Buscar cliente");
            printf("\n 5  - Buscar Filme");
            printf("\n 6  - Buscar Emprestimo");
            printf("\n 7  - Cadastrar outro cliente no vetor de clientes");
            printf("\n 8  - Cadastrar outro filme no vetor de filmes");
            printf("\n 9  - Cadastrar outro emprestimo no vetor de emprestimo");
            printf("\n 10 - Realizar uma devolucao");
            printf("\n 11 - Listar Atrasados");
            printf("\n 12 - Exibir informacoes de um filme a partir do codigo");
            printf("\n 13 - Atualizar o arquivo contendo a lista de clientes");
            printf("\n 14 - Atualizar o arquivo contendo a lista de filmes");
            printf("\n 15 - Atualizar o arquivo contendo a lista de emprestimos");
            printf("\n 16 - Sair do programa\n");
            scanf("%d",&opcao);

            if(opcao == 1){
            nCliente = leCliente(argv[1], c1);
            }
            if(opcao == 2){
            nFilme = leFilmes(argv[2], f1);
            }
            if(opcao == 3){
            nEmprestimo = leEmprestimo(argv[3],e1);
            }
            if(opcao == 4){
                  int aux;
                  printf("\nDigite o codigo do cliente que deseja buscar\n");
                  scanf("%d",&aux);
                  info_Clientes(c1,nCliente,aux);
            }
            if(opcao == 5){
                  char aux;
                  printf("\nDigite o genero do filme que deseja buscar\n");
                  aux = getche();
            lista_Filmes(f1,nFilme,aux);
            }
            if(opcao == 6){
                  int aux;
                  printf("\nDigite o codigo do emprestimo que deseja buscar");
                  scanf("%d",&aux);
            info_Emprestimos(e1,nEmprestimo,aux);
            }
            if(opcao == 7){
            novoCliente(c1,&nCliente);
            }
            if(opcao == 8){
            novoFilme(f1,&nFilme);
            }
            if(opcao == 9){
            novoEmprestimo(e1,&nEmprestimo);
            }
            if(opcao == 10){
            int aux;
            printf("\nDigite o codigo do emprestimo que deseja fazer a devolucao\n");
            scanf("%d",&aux);
             devolucao(e1,aux,nEmprestimo);
            }
            if(opcao == 11){
            lista_Atrasados(e1,c1,nEmprestimo,nCliente);
            }
            if(opcao == 12){
            int aux;
            printf("\nDigite o codigo do filme que deseja exibir informacoes\n");
            scanf("%d",&aux);
            info_Filmes(f1,nFilme,aux);
            }
            if(opcao == 13){
            grava_Clientes(argv[1],c1,nCliente);
            }
            if(opcao == 14){
            grava_Filmes(argv[2],f1,nFilme);
            }
            if(opcao == 15){
            grava_Emprestimos(argv[3],e1,nEmprestimo);
            }

            }while(opcao<16 | opcao>16);

            printf("\n");
            system("PAUSE");
            return 0;
      }
/*do{
                         fscanf(arquivo,"%c", &c);
                    }while(c != '$');
                    j = 0;
                    do{
                         fscanf(arquivo,"%c", &c);
                         if(c != '$')
                             f1[i].nome[j] = c;
                         j++;
                    }while(c != '$');
                    f1[i].nome[j] = '\0';

                  */
