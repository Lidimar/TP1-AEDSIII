/*
 * LIDIMAR DOS SANTOS JUNIOR
 * AMANDA DE ARAUJO MORATO
 *
 * MANOBRAS.H
 *
 * TRABALHO PRÁTICO I
 *
 * CIÊNCIA DA COMPUTAÇÃO
 * ALGORITMOS E ESTRUTURA DE DADOS III
 * 1/2019
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct Dados_Manobras{
      char nome_veiculo_mov;
      char eixo_mov;
      int posicoes_mov;
} Manobras;

struct Lista_Manobras{
      struct Dados_Manobras movimento;
      struct Lista_Manobras *prox;
};

typedef struct Lista_Manobras lista_manobras;

int movimenta_veiculo(lista_manobras **raiz, char* estac);
