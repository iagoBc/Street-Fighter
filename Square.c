#include "Square.h"

// Função para criar um novo quadrado
quadrado* quad_create(unsigned short x, unsigned short y, unsigned short altura, unsigned short largura) {
    quadrado *quad = (quadrado*) malloc(sizeof(quadrado)); // Aloca memória na heap para um novo quadrado
    // Verifica se a alocação foi bem-sucedida
    if (quad == NULL) {
        perror("Falha para alocar memória para o quadrado");
        return NULL;
    }
    quad->x = x;        // Define a posição X do quadrado
    quad->altura = altura;  // Define a altura do quadrado
    quad->largura = largura;  // Define a altura do quadrado  
    quad->y = y;     // Define a posição Y do quadrado
    return quad;       // Retorna o ponteiro para o novo quadrado
}

// Função para destruir um quadrado e liberar memória
void quad_destroy(quadrado *element) {
    // Libera a memória alocada para o quadrado
    free(element);
}
