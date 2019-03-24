#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct Dados_Veiculo{
      char nome_veiculo;
      int tipo_veiculo;
      char eixo_veiculo;
      int x;
      int y;
} Veiculo;

struct Lista_Veiculos{
      struct Dados_Veiculo veiculo;
      struct Lista_Veiculos *prox;
};

typedef struct Lista_Veiculos lista_veiculos;

char **posiciona_veiculo(lista_veiculos **raiz, char* estac);
