#include "io.h"

typedef struct Lista_Veiculos{
      struct Veiculo veiculo;
      struct Lista_Veiculos *prox;
} lista_veiculos;

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
      while(!feof(arqc)){
            fscanf(arqc, "%c %d %c X%dY%d\n", &nome_veiculo, &tipo_veiculo, &eixo_veiculo, &x, &y);
            //criar lista encadeada dos veículos e das manobras e depois enviar para diminuir o tempo de execução
            //posiciona_veiculo(nome_veiculo, tipo_veiculo, eixo_veiculo, x, y);
      }
      fclose(arqc);
      return 1;
}

lista_veiculos *criar_lista(){
      lista_veiculos *li = (lista_veiculos*)malloc(sizeof(lista_veiculos));
      if(li == NULL){
            printf("Falha ao alocar memória.\n");
            return NULL;
      }
      return li;
}

lista_veiculos *adicionar_veiculo(lista_veiculos *li, char nome_veiculo, int tipo_veiculo, char eixo_veiculo, int x, int y){
      li->veiculo.nome_veiculo = nome_veiculo;
      li->veiculo.tipo_veiculo = tipo_veiculo;
      li->veiculo.eixo_veiculo = eixo_veiculo;
      li->veiculo.x = x;
      li->veiculo.y = y;
      li->prox = NUll
}

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
