/*
 * LIDIMAR DOS SANTOS JUNIOR
 * AMANDA DE ARAUJO MORATO
 *
 * MAIN.C
 *
 * TRABALHO PRÁTICO I
 *
 * CIÊNCIA DA COMPUTAÇÃO
 * ALGORITMOS E ESTRUTURA DE DADOS III
 * 1/2019
 */

#include "io.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
      //cria uma struct para inicializacao do getimeofday
      struct timeval inicio, final;
      
      //inicializa gettimeofday
      gettimeofday(&inicio, NULL);
      
      Tempo t;
      
      //inicia a contagem do tempo por getrusage
      iniciaTempo(&t);

      int flag;
      
      //Aloca memoria para tamanho do estacionamento de 6x6
      char* estac = malloc(sizeof (char) * 6 * 6);      

      //Argumento de linha de comando do getopt
      while((flag = getopt(argc, argv, "xyh")) != -1){
            switch (flag)
            {
                  case 'x':
                        le_arquivo_config("arquivoconfig.txt", estac);
                        break;
                  
                  case 'y':
                        le_arquivo_manobras("arquivomanobras.txt", estac);
                        break;

                  case 'h':
                        fprintf(stderr, "-x Chamar arquivo de configuracao inicial\n-y Chamar arquivo de manobras\n");
                        break;

                  case '?':
                        fprintf(stderr, "Argumento inválido ou não informado\n");
                        break;

                  default:
                        printf("Opcao invalida ou faltando argumento: `%c'\n", optopt) ;
                        break;
            }
      }

      
      //finaliza funcao de tempo por getrusage
      finalizaTempo(&t, &t.tempoU, &t.tempoS);
      
      //imprime os tempos de getrusage
      printf("\n\n-Getrusage\nUser time: %f\nSystem Time: %f\nTotal Time: %f\n", t.tempoU, t.tempoS, t.tempoS + t.tempoU);
      
      //finaliza a funcao gettimeofday
      gettimeofday(&final, NULL);
      
      //imprime gettimeofday
      printf("Get Time of Day: %ld\n", (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000));


      return 0;
}
