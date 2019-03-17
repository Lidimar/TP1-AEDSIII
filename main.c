#include "io.h"
#include "config.h"
#include "manobras.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
      int result;
      if (argc = 3){
            result = le_arquivo_config(argv[1]);
            if(result == 0){
                  return 0;
            }
            result = le_arquivo_manobras(argv[2]);
            if(result == 0){
                  return 0;
            }
            printf("OK\n");
      }
      else{
            printf("Quantidade de argumentos errada.\n");
      }
      return 0;
}
