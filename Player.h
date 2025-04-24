#ifndef __PLAYER__ 		// Guardas de inclusão para evitar inclusão múltipla
#define __PLAYER__		// Definição do guardas de inclusão

#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro5.h>																																											// Biblioteca base do Allegro
#include <allegro5/allegro_font.h>																																										// Biblioteca de fontes do Allegro
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include "Joystick.h"
#include "Square.h"
#include "Pers.h"
#include "Vida.h"			// Inclui outros arquivos necessários para a funcionalidade do jogador

#define PLAYER_STEP 10  // Quantidade de pixels que um jogador se move por passo
#define PLAYER_GRAV 15  // Força da gravidade aplicada ao jogador
#define X_SCREEN 1000  // Largura da tela em pixels
#define Y_SCREEN 500   // Altura da tela em pixels

// Definição da estrutura para um jogador
typedef struct {
	ALLEGRO_BITMAP** imagem;  // Ponteiro para uma matriz de bitmaps que representam as imagens do jogador
	int win;                 // Flag para indicar uma vitória (o significado exato não está claro)
	char *nome;              // Nome do jogador
	int arena;			// Nome da arena
	unsigned int index;      // Índice atual do jogador, usado para controle de animação ou estado
	unsigned int largura;   // Largura da imagem do jogador
	unsigned int altura;    // Altura da imagem do jogador
	unsigned short x;       // Posição X do jogador na tela
	unsigned short y;       // Posição Y do jogador na tela
	unsigned short pular;             // Flag para indicar se o jogador está pulando (1 para pular, 0 para não pular)
	joystick *control;     // Estrutura para controle do jogador (presumivelmente para entradas de joystick)
	hp* vida;              // Estrutura que mantém a vida do jogador
	pers* personagem;      // Estrutura que contém os detalhes do personagem, como animações
	int delay;				// Flag para colocar um delay para pular ou agachar novamente
	unsigned short agachar; // Flag para indicar se o jogador está agachado (1 para agachar, 0 para não agachar)
} player;

// Protótipos das funções
player* player_create(char* imagem, unsigned int largura, unsigned int altura, unsigned short x, unsigned short y, unsigned short max_x, unsigned short max_y, char* nome, unsigned short vida);
void player_reset(player* new_player, int num);
void player_move(player *element, char steps, unsigned char trajectory, unsigned short max_x, unsigned short max_y);
void player_destroy(player *element);
unsigned char collision_2D(player *element_first, player *element_second);
void update_position(player *player_1, player *player_2);

#endif	// Fim das guardas de inclusão
