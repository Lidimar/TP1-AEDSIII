#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>
#include "config.h"
#include "manobras.h"

typedef struct Lista_Veiculos lista_veiculos;

void le_arquivo_config(char* arq_config, char* estac);
lista_veiculos *cria_lista_veiculos();
void adicionar_veiculo(lista_veiculos **li, char nome_veiculo, int tipo_veiculo, char eixo_veiculo, int x, int y);
int le_arquivo_manobras(char* arq_manobras, char* estac);
lista_manobras *cria_lista_manobras();
void adicionar_manobra(lista_manobras **li, char nome_veiculo_mov, char eixo_mov, int posicoes_mov);
