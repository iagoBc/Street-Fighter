

# Nome do executável
TARGET = main.exe

# Fontes
SRC = main.c Telas.c Player.c Joystick.c Square.c Pers.c Vida.c

# Compilador e flags
CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lallegro -lallegro_font -lallegro_ttf -lallegro_image -lallegro_primitives

# Regra padrão
all: $(TARGET)

# Regra para criar o executável
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

# Regra para executar o programa
run: $(TARGET)
	.\$(TARGET)

# Regra de limpeza
clean:
	del $(TARGET)

