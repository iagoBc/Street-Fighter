#ifndef __TELAS__    // Diretiva de pré-processamento para evitar inclusão múltipla do mesmo arquivo de cabeçalho
#define __TELAS__    // Define o símbolo __TELAS__ se ainda não estiver definido

#include "Player.h"    // Inclui o arquivo de cabeçalho que contém a definição da estrutura 'player' e funções relacionadas a jogadores
#include "Square.h"    // Inclui o arquivo de cabeçalho que contém a definição da estrutura 'Square' e funções relacionadas a quadrados

// Declaração da função para exibir o menu do jogo
int menu(ALLEGRO_TIMER* timer, ALLEGRO_FONT* font, ALLEGRO_FONT* font2, ALLEGRO_EVENT_QUEUE* queue);

// Declaração da função para a seleção de jogadores e arena
int selecao(ALLEGRO_TIMER* timer, ALLEGRO_FONT* font, ALLEGRO_FONT* font2, ALLEGRO_EVENT_QUEUE* queue, player* player_1, player* player_2);

// Declaração da função para o loop principal do jogo onde a jogabilidade ocorre
int jogar(ALLEGRO_TIMER* timer, ALLEGRO_EVENT_QUEUE* queue, player* player_1, player* player_2, ALLEGRO_FONT* font2, ALLEGRO_FONT* font);

#endif    // Finaliza a diretiva de pré-processamento iniciada com #ifndef
