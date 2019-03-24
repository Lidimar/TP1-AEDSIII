#include "config.h"


char **posiciona_veiculo(lista_veiculos **raiz, char* estac){ //receber lista
            
      int i, j;
      char nome_veiculo;
      int tipo_veiculo;
      char eixo_veiculo;
      int x, y;
      
      
      //zera estacionamento
      for(i=0; i<6; i++){
            for(j=0; j<6; j++){
                  estac[(i*6)+j] = '0';
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
                  
                  estac[(x*6)+y]=nome_veiculo;

                  //verificar o eixo e o tipo de veículo (carro ou caminhão)
                  if(eixo_veiculo == 'x' || eixo_veiculo == 'X'){
                        if(tipo_veiculo == 2){
                              estac[((x+1)*6)+y]= nome_veiculo;
                        }
                        else if(tipo_veiculo == 3){
                              estac[((x+1)*6)+y] = nome_veiculo;
                              estac[((x+2)*6)+y] = nome_veiculo;
                        }
                  }
                  else if(eixo_veiculo == 'y' || eixo_veiculo == 'Y'){
                        if(tipo_veiculo == 2){
                              estac[(x*6)+(y+1)] = nome_veiculo;
                        }
                        else if(tipo_veiculo == 3){
                              estac[(x*6)+(y+1)] = nome_veiculo;
                              estac[(x*6)+(y+2)] = nome_veiculo;
                        }
                  }
            }
      }


      //imprime a configuracao inicial do estacionamento
      for(i=5; i>=0; i--){
                  printf("%c %c %c %c %c %c\n", estac[0*6+i], estac[1*6+i], estac[2*6+i], estac[3*6+i], estac[4*6+i], estac[5*6+i]);
      }
}
