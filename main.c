#include "io.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){

      int flag;
      
      //Argumento de linha de comando do getopt
      while((flag = getopt(argc, argv, "xyh")) != -1){
            switch (flag)
            {
                  case 'x':
                        le_arquivo_config("arquivoconfig.txt");
                        break;
                  
                  case 'y':
                        le_arquivo_manobras("arquivomanobras.txt");
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
      
       return 0;
}
