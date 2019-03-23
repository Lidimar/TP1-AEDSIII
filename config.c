#include "config.h"


char **posiciona_veiculo(lista_veiculos **raiz){ //receber lista
      char **estac = malloc(sizeof (char*) * 6); //cria matriz dinamicamente
      char *mat = malloc(sizeof (char) * 6 * 6);
      for (int i=0; i<6; i++){
            estac[i] = &mat[6*i];
      }
      int i, j;
      char nome_veiculo;
      int tipo_veiculo;
      char eixo_veiculo;
      int x, y;
      
      //zera estacionamento
      for(i=0; i<6; i++){
            for(j=0; j<6; j++){
                  estac[i][j] = '0';
            }
      }
      //verifica a existência de veículos na lista
      if(*raiz == NULL){
            printf("Não há veículos no arquivo.\n");
      }
      else{
            lista_veiculos *aux;
            aux = *raiz;
            while(aux->prox != NULL){ //percorre a lista e posiciona os veículos
                  
                  aux = aux->prox;
                  nome_veiculo = aux->veiculo.nome_veiculo;
                  tipo_veiculo = aux->veiculo.tipo_veiculo;
                  eixo_veiculo = aux->veiculo.eixo_veiculo;
                  x = ((aux->veiculo.x)-1);
                  y = ((aux->veiculo.y)-1);
                 
                  printf("%c %d %c X%dY%d\n", nome_veiculo, tipo_veiculo, eixo_veiculo, x, y);
                  
                  estac[x][y]=nome_veiculo;

                  //verificar o eixo e o tipo de veículo (carro ou caminhão)
                  if(eixo_veiculo == 'x' || eixo_veiculo == 'X'){
                        if(tipo_veiculo == 2){
                              estac[(x+1)][y] = nome_veiculo;
                        }
                        else if(tipo_veiculo == 3){
                              estac[(x+1)][y] = nome_veiculo;
                              estac[(x+2)][y] = nome_veiculo;
                        }
                  }
                  else if(eixo_veiculo == 'y' || eixo_veiculo == 'Y'){
                        if(tipo_veiculo == 2){
                              estac[x][(y+1)] = nome_veiculo;
                        }
                        else if(tipo_veiculo == 3){
                              estac[x][(y+1)] = nome_veiculo;
                              estac[x][(y+2)] = nome_veiculo;
                        }
                  }
            }
      }


      //imprime a configuracao inicial do estacionamento
      for(i=5; i>=0; i--){
                  printf("%c %c %c %c %c %c\n", estac[0][i], estac[1][i], estac[2][i], estac[3][i], estac[4][i], estac[5][i]);
      }
}
