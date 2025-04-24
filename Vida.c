#include "Vida.h" // Inclui o arquivo de cabeçalho "Vida.h"

// Função para criar um novo objeto 'hp'
hp* hp_create(unsigned short x){
	hp *vida = (hp*) malloc(sizeof(hp)); // Aloca memória na heap para uma nova instância de 'hp'
	vida->x = x; // Inicializa o campo 'x' da estrutura 'hp' com o valor passado como argumento
	vida->num = 92; // Inicializa o campo 'num' com o valor 92
	vida->aux = 92; // Inicializa o campo 'aux' com o valor 92
	vida->y = 30; // Inicializa o campo 'y' com o valor 30
	return vida; 
}

// Função para atualizar o estado de 'vida' baseado no jogador
void update_vida(hp* vida, int player){
	if(player == 1){ // Verifica se o jogador é o número 1
		if(vida->num < vida->aux){ // Verifica se 'num' é menor que 'aux'
			if(vida->x < 470){ // Verifica se 'x' é menor que 470
				vida->x += 5; // Incrementa 'x' em 5
				vida->aux = vida->num; // Atualiza 'aux' para ser igual a 'num'
			}
		}
	} 
	
	else { // Se o jogador não for o número 1
		if(vida->num < vida->aux){ // Verifica se 'num' é menor que 'aux'
			if(vida->x > 520){ // Verifica se 'x' é maior que 520
				vida->x -= 5; // Decrementa 'x' em 5
				vida->aux = vida->num; // Atualiza 'aux' para ser igual a 'num'
			}
		}
	}	
}

// Função para destruir (liberar) a memória alocada para 'hp'
void hp_destroy(hp *element){ 
	free(element); // Libera a memória alocada para o objeto 'hp'
}
