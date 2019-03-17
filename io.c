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

      //Abertura do arquivo de Configuração inicial
      FILE *arqc = fopen(arq_config, "r");

      //Verifica se o arquivo foi aberto corretamente
      if(arqc == NULL){
            printf("Erro na abertura do arquivo %s\n", arq_config);
            return 1;
      }

      //lê todo o arquivo de manobras e envia para memoria
      while(!feof(arqc)){
            fscanf(arqc, "%c %d %c X%dY%d\n", &nome_veiculo, &tipo_veiculo, &eixo_veiculo, &x, &y);

            printf("%c %d %c X%dY%d\n",nome_veiculo, tipo_veiculo, eixo_veiculo, x, y); // teste de leitura do arquivo
      }
      fclose(arqc);
      return 0;
}

//criar lista encadeada dos veículos e das manobras e depois enviar para diminuir o tempo de execução
//posiciona_veiculo(nome_veiculo, tipo_veiculo, eixo_veiculo, x, y);
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
      li->prox = NULL;
}

int le_arquivo_manobras(char* arq_manobras){
      char nome_veiculo_mov;
      char eixo_mov;
      char sign;
      int posicoes_mov;

      //Abertura do arquivo de MANOBRAS
      FILE *arqm = fopen(arq_manobras, "r");

      //Verifica se o arquivo foi aberto corretamente
      if(arqm == NULL){
            printf("Erro na abertura do arquivo %s\n", arq_manobras);
            return 1;
      }

      //lê todo o arquivo de manobras e envia para memoria
      while(!feof(arqm)){
            fscanf(arqm, "%c %c %c%d\n", &nome_veiculo_mov, &eixo_mov, &sign, &posicoes_mov);
            printf("%c %c %c%d\n", nome_veiculo_mov, eixo_mov, sign, posicoes_mov); //teste leitura de arquivo manobras
      }

      fclose(arqm);
      return 0;
}
