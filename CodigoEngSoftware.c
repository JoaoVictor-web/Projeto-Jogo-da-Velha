#include <stdio.h>

              // Função para imprimir o tabuleiro
              void print_board(char board[3][3]) {
                  printf("\n");
                  for (int i = 0; i < 3; i++) {
                      printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
                      if (i != 2) printf("---|---|---\n");
                  }
                  printf("\n");
              }

              // Função para verificar se alguém ganhou
              char check_winner(char board[3][3]) {
                  // Verificar linhas
                  for (int i = 0; i < 3; i++) {
                      if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
                          return board[i][0];
                  }

                  // Verificar colunas
                  for (int i = 0; i < 3; i++) {
                      if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
                          return board[0][i];
                  }

                  // Verificar diagonais
                  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
                      return board[0][0];
                  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
                      return board[0][2];

                  // Se não houver vencedor
                  return ' ';
              }

              int main() {
                  char board[3][3] = {
                      {' ', ' ', ' '},
                      {' ', ' ', ' '},
                      {' ', ' ', ' '}
                  };
                  int row, col;
                  char player = 'X'; // Começamos com o jogador X

                  // Loop principal do jogo
                  while (1) {
                      print_board(board);
                      printf("Jogador %c, insira a linha e coluna (de 1 a 3) separadas por espaço: ", player);
                      scanf("%d %d", &row, &col);

                      // Converter para índices base 0
                      row--;
                      col--;

                      // Verificar se a posição está vazia
                      if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
                          board[row][col] = player;

                          // Verificar se alguém ganhou
                          char winner = check_winner(board);
                          if (winner != ' ') {
                              print_board(board);
                              printf("Parabéns, jogador %c! Você ganhou!\n", winner);
                              break; // Fim do jogo
                          }

                          // Verificar empate
                          int empty = 0;
                          for (int i = 0; i < 3; i++) {
                              for (int j = 0; j < 3; j++) {
                                  if (board[i][j] == ' ') {
                                      empty = 1;
                                      break;
                                  }
                              }
                              if (empty) break;
                          }
                          if (!empty) {
                              print_board(board);
                              printf("Empate!\n");
                              break; // Fim do jogo
                          }

                          // Trocar de jogador
                          player = (player == 'X') ? 'O' : 'X';
                      } else {
                          printf("Posição inválida. Tente novamente.\n");
                      }
                  }

                  return 0;
              }