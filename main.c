#include "io.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){

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
                        fprintf(stderr, "getopt");
                        break;
            }
      }
      
      //fecha os arquivos aberto
     // int fcloseall();

      return 0;
}
