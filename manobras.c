#include "manobras.h"

int movimenta_veiculo(lista_manobras **raiz, char* estac){
      char nome_veiculo_mov;
      char eixo_mov;
      int posicoes_mov;
      int x, y, i, cont=0;

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

                  if (eixo_mov == 'x' || eixo_mov == 'X'){ //manobras dos veículos posicionados no eixo x
                        for (int i=0; i<6; i++){
                              for (int j=0; j<6; j++){

                                    if (estac[i*6+j] == nome_veiculo_mov){
                                          x = i;
                                          y = j;
                                          cont++;
                                    }
                              }
                        }

                        if (cont == 2){ //carros
                              estac[x*6+y] = '0';
                              estac[((x-1)*6)+y] = '0';

                              //verifica colisões entre os veículos
                              if (estac[((x+posicoes_mov)*6)+y] != '0'){
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo_mov, estac[((x+posicoes_mov)*6)+y]);
                                    return 0;
                              }
                              else if (estac[(((x-1)+posicoes_mov)*6)+y] != '0'){
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo_mov, estac[(((x-1)+posicoes_mov)*6)+y]);
                                    return 0;
                              }

                              //verifica colisões entre o carro e os limites do estacionamento
                              if (((x+posicoes_mov) > 5) || (((x-1)+posicoes_mov) < 0)){
                                    printf("O carro %c ultrapassou os limites do estacionamento\n", nome_veiculo_mov);
                              }
                              estac[((x+posicoes_mov)*6)+y] = nome_veiculo_mov;
                              estac[(((x-1)+posicoes_mov)*6)+y] = nome_veiculo_mov;
                        }
                        else if (cont == 3){ //caminhões
                              estac[(x*6)+y] = '0';
                              estac[((x-1)*6)+y] = '0';
                              estac[((x-2)*6)+y] = '0';

                              //verifica colisões entre os veículos
                              if (estac[((x+posicoes_mov)*6)+y] != '0'){
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo_mov, estac[((x+posicoes_mov)*6)+y]);
                                    return 0;
                              }
                              else if (estac[(((x-1)+posicoes_mov)*6)+y] != '0'){
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo_mov, estac[(((x-1)+posicoes_mov)*6)+y]);
                                    return 0;
                              }
                              else if (estac[(((x-2)+posicoes_mov)*6)+y] != '0'){
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo_mov, estac[(((x-2)+posicoes_mov)*6)+y]);
                                    return 0;
                              }

                              //verifica colisões entre o caminhão e os limites do estacionamento
                              if (((x+posicoes_mov) > 5) || (((x-2)+posicoes_mov) < 0)){
                                    printf("O carro %c ultrapassou os limites do estacionamento\n", nome_veiculo_mov);
                              }
                              estac[((x+posicoes_mov)*6)+y] = nome_veiculo_mov;
                              estac[(((x-1)+posicoes_mov)*6)+y] = nome_veiculo_mov;
                              estac[(((x-2)+posicoes_mov)*6)+y] = nome_veiculo_mov;
                        }
                        cont = 0;
                  }
                  else if (eixo_mov == 'y' || eixo_mov == 'Y'){ //manobras dos veículos posicionados no eixo y
                        for (int i=0; i<6; i++){
                              for (int j=0; j<6; j++){
                                    if (estac[(i*6)+j] == nome_veiculo_mov){
                                          x = i;
                                          y = j;
                                          cont++;
                                    }
                              }
                        }

                        if (cont == 2){ //carros
                              estac[(x*6)+y] = '0';
                              estac[x*6+(y-1)] = '0';

                              //verifica colisões entre os veículos
                              if (estac[(x*6)+(y+posicoes_mov)] != '0'){
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo_mov, estac[(x*6)+(y+posicoes_mov)]);
                                    return 0;
                              }
                              else if (estac[(x*6)+((y-1)+posicoes_mov)] != '0'){
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo_mov, estac[(x*6)+((y-1)+posicoes_mov)]);
                                    return 0;
                              }

                              //verifica colisões entre o carro e os limites do estacionamento
                              if (((y+posicoes_mov) > 5) || (((y-1)+posicoes_mov) < 0)){
                                    printf("O carro %c ultrapassou os limites do estacionamento\n", nome_veiculo_mov);
                              }
                              estac[(x*6)+(y+posicoes_mov)] = nome_veiculo_mov;
                              estac[(x*6)+((y-1)+posicoes_mov)] = nome_veiculo_mov;
                        }
                        else if (cont == 3){ //caminhões
                              estac[(x*6)+y] = '0';
                              estac[(x*6)+(y-1)] = '0';
                              estac[(x*6)+(y-2)] = '0';

                              //verifica colisões entre os veículos
                              if (estac[(x*6)+(y+posicoes_mov)] != '0'){
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo_mov, estac[(x*6)+(y+posicoes_mov)]);
                                    return 0;
                              }
                              else if (estac[(x*6)+((y-1)+posicoes_mov)] != '0'){
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo_mov, estac[(x*6)+((y-1)+posicoes_mov)]);
                                    return 0;
                              }
                              else if (estac[(x*6)+((y-2)+posicoes_mov)] != '0'){
                                    printf("Colisão entre os veículos %c e %c\n", nome_veiculo_mov, estac[(x*6)+((y-2)+posicoes_mov)]);
                                    return 0;
                              }

                              //verifica colisões entre o caminhão e os limites do estacionamento
                              if (((y+posicoes_mov) > 5) || (((y-2)+posicoes_mov) < 0)){
                                    printf("O carro %c ultrapassou os limites do estacionamento\n", nome_veiculo_mov);
                              }

                              estac[(x*6)+(y+posicoes_mov)] = nome_veiculo_mov;
                              estac[(x*6)+((y-1)+posicoes_mov)] = nome_veiculo_mov;
                              estac[(x*6)+((y-2)+posicoes_mov)] = nome_veiculo_mov;
                        }

                        cont = 0;
                  }

            }
            
            if (estac[(5*6)+3] == 'z' || estac[(5*6)+3] == 'Z'){
                  printf("O carro Z saiu do estacionamento.\n");
            }
            else {
                  printf("O Carro Z não saiu do estacionamento.\n");
            }
      }

       //imprime a configuracao inicial do estacionamento
      for(i=5; i>=0; i--){
                  printf("%c %c %c %c %c %c\n", estac[0*6+i], estac[1*6+i], estac[2*6+i], estac[3*6+i], estac[4*6+i], estac[5*6+i]);
      }

      return 0;
}
