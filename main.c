#include "io.h"
#include "config.h"
#include "manobras.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
      int result;

      le_arquivo_config("arquivoconfig.txt");
      le_arquivo_manobras("arquivomanobras.txt");
            
      return 0;
}
