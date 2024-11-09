#include <stdlib.h>
#include <stdio.h>
#include "Cartas.h"
#include "Tablero.h"
#include <time.h>

Mano Cartas;
int bool_disparo500kg = 0;
int eleccion_carta_copia;
int counter_barcos = 0;

void inicializarMazo(){
    Cartas.disponibles = 5;
    Cartas.carta = (void **) malloc(Cartas.disponibles * sizeof(void *));

    Cartas.carta[0] = DISPAROSIMPLE;
    Cartas.carta[1] = DISPAROSIMPLE;
    Cartas.carta[2] = DISPAROSIMPLE;
    Cartas.carta[3] = DISPAROSIMPLE;
    Cartas.carta[4] = DISPAROSIMPLE;
}

void mostrarMazo(){
    for (int i = 0; i < Cartas.disponibles; i++) {
        if (i<=3){
            if (Cartas.carta[i] == DISPAROSIMPLE) {
                printf("Disparo Simple | ");
            } else if (Cartas.carta[i] == DISPAROGRANDE) {
                printf("Disparo Grande | ");
            } else if (Cartas.carta[i] == DISPAROLINEAL) {
                printf("Disparo Lineal | ");
            } else if (Cartas.carta[i] == DISPARORADAR) {
                printf("Disparo Radar | ");
            } else if (Cartas.carta[i] == DISPARO500KG) {
                printf("Disparo 500KG | ");
            } else {
                printf("#Cañón Roto# | ");
            }
        } else {
            if (Cartas.carta[i] == DISPAROSIMPLE) {
                printf("Disparo Simple");
            } else if (Cartas.carta[i] == DISPAROGRANDE) {
                printf("Disparo Grande");
            } else if (Cartas.carta[i] == DISPAROLINEAL) {
                printf("Disparo Lineal");
            } else if (Cartas.carta[i] == DISPARORADAR) {
                printf("Disparo Radar");
            } else if (Cartas.carta[i] == DISPARO500KG) {
                printf("Disparo 500KG");
            } else {
                printf("#Cañón Roto#");
            }
        }
    }
    printf("\n");
}

void actualizarMazo(){
    int probabilidad = rand()%100;
    if (bool_disparo500kg == 0){ // Se hace siempre la verificación si ya se hizo previamente un Disparo 500KG, entra acá si aún no lo hay
        if (Cartas.carta[eleccion_carta_copia] == DISPAROSIMPLE) { // Si la carta seleccionada es un Disparo Simple
            if (probabilidad < 65) { // 65% de que vuelva a aparecer un Disparo Simple
                Cartas.carta[eleccion_carta_copia] = DISPAROSIMPLE;
            } else if (probabilidad < 85) { // 20% de que aparezca un Disparo Grande
                Cartas.carta[eleccion_carta_copia] = DISPAROGRANDE;
            } else if (probabilidad < 95) { // 10% de que aparezca un Disparo Radar
                Cartas.carta[eleccion_carta_copia] = DISPARORADAR;
            } else { // 5% de que aparezca un Disparo Lineal
                Cartas.carta[eleccion_carta_copia] = DISPAROLINEAL;
            }
        } else if (Cartas.carta[eleccion_carta_copia] == DISPAROGRANDE) { // Si la carta seleccionada es un Disparo Grande
            if (probabilidad < 80) { // 80% de que aparezca un Disparo Simple
                Cartas.carta[eleccion_carta_copia] = DISPAROSIMPLE;
            } else if (probabilidad < 83) { // 3% de que vuelva a aparecer un Disparo Grande
                Cartas.carta[eleccion_carta_copia] = DISPAROGRANDE;
            } else if (probabilidad < 93) { // 10% de que aparezca un Disparo Lineal
                Cartas.carta[eleccion_carta_copia] = DISPAROLINEAL;
            } else if (probabilidad < 98){ // 5% de que aparezca un Disparo Radar
                Cartas.carta[eleccion_carta_copia] = DISPARORADAR;
            } else { // 2% de que aparezca un Disparo 500KG
                Cartas.carta[eleccion_carta_copia] = DISPARO500KG;
            }
        } else if (Cartas.carta[eleccion_carta_copia] == DISPAROLINEAL) { // Si la carta seleccionada es un Disparo Lineal
            if (probabilidad < 85) { // 85% de que aparezca un Disparo Simple
                Cartas.carta[eleccion_carta_copia] = DISPAROSIMPLE;
            } else if (probabilidad < 90) { // 5% de que aparezca un Disparo Grande
                Cartas.carta[eleccion_carta_copia] = DISPAROGRANDE;
            } else if (probabilidad < 92) { // 2% de que vuelva a aparecer un Disparo Lineal
                Cartas.carta[eleccion_carta_copia] = DISPAROLINEAL;
            } else if (probabilidad < 98){ // 6% de que aparezca un Disparo Radar
                Cartas.carta[eleccion_carta_copia] = DISPARORADAR;
            } else { // 2% de que aparezca un Disparo 500KG
                Cartas.carta[eleccion_carta_copia] = DISPARO500KG;
            }
        } else if (Cartas.carta[eleccion_carta_copia] == DISPARORADAR) { // Si la carta seleccionada es un Disparo Radar
            if (probabilidad < 75) { // 75% de que aparezca un Disparo Simple
                Cartas.carta[eleccion_carta_copia] = DISPAROSIMPLE;
            } else if (probabilidad < 90) { // 15% de que aparezca un Disparo Grande
                Cartas.carta[eleccion_carta_copia] = DISPAROGRANDE;
            } else if (probabilidad < 95) { // 5% de que aparezca un Disparo Lineal
                Cartas.carta[eleccion_carta_copia] = DISPAROLINEAL;
            } else if (probabilidad < 97){ // 2% de que vuelva a aparecer un Disparo Radar
                Cartas.carta[eleccion_carta_copia] = DISPARORADAR;
            } else { // 3% de que aparezca un Disparo 500KG
                Cartas.carta[eleccion_carta_copia] = DISPARO500KG;
            }
        } else { // Si la carta seleccionada es un Disparo 500Kg
            bool_disparo500kg = 1;
            Cartas.carta[eleccion_carta_copia] = CANONROTO;
        }
    }
    else { // Si ya se hizo un Disparo 500KG, las probabilidades se redistribuyen y el programa entra acá
        if (Cartas.carta[eleccion_carta_copia] == DISPAROSIMPLE) { // Si la carta seleccionada es un Disparo Simple
            if (probabilidad < 65) { // 65% de que vuelva a aparecer un Disparo Simple
                Cartas.carta[eleccion_carta_copia] = DISPAROSIMPLE;
            } else if (probabilidad < 85) { // 20% de que aparezca un Disparo Grande
                Cartas.carta[eleccion_carta_copia] = DISPAROGRANDE;
            } else if (probabilidad < 95) { // 10% de que aparezca un Disparo Radar
                Cartas.carta[eleccion_carta_copia] = DISPARORADAR;
            } else { // 5% de que aparezca un Disparo Lineal
                Cartas.carta[eleccion_carta_copia] = DISPAROLINEAL;
            }
        } else if (Cartas.carta[eleccion_carta_copia] == DISPAROGRANDE) { // Si la carta seleccionada es un Disparo Grande
            if (probabilidad < 80) { // 80% de que aparezca un Disparo Simple
                Cartas.carta[eleccion_carta_copia] = DISPAROSIMPLE;
            } else if (probabilidad < 85) { // 5% de que vuelva a aparecer un Disparo Grande
                Cartas.carta[eleccion_carta_copia] = DISPAROGRANDE;
            } else if (probabilidad < 95) { // 10% de que aparezca un Disparo Lineal
                Cartas.carta[eleccion_carta_copia] = DISPAROLINEAL;
            } else { // 5% de que aparezca un Disparo Radar
                Cartas.carta[eleccion_carta_copia] = DISPARORADAR;
            }
        } else if (Cartas.carta[eleccion_carta_copia] == DISPAROLINEAL) { // Si la carta seleccionada es un Disparo Lineal
            if (probabilidad < 85) { // 85% de que aparezca un Disparo Simple
                Cartas.carta[eleccion_carta_copia] = DISPAROSIMPLE;
            } else if (probabilidad < 90) { // 5% de que aparezca un Disparo Grande
                Cartas.carta[eleccion_carta_copia] = DISPAROGRANDE;
            } else if (probabilidad < 94) { // 4% de que vuelva a aparecer un Disparo Lineal
                Cartas.carta[eleccion_carta_copia] = DISPAROLINEAL;
            } else { // 6% de que aparezca un Disparo Radar
                Cartas.carta[eleccion_carta_copia] = DISPARORADAR;
            }
        } else if (Cartas.carta[eleccion_carta_copia] == DISPARORADAR) { // Si la carta seleccionada es un Disparo Radar
            if (probabilidad < 75) { // 75% de que aparezca un Disparo Simple
                Cartas.carta[eleccion_carta_copia] = DISPAROSIMPLE;
            } else if (probabilidad < 90) { // 15% de que aparezca un Disparo Grande
                Cartas.carta[eleccion_carta_copia] = DISPAROGRANDE;
            } else if (probabilidad < 95) { // 5% de que aparezca un Disparo Lineal
                Cartas.carta[eleccion_carta_copia] = DISPAROLINEAL;
            } else { // 5% de que vuelva a aparecer un Disparo Radar
                Cartas.carta[eleccion_carta_copia] = DISPARORADAR;
            }
        }
    }
}

void usarCarta(){
    srand(time(NULL));
    int eleccion_carta;
    printf("Selecciona una carta: ");
    scanf("%d", &eleccion_carta);
    while (eleccion_carta > 5) {
        printf("Selección inválida, ingresa un número del 1 al 5: ");
        scanf("%d", &eleccion_carta);
    }
    eleccion_carta_copia = eleccion_carta-1;
    //printf("%d\n", eleccion_carta_copia);
    while (Cartas.carta[eleccion_carta-1] == CANONROTO) { // En caso de que haya habido un Disparo 500Kg, el cañón debe quedar inutilizable.
        printf("Selecciona otra carta, el cañón que quieres utilizar está roto: ");
        scanf("%d", &eleccion_carta);
    }
    if (Cartas.carta[eleccion_carta_copia] == DISPAROSIMPLE) { // Si la carta seleccionada es un Disparo Simple
        printf("Has seleccionado un Disparo Simple (1x1)\n");
    } else if (Cartas.carta[eleccion_carta_copia] == DISPAROGRANDE) { // Si la carta seleccionada es un Disparo Grande
        printf("Has seleccionado un Disparo Grande (3x3)\n");
        printf("Nota: Las coordenadas a seleccionar corresponderán al centro del ataque.\n");
    } else if (Cartas.carta[eleccion_carta_copia] == DISPAROLINEAL) { // Si la carta seleccionada es un Disparo Lineal
        printf("Has seleccionado un Disparo Lineal (5x1 o 1x5)\n");
        printf("Nota: Las coordenadas a seleccionar corresponderán al centro del ataque.\n");
    } else if (Cartas.carta[eleccion_carta_copia] == DISPARORADAR) { // Si la carta seleccionada es un Disparo Radar
        printf("Has seleccionado un Disparo Radar (5x5)\n");
        printf("Nota: Las coordenadas a seleccionar corresponderán al centro del ataque.\n");
    } else { // Si la carta seleccionada es un Disparo 500Kg
        printf("Has seleccionado un Disparo 500KG (11x11)\n");
        printf("Nota: ¡¡¡Se perderá el cañón... Gran misíl preparado!!! Las coordenadas a seleccionar corresponderán al centro del ataque.\n");
    }
}

void* disparoSimple(int x, int y){
    // printf("%d, %d\n", x, y);
    if (tablero[x][y] == NULL) { 
        printf("MISS!\n");
        tablero[x][y] = TARGETFALLADO;
    } else if ((tablero[x][y] == TARGETOCULTO2) || (tablero[x][y] == TARGETOCULTO3) || (tablero[x][y] == TARGETOCULTO4) || (tablero[x][y] == TARGETOCULTO5)) {
        printf("HIT!\n");
        tablero[x][y] = TARGETACERTADO;
        counter_barcos++;
    }
    return NULL;
}

void* disparoGrande(int x, int y){
    int bool_hit = 0;
    for (int fila = x-1; fila < x+2; fila++) {
        for (int columna = y-1; columna < y+2; columna++) {
            if ((fila >= 0 && fila < tamano_tablero) && (columna >= 0 && columna < tamano_tablero)) {
                // printf("%d, %d\n", fila+1, columna+1);
                if (tablero[fila][columna] == NULL) {
                    tablero[fila][columna] = TARGETFALLADO;
                } else if ((tablero[fila][columna] == TARGETOCULTO2) || (tablero[fila][columna] == TARGETOCULTO3) || (tablero[fila][columna] == TARGETOCULTO4) || (tablero[fila][columna] == TARGETOCULTO5)) {
                    tablero[fila][columna] = TARGETACERTADO;
                    bool_hit = 1;
                    counter_barcos++;
                }
            }
        }
    }
    if (bool_hit == 0) {
        printf("MISS!\n");
    } else {
        printf("HIT!\n");
    }
    return NULL;
}

void* disparoLineal(int x, int y){
    char eleccion;
    printf("¿Vertical [V] u Horizontal [H]?: ");
    scanf(" %c", &eleccion);
    while ((eleccion != 'V') && (eleccion != 'v') && (eleccion != 'H') && (eleccion != 'h')) {
        printf("Selección inválida, vuelve a intentarlo (V/H): ");
        scanf(" %c", &eleccion);
    }
    int bool_hit = 0;
    if ((eleccion == 'V') || (eleccion == 'v')){
        for (int fila = x-2; fila < x+3; fila++) {
            if (fila >= 0 && fila < tamano_tablero) {
                // printf("%d, %d\n", fila+1, columna+1);
                if (tablero[fila][y] == NULL) {
                    tablero[fila][y] = TARGETFALLADO;
                } else if ((tablero[fila][y] == TARGETOCULTO2) || (tablero[fila][y] == TARGETOCULTO3) || (tablero[fila][y] == TARGETOCULTO4) || (tablero[fila][y] == TARGETOCULTO5)) {
                    tablero[fila][y] = TARGETACERTADO;
                    bool_hit = 1;
                    counter_barcos++;
                }
            }
        }
    } else if ((eleccion == 'H') || (eleccion == 'h')){
        for (int columna = y-2; columna < y+3; columna++) {
            if (columna >= 0 && columna < tamano_tablero) {
                // printf("%d, %d\n", fila+1, columna+1);
                if (tablero[x][columna] == NULL) {
                    tablero[x][columna] = TARGETFALLADO;
                } else if ((tablero[x][columna] == TARGETOCULTO2) || (tablero[x][columna] == TARGETOCULTO3) || (tablero[x][columna] == TARGETOCULTO4) || (tablero[x][columna] == TARGETOCULTO5)) {
                    tablero[x][columna] = TARGETACERTADO;
                    bool_hit = 1;
                }
            }
        }
    }
    if (bool_hit == 0) {
        printf("MISS!\n");
    } else {
        printf("HIT!\n");
    }
    return NULL;
}

void* disparoRadar(int x, int y){
    int bool_avistamiento = 0;
    for (int fila = x-2; fila < x+3; fila++) {
        for (int columna = y-2; columna < y+3; columna++) {
            if ((fila >= 0 && fila < tamano_tablero) && (columna >= 0 && columna < tamano_tablero)) {
                // printf("%d, %d\n", fila+1, columna+1);
                if ((tablero[fila][columna] == TARGETOCULTO2) || (tablero[fila][columna] == TARGETOCULTO3) || (tablero[fila][columna] == TARGETOCULTO4) || (tablero[fila][columna] == TARGETOCULTO5)) {
                    printf("ATENCIÓN: EL MISÍL RADAR HA DETECTADO UN POSIBLE AVISTAMIENTO DE FLOTA ENEMIGA EN (%d, %d)\n", columna+1, fila+1);
                    bool_avistamiento = 1;
                }
            }
        }
    }
    if (bool_avistamiento == 0) {
        printf("ATENCIÓN: EL MISÍL RADAR NO HA DETECTADO ACTIVIDAD DE FLOTA ENEMIGA EN UN RADIO DE 5x5 DESDE (%d, %d)\n", x+1, y+1);
    }
    return NULL;
}

void* disparo500KG(int x, int y){
    int bool_hit = 0;
    for (int fila = x-5; fila < x+6; fila++) {
        for (int columna = y-5; columna < y+6; columna++) {
            if ((fila >= 0 && fila < tamano_tablero) && (columna >= 0 && columna < tamano_tablero)) {
                // printf("%d, %d\n", fila+1, columna+1);
                if (tablero[fila][columna] == NULL) {
                    tablero[fila][columna] = TARGETFALLADO;
                } else if ((tablero[fila][columna] == TARGETOCULTO2) || (tablero[fila][columna] == TARGETOCULTO3) || (tablero[fila][columna] == TARGETOCULTO4) || (tablero[fila][columna] == TARGETOCULTO5)) {
                    tablero[fila][columna] = TARGETACERTADO;
                    bool_hit = 1;
                    counter_barcos++;
                }
            }
        }
    }
    if (bool_hit == 0) {
        printf("MISS!\n");
    } else {
        printf("ULTRA HIT!\n");
    }
    return NULL;
}