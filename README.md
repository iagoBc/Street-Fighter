# Street Fighter 2D em C

Um clone simplificado do Street Fighter, desenvolvido em C utilizando a biblioteca gráfica [Allegro5](https://liballeg.org/). Projeto acadêmico com foco em lógica de jogo, manipulação de sprites, detecção de colisão e máquina de estados (menu → seleção de personagem → luta).

## Funcionalidades
- Menu inicial e tela de seleção de personagens
- Sistema de vida (HP) por jogador
- Movimentação, pulo, agachamento e colisão 2D entre jogadores
- Suporte a controle via joystick
- Animações por sprite sheet (parado, andar, pular, atacar, etc.)

## Estrutura do projeto
| Arquivo | Responsabilidade |
|---|---|
| `main.c` | Loop principal e inicialização do Allegro |
| `Player.c/.h` | Estrutura e lógica do jogador |
| `Pers.c/.h` | Personagens e animações |
| `Vida.c/.h` | Sistema de vida/HP |
| `Joystick.c/.h` | Entrada via joystick |
| `Square.c/.h` | Colisão / geometria |
| `Telas.c/.h` | Telas (menu, seleção, jogo) |

## Pré-requisitos
- GCC
- Biblioteca Allegro5 (`allegro`, `allegro_font`, `allegro_ttf`, `allegro_image`, `allegro_primitives`)

### Instalação do Allegro5
[Allegro5](https://github.com/liballeg/allegro_wiki/wiki/Quickstart)
**Ubuntu/Debian:**
Primeiro, adicione o PPA do Allegro. Isso te dá versões atualizadas do Allegro; os repositórios base fornecem apenas a versão 5.2.3 no momento em que este texto foi escrito.

```bash

sudo add-apt-repository ppa:allegro/5.2
```

Depois, instale o Allegro:
```

```bash
sudo apt-get install liballegro*5.2 liballegro*5-dev
```

## Compilação e execução
```bash
make
./main   # ou ./main.exe, dependendo do ajuste do SO
```

## Status do projeto
Projeto acadêmico funcional, desenvolvido como exercício de C e programação orientada a estruturas. Não é um jogo em produção — próximos passos possíveis incluem portar o build para Linux/macOS e adicionar sistema de golpes especiais.

## Autor
Iago Bariuka — [github.com/iagoBc](https://github.com/iagoBc)