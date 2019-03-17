

#include "io.h"

// open file of initial configuration
int ConfInit(){

    FILE *config_init = fopen("config_init.txt", "r");
    
    if (config_init == NULL) {
        printf("Erro de leitura");
        return 1;
    }
    
    printf("teste arquivo");
    
    return ConfInit;
} 


