#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>
#include "config.h"

typedef struct Lista_Veiculos lista_veiculos;

int le_arquivo_config(char* arq_config);
int le_arquivo_manobras(char* arq_manobras);
lista_veiculos *cria_lista();
//void imprime_lista(lista_veiculos **li);
void adicionar_veiculo(lista_veiculos **li, char nome_veiculo, int tipo_veiculo, char eixo_veiculo, int x, int y);
