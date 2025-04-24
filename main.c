#include "Telas.h"  // Inclui o arquivo de cabeçalho "telas.h"

int main(){  
    al_init();  // Inicializa a biblioteca Allegro
    al_install_keyboard();  // Instala o suporte para teclado
    al_init_font_addon();  // Inicializa o addon de fontes
    al_init_ttf_addon();  // Inicializa o addon para fontes TrueType
    al_init_image_addon();  // Inicializa o addon de imagens
    al_init_primitives_addon();  // Inicializa o addon para primitivas gráficas

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);  // Cria um temporizador que dispara a cada 1/30 de segundo
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();  // Cria uma fila de eventos

    ALLEGRO_FONT* font = al_load_font("imagens/street_fighter.ttf", 90, 0);  // Carrega uma fonte com tamanho 90
    ALLEGRO_FONT* font2 = al_load_font("imagens/street_fighter.ttf", 15, 0);  // Carrega uma fonte com tamanho 15

    if (!(font && font2)) {  // Verifica se as fontes foram carregadas corretamente
        fprintf(stderr, "Falha ao carregar a fonte do Street Fighter!\n");
    }

    ALLEGRO_DISPLAY* tela = al_create_display(X_SCREEN, Y_SCREEN);  // Cria a tela com dimensões X_SCREEN por Y_SCREEN
    ALLEGRO_BITMAP* icon = al_load_bitmap("imagens/icon.png");  // Carrega um ícone para a janela
    al_set_window_title(tela, "Street Fighter");  // Define o título da janela
    al_set_display_icon(tela, icon);  // Define o ícone da janela

    al_register_event_source(queue, al_get_keyboard_event_source());  // Registra a fonte de eventos do teclado na fila de eventos
    al_register_event_source(queue, al_get_display_event_source(tela));  // Registra a fonte de eventos da tela na fila de eventos
    al_register_event_source(queue, al_get_timer_event_source(timer));  // Registra a fonte de eventos do temporizador na fila de eventos

    int estado_jogo = 1;  // Inicializa a variável que representa o estado do jogo

    player* player_1 = player_create("imagens/player1.png",120, 150, 70, 300, X_SCREEN, Y_SCREEN, "", 20);  // Cria o primeiro jogador
    if (!player_1) return 0;  // Verifica se o jogador 1 foi criado corretamente, caso contrário, encerra o programa
    player* player_2 = player_create("imagens/Parado/player2_0.png", 120, 150, 800, 300, X_SCREEN, Y_SCREEN, "", 980);  // Cria o segundo jogador
    if (!player_2) return 0;  // Verifica se o jogador 2 foi criado corretamente, caso contrário, encerra o programa

    while(estado_jogo){  // Loop principal do jogo
        estado_jogo = menu(timer, font, font2, queue);  // Executa a função do menu e atualiza o estado do jogo
        if(!estado_jogo) break;  // Sai do loop se o estado do jogo for 0

        estado_jogo = selecao(timer, font, font2, queue, player_1, player_2);  // Executa a função de seleção de personagens e atualiza o estado do jogo
        if(!estado_jogo) break;  // Sai do loop se o estado do jogo for 0

        estado_jogo = jogar(timer, queue, player_1, player_2, font2, font);  // Executa a função de jogo e atualiza o estado do jogo
        if(!estado_jogo) break;  // Sai do loop se o estado do jogo for 0
        
        player_reset(player_1, 1);  // Reseta o estado do jogador 1
        player_reset(player_2, 2);  // Reseta o estado do jogador 2
        player_1->win = 0;  // Reseta a vitória do jogador 1
        player_2->win = 0;  // Reseta a vitória do jogador 2
    }

    al_destroy_font(font);  // Destroi a fonte carregada
    al_destroy_font(font2);  // Destroi a segunda fonte carregada
    al_destroy_display(tela);  // Destroi a tela criada
    al_destroy_timer(timer);  // Destroi o temporizador criado
    al_destroy_event_queue(queue);  // Destroi a fila de eventos criada
    al_destroy_bitmap(icon);  // Destroi o bitmap do ícone
    player_destroy(player_1);  // Destroi o primeiro jogador
    player_destroy(player_2);  // Destroi o segundo jogador

    return 0; 
}
