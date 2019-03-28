/*
 * LIDIMAR DOS SANTOS JUNIOR
 * AMANDA DE ARAUJO MORATO
 *
 * MANOBRAS.C
 *
 * TRABALHO PRÁTICO I
 *
 * CIÊNCIA DA COMPUTAÇÃO
 * ALGORITMOS E ESTRUTURA DE DADOS III
 * 1/2019
 */

#include "manobras.h"


int movimenta_veiculo(lista_manobras **raiz, char* estac){
      char nome_veiculo_mov;
      char eixo_mov;
      int posicoes_mov;
      int x, y, i, j, cont=0;
      
      
      if(*raiz == NULL){
            printf("Não há veículos no arquivo.\n");
      }
      else{
            lista_manobras *aux;
            aux = *raiz;

            while(aux->prox != NULL){ //percorre a lista e movimenta os veículos
                  aux = aux->prox;
                  nome_veiculo_mov = aux->movimento.nome_veiculo_mov;
                  eixo_mov = aux->movimento.eixo_mov;
                  posicoes_mov = aux->movimento.posicoes_mov;
                  
                  //Zera variaveis i e j apos uso no loop for
                  i = 0;
                  j = 0;

                  for (i=0; i<6; i++){
                      
                        for (j=0; j<6; j++){
                             
                              if (estac[i*6+j] == nome_veiculo_mov){//estac[i][j]
                                    //Atribui as variavies x e y as coordenadas da primeira casa que continha o nome do veiculo a ser movido
                                    x = i;
                                    y = j;
                                    //depois de encontrar a primeira posicao que tem o nome do veiculo o for é parado
                                    i = 6;
                                    j = 6;    
                              }
 
                        }
     
                  }
                  
                  /////******* Eixo X **********//////
                  //Caminhao do eixo x
                  if ((estac[x*6+y] == nome_veiculo_mov) && (estac[((x+1)*6)+y] == nome_veiculo_mov) && (estac[((x+2)*6)+y] == nome_veiculo_mov)){ 

                        if (eixo_mov == 'x' || eixo_mov == 'X'){ //manobras dos veículos posicionados no eixo x

                              estac[(x*6)+y] = '0';//estac[x][y],
                              estac[((x+1)*6)+y] = '0';//estac[x+1][y]
                              estac[((x+2)*6)+y] = '0';//estac[x+2][y]

                              //verifica colisões entre os veículos
                              if (estac[((x+posicoes_mov)*6)+y] != '0' && estac[((x+posicoes_mov)*6)+y] > 0){//estac[x+posicoes_mov][y]
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo_mov, estac[((x+posicoes_mov)*6)+y]);//estac[x+posicoes_mov][y]
                                    printf("colisao1x caminhao\n");
                                    printf("colisao1xx%d y%d\n", x, y);
                                    //exit(0);
                              }
                              else if (estac[(((x+1)+posicoes_mov)*6)+y] != '0' && estac[(((x+1)+posicoes_mov)*6)+y] > 0){//estac[(x+1)+posicoes_mov][y]
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo_mov, estac[(((x+1)+posicoes_mov)*6)+y]);//estac[(x+1)+posicoes_mov][y]
                                    printf("colisao2x caminhao\n");
                                    printf("colisao2x x%d y%d\n", x, y);
                                    //exit(0);
                              }
                              else if (estac[(((x+2)+posicoes_mov)*6)+y] != '0' && estac[(((x+2)+posicoes_mov)*6)+y] > 0){//estac[(x+2)+posicoes_mov][y]
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo_mov, estac[(((x+2)+posicoes_mov)*6)+y]);//estac[(x-2)+posicoes_mov][y]
                                    printf("colisao3x caminhao\n");
                                    printf("colisao3x x%d y%d\n", x, y);
                                    //exit(0);
                              }

                              //verifica colisões entre o caminhão e os limites do estacionamento
                              if (((x+posicoes_mov) > 5) || ((x+posicoes_mov) < 0) || (((x-2)+posicoes_mov) > 5) || (((x-2)+posicoes_mov) < 0) ){
                                    printf("O carro %c ultrapassou os limites do estacionamento\n", nome_veiculo_mov);
                                    printf("Ultrapassou x caminhao\n");
                                    printf("Ultrapassou x x%d y%d\n", x, y);
                                    //exit(0);
                              }
                              estac[((x+posicoes_mov)*6)+y] = nome_veiculo_mov;//estac[x+posicoes_mov][y]
                              estac[(((x+1)+posicoes_mov)*6)+y] = nome_veiculo_mov;//estac[(x-1)+posicoes_mov][y]
                              estac[(((x+2)+posicoes_mov)*6)+y] = nome_veiculo_mov;//estac[(x-2)+posicoes_mov][y]

                        }
                        //Movimentacao lateral no eixo Y
                        else if (eixo_mov == 'y' || eixo_mov == 'Y'){
                             
                             //Zera casa no eixo X 1
                              estac[(x*6)+y] = '0';//estac[x][y]
                              estac[((x+1)*6)+y] = '0';//estac[x+1][y]
                              estac[((x+2)*6)+y] = '0';//estac[x+2][y]


                              //verifica colisões entre os veículos
                              if (estac[(x*6)+(y+posicoes_mov)] != '0' && estac[(x*6)+(y+posicoes_mov)] > 0){//estac[x][y+posicoes_mov]
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo_mov, estac[(x*6)+(y+posicoes_mov)]);//estac[x][y+posicoes_mov]
                                    //exit(0);
                              }
                              else if (estac[(x*6)+((y-1)+posicoes_mov)] != '0' && estac[(x*6)+((y-1)+posicoes_mov)] > 0 ){//estac[x][(y-1)+posicoes_mov]
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo_mov, estac[(x*6)+((y-1)+posicoes_mov)]);//estac[x][(y-1)+posicoes_mov]
                                    //exit(0);
                              }
                              else if (estac[(x*6)+((y-2)+posicoes_mov)] != '0' && estac[(x*6)+((y-2)+posicoes_mov)] > 0){//estac[x][(y-2)+posicoes_mov]
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo_mov, estac[(x*6)+((y-2)+posicoes_mov)]);//estac[x][(y-2)+posicoes_mov]
                                    //exit(0);
                              }

                              //verifica colisões entre o caminhão e os limites do estacionamento
                              if (((y+posicoes_mov) > 5) || ((y+posicoes_mov) > 5) || (((y-2)+posicoes_mov) < 0) || (((y-2)+posicoes_mov) > 5)){
                                    printf("O carro %c ultrapassou os limites do estacionamento\n", nome_veiculo_mov);
                                    //exit(0);
                              }

                              estac[(x*6)+(y+posicoes_mov)] = nome_veiculo_mov;//estac[x][y+posicoes_mov]
                              estac[((x+1)*6)+(y+posicoes_mov)] = nome_veiculo_mov;//estac[x][(y+1)+posicoes_mov] 
                              estac[((x+2)*6)+(y+posicoes_mov)] = nome_veiculo_mov;//estac[x][(y+2)+posicoes_mov]
                        }
                        
                  }

                  //carros do eixo X
                  else if ((estac[x*6+y] == nome_veiculo_mov) && (estac[((x+1)*6)+y] == nome_veiculo_mov)){ 
                         
                         //Toda matriz foi desmembrada e transformada em um vetor
                        if (eixo_mov == 'x' || eixo_mov == 'X'){ //manobras dos veículos posicionados no eixo x
                              //zera a posicao antiga
                              estac[(x*6)+y] = '0';//estac[x][y],
                              estac[((x+1)*6)+y] = '0';//estac[x+1][y]

                              //verifica colisões entre os veículos
                              if (estac[((x+posicoes_mov)*6)+y] != '0' && estac[((x+posicoes_mov)*6)+y] > 0){//estac[x+posicoes_mov][y]
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo_mov, estac[((x+posicoes_mov)*6)+y]);//estac[x+posicoes_mov][y]
                                    printf("colisao1x  carro\n");
                                    //exit(0);
                              }
                              else if (estac[(((x-1)+posicoes_mov)*6)+y] != '0' && estac[(((x-1)+posicoes_mov)*6)+y] > 0){//estac[(x-1)+posicoes_mov][y]
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo_mov, estac[(((x-1)+posicoes_mov)*6)+y]);//estac[(x-1)+posicoes_mov][y]
                                    printf("colisao2x  carro\n");
                                    //exit(0);
                              }

                              //verifica colisões entre o carro e os limites do estacionamento
                              if (((x+posicoes_mov) > 5) || ((x+posicoes_mov) < 0) || (((x-1)+posicoes_mov) > 5) || (((x-1)+posicoes_mov) < 0)){
                                    printf("O carro %c ultrapassou os limites do estacionamento\n", nome_veiculo_mov);
                                    printf("Ultrapassou x  carro\n");
                                    //exit(0);
                              }

                              estac[((x+posicoes_mov)*6)+y] = nome_veiculo_mov;//estac[x+posicoes_mov][y]
                              estac[(((x+1)+posicoes_mov)*6)+y] = nome_veiculo_mov;//estac[(x+1)+posicoes_mov][y]
                        }

                        //Movimentacao lateral no eixo Y
                        else if (eixo_mov == 'y' || eixo_mov == 'Y'){
                              
                              estac[(x*6)+y] = '0';//estac[x][y]
                              estac[((x+1)*6)+y] = '0';//estac[x+1][y]


                              //verifica colisões entre os veículos
                              if (estac[(x*6)+(y+posicoes_mov)] != '0' && estac[(x*6)+(y+posicoes_mov)] > 0){//estac[x][y+posicoes_mov]
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo_mov, estac[(x*6)+(y+posicoes_mov)]);//estac[x][y+posicoes_mov]
                                    printf("colisao1y  carro\n");
                                    //exit(0);
                              }
                              else if (estac[(x*6)+((y-1)+posicoes_mov)] != '0' && estac[(x*6)+((y-1)+posicoes_mov)] > 0){//estac[x][(y-1)+posicoes_mov] 
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo_mov, estac[(x*6)+((y-1)+posicoes_mov)]);//estac[x][(y-1)+posicoes_mov]
                                    printf("colisao2y  carro\n");
                                    //exit(0);
                              }

                              //verifica colisões entre o carro e os limites do estacionamento
                              if (((y+posicoes_mov) > 5) || ((y+posicoes_mov) < 0) || (((y-1)+posicoes_mov) < 0) || (((y-1)+posicoes_mov) > 5)){
                                    printf("O carro %c ultrapassou os limites do estacionamento\n", nome_veiculo_mov);
                                    printf("Ultrapassou y  carro\n");
                                    //exit(0);
                              }
                              
                              estac[(x*6)+(y+posicoes_mov)] = nome_veiculo_mov;//estac[x][y+posicoes_mov]
                              estac[((x+1)*6)+(y+posicoes_mov)] = nome_veiculo_mov;//estac[x+1][(y+posicoes_mov] 
                        }
                        
                  }
                  
                  /////******* Fim dos Carros e Caminhoes criados no Eixo X **********//////

                  /////******* Eixo Y **********//////

                  //Caminhao do eixo Y
                  if ((estac[x*6+y] == nome_veiculo_mov) && (estac[(x*6)+(y+1)] == nome_veiculo_mov) && (estac[(x*6)+(y+2)] == nome_veiculo_mov)){ 

                        //manobras dos veículos posicionados no eixo x
                        if (eixo_mov == 'y' || eixo_mov == 'Y'){ 

                              estac[(x*6)+y] = '0';//estac[x][y]
                              estac[(x*6)+(y+1)] = '0';//estac[x][y-1]
                              estac[(x*6)+(y+2)] = '0';//estac[x][y-2]

                              //verifica colisões entre os veículos
                              if (estac[(x*6)+(y+posicoes_mov)] != '0' && estac[(x*6)+(y+posicoes_mov)] > 0){//estac[x][y+posicoes_mov]
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo_mov, estac[(x*6)+(y+posicoes_mov)]);//estac[x][y+posicoes_mov]
                                    //exit(0);
                              }
                              else if (estac[(x*6)+((y-1)+posicoes_mov)] != '0' && estac[(x*6)+((y-1)+posicoes_mov)] > 0 ){//estac[x][(y-1)+posicoes_mov]
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo_mov, estac[(x*6)+((y-1)+posicoes_mov)]);//estac[x][(y-1)+posicoes_mov]
                                    //exit(0);
                              }
                              else if (estac[(x*6)+((y-2)+posicoes_mov)] != '0' && estac[(x*6)+((y-2)+posicoes_mov)] > 0){//estac[x][(y-2)+posicoes_mov]
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo_mov, estac[(x*6)+((y-2)+posicoes_mov)]);//estac[x][(y-2)+posicoes_mov]
                                    //exit(0);
                              }

                              //verifica colisões entre o caminhão e os limites do estacionamento
                              if (((y+posicoes_mov) > 5) || ((y+posicoes_mov) > 5) || (((y-2)+posicoes_mov) < 0) || (((y-2)+posicoes_mov) > 5)){
                                    printf("O carro %c ultrapassou os limites do estacionamento\n", nome_veiculo_mov);
                                    //exit(0);
                              }

                              printf("%d %c\n", posicoes_mov, nome_veiculo_mov);

                              estac[(x*6)+(y+posicoes_mov)] = nome_veiculo_mov;//estac[x][y+posicoes_mov]
                              estac[(x*6)+((y+1)+posicoes_mov)] = nome_veiculo_mov;//estac[x][(y-1)+posicoes_mov] 
                              estac[(x*6)+((y+2)+posicoes_mov)] = nome_veiculo_mov;//estac[x][(y-2)+posicoes_mov]

                        }
                        //Movimentacao lateral no eixo x
                        else if (eixo_mov == 'x' || eixo_mov == 'X'){
                             
                             //eixo x 1
                              estac[(x*6)+y] = '0';//estac[x][y],
                              estac[(x*6)+(y+1)] = '0';//estac[x+1][y]
                              estac[(x*6)+(y+2)] = '0';//estac[x+1][y]

                              //verifica colisões entre os veículos
                              if (estac[(x*6)+(y+posicoes_mov)] != '0' && estac[(x*6)+(y+posicoes_mov)] > 0){//estac[x][y+posicoes_mov]
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo_mov, estac[(x*6)+(y+posicoes_mov)]);//estac[x][y+posicoes_mov]
                                    //exit(0);
                              }
                              else if (estac[(x*6)+((y-1)+posicoes_mov)] != '0' && estac[(x*6)+((y-1)+posicoes_mov)] > 0 ){//estac[x][(y-1)+posicoes_mov]
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo_mov, estac[(x*6)+((y-1)+posicoes_mov)]);//estac[x][(y-1)+posicoes_mov]
                                    //exit(0);
                              }
                              else if (estac[(x*6)+((y-2)+posicoes_mov)] != '0' && estac[(x*6)+((y-2)+posicoes_mov)] > 0){//estac[x][(y-2)+posicoes_mov]
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo_mov, estac[(x*6)+((y-2)+posicoes_mov)]);//estac[x][(y-2)+posicoes_mov]
                                    //exit(0);
                              }

                              //verifica colisões entre o caminhão e os limites do estacionamento
                              if (((y+posicoes_mov) > 5) || ((y+posicoes_mov) > 5) || (((y-2)+posicoes_mov) < 0) || (((y-2)+posicoes_mov) > 5)){
                                    printf("O carro %c ultrapassou os limites do estacionamento\n", nome_veiculo_mov);
                                    //exit(0);
                              }

                              estac[((x+posicoes_mov)*6)+y] = nome_veiculo_mov;//estac[x-posicoes_mov][y+]
                              estac[((x+posicoes_mov)*6)+(y+1)] = nome_veiculo_mov;//estac[x-posicoes_mov][y+1] 
                              estac[((x+posicoes_mov)*6)+(y+2)] = nome_veiculo_mov;//estac[x-posicoes_mov][y+2] 
                        }
                        
                  }

                  //carros do eixo y
                  else if ((estac[x*6+y] == nome_veiculo_mov) && (estac[(x*6)+(y+1)] == nome_veiculo_mov)){ 
                         
                        //Toda matriz foi desmembrada e transformada em um vetor
                        if (eixo_mov == 'y' || eixo_mov == 'Y'){ //manobras dos veículos posicionados no eixo x
                              //zera a posicao antiga
                              estac[(x*6)+y] = '0';//estac[x][y]
                              estac[(x*6)+(y+1)] = '0';//estac[x][y-1]

                              //verifica colisões entre os veículos
                              if (estac[(x*6)+(y+posicoes_mov)] != '0' && estac[(x*6)+(y+posicoes_mov)] > 0){//estac[x][y+posicoes_mov]
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo_mov, estac[(x*6)+(y+posicoes_mov)]);//estac[x][y+posicoes_mov]
                                    //exit(0);
                              }
                              else if (estac[(x*6)+((y-1)+posicoes_mov)] != '0' && estac[(x*6)+((y-1)+posicoes_mov)] > 0){//estac[x][(y-1)+posicoes_mov] 
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo_mov, estac[(x*6)+((y-1)+posicoes_mov)]);//estac[x][(y-1)+posicoes_mov]
                                    //exit(0);
                              }

                              //verifica colisões entre o carro e os limites do estacionamento
                              if (((y+posicoes_mov) > 5) || ((y+posicoes_mov) < 0) || (((y-1)+posicoes_mov) < 0) || (((y-1)+posicoes_mov) > 5)){
                                    printf("O carro %c ultrapassou os limites do estacionamento\n", nome_veiculo_mov);
                                    //exit(0);
                              }
                              estac[(x*6)+(y+posicoes_mov)] = nome_veiculo_mov;//estac[x][y+posicoes_mov]
                              estac[(x*6)+((y+1)+posicoes_mov)] = nome_veiculo_mov;//estac[x][(y-1)+posicoes_mov]

                        }

                        //Movimentacao lateral no eixo X
                        else if (eixo_mov == 'x' || eixo_mov == 'X'){
                              
                              //eixo x 1
                              estac[(x*6)+y] = '0';//estac[x][y],
                              printf("x%d y%d\n", x, y);
                              
                              //eixo x 2
                              estac[(x*6)+(y+1)] = '0';//estac[x][y],
                              printf("x%d y%d\n", x, y+1);
                              


                              //verifica colisões entre os veículos
                              if (estac[(x*6)+(y+posicoes_mov)] != '0' && estac[(x*6)+(y+posicoes_mov)] > 0){//estac[x][y+posicoes_mov]
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo_mov, estac[(x*6)+(y+posicoes_mov)]);//estac[x][y+posicoes_mov]
                                    //exit(0);
                              }
                              else if (estac[(x*6)+((y-1)+posicoes_mov)] != '0' && estac[(x*6)+((y-1)+posicoes_mov)] > 0){//estac[x][(y-1)+posicoes_mov] 
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo_mov, estac[(x*6)+((y-1)+posicoes_mov)]);//estac[x][(y-1)+posicoes_mov]
                                    //exit(0);
                              }

                              //verifica colisões entre o carro e os limites do estacionamento
                              if (((y+posicoes_mov) > 5) || ((y+posicoes_mov) < 0) || (((y-1)+posicoes_mov) < 0) || (((y-1)+posicoes_mov) > 5)){
                                    printf("O carro %c ultrapassou os limites do estacionamento\n", nome_veiculo_mov);
                                    //exit(0);
                              }
                              
                              estac[((x+posicoes_mov)*6)+y] = nome_veiculo_mov;//estac[x-posicoes_mov][y] 
                              printf("x%d y%d\n", x-posicoes_mov, y);
                              estac[((x+posicoes_mov)*6)+(y+1)] = nome_veiculo_mov;//estac[x-posicoes_mov][y+1]  
                              printf("x%d y%d\n", x-posicoes_mov, y+1);
                        }
                        
                  }
                  
                  /////******* Fim do Eixo Y **********//////
            }
            
            if (estac[(5*6)+3] == 'z' || estac[(5*6)+3] == 'Z'){//estac[5][3] == 'z' || estac[5][3] == 'Z'
                  printf("O carro Z saiu do estacionamento.\n");
            }
            else {
                  printf("O Carro Z não saiu do estacionamento.\n");
            }
      }

      printf("Saida\n");
       //imprime a configuracao inicial do estacionamento
      for(i=5; i>=0; i--){
                  printf("%c %c %c %c %c %c\n", estac[0*6+i], estac[1*6+i], estac[2*6+i], estac[3*6+i], estac[4*6+i], estac[5*6+i]);
      }

      return 0;
}
