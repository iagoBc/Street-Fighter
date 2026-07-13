# Street Fighter 2D em C

Um clone simplificado do Street Fighter, desenvolvido em C utilizando a biblioteca gráfica [Allegro5](https://liballeg.org/). Projeto acadêmico com foco em lógica de jogo, manipulação de sprites, detecção de colisão e máquina de estados (menu → seleção de personagem → luta).

![Gameplay](imagens/menu.png)
<!-- adicione um screenshot ou GIF real aqui -->

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
**Ubuntu/Debian:**
```bash
sudo apt install liballegro5-dev liballegro-image5-dev liballegro-font5-dev liballegro-ttf5-dev liballegro-primitives5-dev
```

## Compilação e execução
```bash
make
./main.exe   # ou ./main, dependendo do ajuste do Makefile
```

## Status do projeto
Projeto acadêmico funcional, desenvolvido como exercício de C e programação orientada a estruturas. Não é um jogo em produção — próximos passos possíveis incluem portar o build para Linux/macOS e adicionar sistema de golpes especiais.

## Autor
Iago Bariuka — [github.com/iagoBc](https://github.com/iagoBc)