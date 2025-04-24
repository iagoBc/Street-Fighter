#ifndef __PERS__                    // Início das guardas de inclusão para evitar múltiplas inclusões do mesmo cabeçalho
#define __PERS__                    // Define __PERS__ se não estiver definido

#include <stdlib.h>                
#include <stdio.h>                 
#include <allegro5/allegro5.h>      // Inclui a biblioteca principal do Allegro para manipulação gráfica
#include <allegro5/allegro_image.h> // Inclui a biblioteca de manipulação de imagens do Allegro

typedef struct {                    
    char *nome;                     // Ponteiro para uma string que armazena o nome do personagem
    ALLEGRO_BITMAP **parar;         // Ponteiro para um array de bitmaps que armazena as imagens para a ação 'parar'
    ALLEGRO_BITMAP **andar;         // Ponteiro para um array de bitmaps que armazena as imagens para a ação 'andar'
    ALLEGRO_BITMAP **pular;         // Ponteiro para um array de bitmaps que armazena as imagens para a ação 'pular'
    ALLEGRO_BITMAP **descer;        // Ponteiro para um array de bitmaps que armazena as imagens para a ação 'descer'
    ALLEGRO_BITMAP **agachar;       // Ponteiro para um array de bitmaps que armazena as imagens para a ação 'agachar'
    ALLEGRO_BITMAP **superior;      // Ponteiro para um array de bitmaps que armazena as imagens para a ação 'superior'
    ALLEGRO_BITMAP **inferior;      // Ponteiro para um array de bitmaps que armazena as imagens para a ação 'inferior'
} pers;                             // Nome da estrutura é 'pers'

pers* pers_create(char *nome);      // Declaração da função que cria um novo personagem

void pers_destroy(pers *element);   // Declaração da função que destrói um personagem, liberando a memória alocada

#endif                              // Fim das guardas de inclusão
