#include <stdlib.h>
#include <stdio.h>
#include "Tablero.h"

void*** tablero = NULL;
int tamano_tablero;
int total_barcos;

void inicializarTablero(int tamano){
    // Asignación del tamaño a la variable global tamano_tablero
    tamano_tablero = tamano;
    // Asignación de memoria a las filas del tablero
    tablero = (void ***)malloc(tamano * sizeof(void **));
    if (tablero == NULL) { // Si ocurre un error al asignar la memoria
        fprintf(stderr, "Ocurrió un error al asignar memoria para las filas del tablero.");
        exit(EXIT_FAILURE);
    }
    // Asignación de memoria a las columnas del tablero
    for (int fila = 0; fila < tamano; fila++) {
        tablero[fila] = (void **)malloc(tamano * sizeof(void *));
        if (tablero[fila] == NULL) { // Si ocurre un error al asignar la memoria
            fprintf(stderr, "Ocurrió un error al asignar memoria para las columnas del tablero.");
            exit(EXIT_FAILURE);
        }
        // Inicializar cada celda del tablero a NULL
        for (int columna = 0; columna < tamano; columna++) {
            tablero[fila][columna] = NULL;
        }
    }

}

void generarBarcos(int tamano, int dificultad){
    int barcos1x2, barcos1x3, barcos1x4, barcos1x5;
    if (dificultad == 1) {
        barcos1x2 = 2; barcos1x3 = 1; barcos1x4 = 1; barcos1x5 = 1;
    } else if (dificultad == 2) {
        barcos1x2 = 3; barcos1x3 = 2; barcos1x4 = 1; barcos1x5 = 1;
    } else {
        barcos1x2 = 3; barcos1x3 = 2; barcos1x4 = 2; barcos1x5 = 2; 
    }
    total_barcos = ((2*barcos1x2) + (3*barcos1x3) + (4*barcos1x4) + (5*barcos1x5)); // Dependiendo de la dificultad, varían la cantidad total de casillas a atinar
    int i=0;
    while (i<barcos1x2) { // Generar los barcos 1x2 necesarios
        int direccion = rand()%2; // Si la dirección es 0: Horizontal; Si la dirección es 1: Vertical 
        int fila = rand()%tamano;
        int columna = rand()%tamano;
        //printf("i es: %d\n", i);
        //printf("%d %d\n", fila, columna);
        if (direccion == 0 && columna + 2 <= tamano) { // Generación de un barco 2x1 Horizontal
            int espacioLibre = 1;
            for (int j = 0; j < 2; j++) { // Verificamos si el barco tiene espacio para generarse
                if (tablero[fila][columna + j] != NULL) {
                    espacioLibre = 0;
                    break;
                }
            }
            if (espacioLibre) {
                for (int k = 0; k < 2; k++) {
                    //printf("%d %d\n", fila, columna);
                    tablero[fila][columna + k] = TARGETOCULTO2;
                }
                i++;
            }
        } else if (direccion == 1 && fila + 2 <= tamano) { // Generación de un barco 2x1 Vertical
            int espacioLibre = 1;
            for (int j=0; j < 2; j++) {
                if (tablero[fila + j][columna] != NULL) {
                    espacioLibre = 0;
                    break;
                }
            }
            if (espacioLibre) {
                for (int k = 0; k < 2; k++) {
                    tablero[fila + k][columna] = TARGETOCULTO2;
                }
                i++;
            }
        }
    }
    i = 0;
    while (i<barcos1x3) {
        int direccion = rand()%2; // Si la dirección es 0: Horizontal; Si la dirección es 1: Vertical 
        int fila = rand()%tamano;
        int columna = rand()%tamano;
        //printf("i es: %d\n", i);
        //printf("%d %d\n", fila, columna);
        if (direccion == 0 && columna + 3 <= tamano) { // Generación de un barco 3x1 Horizontal
            int espacioLibre = 1;
            for (int j = 0; j < 3; j++) { // Verificamos si el barco tiene espacio para generarse
                if (tablero[fila][columna + j] != NULL) {
                    espacioLibre = 0;
                    break;
                }
            }
            if (espacioLibre) {
                for (int k = 0; k < 3; k++) {
                    //printf("%d %d\n", fila, columna);
                    tablero[fila][columna + k] = TARGETOCULTO3;
                }
                i++;
            }
        } else if (direccion == 1 && fila + 3 <= tamano) { // Generación de un barco 3x1 Vertical
            int espacioLibre = 1;
            for (int j=0; j < 3; j++) {
                if (tablero[fila + j][columna] != NULL) {
                    espacioLibre = 0;
                    break;
                }
            }
            if (espacioLibre) {
                for (int k = 0; k < 3; k++) {
                    tablero[fila + k][columna] = TARGETOCULTO3;
                }
                i++;
            }
        }
    }
    i = 0;
    while (i<barcos1x4) {
        int direccion = rand()%2; // Si la dirección es 0: Horizontal; Si la dirección es 1: Vertical 
        int fila = rand()%tamano;
        int columna = rand()%tamano;
        //printf("i es: %d\n", i);
        //printf("%d %d\n", fila, columna);
        if (direccion == 0 && columna + 4 <= tamano) { // Generación de un barco 4x1 Horizontal
            int espacioLibre = 1;
            for (int j = 0; j < 4; j++) { // Verificamos si el barco tiene espacio para generarse
                if (tablero[fila][columna + j] != NULL) {
                    espacioLibre = 0;
                    break;
                }
            }
            if (espacioLibre) {
                for (int k = 0; k < 4; k++) {
                    //printf("%d %d\n", fila, columna);
                    tablero[fila][columna + k] = TARGETOCULTO4;
                }
                i++;
            }
        } else if (direccion == 1 && fila + 4 <= tamano) { // Generación de un barco 4x1 Vertical
            int espacioLibre = 1;
            for (int j=0; j < 4; j++) {
                if (tablero[fila + j][columna] != NULL) {
                    espacioLibre = 0;
                    break;
                }
            }
            if (espacioLibre) {
                for (int k = 0; k < 4; k++) {
                    tablero[fila + k][columna] = TARGETOCULTO4;
                }
                i++;
            }
        }
    }
    i = 0;
    while (i<barcos1x5) {
        int direccion = rand()%2; // Si la dirección es 0: Horizontal; Si la dirección es 1: Vertical 
        int fila = rand()%tamano;
        int columna = rand()%tamano;
        //printf("i es: %d\n", i);
        //printf("%d %d\n", fila, columna);
        if (direccion == 0 && columna + 5 <= tamano) { // Generación de un barco 5x1 Horizontal
            int espacioLibre = 1;
            for (int j = 0; j < 5; j++) { // Verificamos si el barco tiene espacio para generarse
                if (tablero[fila][columna + j] != NULL) {
                    espacioLibre = 0;
                    break;
                }
            }
            if (espacioLibre) {
                for (int k = 0; k < 5; k++) {
                    //printf("%d %d\n", fila, columna);
                    tablero[fila][columna + k] = TARGETOCULTO5;
                }
                i++;
            }
        } else if (direccion == 1 && fila + 5 <= tamano) { // Generación de un barco 5x1 Vertical
            int espacioLibre = 1;
            for (int j=0; j < 5; j++) {
                if (tablero[fila + j][columna] != NULL) {
                    espacioLibre = 0;
                    break;
                }
            }
            if (espacioLibre) {
                for (int k = 0; k < 5; k++) {
                    tablero[fila + k][columna] = TARGETOCULTO5;
                }
                i++;
            }
        }
    }
}

void mostrarTablero(){
    for (int fila = 0; fila < tamano_tablero; fila++) {
        for (int columna = 0; columna < tamano_tablero; columna++) {
            if (tablero[fila][columna] == NULL) { // Marcamos una celda donde no se ha disparado
                if (columna == tamano_tablero-1) {
                    printf("| |");
                } else {
                    printf("| ");
                }
            } else if ((tablero[fila][columna] == TARGETOCULTO2) || (tablero[fila][columna] == TARGETOCULTO3) || (tablero[fila][columna] == TARGETOCULTO4) || (tablero[fila][columna] == TARGETOCULTO5)){ // Marcamos una celda donde se disparó y no se atinó a un barco
                if (columna == tamano_tablero-1){
                    printf("| |");
                } else {
                    printf("| ");
                }
            } else if (tablero[fila][columna] == TARGETFALLADO){ // Marcamos una celda donde se disparó y no se atinó a un barco
                if (columna == tamano_tablero-1){
                    printf("|O|");
                } else {
                    printf("|O");
                }
            } else if (tablero[fila][columna] == TARGETACERTADO) { // Marcamos una celda donde se disparó y se atinó a un barco
                if (columna == tamano_tablero-1){
                    printf("|X|");
                } else {
                    printf("|X");
                }
            }
        }
    printf("\n"); // Nueva línea al final de cada fila
    }
}

void mostrarTableroFinal(){
    for (int fila = 0; fila < tamano_tablero; fila++) { // Las casillas donde no se disparó, y además había un barco, son marcadas con el número correspondiente a la longitud del barco
        for (int columna = 0; columna < tamano_tablero; columna++) {
            if (tablero[fila][columna] == TARGETOCULTO2) {
                tablero[fila][columna] = TARGET2;
            } else if (tablero[fila][columna] == TARGETOCULTO3) {
                tablero[fila][columna] = TARGET3;
            } else if (tablero[fila][columna] == TARGETOCULTO4) {
                tablero[fila][columna] = TARGET4;
            } else if (tablero[fila][columna] == TARGETOCULTO5) {
                tablero[fila][columna] = TARGET5;
            }
        }
    }
    
    for (int fila = 0; fila < tamano_tablero; fila++) { // Se muestra el tablero final
        for (int columna = 0; columna < tamano_tablero; columna++) {
            if (tablero[fila][columna] == NULL) { // Marcamos una celda donde no se disparó
                if (columna == tamano_tablero-1) {
                    printf("| |");
                } else {
                    printf("| ");
                }
            } else if (tablero[fila][columna] == TARGETFALLADO){ // Marcamos una celda donde se disparó y no se atinó a un barco
                if (columna == tamano_tablero-1){
                    printf("|O|");
                } else {
                    printf("|O");
                }
            } else if (tablero[fila][columna] == TARGETACERTADO) { // Marcamos una celda donde se disparó y se atinó a un barco
                if (columna == tamano_tablero-1){
                    printf("|X|");
                } else {
                    printf("|X");
                }
            } else if (tablero[fila][columna] == TARGET2) { // Marcamos una celda donde no se disparó, pero había un barco de longitud 2
                if (columna == tamano_tablero-1){
                    printf("|2|");
                } else {
                    printf("|2");
                }
            } else if (tablero[fila][columna] == TARGET3) { // Marcamos una celda donde no se disparó, pero había un barco de longitud 3
                if (columna == tamano_tablero-1){
                    printf("|3|");
                } else {
                    printf("|3");
                }
            } else if (tablero[fila][columna] == TARGET4) { // Marcamos una celda donde no se disparó, pero había un barco de longitud 4
                if (columna == tamano_tablero-1){
                    printf("|4|");
                } else {
                    printf("|4");
                }
            } else if (tablero[fila][columna] == TARGET5) { // Marcamos una celda donde no se disparó, pero había un barco de longitud 5
                if (columna == tamano_tablero-1){
                    printf("|5|");
                } else {
                    printf("|5");
                }
            }
        }
    printf("\n"); // Nueva línea al final de cada fila
    }
}