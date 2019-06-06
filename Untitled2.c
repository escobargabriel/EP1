#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define max 100

      struct Cliente{
            int codigo;
            char nome[50];
            int telefone;
      };
      struct Filme{
            int codigo;
            char nome[50];
            char genero;
            int duracao;
            float preco;
      };
      struct Emprestimo{
            int codigoEmprestimo;
            int codigoCliente;
            int codigoFilme;
            int dia;
            int mes;
            int ano;
            char codigoEntrega;
      };

      void exibeDoArquivo(){
            FILE *arquivo;
            char c;
            arquivo = fopen ("Clientes.txt","r");
            if(!arquivo){
                  printf("\nErro ao abrir o arquivo!!!\n",argv[1]);
            }
            while(!feof(arquivo)){
                  while(c != '$'){
                  }
                  fscanf(arquivo,"%c",&c);
                        for(int i=0;i<100;i++){
                              c1.[i] = (arquivo,"%c",&c);
                                    if(!feof(arquivo)){
                                    printf("%c",c);

                                    }
                        }
            }
            fclose(arquivo);
      }

      int main(int argc,char *argv[]){
            struct cliente c1[max];
            struct Emprestimo[max];
            struct Filme[max];



            exibeDoArquivo();




            return 0;
            system("Pause")
     }
