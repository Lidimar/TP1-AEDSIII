#include "io.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
      int result;
      if (argc=3){
            result = le_arquivo_config(argv[1]);
            result = le_arquivo_manobras(argv[2]);
      }
      else{
            printf("Quantidade de argumentos errada.\n");
      }
      return 0;
}
