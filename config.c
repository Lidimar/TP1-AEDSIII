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
                  x = ((aux->veiculo.x)-1);//subtrai uma casa da coordenada X para ser posicionada no local correto na matriz com inicio em 0
                  y = ((aux->veiculo.y)-1);//subtrai uma casa da coordenada y para ser posicionada no local correto na matriz com inicio em 0
                 
                  
                  //verifica se já existe carro na posicao
                  if (estac[(x*6)+y] == '0') {
                        estac[(x*6)+y] = nome_veiculo;//estac[x][y]
                  }
                  else{
                        printf("Colisão entre os veículos %c e %c\n", nome_veiculo, estac[(x*6)+y]);
                        exit(0);
                  }
                  

                  //verificar o eixo e o tipo de veículo (carro ou caminhão)
                  //Toda matriz foi desmembrada e transformada em um vetor
                  if(eixo_veiculo == 'x' || eixo_veiculo == 'X'){                        
                        //se o carro nasce entre o x[0] e x[4] ele adiciona mais uma/duas casas para completar o carro ou caminhao
                        if(tipo_veiculo == 2 && x < 5){//carro
                              //verifica se já existe carro na posicao
                              if (estac[((x+1)*6)+y] == '0') {
                                    estac[((x+1)*6)+y] = nome_veiculo; //estac[x+1][y]
                              }
                              else{
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo, estac[((x+1)*6)+y]);
                                    exit(0);
                              }
                               
                        }
                        else if(tipo_veiculo == 3 && x < 5){//caminhao
                              //verifica se já existe carro na posicao
                              if (estac[((x+1)*6)+y] == '0') {
                                    estac[((x+1)*6)+y] = nome_veiculo;//estac[x+1][y]
                              }
                              else{
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo, estac[((x+1)*6)+y]);
                                    exit(0);
                              }
                              if (estac[((x+2)*6)+y]) {//verifica se já existe carro na posicao
                                    estac[((x+2)*6)+y] = nome_veiculo;//estac[x+2][y]
                              }
                              else{
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo, estac[((x+2)*6)+y]);
                                    exit(0);
                              }
                        }
                        //se o carro nasce em posicao >= x[4]  ele adiciona mais uma/duas casas para completar o carro ou caminhao em direcao contraria ao muro
                        else if(tipo_veiculo == 2 && x >= 5){//carro
                              
                              //verifica se já existe carro na posicao
                              if(estac[((x-1)*6)+y] == '0'){
                                    estac[((x-1)*6)+y] = nome_veiculo; //estac[x-1][y]
                              }
                              else{
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo, estac[((x-1)*6)+y]);
                                    exit(0);
                              }
                        }
                        else if(tipo_veiculo == 3 && x >= 5){
                              //verifica se já existe carro na posicao
                              if (estac[((x-1)*6)+y] == '0') {
                                    estac[((x-1)*6)+y] = nome_veiculo;//estac[x-1][y]
                              }
                              else{
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo, estac[((x-1)*6)+y]);
                                    exit(0);
                              }

                              if (estac[((x-2)*6)+y] == '0') {
                                   estac[((x-2)*6)+y] = nome_veiculo;//estac[x-2][y]
                              }
                              else{
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo, estac[((x-2)*6)+y]);
                                    exit(0);
                              }
                              
                        }
                  }
                  else if(eixo_veiculo == 'y' || eixo_veiculo == 'Y'){
                        //se o carro nasce entre o y[0] e y[4] ele adiciona mais uma/duas casas para completar o carro ou caminhao
                        if(tipo_veiculo == 2 && y < 5 ){
                              //verifica se já existe carro na posicao
                              if(estac[(x*6)+(y+1)] == '0'){
                                    estac[(x*6)+(y+1)] = nome_veiculo;//estac[x][y+1]
                              }
                              else{
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo, estac[(x*6)+(y+1)]);
                                    exit(0);
                              }
                              
                        }
                        else if(tipo_veiculo == 3 && y < 5){
                              //verifica se já existe carro na posicao
                              if (estac[(x*6)+(y+1)] == '0') {
                                    estac[(x*6)+(y+1)] = nome_veiculo;//estac[x][y+1]
                              }
                              else{
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo, estac[(x*6)+(y+1)]);
                                    exit(0);
                              }

                              if (estac[(x*6)+(y+2)] == '0') {
                                   estac[(x*6)+(y+2)] = nome_veiculo;//estac[x][y+2]
                              }
                              else{
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo, estac[(x*6)+(y+2)]);
                                    exit(0);
                              }
                              
                              
                        }
                        //se o carro nasce em posicao >= y[4]  ele adiciona mais uma/duas casas para completar o carro ou caminhao em direcao contraria ao muro
                        else if (tipo_veiculo == 2 && y >= 5 ) {
                              //verifica se já existe carro na posicao
                              if(estac[(x*6)+(y-1)] == '0'){
                                    estac[(x*6)+(y-1)] = nome_veiculo;//estac[x][y-1]
                              }
                              else{
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo, estac[(x*6)+(y-1)]);
                                    exit(0);
                              }
                              
                        }
                        else if(tipo_veiculo == 3 && y >= 5){
                              //verifica se já existe carro na posicao
                              if (estac[(x*6)+(y-1)] == '0') {
                                    estac[(x*6)+(y-1)] = nome_veiculo;//estac[x][y-1]
                              }
                              else{
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo, estac[(x*6)+(y-1)]);
                                    exit(0);
                              }

                              if (estac[(x*6)+(y-2)] == '0') {
                                   estac[(x*6)+(y-2)] = nome_veiculo;//estac[x][y-2]
                              }
                              else{
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo, estac[(x*6)+(y-2)]);
                                    exit(0);
                              }
                              
                              
                        }
                        
                  }
            }
      }

      printf("Entrada\n");

      //imprime a configuracao inicial do estacionamento
      for(i=5; i>=0; i--){
                  printf("%c %c %c %c %c %c\n", estac[0*6+i], estac[1*6+i], estac[2*6+i], estac[3*6+i], estac[4*6+i], estac[5*6+i]);
      }

      printf("\n");

      return 0;
}
