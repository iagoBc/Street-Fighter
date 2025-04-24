#ifndef __SQUARE__  // Guardas de inclusão
#define __SQUARE__

#include <stdlib.h>
#include <stdio.h>

// Definição da estrutura 'quadrado'
typedef struct {
    unsigned short x;   // Posição X do quadrado
    unsigned short y;   // Posição Y do quadrado
    unsigned short altura;  // Tamanho a altura do quadrado
    unsigned short largura;  // Tamanho a largura do quadrado
} quadrado;

// Protótipos das funções
quadrado* quad_create(unsigned short x, unsigned short y, unsigned short altura, unsigned short largura);   // Função para criar um quadrado
void quad_destroy(quadrado *element);     // Função para destruir um quadrado

#endif  // Fim das guardas de inclusão
