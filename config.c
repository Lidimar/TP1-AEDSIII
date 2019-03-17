#include "config.h"


void posiciona_veiculo(char nome_veiculo, int tipo_veiculo, char eixo_veiculo, int x, int y){ //receber lista
      char estac[6][6];
      int i, j;
      for(i=0; i<6; i++){
            for(i=0; j<6; j++){
                  estac[i][j] = 0;
            }
      }
      estac[x][y]=nome_veiculo;
      if(eixo_veiculo == 'x' || eixo_veiculo == 'X'){
            if(tipo_veiculo == 2){
                  estac[x+1][y] = nome_veiculo;
            }
            if(tipo_veiculo == 3){
                  estac[x+1][y] = nome_veiculo;
                  estac[x+2][y] = nome_veiculo;
            }
      }
      else if(eixo_veiculo == 'y' || eixo_veiculo == 'Y'){
            if(tipo_veiculo == 2){
                  estac[x][y+1] = nome_veiculo;
            }
            if(tipo_veiculo == 3){
                  estac[x][y+1] = nome_veiculo;
                  estac[x][y+2] = nome_veiculo;
            }
      }
      //imprime estacionamento
      for(i=5; i>=0; i--){
            for(j=5; j>=0; j--){
                  printf("%c\n", estac[i][j]);
                  if(j=0){
                        printf("\n");
                  }
            }
      }
}
