#include "Telas.h"

int menu(ALLEGRO_TIMER* timer, ALLEGRO_FONT* font, ALLEGRO_FONT* font2, ALLEGRO_EVENT_QUEUE* queue) {
    ALLEGRO_BITMAP* background = al_load_bitmap("imagens/menu.jpg");

    if (!background) {
        perror("Erro ao carregar imagem do menu!\n");
        return -1;
    }

    int flag = 0;
    int saida = 0;
    int teclas = 0;
    int estado_jogo = 0;

    ALLEGRO_EVENT event;
    al_start_timer(timer);

    while (!saida) {  // Laço principal do programa
        al_wait_for_event(queue, &event);  // Captura eventos da fila e insere na variável `event`

        if (!teclas) {
            if (event.type == ALLEGRO_EVENT_TIMER) {  // Verificação de eventos de relógio (FPS)
                al_clear_to_color(al_map_rgb(0, 0, 0));
                al_draw_scaled_bitmap(background, 0, 0, al_get_bitmap_width(background), al_get_bitmap_height(background), 0, 0, X_SCREEN, Y_SCREEN, 0);

                // Desenha a sombra do texto
                al_draw_text(font, al_map_rgba(0, 0, 0, 150), 500 + 4, 100 + 4, ALLEGRO_ALIGN_CENTER, "Street");
                al_draw_text(font, al_map_rgba(0, 0, 0, 150), 490 + 4, 200 + 4, ALLEGRO_ALIGN_CENTER, "Fighter");

                if (flag < 40) {
                    // Desenha a sombra e o texto das opções do menu
                    al_draw_text(font2, al_map_rgba(0, 0, 0, 150), 500 + 2, 400 + 2, ALLEGRO_ALIGN_CENTER, "Aperte a tecla ENTER para jogar");
                    al_draw_text(font2, al_map_rgb(255, 255, 255), 500, 400, ALLEGRO_ALIGN_CENTER, "Aperte a tecla ENTER para jogar");

                    al_draw_text(font2, al_map_rgba(0, 0, 0, 150), 500 + 2, 430 + 2, ALLEGRO_ALIGN_CENTER, "Aperte a tecla ESC para sair");
                    al_draw_text(font2, al_map_rgb(255, 255, 255), 500, 430, ALLEGRO_ALIGN_CENTER, "Aperte a tecla ESC para sair");

                    al_draw_text(font2, al_map_rgba(0, 0, 0, 150), 500 + 2, 460 + 2, ALLEGRO_ALIGN_CENTER, "Aperte a tecla M para ver as teclas");
                    al_draw_text(font2, al_map_rgb(255, 255, 255), 500, 460, ALLEGRO_ALIGN_CENTER, "Aperte a tecla M para ver as teclas");
                    flag++;
                } 
                
                else {
                    flag++;
                    if (!(flag % 50)) flag = 0;
                }

                al_draw_text(font, al_map_rgb(255, 255, 255), 500, 100, ALLEGRO_ALIGN_CENTER, "Street");
                al_draw_text(font, al_map_rgb(255, 255, 255), 490, 200, ALLEGRO_ALIGN_CENTER, "Fighter");

                al_flip_display();  // Insere as modificações realizadas nos buffers de tela
            } 
            
            else if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_ENTER:  // Se ENTER é pressionado, sai do loop e vai para a próxima tela
                        estado_jogo = 1;
                        saida = 1;
                        al_rest(0.1);  // Adiciona um pequeno atraso
                        break;

                    case ALLEGRO_KEY_M:  // Se 'M' é pressionado, mostra as teclas
                        teclas = 1;
                        al_rest(0.1);  // Adiciona um pequeno atraso
                        break;

                    case ALLEGRO_KEY_ESCAPE:  // Se ESC é pressionado, sai do jogo
                        saida = 1;
                        al_rest(0.1);  // Adiciona um pequeno atraso
                        break;
                }
            } 
            
            else if (event.type == 42) return 0;  // Verificação de um tipo de evento específico (não documentado)
        } 
        
        else {
            if (event.type == ALLEGRO_EVENT_TIMER) {  // Verificação de eventos de relógio (FPS)
                al_clear_to_color(al_map_rgb(0, 0, 0));

                // Desenha os controles do jogo
                al_draw_text(font2, al_map_rgb(255, 255, 255), 200, 200, ALLEGRO_ALIGN_CENTER, "A Andar para esquerda");
                al_draw_text(font2, al_map_rgb(255, 255, 255), 200, 230, ALLEGRO_ALIGN_CENTER, "S Agachar");
                al_draw_text(font2, al_map_rgb(255, 255, 255), 200, 260, ALLEGRO_ALIGN_CENTER, "D Andar para direita");
                al_draw_text(font2, al_map_rgb(255, 255, 255), 200, 290, ALLEGRO_ALIGN_CENTER, "W Pular");
                al_draw_text(font2, al_map_rgb(255, 255, 255), 200, 320, ALLEGRO_ALIGN_CENTER, "Q Golpear com membros superiores");
                al_draw_text(font2, al_map_rgb(255, 255, 255), 200, 350, ALLEGRO_ALIGN_CENTER, "E Golpear com membros inferiores");

                al_draw_text(font2, al_map_rgb(255, 255, 255), 800, 200, ALLEGRO_ALIGN_CENTER, "Seta para esquerda Andar para esquerda");
                al_draw_text(font2, al_map_rgb(255, 255, 255), 800, 230, ALLEGRO_ALIGN_CENTER, "Seta para para baixo Agachar");
                al_draw_text(font2, al_map_rgb(255, 255, 255), 800, 260, ALLEGRO_ALIGN_CENTER, "Seta para direita Andar para direita");
                al_draw_text(font2, al_map_rgb(255, 255, 255), 800, 290, ALLEGRO_ALIGN_CENTER, "Seta para cima Pular");
                al_draw_text(font2, al_map_rgb(255, 255, 255), 800, 320, ALLEGRO_ALIGN_CENTER, "SHIFT DIREITO Golpear com membros superiores");
                al_draw_text(font2, al_map_rgb(255, 255, 255), 800, 350, ALLEGRO_ALIGN_CENTER, "CTRL ESQUERDO Golpear com membros inferiores");

                al_draw_text(font2, al_map_rgb(255, 255, 255), 500, 450, ALLEGRO_ALIGN_CENTER, "ESC voltar");

                al_draw_text(font, al_map_rgb(255, 255, 255), 200, 50, ALLEGRO_ALIGN_CENTER, "PLAYER 1");
                al_draw_text(font, al_map_rgb(255, 255, 255), 800, 50, ALLEGRO_ALIGN_CENTER, "PLAYER 2");

                al_flip_display();  // Insere as modificações realizadas nos buffers de tela
            } 
            
            else if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_ESCAPE:
                        teclas = 0;
                        al_rest(0.1);  // Adiciona um pequeno atraso
                        break;
                }
            } 
            
            else if (event.type == 42) return 0;  // Verificação de um tipo de evento específico (não documentado)
        }
    }

    al_destroy_bitmap(background);

    return estado_jogo;
}

int selecao(ALLEGRO_TIMER* timer, ALLEGRO_FONT* font, ALLEGRO_FONT* font2, ALLEGRO_EVENT_QUEUE* queue, player* player_1, player* player_2){
    // Carrega as imagens dos personagens e arenas de arquivos
    ALLEGRO_BITMAP* ken = al_load_bitmap("imagens/ken.png");
    ALLEGRO_BITMAP* ryu = al_load_bitmap("imagens/ryu.png");
    ALLEGRO_BITMAP* ken1 = al_load_bitmap("imagens/ken1.png");
    ALLEGRO_BITMAP* ryu1 = al_load_bitmap("imagens/ryu1.png");
    ALLEGRO_BITMAP* cammy = al_load_bitmap("imagens/cammy.png");
    ALLEGRO_BITMAP* dee = al_load_bitmap("imagens/dee.png");
    ALLEGRO_BITMAP* cammy1 = al_load_bitmap("imagens/cammy1.png");
    ALLEGRO_BITMAP* dee1 = al_load_bitmap("imagens/dee1.png");
    
    // Cria os quadrados de seleção
    quadrado* square = quad_create(440, 230, 100, 100);
    quadrado* square1 = quad_create(270, 275, 270, 420);

    // Carrega as imagens das arenas
    ALLEGRO_BITMAP* stage_ryu = al_load_bitmap("imagens/arena0.jpg");
    ALLEGRO_BITMAP* ring = al_load_bitmap("imagens/arena1.jpg");

    if(!ken || !ken1 || !ryu || !ryu1 || !dee || !dee1 || !cammy || !cammy1 || !stage_ryu || !ring) {
        perror("Erro ao carregar as imagens de seleção!\n");
        return -1;
    } 

    // Inicializa variáveis
    int flag = 0, saida = 0, estado_jogo = 0, aux = 1;

    ALLEGRO_EVENT event;
    al_start_timer(timer);

     // Loop principal para seleção de personagem do Player 1
    while (!saida) {
        al_wait_for_event(queue, &event); // Aguarda evento na fila

        if (event.type == ALLEGRO_EVENT_TIMER) { // Evento de atualização da tela
            al_clear_to_color(al_map_rgb(0, 0, 130));
            al_draw_text(font, al_map_rgb(255, 255, 255), 500, 50, ALLEGRO_ALIGN_CENTER, "PLAYER 1");
            al_draw_text(font2, al_map_rgb(255, 255, 255), 500, 420, ALLEGRO_ALIGN_CENTER, "Selecione seu personagem: ");

            if (flag < 30) {
                al_draw_filled_rectangle(square->x - square->largura / 2, square->y - square->altura / 2, square->x + square->largura / 2, square->y + square->altura / 2, al_map_rgb(255, 255, 255));
                flag++;
            } 
            
            else {
                flag++;
                if (!(flag % 50)) flag = 0;
            }

            // Desenha os personagens na tela
            al_draw_scaled_bitmap(ken, 0, 0, al_get_bitmap_width(ken), al_get_bitmap_height(ken), 390, 180, 100, 100, 0);
            al_draw_scaled_bitmap(ryu, 0, 0, al_get_bitmap_width(ryu), al_get_bitmap_height(ryu), 500, 180, 100, 100, 0);
            al_draw_scaled_bitmap(cammy, 0, 0, al_get_bitmap_width(cammy), al_get_bitmap_height(cammy), 390, 290, 100, 100, 0);
            al_draw_scaled_bitmap(dee, 0, 0, al_get_bitmap_width(dee), al_get_bitmap_height(dee), 500, 290, 100, 100, 0);

            // Desenha personagem selecionado ampliado
            if (!aux) {
                al_draw_text(font2, al_map_rgb(255, 255, 255), 835, 150, ALLEGRO_ALIGN_CENTER, "RYU");
                al_draw_scaled_bitmap(ryu1, 0, 0, al_get_bitmap_width(ryu1), al_get_bitmap_height(ryu1), 730, 180, 200, 300, ALLEGRO_FLIP_HORIZONTAL);
            }
            if (aux == 1) {
                al_draw_scaled_bitmap(ken1, 0, 0, al_get_bitmap_width(ken1), al_get_bitmap_height(ken1), 70, 200, 200, 250, ALLEGRO_FLIP_HORIZONTAL);
                al_draw_text(font2, al_map_rgb(255, 255, 255), 155, 150, ALLEGRO_ALIGN_CENTER, "KEN");
            }
            if (aux == 2) {
                al_draw_text(font2, al_map_rgb(255, 255, 255), 835, 150, ALLEGRO_ALIGN_CENTER, "DEE");
                al_draw_scaled_bitmap(dee1, 0, 0, al_get_bitmap_width(dee1), al_get_bitmap_height(dee1), 730, 180, 200, 300, ALLEGRO_FLIP_HORIZONTAL);
            }
            if (aux == 3) {
                al_draw_scaled_bitmap(cammy1, 0, 0, al_get_bitmap_width(cammy1), al_get_bitmap_height(cammy1), 70, 200, 200, 250, 0);
                al_draw_text(font2, al_map_rgb(255, 255, 255), 155, 150, ALLEGRO_ALIGN_CENTER, "CAMMY");
            }
            al_flip_display(); // Atualiza a tela
        }

        // Verifica eventos de teclado
        else if ((event.type == 10) || (event.type == 12)) {
            if (event.keyboard.keycode == 1) {
                square->x = 440;
            } 
            
            else if (event.keyboard.keycode == 4) {
                square->x = 550;
            } 
            
            else if (event.keyboard.keycode == 19) {
                square->y = 340;
            } 
            
            else if (event.keyboard.keycode == 23) {
                square->y = 230;
            } 
            
            else if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_ENTER:
                        if (aux == 0) player_1->nome = "ryu";
                        if (aux == 1) player_1->nome = "ken";
                        if (aux == 2) player_1->nome = "dee";
                        if (aux == 3) player_1->nome = "cammy";
                        estado_jogo = 1;
                        saida = 1;
                        al_rest(0.1); // Pequeno atraso
                        break;
                }
            }
        }

        // Verifica outros tipos de evento
        else if (event.type == 42) return 0;

        // Atualiza a variável aux com base na posição do quadrado de seleção
        else if (square->x == 440 && square->y == 230) aux = 1;
        else if (square->x == 550 && square->y == 230) aux = 0;
        else if (square->x == 550 && square->y == 340) aux = 2;
        else if (square->x == 440 && square->y == 340) aux = 3;
    }

    saida = 0;

       // Loop principal para seleção de personagem do Player 2 (similar ao loop do Player 1)
    while (!saida) {
        al_wait_for_event(queue, &event); // Aguarda e captura eventos da fila

        if (event.type == ALLEGRO_EVENT_TIMER) { // Evento de temporizador para atualização da tela
            al_clear_to_color(al_map_rgb(130, 0, 0)); // Limpa a tela com a cor de fundo
            al_draw_text(font, al_map_rgb(255, 255, 255), 500, 50, ALLEGRO_ALIGN_CENTER, "PLAYER 2"); // Exibe o texto "PLAYER 2"
            al_draw_text(font2, al_map_rgb(255, 255, 255), 500, 420, ALLEGRO_ALIGN_CENTER, "Selecione seu personagem: "); // Instrução para selecionar o personagem

            if (flag < 30) { // Animação do quadrado de seleção
                al_draw_filled_rectangle(square->x - square->largura / 2, square->y - square->altura / 2, square->x + square->largura / 2, square->y + square->altura / 2, al_map_rgb(255, 255, 255)); // Desenha o quadrado de seleção
                flag++;
            } 
            
            else {
                flag++;
                if (!(flag % 50)) flag = 0; // Reseta a animação do quadrado
            }

            // Desenha os personagens disponíveis para seleção
            al_draw_scaled_bitmap(ken, 0, 0, al_get_bitmap_width(ken), al_get_bitmap_height(ken), 390, 180, 100, 100, 0); // Personagem Ken
            al_draw_scaled_bitmap(ryu, 0, 0, al_get_bitmap_width(ryu), al_get_bitmap_height(ryu), 500, 180, 100, 100, 0); // Personagem Ryu
            al_draw_scaled_bitmap(cammy, 0, 0, al_get_bitmap_width(cammy), al_get_bitmap_height(cammy), 390, 290, 100, 100, 0); // Personagem Cammy
            al_draw_scaled_bitmap(dee, 0, 0, al_get_bitmap_width(dee), al_get_bitmap_height(dee), 500, 290, 100, 100, 0); // Personagem Dee

            // Exibe o personagem selecionado de forma ampliada
            if (!aux) {
                al_draw_text(font2, al_map_rgb(255, 255, 255), 835, 150, ALLEGRO_ALIGN_CENTER, "RYU"); // Nome do personagem selecionado
                al_draw_scaled_bitmap(ryu1, 0, 0, al_get_bitmap_width(ryu1), al_get_bitmap_height(ryu1), 730, 180, 200, 300, ALLEGRO_FLIP_HORIZONTAL); // Personagem ampliado (RYU)
            }
            if (aux == 1) {
                al_draw_scaled_bitmap(ken1, 0, 0, al_get_bitmap_width(ken1), al_get_bitmap_height(ken1), 70, 200, 200, 250, ALLEGRO_FLIP_HORIZONTAL); // Personagem ampliado (KEN)
                al_draw_text(font2, al_map_rgb(255, 255, 255), 155, 150, ALLEGRO_ALIGN_CENTER, "KEN"); // Nome do personagem selecionado
            }
            if (aux == 2) {
                al_draw_text(font2, al_map_rgb(255, 255, 255), 835, 150, ALLEGRO_ALIGN_CENTER, "DEE"); // Nome do personagem selecionado
                al_draw_scaled_bitmap(dee1, 0, 0, al_get_bitmap_width(dee1), al_get_bitmap_height(dee1), 730, 180, 200, 300, ALLEGRO_FLIP_HORIZONTAL); // Personagem ampliado (DEE)
            }
            if (aux == 3) {
                al_draw_scaled_bitmap(cammy1, 0, 0, al_get_bitmap_width(cammy1), al_get_bitmap_height(cammy1), 70, 200, 200, 250, 0); // Personagem ampliado (CAMMY)
                al_draw_text(font2, al_map_rgb(255, 255, 255), 155, 150, ALLEGRO_ALIGN_CENTER, "CAMMY"); // Nome do personagem selecionado
            }
            al_flip_display(); // Atualiza a tela com as alterações feitas
        }

        else if ((event.type == 10) || (event.type == 12)) { // Evento de teclado (pressionado ou solto)
            if (event.keyboard.keycode == 82) {
                square->x = 440; // Move o quadrado de seleção para a posição do "RYU"
            } 
            
            else if (event.keyboard.keycode == 83) {
                square->x = 550; // Move o quadrado de seleção para a posição do "KEN"
            }

            else if (event.keyboard.keycode == 85) {
                square->y = 340; // Move o quadrado de seleção para a posição do "DEE"
            }

            else if (event.keyboard.keycode == 84) {
                square->y = 230; // Move o quadrado de seleção para a posição do "CAMMY"
            }

            else if (event.type == ALLEGRO_EVENT_KEY_DOWN) { // Verifica eventos de tecla pressionada
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_ENTER:
                        // Define o personagem selecionado para o Player 2 com base na posição do quadrado
                        if (aux == 0) player_2->nome = "ryu";
                        if (aux == 1) player_2->nome = "ken";
                        if (aux == 2) player_2->nome = "dee";
                        if (aux == 3) player_2->nome = "cammy";
                        estado_jogo = 1; // Atualiza o estado do jogo
                        saida = 1; // Sinaliza que a seleção está concluída
                        al_rest(0.1); // Adiciona um pequeno atraso
                        break;
                }
            }
        }

        else if (event.type == 42) return 0; // Verifica outro tipo de evento (por exemplo, fechamento da janela)

        // Atualiza o valor de `aux` com base na posição do quadrado
        else if (square->x == 440 && square->y == 230) aux = 1; // Se o quadrado está na posição do "RYU"
        else if (square->x == 550 && square->y == 230) aux = 0; // Se o quadrado está na posição do "KEN"
        else if (square->x == 550 && square->y == 340) aux = 2; // Se o quadrado está na posição do "DEE"
        else if (square->x == 440 && square->y == 340) aux = 3; // Se o quadrado está na posição do "CAMMY"
    }

    quad_destroy(square);

    saida = 0;

    while (!saida) {    // Laço principal para escolher a arena
        al_wait_for_event(queue, &event);    // Aguarda e captura eventos da fila, inserindo-os na variável 'event'

        if (event.type == ALLEGRO_EVENT_TIMER) {    // Evento do tipo TIMER indica que é hora de atualizar a tela (geralmente usado para controlar a taxa de quadros)
            al_clear_to_color(al_map_rgb(0, 0, 0));    // Limpa a tela com a cor preta
            al_draw_text(font, al_map_rgb(255, 255, 255), 500, 50, ALLEGRO_ALIGN_CENTER, "Arena");    // Exibe o texto "Arena" no topo da tela
            al_draw_text(font2, al_map_rgb(255, 255, 255), 745, 420, ALLEGRO_ALIGN_CENTER, "Ryu Stage");    // Exibe o nome da arena "Ryu Stage"
            al_draw_text(font2, al_map_rgb(255, 255, 255), 265, 420, ALLEGRO_ALIGN_CENTER, "Ring of power");    // Exibe o nome da arena "Ring of power"
            al_draw_text(font2, al_map_rgb(255, 255, 255), 500, 460, ALLEGRO_ALIGN_CENTER, "Selecione a arena: ");    // Instrução para selecionar a arena

            if (flag < 30) {    // Animação do quadrado de seleção
                al_draw_filled_rectangle(square1->x - square1->largura / 2, square1->y - square1->altura / 2, square1->x + square1->largura / 2, square1->y + square1->altura / 2, al_map_rgb(255, 255, 255));    // Desenha o quadrado de seleção
                flag++;
            } 
            
            else {
                flag++;
                if (!(flag % 50)) flag = 0;    // Reseta a animação do quadrado após 50 iterações
            }

            // Desenha as imagens das arenas disponíveis para seleção
            al_draw_scaled_bitmap(ring, 0, 0, al_get_bitmap_width(ring), al_get_bitmap_height(ring), 70, 150, 400, 250, 0);    // Arena "Ring of power"
            al_draw_scaled_bitmap(stage_ryu, 0, 0, al_get_bitmap_width(stage_ryu), al_get_bitmap_height(stage_ryu), 530, 150, 400, 250, 0);    // Arena "Ryu Stage"

            al_flip_display();    // Atualiza a tela com as modificações feitas
        }

        else if ((event.type == 10) || (event.type == 12)) {    // Evento de teclado (pressionado ou solto)
            if (event.keyboard.keycode == 1) {    // Se a tecla correspondente ao código 1 for pressionada (movimento à esquerda)
                square1->x = 270;    // Move o quadrado de seleção para a posição da arena "Ring of power"
                aux = 1;    // Atualiza a variável auxiliar para refletir a seleção
            } 
            
            else if (event.keyboard.keycode == 4) {    // Se a tecla correspondente ao código 4 for pressionada (movimento à direita)
                square1->x = 730;    // Move o quadrado de seleção para a posição da arena "Ryu Stage"
                aux = 0;    // Atualiza a variável auxiliar para refletir a seleção
            }   

            else if (event.type == ALLEGRO_EVENT_KEY_DOWN) {    // Verifica eventos de tecla pressionada
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_ENTER:    // Se a tecla Enter for pressionada
                        if (square1->x == 730) player_1->arena = 0;    // Se o quadrado está na posição da arena "Ryu Stage"
                        else player_1->arena = 1;    // Caso contrário, seleciona a arena "Ring of power"
                        estado_jogo = 1;    // Atualiza o estado do jogo para indicar que a seleção foi feita
                        saida = 1;    // Define 'saida' como 1 para sair do loop
                        al_rest(0.1);    // Adiciona um pequeno atraso antes de sair
                        break;
                }
            }
        }

        else if (event.type == 42) return 0;    // Se o evento for do tipo 42 (por exemplo, fechamento da janela), encerra o programa

    }

    // Libera a memória alocada para as imagens e o quadrado de seleção
    al_destroy_bitmap(ken);
    al_destroy_bitmap(ken1);
    al_destroy_bitmap(ryu);
    al_destroy_bitmap(ryu1);
    al_destroy_bitmap(cammy);
    al_destroy_bitmap(cammy1);
    al_destroy_bitmap(dee);
    al_destroy_bitmap(dee1);
    al_destroy_bitmap(stage_ryu);
    al_destroy_bitmap(ring);    
    quad_destroy(square1);

    return estado_jogo;    // Retorna o estado do jogo, indicando se o jogo deve continuar ou não

}

int jogar(ALLEGRO_TIMER* timer, ALLEGRO_EVENT_QUEUE* queue, player* player_1, player* player_2, ALLEGRO_FONT* font2, ALLEGRO_FONT* font){    
    char arena[50];    // Declara um array de caracteres para armazenar o caminho da imagem da arena
    sprintf(arena, "imagens/arena%d.jpg", player_1->arena);    // Formata o caminho da imagem da arena com base no valor armazenado em player_1->arena
    ALLEGRO_BITMAP* image = al_load_bitmap(arena);    // Carrega a imagem da arena usando o caminho formatado
    ALLEGRO_BITMAP* hp = al_load_bitmap("imagens/hp.png");    // Carrega a imagem do HP (barra de vida) 
    if(!image || !hp) {
        perror("Erro ao carregar as imagens de hp ou da arena!\n");
        return -1;
    } 

    // Obtém o tamanho original da imagem da arena
    int original_width = al_get_bitmap_width(image);    // Obtém a largura da imagem da arena
    int original_height = al_get_bitmap_height(image);    // Obtém a altura da imagem da arena

    int flag = 0;    // Inicializa a variável 'flag', provavelmente para controle de animações ou efeitos
    int jogar = 0;    // Inicializa a variável 'jogar', que pode ser usada para controlar o fluxo do jogo
    int round = 1;    // Inicializa a variável 'round' para controlar o número da rodada

    // Cria personagens para os jogadores usando suas seleções de nomes
    player_1->personagem = pers_create(player_1->nome);    // Cria um novo personagem para o player 1 com base no nome selecionado
    player_2->personagem = pers_create(player_2->nome);    // Cria um novo personagem para o player 2 com base no nome selecionado

    // Define as imagens dos personagens para os jogadores
    player_1->imagem = player_1->personagem->parar;    // Define a imagem atual do player 1 como a imagem de "parar" do seu personagem
    player_2->imagem = player_2->personagem->parar;    // Define a imagem atual do player 2 como a imagem de "parar" do seu personagem

    ALLEGRO_EVENT event;    // Declara uma variável para armazenar eventos capturados. A estrutura deste evento é definida na documentação do Allegro: https://www.allegro.cc/manual/5/ALLEGRO_EVENT

    al_start_timer(timer);    // Inicia o temporizador para controlar o intervalo de atualização da tela (conceito de FPS)

    while(player_1->win != 2 && player_2->win != 2) {    // Loop principal do jogo que continua enquanto nenhum dos jogadores tiver vencido duas vezes
        jogar = 0;    // Inicializa a variável 'jogar' como 0. Pode ser usada para controlar o fluxo do jogo.
        player_reset(player_1, 1);    // Reseta o estado do jogador 1
        player_reset(player_2, 2);    // Reseta o estado do jogador 2
        
        al_clear_to_color(al_map_rgb(0, 0, 0));    // Limpa a tela com a cor preta
        al_draw_scaled_bitmap(image, 0, 0, original_width, original_height, 0, 0, X_SCREEN, Y_SCREEN, 0);    // Desenha a imagem da arena na tela redimensionada para as dimensões da tela

        // Desenha o texto indicando o número da rodada com sombra
        if (round == 1) {
            al_draw_text(font, al_map_rgba(0, 0, 0, 150), 500 + 4, 200 + 4, ALLEGRO_ALIGN_CENTER, "ROUND 1");
            al_draw_text(font, al_map_rgb(255, 255, 255), 500, 200, ALLEGRO_ALIGN_CENTER, "ROUND 1");
        }
        if (round == 2) {
            al_draw_text(font, al_map_rgba(0, 0, 0, 150), 500 + 4, 200 + 4, ALLEGRO_ALIGN_CENTER, "ROUND 2");
            al_draw_text(font, al_map_rgb(255, 255, 255), 500, 200, ALLEGRO_ALIGN_CENTER, "ROUND 2");
        }
        if (round == 3) {
            al_draw_text(font, al_map_rgba(0, 0, 0, 150), 500 + 4, 200 + 4, ALLEGRO_ALIGN_CENTER, "ROUND 3");
            al_draw_text(font, al_map_rgb(255, 255, 255), 500, 200, ALLEGRO_ALIGN_CENTER, "ROUND 3");
        }

        al_flip_display();    // Atualiza a tela com o que foi desenhado

        al_rest(2);    // Pausa a execução por 2 segundos para mostrar o texto da rodada

        // Limpa a fila de eventos para evitar processamento de eventos antigos
        al_flush_event_queue(queue);

        while (jogar == 0) {    // Loop que continua enquanto a variável 'jogar' for 0
            al_wait_for_event(queue, &event);    // Espera e captura um evento da fila de eventos

            if (event.type == 30) {    // Verifica se o evento capturado é um evento de temporizador (indica a atualização da tela)
                update_position(player_1, player_2);    // Atualiza as posições dos jogadores
                update_vida(player_1->vida, 1);    // Atualiza a vida do jogador 1
                update_vida(player_2->vida, 2);    // Atualiza a vida do jogador 2

                al_clear_to_color(al_map_rgb(0, 0, 0));    // Limpa a tela com a cor preta
                al_draw_scaled_bitmap(image, 0, 0, original_width, original_height, 0, 0, X_SCREEN, Y_SCREEN, 0);    // Desenha a imagem da arena na tela redimensionada

                // Desenha os textos e imagens relacionados aos jogadores e à vida
                al_draw_text(font2, al_map_rgb(180, 0, 0), 250, 10, ALLEGRO_ALIGN_CENTER, "PLAYER 1");
                al_draw_text(font2, al_map_rgb(0, 0, 180), 750, 10, ALLEGRO_ALIGN_CENTER, "PLAYER 2");
                al_draw_scaled_bitmap(hp, 0, 0, al_get_bitmap_width(hp), al_get_bitmap_height(hp), 470, 20, 50, 50, 0);
                al_draw_filled_rectangle(player_1->vida->x, player_1->vida->y, 470, player_1->vida->y + 30, al_map_rgb(180, 0, 0));
                al_draw_filled_rectangle(player_2->vida->x, player_2->vida->y, 520, player_2->vida->y + 30, al_map_rgb(0, 0, 180));

                // Desenha os indicadores de vitória para os jogadores
                al_draw_circle(70, 70, 8, al_map_rgb(255, 255, 0), 2.0);
                al_draw_circle(90, 70, 8, al_map_rgb(255, 255, 0), 2.0);
                al_draw_text(font2, al_map_rgb(255, 255, 0), 40, 65, ALLEGRO_ALIGN_CENTER, "WINS");
                if (player_1->win == 1) al_draw_filled_circle(70, 70, 8, al_map_rgb(255, 255, 0));

                al_draw_circle(930, 70, 8, al_map_rgb(255, 255, 0), 2.0);
                al_draw_circle(910, 70, 8, al_map_rgb(255, 255, 0), 2.0);
                al_draw_text(font2, al_map_rgb(255, 255, 0), 960, 65, ALLEGRO_ALIGN_CENTER, "WINS");
                if (player_2->win == 1) al_draw_filled_circle(930, 70, 8, al_map_rgb(255, 255, 0));

                // Verifica se algum jogador perdeu
                if (player_2->vida->num <= 0) {
                    player_1->win += 1;    // Incrementa a vitória do jogador 1
                    if (player_1->win == 2) al_draw_filled_circle(90, 70, 8, al_map_rgb(255, 255, 0));
                    al_flip_display();    // Atualiza a tela
                    al_rest(1);    // Pausa por 1 segundo
                    jogar = 1;    // Define 'jogar' como 1 para sair do loop interno
                    round++;    // Avança para a próxima rodada
                    al_rest(1);    // Pausa por mais 1 segundo
                }

                if (player_1->vida->num <= 0) {
                    player_2->win += 1;    // Incrementa a vitória do jogador 2
                    if (player_2->win == 2) al_draw_filled_circle(910, 70, 8, al_map_rgb(255, 255, 0));
                    al_flip_display();    // Atualiza a tela
                    al_rest(1);    // Pausa por 1 segundo
                    jogar = 1;    // Define 'jogar' como 1 para sair do loop interno
                    round++;    // Avança para a próxima rodada
                    al_rest(1);    // Pausa por mais 1 segundo
                }

                // Desenha os jogadores com base em suas posições e ações
                if (player_2->x > player_1->x) {    // Verifica se o jogador 2 está à direita do jogador 1
                    if ((player_2->control->punch && player_2->index == 2) || (player_2->control->kick && player_2->index == 2)) {
                        if (player_2->control->down && player_2->pular == 0 && player_2->agachar == 1) {
                            al_draw_scaled_bitmap(player_2->imagem[player_2->index], 0, 0, al_get_bitmap_width(player_2->imagem[player_2->index]), al_get_bitmap_height(player_2->imagem[player_2->index]), player_2->x - 50, player_2->y + 30, player_2->largura, player_2->altura, ALLEGRO_FLIP_HORIZONTAL);
                        } 
                        
                        else {
                            al_draw_scaled_bitmap(player_2->imagem[player_2->index], 0, 0, al_get_bitmap_width(player_2->imagem[player_2->index]), al_get_bitmap_height(player_2->imagem[player_2->index]), player_2->x - 50, player_2->y, player_2->largura, player_2->altura, ALLEGRO_FLIP_HORIZONTAL);
                        }
                    } 
                    
                    else {
                        if (player_2->control->down && player_2->pular == 0 && player_2->agachar == 1) {
                            al_draw_scaled_bitmap(player_2->imagem[player_2->index], 0, 0, al_get_bitmap_width(player_2->imagem[player_2->index]), al_get_bitmap_height(player_2->imagem[player_2->index]), player_2->x, player_2->y + 30, player_2->largura, player_2->altura, ALLEGRO_FLIP_HORIZONTAL);
                        } 
                        
                        else {
                            al_draw_scaled_bitmap(player_2->imagem[player_2->index], 0, 0, al_get_bitmap_width(player_2->imagem[player_2->index]), al_get_bitmap_height(player_2->imagem[player_2->index]), player_2->x, player_2->y, player_2->largura, player_2->altura, ALLEGRO_FLIP_HORIZONTAL);
                        }
                    }
                    
                    if (player_1->control->down && player_1->pular == 0 && player_1->agachar == 1) {
                        al_draw_scaled_bitmap(player_1->imagem[player_1->index], 0, 0, al_get_bitmap_width(player_1->imagem[player_1->index]), al_get_bitmap_height(player_1->imagem[player_1->index]), player_1->x, player_1->y + 30, player_1->largura, player_1->altura, 0);
                    } 
                    
                    else {
                        al_draw_scaled_bitmap(player_1->imagem[player_1->index], 0, 0, al_get_bitmap_width(player_1->imagem[player_1->index]), al_get_bitmap_height(player_1->imagem[player_1->index]), player_1->x, player_1->y, player_1->largura, player_1->altura, 0);
                    }
                } 
                
                else {    // Quando o jogador 2 está à esquerda ou na mesma posição horizontal do jogador 1
                    if (player_2->control->down && player_2->pular == 0 && player_2->agachar == 1) {
                        al_draw_scaled_bitmap(player_2->imagem[player_2->index], 0, 0, al_get_bitmap_width(player_2->imagem[player_2->index]), al_get_bitmap_height(player_2->imagem[player_2->index]), player_2->x, player_2->y + 30, player_2->largura, player_2->altura, 0);
                    } 
                    
                    else {
                        al_draw_scaled_bitmap(player_2->imagem[player_2->index], 0, 0, al_get_bitmap_width(player_2->imagem[player_2->index]), al_get_bitmap_height(player_2->imagem[player_2->index]), player_2->x, player_2->y, player_2->largura, player_2->altura, 0);
                    }
                    
                    if ((player_1->control->punch && player_1->index == 2) || (player_1->control->kick && player_1->index == 2)) {
                        if (player_1->control->down && player_1->pular == 0 && player_1->agachar == 1) {
                            al_draw_scaled_bitmap(player_1->imagem[player_1->index], 0, 0, al_get_bitmap_width(player_1->imagem[player_1->index]), al_get_bitmap_height(player_1->imagem[player_1->index]), player_1->x - 50, player_1->y + 30, player_1->largura, player_1->altura, ALLEGRO_FLIP_HORIZONTAL);
                        } 
                        
                        else {
                            al_draw_scaled_bitmap(player_1->imagem[player_1->index], 0, 0, al_get_bitmap_width(player_1->imagem[player_1->index]), al_get_bitmap_height(player_1->imagem[player_1->index]), player_1->x - 50, player_1->y, player_1->largura, player_1->altura, ALLEGRO_FLIP_HORIZONTAL);
                        }
                    } 
                    
                    else {
                        if (player_1->control->down && player_1->pular == 0 && player_1->agachar == 1) {
                            al_draw_scaled_bitmap(player_1->imagem[player_1->index], 0, 0, al_get_bitmap_width(player_1->imagem[player_1->index]), al_get_bitmap_height(player_1->imagem[player_1->index]), player_1->x, player_1->y + 30, player_1->largura, player_1->altura, ALLEGRO_FLIP_HORIZONTAL);
                        } 
                        
                        else {
                            al_draw_scaled_bitmap(player_1->imagem[player_1->index], 0, 0, al_get_bitmap_width(player_1->imagem[player_1->index]), al_get_bitmap_height(player_1->imagem[player_1->index]), player_1->x, player_1->y, player_1->largura, player_1->altura, ALLEGRO_FLIP_HORIZONTAL);
                        }
                    }
                }

                al_flip_display();    // Atualiza a tela com o que foi desenhado

                // Atualiza o índice de animação dos jogadores a cada 5 frames
                if (flag > 5) {
                    if (player_1->index < 3) player_1->index++;
                    else player_1->index = 0;
                    if (player_2->index < 3) player_2->index++;
                    else player_2->index = 0;
                    flag = 0;
                }

                flag++;    // Incrementa o contador de frames
            } 
            
            else if ((event.type == 10) || (event.type == 12)) {    // Verifica se o evento é de tecla pressionada ou liberada
                // Verifica a tecla pressionada e chama a função correspondente para controlar o jogador 1
                if (event.keyboard.keycode == 1) joystick_left(player_1->control);
                else if (event.keyboard.keycode == 4) joystick_right(player_1->control);
                else if (event.keyboard.keycode == 23) joystick_up(player_1->control);
                else if (event.keyboard.keycode == 19) {
                    joystick_down(player_1->control);
                    if (event.type == 12) player_1->agachar = 0;
                }
                else if (event.keyboard.keycode == 17) joystick_punch(player_1->control);
                else if (event.keyboard.keycode == 5) joystick_kick(player_1->control);
                // Verifica a tecla pressionada e chama a função correspondente para controlar o jogador 2
                else if (event.keyboard.keycode == 82) joystick_left(player_2->control);
                else if (event.keyboard.keycode == 83) joystick_right(player_2->control);
                else if (event.keyboard.keycode == 84) joystick_up(player_2->control);
                else if (event.keyboard.keycode == 85) {
                    joystick_down(player_2->control);
                    if (event.type == 12) player_2->agachar = 0;
                }
                else if (event.keyboard.keycode == 216) joystick_punch(player_2->control);
                else if (event.keyboard.keycode == 218) joystick_kick(player_2->control);
            } else if (event.type == 42) break;    // Verifica se o evento é o clique no "X" de fechamento da janela e sai do loop principal
        }

        if (event.type == 42) return 0;    // Se o evento de fechamento da janela foi capturado, encerra o programa
    }

    flag = 0;    // Reseta o contador de frames ao final do loop principal

    while (1) {    // Laço principal do programa, que executa indefinidamente até ser explicitamente interrompido
        al_wait_for_event(queue, &event);    // Função que captura eventos da fila 'queue' e armazena o evento na variável 'event'

        if (event.type == 30) {    // O evento tipo 30 indica um evento de temporizador, usado para controle de atualização da tela (conceito de FPS)
            al_clear_to_color(al_map_rgb(0, 0, 0));    // Limpa a tela com a cor preta

            if (flag < 40) {    // Condição que controla a exibição do texto de instrução
                al_draw_text(font2, al_map_rgba(0, 0, 0, 150), 500 + 2, 400 + 2, ALLEGRO_ALIGN_CENTER, "Aperte a tecla ENTER para continuar");    // Desenha a sombra do texto
                al_draw_text(font2, al_map_rgb(255, 255, 255), 500, 400, ALLEGRO_ALIGN_CENTER, "Aperte a tecla ENTER para continuar");    // Desenha o texto principal

                flag++;    // Incrementa o valor da variável 'flag'
            } 
            
            else {
                flag++;    // Incrementa o valor da variável 'flag'
                if (!(flag % 50)) flag = 0;    // Quando 'flag' atinge um múltiplo de 50, reseta 'flag' para 0
            }

            // Verifica se o jogador 1 ganhou
            if (player_1->win == 2) {
                al_draw_text(font, al_map_rgba(0, 0, 0, 150), 500 + 4, 200 + 4, ALLEGRO_ALIGN_CENTER, "PLAYER 1 VENCEDOR!!");    // Desenha a sombra do texto indicando que o jogador 1 venceu
                al_draw_text(font, al_map_rgb(255, 255, 255), 500, 200, ALLEGRO_ALIGN_CENTER, "PLAYER 1 VENCEDOR!!");    // Desenha o texto principal indicando que o jogador 1 venceu
            } 
            
            else {
                // Se o jogador 1 não ganhou, então o jogador 2 ganhou
                al_draw_text(font, al_map_rgba(0, 0, 0, 150), 500 + 4, 200 + 4, ALLEGRO_ALIGN_CENTER, "PLAYER 2 VENCEDOR!!");    // Desenha a sombra do texto indicando que o jogador 2 venceu
                al_draw_text(font, al_map_rgb(255, 255, 255), 500, 200, ALLEGRO_ALIGN_CENTER, "PLAYER 2 VENCEDOR!!");    // Desenha o texto principal indicando que o jogador 2 venceu
            }

            al_flip_display();    // Atualiza a tela com o que foi desenhado
        }
        else if ((event.type == 10) || (event.type == 12)) {    // Verifica se o evento é de tecla pressionada (evento tipo 10) ou liberada (evento tipo 12)
            if (event.keyboard.keycode == 67) break;    // Se a tecla pressionada ou liberada for a tecla ENTER (código 67), sai do laço principal
        }
        else if (event.type == 42) return 0;    // Verifica se o evento é o fechamento da janela (evento tipo 42) e encerra o programa graciosamente
    }

    al_destroy_bitmap(image);    // Libera a memória alocada para a imagem após o término do laço principal
    al_destroy_bitmap(hp);       // Libera a memória alocada para a imagem após o término do laço principal

    return 1;
}