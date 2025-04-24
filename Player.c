#include "Player.h"

player* player_create(char* imagem, unsigned int largura, unsigned int altura, unsigned short x, unsigned short y, unsigned short max_x, unsigned short max_y, char* nome, unsigned short vida) {
    // Verifica se a posição inicial do jogador está dentro dos limites da área definida
    if ((x - largura/2 < 0) || (x + largura/2 > max_x) || (y - altura/2 < 0) || (y + altura/2 > max_y)) return NULL;

    // Aloca memória para um novo jogador (estrutura player)
    player *new_player = (player*) malloc(sizeof(player));
    
    // Aloca memória para um array de ponteiros para bitmaps (aqui alocando apenas um elemento)
    new_player->imagem = (ALLEGRO_BITMAP**) malloc(sizeof(ALLEGRO_BITMAP*));
    
    // Carrega a imagem do jogador a partir do arquivo especificado
    new_player->imagem[0] = al_load_bitmap(imagem);
    
    // Define as propriedades do jogador com os valores fornecidos
    new_player->largura = largura;      
    new_player->altura = altura;        
    new_player->x = x;                  
    new_player->y = y;                  
    new_player->nome = nome;            
    new_player->pular = 0;              
    new_player->index = 0;              
    new_player->win = 0;
    new_player->delay = 0;                
    
    // Cria um novo controle para o jogador usando a função joystick_create
    new_player->control = joystick_create();
    
    // Cria um novo objeto de vida para o jogador com a quantidade de vida fornecida
    new_player->vida = hp_create(vida);
    
    // Retorna o ponteiro para o novo jogador criado
    return new_player;
}

void player_reset(player* new_player, int num) {
    // Reseta o atributo 'pular' para 0, provavelmente indicando que o jogador não está pulando
    new_player->pular = 0;

    // Reseta o índice (pode ser usado para animações ou estados do jogador)
    new_player->index = 0;

    // Define as dimensões padrão do jogador
    new_player->largura = 120;  // Define a largura do jogador
    new_player->altura = 150;   // Define a altura do jogador

    // Define a posição inicial do jogador com base no valor de 'num'
    if (num == 1) {
        new_player->x = 70;              // Define a posição inicial do jogador no eixo X para o caso 'num' igual a 1
        new_player->vida->x = 20;       // Define a posição X da vida do jogador para o caso 'num' igual a 1
    } else {
        new_player->x = 800;             // Define a posição inicial do jogador no eixo X para o caso 'num' diferente de 1
        new_player->vida->x = 980;      // Define a posição X da vida do jogador para o caso 'num' diferente de 1
    }

    // Define a posição Y do jogador
    new_player->y = 300;                // Define a posição inicial do jogador no eixo Y

    // Destrói o controle atual do jogador e cria um novo
    joystick_destroy(new_player->control);  // Destrói o controle antigo
    new_player->control = joystick_create(); // Cria um novo controle

    // Reseta o status da vida do jogador
    new_player->vida->aux = 92;         // Reseta o atributo auxiliar da vida
    new_player->vida->num = 92;         // Reseta o número de vida
}

void player_move(player *element, char steps, unsigned char trajectory, unsigned short max_x, unsigned short max_y) {
    // Trajetória 0: Movimento para a esquerda
    if (!trajectory) {
        // Verifica se o movimento para a esquerda é possível sem sair dos limites da tela
        if ((element->x - steps * PLAYER_STEP) - element->largura / 2 >= 10) {
            element->x = element->x - steps * PLAYER_STEP; // Move o jogador para a esquerda
        }
    }

    // Trajetória 1: Movimento para a direita
    else if (trajectory == 1) {
        // Verifica se o movimento para a direita é possível sem sair dos limites da tela
        if ((element->x + steps * PLAYER_STEP) + element->largura / 2 <= max_x - 135) {
            element->x = element->x + steps * PLAYER_STEP; // Move o jogador para a direita
        }
    }

    // Trajetória 2: Movimento para cima (pular)
    else if (trajectory == 2) {
        // Verifica se o movimento para cima é possível sem sair dos limites da tela
        if ((element->y - steps * PLAYER_GRAV) - element->altura / 2 >= 10) {
            element->y = element->y - steps * PLAYER_GRAV; // Move o jogador para cima
        }

        // Se o jogador não está pulando, inicia o pulo
        if (element->pular == 0) {
            element->pular = 1; // Marca que o jogador começou a pular
        }
    }

    // Trajetória 3: Movimento para baixo (cair)
    else if (trajectory == 3) {
        // Verifica se o movimento para baixo é possível sem sair dos limites da tela
        if ((element->y + steps * PLAYER_GRAV) + element->altura / 2 <= max_y - 100) {
            element->y = element->y + steps * PLAYER_GRAV; // Move o jogador para baixo
        }
    }
}

unsigned char collision_2D(player *element_first, player *element_second){

	if ((((element_first->y+element_first->altura/2 >= element_second->y-element_second->altura/2) && (element_second->y-element_second->altura/2 >= element_first->y-element_first->altura/2)) || 	//			//Verifica se o primeiro elemento colidiu com o segundo no eixo X			
		((element_second->y+element_second->altura/2 >= element_first->y-element_first->altura/2) && (element_first->y-element_first->altura/2 >= element_second->y-element_second->altura/2))) && 	//			//Verifica se o segundo elemento colidiu com o primeiro no eixo X
		(((element_first->x+element_first->largura/2 >= element_second->x-element_second->largura/2) && (element_second->x-element_second->largura/2 >= element_first->x-element_first->largura/2)) || 	//			//Verifica se o primeiro elemento colidiu com o segundo no eixo Y
		((element_second->x+element_second->largura/2 >= element_first->x-element_first->largura/2) && (element_first->x-element_first->largura/2 >= element_second->x-element_second->largura/2)))) return 1;		//Verifica se o segundo elemento colidiu com o primeiro no eixo Y
	else return 0;
}

void update_position(player *player_1, player *player_2) {

    // Se o jogador 1 está pulando e está acima de 120 no eixo Y
    if (player_1->pular == 1 && player_1->y > 120) {
        player_move(player_1, 1, 2, X_SCREEN, Y_SCREEN); // Move o jogador 1 para cima
    } 
	
	else {
        player_1->pular = 0; // Se não está pulando, garante que o estado de pular está desligado
    }

    // Se o jogador 1 não está na posição Y 300 e não está pulando
    if (player_1->y != 300 && player_1->pular == 0) {
        player_1->imagem = player_1->personagem->descer; // Define a imagem de descida
        player_move(player_1, 1, 3, X_SCREEN, Y_SCREEN); // Move o jogador 1 para baixo
        // Se há colisão com o jogador 2, desfaz o movimento
        if (collision_2D(player_1, player_2)) {
            player_move(player_1, -1, 3, X_SCREEN, Y_SCREEN);
        }
    }

    // Se o jogador 2 está pulando e está acima de 120 no eixo Y
    if (player_2->pular == 1 && player_2->y > 120) {
        player_move(player_2, 1, 2, X_SCREEN, Y_SCREEN); // Move o jogador 2 para cima
    } 
	
	else {
        player_2->pular = 0; // Se não está pulando, garante que o estado de pular está desligado
    }

    // Se o jogador 2 não está na posição Y 300 e não está pulando
    if (player_2->y != 300 && player_2->pular == 0) {
        player_2->imagem = player_2->personagem->descer; // Define a imagem de descida
        player_move(player_2, 1, 3, X_SCREEN, Y_SCREEN); // Move o jogador 2 para baixo
        // Se há colisão com o jogador 1, desfaz o movimento
        if (collision_2D(player_2, player_1)) {
            player_move(player_2, -1, 3, X_SCREEN, Y_SCREEN);
        }
    }

    // Controle do jogador 1

    // Se o botão de movimento para a esquerda está pressionado
    if (player_1->control->left && player_1->altura > 120 && player_1->y == 300) {
        player_move(player_1, 1, 0, X_SCREEN, Y_SCREEN); // Move o jogador 1 para a esquerda
        player_1->imagem = player_1->personagem->andar; // Define a imagem de andar
        player_1->altura = 150; // Define a altura do jogador 1
        // Se há colisão com o jogador 2, desfaz o movimento
        if (collision_2D(player_1, player_2)) {
            player_move(player_1, -1, 0, X_SCREEN, Y_SCREEN);
        }
    }

    // Se o botão de movimento para a direita está pressionado
    if (player_1->control->right && player_1->altura > 120 && player_1->y == 300) {
        player_move(player_1, 1, 1, X_SCREEN, Y_SCREEN); // Move o jogador 1 para a direita
        player_1->imagem = player_1->personagem->andar; // Define a imagem de andar
        player_1->altura = 150; // Define a altura do jogador 1
        // Se há colisão com o jogador 2, desfaz o movimento
        if (collision_2D(player_1, player_2)) {
            player_move(player_1, -1, 1, X_SCREEN, Y_SCREEN);
        }
    }

    // Se o botão de pular está pressionado e o jogador 1 está na posição Y 300
    if (player_1->control->up && player_1->delay <= 0) {
        if (player_1->y == 300) {
            player_1->largura = 120; // Define a largura do jogador 1
            player_1->altura = 150; // Define a altura do jogador 1
            player_1->imagem = player_1->personagem->pular; // Define a imagem de pular
            // Se não há colisão com o jogador 2, faz o movimento
            if ((player_1->x < player_2->x && player_1->x + player_1->largura/2 < player_2->x - player_2->largura/2) || (player_1->x > player_2->x && player_1->x - player_1->largura/2 > player_2->x + player_2->largura/2)) {
                player_move(player_1, 1, 2, X_SCREEN, Y_SCREEN);
                player_1->delay = 40;
            }       
        }
    }

    // Se o botão de agachar está pressionado e o jogador 1 está na posição Y 300
    if (player_1->control->down && player_1->delay <= 0) {
        if (player_1->y == 300) {
            player_1->agachar = 1;
            player_1->imagem = player_1->personagem->agachar; // Define a imagem de agachar
            player_1->altura = 120; // Define a altura do jogador 1
            player_1->delay = 40;
        }
    }

    // Se o botão de soco está pressionado
    if (player_1->control->punch && player_1->altura > 120) {
        if (player_1->index == 2) {
            player_1->largura = 170; // Aumenta a largura do jogador 1 para o soco
            // Verifica se o jogador 2 está na área de impacto do soco
            if (player_1->x < player_2->x) {
                if (player_2->y < 230 || player_2->altura == 120 ||
                    player_2->x - player_2->largura / 2 > player_1->x + player_1->largura / 2 ||
                    player_1->y < 300) {
                    // Não faz nada se não está na área de impacto
                } 
				
				else {
                    player_2->vida->num--; // Diminui a vida do jogador 2
                }
            }
            if (player_1->x > player_2->x) {
                if (player_2->y < 230 || player_2->altura == 120 ||
                    player_2->x + player_2->largura / 2 < player_1->x - player_1->largura / 2 ||
                    player_1->y < 300) {
                    // Não faz nada se não está na área de impacto
                } 
				
				else {
                    player_2->vida->num--; // Diminui a vida do jogador 2
                }
            }
        } 
		
		else {
            player_1->largura = 120; // Reseta a largura se não estiver no índice 2
        }
        player_1->imagem = player_1->personagem->superior; // Define a imagem de soco
    }

    // Se o botão de chute está pressionado
    if (player_1->control->kick && player_1->altura > 120) {
        if (player_1->index == 2) {
            player_1->largura = 170; // Aumenta a largura do jogador 1 para o chute
            // Verifica se o jogador 2 está na área de impacto do chute
            if (player_1->x < player_2->x) {
                if (player_2->y < 220 || player_2->altura == 120 ||
                    player_2->x - player_2->largura / 2 > player_1->x + player_1->largura / 2 ||
                    player_1->y < 300) {
                    // Não faz nada se não está na área de impacto
                } 
				
				else {
                    player_2->vida->num--; // Diminui a vida do jogador 2
                }
            }
            if (player_1->x > player_2->x) {
                if (player_2->y < 220 || player_2->altura == 120 ||
                    player_2->x + player_2->largura / 2 < player_1->x - player_1->largura / 2 ||
                    player_1->y < 300) {
                    // Não faz nada se não está na área de impacto
                } 
				
				else {
                    player_2->vida->num--; // Diminui a vida do jogador 2
                }
            }
        } 
		
		else {
            player_1->largura = 120; // Reseta a largura se não estiver no índice 2
        }
        player_1->imagem = player_1->personagem->inferior; // Define a imagem de chute
    }

    // Atualiza a posição do jogador 2

    // Se o botão de movimento para a esquerda está pressionado
    if (player_2->control->left && player_2->altura > 120 && player_2->y == 300) {
        player_move(player_2, 1, 0, X_SCREEN, Y_SCREEN); // Move o jogador 2 para a esquerda
        player_2->imagem = player_2->personagem->andar; // Define a imagem de andar
        player_2->altura = 150; // Define a altura do jogador 2
        // Se há colisão com o jogador 1, desfaz o movimento
        if (collision_2D(player_2, player_1)) {
            player_move(player_2, -1, 0, X_SCREEN, Y_SCREEN);
        }
    }

    // Se o botão de movimento para a direita está pressionado
    if (player_2->control->right && player_2->altura > 120 && player_2->y == 300) {
        player_move(player_2, 1, 1, X_SCREEN, Y_SCREEN); // Move o jogador 2 para a direita
        player_2->imagem = player_2->personagem->andar; // Define a imagem de andar
        player_2->altura = 150; // Define a altura do jogador 2
        // Se há colisão com o jogador 1, desfaz o movimento
        if (collision_2D(player_2, player_1)) {
            player_move(player_2, -1, 1, X_SCREEN, Y_SCREEN);
        }
    }

    // Se o botão de pular está pressionado e o jogador 2 está na posição Y 300
    if (player_2->control->up && player_2->delay <= 0 ) {
        if (player_2->y == 300) {
            player_2->largura = 120; // Define a largura do jogador 2
            player_2->altura = 150; // Define a altura do jogador 2
            player_2->imagem = player_2->personagem->pular; // Define a imagem de pular
            
            // Se não há colisão com o jogador 1, faz o movimento
            if ((player_1->x < player_2->x && player_1->x + player_1->largura/2 < player_2->x - player_2->largura/2) || 
                (player_1->x > player_2->x && player_1->x - player_1->largura/2 > player_2->x + player_2->largura/2)) {
                player_move(player_2, 1, 2, X_SCREEN, Y_SCREEN); // Move o jogador 2 para cima
                player_2->delay = 40;
            }
        }
    }

    // Se o botão de agachar está pressionado e o jogador 2 está na posição Y 300
    if (player_2->control->down && player_2->delay <= 0) {
        if (player_2->y == 300) {
            player_2->agachar = 1;
            player_2->imagem = player_2->personagem->agachar; // Define a imagem de agachar
            player_2->altura = 120; // Define a altura do jogador 2
            player_2->delay = 40;
        }
    }

    // Se o botão de soco está pressionado
    if (player_2->control->punch && player_2->altura > 120) {
        if (player_2->index == 2) {
            player_2->largura = 170; // Aumenta a largura do jogador 2 para o soco
            // Verifica se o jogador 1 está na área de impacto do soco
            if (player_2->x < player_1->x) {
                if (player_1->y < 230 || player_1->altura == 120 ||
                    player_1->x - player_1->largura / 2 > player_2->x + player_2->largura / 2 ||
                    player_2->y < 300) {
                    // Não faz nada se não está na área de impacto
                } 
				
				else {
                    player_1->vida->num--; // Diminui a vida do jogador 1
                }
            }
            if (player_2->x > player_1->x) {
                if (player_1->y < 230 || player_1->altura == 120 ||
                    player_1->x + player_1->largura / 2 < player_2->x - player_2->largura / 2 ||
                    player_2->y < 300) {
                    // Não faz nada se não está na área de impacto
                } 
				
				else {
                    player_1->vida->num--; // Diminui a vida do jogador 1
                }
            }
        } else {
            player_2->largura = 120; // Reseta a largura se não estiver no índice 2
        }
        player_2->imagem = player_2->personagem->superior; // Define a imagem de soco
    }

    // Se o botão de chute está pressionado
    if (player_2->control->kick && player_2->altura > 120) {
        if (player_2->index == 2) {
            player_2->largura = 170; // Aumenta a largura do jogador 2 para o chute
            // Verifica se o jogador 1 está na área de impacto do chute
            if (player_2->x < player_1->x) {
                if (player_1->y < 220 || player_1->altura == 120 ||
                    player_1->x - player_1->largura / 2 > player_2->x + player_2->largura / 2 ||
                    player_2->y < 300) {
                    // Não faz nada se não está na área de impacto
                } 
				
				else {
                    player_1->vida->num--; // Diminui a vida do jogador 1
                }
            }
            if (player_2->x > player_1->x) {
                if (player_1->y < 220 || player_1->altura == 120 ||
                    player_1->x + player_1->largura / 2 < player_2->x - player_2->largura / 2 ||
                    player_2->y < 300) {
                    // Não faz nada se não está na área de impacto
                } 
				
				else {
                    player_1->vida->num--; // Diminui a vida do jogador 1
                }
            }
        } 
		
		else {
            player_2->largura = 120; // Reseta a largura se não estiver no índice 2
        }
        player_2->imagem = player_2->personagem->inferior; // Define a imagem de chute
    }

    // Se o jogador 1 não está pulando e está na posição Y 300
    if (!player_1->pular && player_1->y == 300) {
        // Se nenhum botão está pressionado
        if (!(player_1->control->right || player_1->control->left ||
              player_1->control->up || player_1->control->down ||
              player_1->control->punch || player_1->control->kick)) {
            player_1->altura = 150; // Reseta a altura do jogador 1
            player_1->largura = 120; // Reseta a largura do jogador 1
            player_1->imagem = player_1->personagem->parar; // Define a imagem de parar
        }
    }

    // Se o jogador 2 não está pulando e está na posição Y 300
    if (!player_2->pular && player_2->y == 300) {
        // Se nenhum botão está pressionado
        if (!(player_2->control->right || player_2->control->left ||
              player_2->control->up || player_2->control->down ||
              player_2->control->punch || player_2->control->kick)) {
            player_2->altura = 150; // Reseta a altura do jogador 2
            player_2->largura = 120; // Reseta a largura do jogador 2
            player_2->imagem = player_2->personagem->parar; // Define a imagem de parar
        }
    }

    player_1->delay--;
    player_2->delay--;
}

void player_destroy(player *element) {
    // Verifica se o controle do jogador foi alocado e, em caso afirmativo, destrói-o
    if (element->control) {
        joystick_destroy(element->control);
    }
    
    // Verifica se o personagem do jogador foi alocado e, em caso afirmativo, destrói-o
    if (element->personagem) {
        pers_destroy(element->personagem);
    }

    // Itera sobre o array de imagens (assumidamente 4 imagens) e destrói cada bitmap não nulo
    for (int i = 0; i < 4; i++) {
        if (element->imagem[i] != NULL) {
            al_destroy_bitmap(element->imagem[i]);
        }
    }

    // Destrói o objeto de vida do jogador
    hp_destroy(element->vida);

    // Libera a memória alocada para o array de imagens
    free(element->imagem);

    // Libera a memória alocada para o próprio objeto player
    free(element);
}

