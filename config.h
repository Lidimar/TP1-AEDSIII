/*
 * LIDIMAR DOS SANTOS JUNIOR
 * AMANDA DE ARAUJO MORATO
 *
 * CONFIG.H
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

#ifndef CONFIG_H
#define CONFIG_H

typedef struct Dados_Veiculo{
      char nome_veiculo;
      int tipo_veiculo;
      char eixo_veiculo;
      int x;
      int y;
} Veiculo;

typedef struct Lista_Veiculos{
      struct Dados_Veiculo veiculo;
      struct Lista_Veiculos *prox;
}lista_veiculos;


char **posiciona_veiculo(lista_veiculos **raiz, char* estac);

#endif