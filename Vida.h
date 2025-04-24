#ifndef __VIDA__  // Guarda de inclusão para evitar múltiplas inclusões do mesmo arquivo
#define __VIDA__

#include <stdlib.h> 
#include <allegro5\allegro5.h> // Inclui a biblioteca Allegro 5 para manipulação de gráficos
#include <allegro5/allegro_image.h> // Inclui a biblioteca Allegro 5 para manipulação de imagens

// Define a estrutura 'hp' que representa um objeto com coordenadas x, y e dois valores numéricos
typedef struct {
    unsigned short x; // Coordenada x
    unsigned short y; // Coordenada y
    int num; // Valor numérico, usado provavelmente para controle de algum estado
    int aux; // Valor auxiliar, usado para comparação e controle de estado
} hp;

// Declaração da função que cria e inicializa um objeto 'hp'
hp* hp_create(unsigned short x);

// Declaração da função que atualiza o estado de um objeto 'hp' baseado no jogador
void update_vida(hp* vida, int player);

// Declaração da função que libera a memória alocada para um objeto 'hp'
void hp_destroy(hp *element);

#endif // Fim da guarda de inclusão
