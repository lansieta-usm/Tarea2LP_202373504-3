# Definición de variables
CC = gcc
CFLAGS = -Wall -g

# Regla para compilar el programa principal
CityDefender: CityDefender.o Cartas.o Tablero.o
	$(CC) $(CFLAGS) -o main CityDefender.o Cartas.o Tablero.o

# Regla para compilar CityDefender.o
CityDefender.o: CityDefender.c Cartas.h Tablero.h
	$(CC) $(CFLAGS) -c CityDefender.c

# Regla para compilar Cartas.o
Cartas.o: Cartas.c Cartas.h
	$(CC) $(CFLAGS) -c Cartas.c

# Regla para compilar Tablero.o
Tablero.o: Tablero.c Tablero.h
	$(CC) $(CFLAGS) -c Tablero.c

# Regla para limpiar archivos compilados
clean:
	rm -f *.o CityDefender
