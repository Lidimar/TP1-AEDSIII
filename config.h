#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>

/*struct veiculo{
      char nome_veiculo;
      int tipo_veiculo;
      char eixo_veiculo;
      int x;
      int y;
};*/

//typedef struct Lista_Veiculos* lista_veiculos; //lista_veiculos = Lista . Lista_Veiculos = elemento

void posiciona_veiculo(char nome_veiculo, int tipo_veiculo, char eixo_veiculo, int x, int y);
