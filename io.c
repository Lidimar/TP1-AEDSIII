#include "io.h"


int le_arquivo_config(char* arq_config){
      char nome_veiculo;
      int tipo_veiculo;
      char eixo_veiculo;
      int x, y;
      FILE *arqc = fopen(arq_config, "r");
      if(arqc == NULL){
            printf("Erro na abertura do arquivo %s\n", arq_config);
            return 0;
      }
      lista_veiculos *lista_config;
      lista_config = cria_lista();
      if (lista_config == NULL){
            printf("ERRO 1\n");
      }
      while(!feof(arqc)){
            fscanf(arqc, "%c %d %c X%dY%d\n", &nome_veiculo, &tipo_veiculo, &eixo_veiculo, &x, &y);
            adicionar_veiculo(&lista_config, nome_veiculo, tipo_veiculo, eixo_veiculo, x, y);
      }
      posiciona_veiculo(&lista_config);

      //imprime_lista(&lista_config);
      fclose(arqc);
      return 1;
}

lista_veiculos *cria_lista(){
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

/*void imprime_lista(lista_veiculos **li){
      lista_veiculos *aux;
      aux = *li;
      while(aux->prox!=NULL){
            aux = aux->prox;
            printf("%c %d %c X%dY%d\n", aux->veiculo.nome_veiculo, aux->veiculo.tipo_veiculo, aux->veiculo.eixo_veiculo, aux->veiculo.x, aux->veiculo.y);
      }
}*/

int le_arquivo_manobras(char* arq_manobras){
      char nome_veiculo_mov;
      char eixo_mov;
      char sign;
      int posicoes_mov;
      FILE *arqm = fopen(arq_manobras, "r");
      if(arqm == NULL){
            printf("Erro na abertura do arquivo %s\n", arq_manobras);
            return 0;
      }
      
      while(!feof(arqm)){
            fscanf(arqm, "%c %c %c%d\n", &nome_veiculo_mov, &eixo_mov, &sign, &posicoes_mov);
      }
      fclose(arqm);
      return 1;
}
