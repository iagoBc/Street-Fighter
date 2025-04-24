#include "Pers.h" // Inclui o cabeçalho que define a estrutura e as funções do personagem

// Função para criar um personagem
pers* pers_create(char *nome) {
    int j = 3;

    // Aloca memória para a estrutura `pers`
    pers *personagem = (pers*) malloc(sizeof(pers));
    if (personagem == NULL) {
        fprintf(stderr, "Erro ao alocar memória para personagem.\n");
        return NULL; // Retorna NULL se a alocação falhar
    }

    // Aloca memória para os ponteiros de bitmaps (imagens) para várias ações do personagem
    personagem->parar = (ALLEGRO_BITMAP**) malloc(4 * sizeof(ALLEGRO_BITMAP*));
    personagem->pular = (ALLEGRO_BITMAP**) malloc(4 * sizeof(ALLEGRO_BITMAP*));
    personagem->descer = (ALLEGRO_BITMAP**) malloc(4 * sizeof(ALLEGRO_BITMAP*));
    personagem->andar = (ALLEGRO_BITMAP**) malloc(4 * sizeof(ALLEGRO_BITMAP*));
    personagem->agachar = (ALLEGRO_BITMAP**) malloc(4 * sizeof(ALLEGRO_BITMAP*));
    personagem->superior = (ALLEGRO_BITMAP**) malloc(4 * sizeof(ALLEGRO_BITMAP*));
    personagem->inferior = (ALLEGRO_BITMAP**) malloc(4 * sizeof(ALLEGRO_BITMAP*));

    // Verifica se todas as alocações de memória para bitmaps foram bem-sucedidas
    if (personagem->parar == NULL || personagem->pular == NULL || personagem->andar == NULL || 
        personagem->agachar == NULL || personagem->superior == NULL || personagem->inferior == NULL || personagem->descer == NULL) {
        fprintf(stderr, "Erro ao alocar memória para imagens.\n");
        // Libera a memória já alocada e o próprio `personagem` antes de retornar NULL
        free(personagem->parar);
        free(personagem->pular);
        free(personagem->andar);
        free(personagem->agachar);
        free(personagem->superior);
        free(personagem->inferior);
        free(personagem->descer);
        free(personagem);
        return NULL;
    }
    
    // Duplicar a string `nome` para o membro `nome` do `personagem`
    personagem->nome = strdup(nome);
    if (personagem->nome == NULL) {
        fprintf(stderr, "Erro ao duplicar nome.\n");
        // Libera toda a memória alocada em caso de falha
        free(personagem->parar);
        free(personagem->pular);
        free(personagem->andar);
        free(personagem->agachar);
        free(personagem->superior);
        free(personagem->inferior);
        free(personagem->descer);
        free(personagem);
        return NULL;
    }

    // Inicializa os ponteiros de bitmap com NULL para garantir que não sejam lixo
    for (int i = 0; i < 4; i++) {
        personagem->parar[i] = NULL;
        personagem->pular[i] = NULL;
        personagem->andar[i] = NULL;
        personagem->agachar[i] = NULL;
        personagem->superior[i] = NULL;
        personagem->inferior[i] = NULL;
        personagem->descer[i] = NULL;
    }

    // Carrega as imagens para o personagem Ken
    if (strcmp(personagem->nome, "ken") == 0) {
        for (int i = 0; i < 4; i++) {
            char filename[50];
            char filename2[50];
            char filename3[50];
            char filename4[50];
            char filename5[50];
            char filename6[50];
            char filename7[50];

            // Cria strings com os nomes dos arquivos das imagens
            sprintf(filename, "imagens/parar/ken%d.png", i);
            sprintf(filename2, "imagens/andar/ken%d.png", i);
            sprintf(filename3, "imagens/agachar/ken%d.png", i);
            sprintf(filename4, "imagens/pular/ken%d.png", i);
            sprintf(filename5, "imagens/pular/ken%d.png", j);
            sprintf(filename6, "imagens/superior/ken%d.png", i);
            sprintf(filename7, "imagens/inferior/ken%d.png", i);

            // Carrega as imagens para as diferentes ações do personagem Ken
            personagem->parar[i] = al_load_bitmap(filename);
            personagem->andar[i] = al_load_bitmap(filename2);
            personagem->agachar[i] = al_load_bitmap(filename3);
            personagem->pular[i] = al_load_bitmap(filename4);
            personagem->descer[j] = al_load_bitmap(filename5);
            personagem->inferior[i] = al_load_bitmap(filename7);
            personagem->superior[i] = al_load_bitmap(filename6);

            // Verifica se cada imagem foi carregada corretamente
            if (personagem->parar[i] == NULL) {
                fprintf(stderr, "Erro ao carregar imagem: %s\n", filename);
            }
            if (personagem->andar[i] == NULL) {
                fprintf(stderr, "Erro ao carregar imagem: %s\n", filename2);
            }
            if (personagem->agachar[i] == NULL) {
                fprintf(stderr, "Erro ao carregar imagem: %s\n", filename3);
            }
            if (personagem->pular[i] == NULL) {
                fprintf(stderr, "Erro ao carregar imagem: %s\n", filename4);
            }
            if (personagem->descer[j] == NULL) {
                fprintf(stderr, "Erro ao carregar imagem: %s\n", filename5);
            }
            if (personagem->superior[i] == NULL) {
                fprintf(stderr, "Erro ao carregar imagem: %s\n", filename6);
            }
            if (personagem->inferior[i] == NULL) {
                fprintf(stderr, "Erro ao carregar imagem: %s\n", filename7);
            }

            j--;
        }
    } 
    
    else if (strcmp(personagem->nome, "ryu") == 0) {
        // Carrega as imagens para o personagem Ryu
        for (int i = 0; i < 4; i++) {
            char filename[50];
            char filename2[50];
            char filename3[50];
            char filename4[50];
            char filename5[50];
            char filename6[50];
            char filename7[50];
                 
            // Cria strings com os nomes dos arquivos das imagens
            sprintf(filename, "imagens/parar/ryu%d.png", i);
            sprintf(filename2, "imagens/andar/ryu%d.png", i);
            sprintf(filename3, "imagens/agachar/ryu%d.png", i);
            sprintf(filename4, "imagens/pular/ryu%d.png", i);
            sprintf(filename5, "imagens/pular/ryu%d.png", j);
            sprintf(filename6, "imagens/superior/ryu%d.png", i);
            sprintf(filename7, "imagens/inferior/ryu%d.png", i);

            // Carrega as imagens para as diferentes ações do personagem Ryu
            personagem->parar[i] = al_load_bitmap(filename);
            personagem->andar[i] = al_load_bitmap(filename2);
            personagem->agachar[i] = al_load_bitmap(filename3);
            personagem->pular[i] = al_load_bitmap(filename4);
            personagem->descer[j] = al_load_bitmap(filename5);
            personagem->inferior[i] = al_load_bitmap(filename7);
            personagem->superior[i] = al_load_bitmap(filename6);

            // Verifica se cada imagem foi carregada corretamente
            if (personagem->parar[i] == NULL) {
                fprintf(stderr, "Erro ao carregar imagem: %s\n", filename);
            }
            if (personagem->andar[i] == NULL) {
                fprintf(stderr, "Erro ao carregar imagem: %s\n", filename2);
            }
            if (personagem->agachar[i] == NULL) {
                fprintf(stderr, "Erro ao carregar imagem: %s\n", filename3);
            }
            if (personagem->pular[i] == NULL) {
                fprintf(stderr, "Erro ao carregar imagem: %s\n", filename4);
            }
            if (personagem->descer[j] == NULL) {
                fprintf(stderr, "Erro ao carregar imagem: %s\n", filename5);
            }
            if (personagem->superior[i] == NULL) {
                fprintf(stderr, "Erro ao carregar imagem: %s\n", filename6);
            }
            if (personagem->inferior[i] == NULL) {
                fprintf(stderr, "Erro ao carregar imagem: %s\n", filename7);
            }

            j--;
        }
    }

    else if (strcmp(personagem->nome, "dee") == 0) {
        // Carrega as imagens para o personagem Ryu
        for (int i = 0; i < 4; i++) {
            char filename[50];
            char filename2[50];
            char filename3[50];
            char filename4[50];
            char filename5[50];
            char filename6[50];
            char filename7[50];
                 
            // Cria strings com os nomes dos arquivos das imagens
            sprintf(filename, "imagens/parar/dee%d.png", i);
            sprintf(filename2, "imagens/andar/dee%d.png", i);
            sprintf(filename3, "imagens/agachar/dee%d.png", i);
            sprintf(filename4, "imagens/pular/dee%d.png", i);
            sprintf(filename5, "imagens/pular/dee%d.png", j);
            sprintf(filename6, "imagens/superior/dee%d.png", i);
            sprintf(filename7, "imagens/inferior/dee%d.png", i);

            // Carrega as imagens para as diferentes ações do personagem Ryu
            personagem->parar[i] = al_load_bitmap(filename);
            personagem->andar[i] = al_load_bitmap(filename2);
            personagem->agachar[i] = al_load_bitmap(filename3);
            personagem->pular[i] = al_load_bitmap(filename4);
            personagem->descer[j] = al_load_bitmap(filename5);
            personagem->inferior[i] = al_load_bitmap(filename7);
            personagem->superior[i] = al_load_bitmap(filename6);

            // Verifica se cada imagem foi carregada corretamente
            if (personagem->parar[i] == NULL) {
                fprintf(stderr, "Erro ao carregar imagem: %s\n", filename);
            }
            if (personagem->andar[i] == NULL) {
                fprintf(stderr, "Erro ao carregar imagem: %s\n", filename2);
            }
            if (personagem->agachar[i] == NULL) {
                fprintf(stderr, "Erro ao carregar imagem: %s\n", filename3);
            }
            if (personagem->pular[i] == NULL) {
                fprintf(stderr, "Erro ao carregar imagem: %s\n", filename4);
            }
            if (personagem->descer[j] == NULL) {
                fprintf(stderr, "Erro ao carregar imagem: %s\n", filename5);
            }
            if (personagem->superior[i] == NULL) {
                fprintf(stderr, "Erro ao carregar imagem: %s\n", filename6);
            }
            if (personagem->inferior[i] == NULL) {
                fprintf(stderr, "Erro ao carregar imagem: %s\n", filename7);
            }

            j--;
        }
    }

    else if (strcmp(personagem->nome, "cammy") == 0) {
        // Carrega as imagens para o personagem Ryu
        for (int i = 0; i < 4; i++) {
            char filename[50];
            char filename2[50];
            char filename3[50];
            char filename4[50];
            char filename5[50];
            char filename6[50];
            char filename7[50];
                 
            // Cria strings com os nomes dos arquivos das imagens
            sprintf(filename, "imagens/parar/cammy%d.png", i);
            sprintf(filename2, "imagens/andar/cammy%d.png", i);
            sprintf(filename3, "imagens/agachar/cammy%d.png", i);
            sprintf(filename4, "imagens/pular/cammy%d.png", i);
            sprintf(filename5, "imagens/pular/cammy%d.png", j);
            sprintf(filename6, "imagens/superior/cammy%d.png", i);
            sprintf(filename7, "imagens/inferior/cammy%d.png", i);

            // Carrega as imagens para as diferentes ações do personagem Ryu
            personagem->parar[i] = al_load_bitmap(filename);
            personagem->andar[i] = al_load_bitmap(filename2);
            personagem->agachar[i] = al_load_bitmap(filename3);
            personagem->pular[i] = al_load_bitmap(filename4);
            personagem->descer[j] = al_load_bitmap(filename5);
            personagem->inferior[i] = al_load_bitmap(filename7);
            personagem->superior[i] = al_load_bitmap(filename6);

            // Verifica se cada imagem foi carregada corretamente
            if (personagem->parar[i] == NULL) {
                fprintf(stderr, "Erro ao carregar imagem: %s\n", filename);
            }
            if (personagem->andar[i] == NULL) {
                fprintf(stderr, "Erro ao carregar imagem: %s\n", filename2);
            }
            if (personagem->agachar[i] == NULL) {
                fprintf(stderr, "Erro ao carregar imagem: %s\n", filename3);
            }
            if (personagem->pular[i] == NULL) {
                fprintf(stderr, "Erro ao carregar imagem: %s\n", filename4);
            }
            if (personagem->descer[j] == NULL) {
                fprintf(stderr, "Erro ao carregar imagem: %s\n", filename5);
            }
            if (personagem->superior[i] == NULL) {
                fprintf(stderr, "Erro ao carregar imagem: %s\n", filename6);
            }
            if (personagem->inferior[i] == NULL) {
                fprintf(stderr, "Erro ao carregar imagem: %s\n", filename7);
            }

            j--;
        }
    }

    return personagem; // Retorna o ponteiro para o personagem criado
}

// Função para destruir um personagem
void pers_destroy(pers *element) {
    if (element == NULL) return; // Verifica se o ponteiro é nulo

    // Destrói os bitmaps alocados para cada ação do personagem
    for (int i = 0; i < 4; i++) {
        if (element->agachar[i] != NULL) {
            al_destroy_bitmap(element->agachar[i]);
            element->agachar[i] = NULL;
        }
        if (element->parar[i] != NULL) {
            al_destroy_bitmap(element->parar[i]);
            element->parar[i] = NULL;
        }
        if (element->pular[i] != NULL) {
            al_destroy_bitmap(element->pular[i]);
            element->pular[i] = NULL;
        }
        if (element->andar[i] != NULL) {
            al_destroy_bitmap(element->andar[i]);
            element->andar[i] = NULL;
        }
        if (element->superior[i] != NULL) {
            al_destroy_bitmap(element->superior[i]);
            element->superior[i] = NULL;
        }
        if (element->inferior[i] != NULL) {
            al_destroy_bitmap(element->inferior[i]);
            element->inferior[i] = NULL;
        }
    }

    // Libera a memória alocada para os ponteiros de bitmaps
    free(element->agachar);
    free(element->parar);
    free(element->pular);
    free(element->andar);
    free(element->superior);
    free(element->inferior);

    // Libera a memória alocada para o nome e a própria estrutura do personagem
    free(element->nome);
    free(element);
}
