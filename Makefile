# Definición de variables
CC = gcc
CFLAGS = -Wall -g
OBJ_DIR = Objetos

# Archivos fuente
SRC = CityDefender.c Cartas.c Tablero.c

# Archivos objeto (en el directorio Objetos)
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

# Regla para compilar el programa principal
CityDefender: $(OBJ)
	$(CC) $(CFLAGS) -o Main $(OBJ)

# Regla para compilar los archivos .o en el directorio Objetos
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar archivos compilados
clean:
	rm -rf $(OBJ_DIR) Main

.PHONY: clean
