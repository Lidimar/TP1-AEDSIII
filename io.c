/*
 * LIDIMAR DOS SANTOS JUNIOR
 * AMANDA DE ARAUJO MORATO
 *
 * IO.C
 *
 * TRABALHO PRÁTICO I
 *
 * CIÊNCIA DA COMPUTAÇÃO
 * ALGORITMOS E ESTRUTURA DE DADOS III
 * 1/2019
 */

#include "io.h"

void le_arquivo_config(char *arq_config, char *estac){
      char nome_veiculo;
      int tipo_veiculo;
      char eixo_veiculo;
      int x, y;

      FILE *arqc = fopen(arq_config, "r");

      if(arqc == NULL){
            printf("Erro na abertura do arquivo %s\n", arq_config);
            return 1;
      }

      lista_veiculos *lista_config;
      lista_config = cria_lista_veiculos();

     

      while(!feof(arqc)){
            fscanf(arqc, "%c %d %c X%dY%d\n", &nome_veiculo, &tipo_veiculo, &eixo_veiculo, &x, &y);//le todo o arquivo e grava nas variaveis

            printf("%c %d %c X%dY%d\n", nome_veiculo, tipo_veiculo, eixo_veiculo, x, y);//printa as coordenadas existente no arquivo de configuracao

            adicionar_veiculo(&lista_config, nome_veiculo, tipo_veiculo, eixo_veiculo, x, y);
            
      }

      posiciona_veiculo(&lista_config, estac);

      
      fclose(arqc);

}

lista_veiculos *cria_lista_veiculos(){
      
      lista_veiculos *li = (lista_veiculos*) malloc (sizeof(lista_veiculos));
     
      if(li == NULL){
            printf("Erro ao alocar memória.\n");
            return NULL;
      }

      li->prox = NULL;

      return li;
}

void adicionar_veiculo(lista_veiculos **li, char nome_veiculo, int tipo_veiculo, char eixo_veiculo, int x, int y){
      
      lista_veiculos *novo = (lista_veiculos*) malloc(sizeof(lista_veiculos));
      
      if(novo == NULL){
            printf("Erro ao alocar memória.\n");
            exit(0);
      }

      novo->veiculo.nome_veiculo = nome_veiculo;
      novo->veiculo.tipo_veiculo = tipo_veiculo;
      novo->veiculo.eixo_veiculo = eixo_veiculo;
      novo->veiculo.x = x;
      novo->veiculo.y = y;
      novo->prox = NULL;

      if(*li == NULL){
            *li = novo;
      }
      else{
            lista_veiculos *aux;
            aux = *li;

            while (aux->prox != NULL){
                  aux = aux->prox;
            }

            aux->prox = novo;
      }

}

int le_arquivo_manobras(char* arq_manobras, char* estac){
       
      char nome_veiculo_mov;
      char eixo_mov;
      int posicoes_mov;

      FILE *arqm = fopen(arq_manobras, "r");

      if(arqm == NULL){
            printf("Erro na abertura do arquivo %s\n", arq_manobras);
            return 1;
      }
  
      lista_manobras *lista_movimentos;
      lista_movimentos = cria_lista_manobras();

      lista_veiculos *lista_config;
      lista_config = cria_lista_veiculos();

      
      int cont = 0;

      while(!feof(arqm)){
            fscanf(arqm, "%c %c %d\n", &nome_veiculo_mov, &eixo_mov, &posicoes_mov);

            adicionar_manobra(&lista_movimentos, nome_veiculo_mov, eixo_mov, posicoes_mov);

            cont++;
      }

      int result = movimenta_veiculo(&lista_movimentos, estac);

      fclose(arqm);

      return 0;
}

lista_manobras *cria_lista_manobras(){
     
      lista_manobras *li = (lista_manobras*) malloc (sizeof(lista_manobras));
     
      if(li == NULL){
            printf("Erro ao alocar memória.\n");
            return NULL;
      }
      
      li->prox = NULL;
      
      return li;
}

void adicionar_manobra(lista_manobras **li, char nome_veiculo_mov, char eixo_mov, int posicoes_mov){

      lista_manobras *novo = (lista_manobras*) malloc(sizeof(lista_manobras));
      
      if(novo == NULL){
            printf("Erro ao alocar memória.\n");
            exit(0);
      }

      novo->movimento.nome_veiculo_mov = nome_veiculo_mov;
      novo->movimento.eixo_mov = eixo_mov;
      novo->movimento.posicoes_mov = posicoes_mov;
      novo->prox = NULL;

      if(*li == NULL){
            *li = novo;
      }
      else{
            lista_manobras *aux;
            aux = *li;
            
            while (aux->prox != NULL){
                  aux = aux->prox;
            }
            
            aux->prox = novo;
      }
      
}

void iniciaTempo(Tempo *t){
    
    //Inicia a contagem de tempo do usuario e sistema.
    getrusage(RUSAGE_SELF, &(t->resources));
    t->inicioU = t->resources.ru_utime;
    t->inicioS = t->resources.ru_stime;
}

void finalizaTempo(Tempo *t,double *tempoU, double *tempoS){
    
    // Finaliza a contagem de tempo do usuario e sistema.
    getrusage(RUSAGE_SELF, &(t->resources));
    t->fimU = t->resources.ru_utime;
    t->fimS = t->resources.ru_stime;
    
    // Calcula o tempo do usuario.
    *tempoU = (double) (t->fimU.tv_sec - t->inicioU.tv_sec) + 1.e-6 * (double) (t->fimU.tv_usec - t->inicioU.tv_usec);
    
    // Calcula o tempo do sistema.
    *tempoS = (double) (t->fimS.tv_sec - t->inicioS.tv_sec) + 1.e-6 * (double) (t->fimS.tv_usec - t->inicioS.tv_usec);
}

//Mostra help do getopt
void show_help(char *name) {
    fprintf(stderr, "\
            [uso] %s <opcoes>\n\
            -h Help.\n\
            -x Carregar Arquivo de configuracao inicial do estacionamento\n\
            -y Carrega Arquvio de manobras.\n", name) ;
    exit(-1) ;
}


