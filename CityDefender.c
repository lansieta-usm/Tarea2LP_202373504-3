#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Cartas.h"
#include "Tablero.h"

int main(int argc, char const *argv[]) {
    srand(time(NULL));

    int dificultad, limite_turnos, tablero_size, turno_actual = 1, coordX, coordY;
    printf("------------------------------------------\n");
    printf("TE DAMOS LA BIENVENIDA A CITY DEFENDER 2.0\n");
    printf("------------------------------------------\n");
    printf("Selecciona la dificultad:\n");
    printf("1. Fácil -> 11 X 11, 5 Barcos, 30 Trunos.\n");
    printf("2. Medio -> 17 X 17, 7 Barcos, 25 Turnos.\n");
    printf("3. Difícil -> 21 X 21, 9 Barcos, 15 Turnos.\n");
    printf("Ingresa un número: ");
    scanf("%d", &dificultad);
    while (dificultad > 3) {
        printf("Selección inválida, ingresa un número del 1 al 3: ");
        scanf("%d", &dificultad);
    }
    inicializarMazo();
    // Se inicializan tablero y barcos acorde a la dificultad seleccionada
    if(dificultad == 1){
        tablero_size = 11;
        inicializarTablero(tablero_size);
        generarBarcos(tablero_size, dificultad);
        limite_turnos = 30;
    } else if (dificultad == 2) {
        tablero_size = 17;
        inicializarTablero(tablero_size);
        generarBarcos(tablero_size, dificultad);
        limite_turnos = 25;
    } else {
        tablero_size = 21;
        inicializarTablero(tablero_size);
        generarBarcos(tablero_size, dificultad);
        limite_turnos = 15;
    }
    // printf("Total barcos: %d\n", total_barcos);
    while(turno_actual <= limite_turnos){
        // printf("%d, %d\n", counter_barcos, total_barcos);
        if (counter_barcos >= total_barcos){
            break;
        }
        printf("Turno %d:\n", turno_actual);
        mostrarTablero();
        printf("Cartas:\n");
        mostrarMazo();
        usarCarta();
        printf("X: ");
        scanf("%d", &coordX);
        while (coordX > tablero_size) {
            printf("Coordenada inválida, reingresa X: ");
            scanf("%d", &coordX);
        }
        printf("Y: ");
        scanf("%d", &coordY);
        while (coordY > tablero_size) {
            printf("Coordenada inválida, reingresa Y: ");
            scanf("%d", &coordY);
        }
        // Se llama al disparo correspondiente a la elección de la carta
        // printf("%d\n", eleccion_carta_copia);
        // printf("(%d, %d)\n", coordY-1, coordX-1);
        if (Cartas.carta[eleccion_carta_copia] == DISPAROSIMPLE) {
            disparoSimple(coordY-1, coordX-1);
        } else if (Cartas.carta[eleccion_carta_copia] == DISPAROGRANDE) {
            disparoGrande(coordY-1, coordX-1);
        } else if (Cartas.carta[eleccion_carta_copia] == DISPAROLINEAL) {
            disparoLineal(coordY-1, coordX-1);
        } else if (Cartas.carta[eleccion_carta_copia] == DISPARORADAR) {
            disparoRadar(coordY-1, coordX-1);
        } else if (Cartas.carta[eleccion_carta_copia] == DISPARO500KG) {
            disparo500KG(coordY-1, coordX-1);
        }
        actualizarMazo();
        turno_actual++;
        //break;
    }
    
    if ((turno_actual > limite_turnos) && (counter_barcos < total_barcos)) {
        printf("GAME OVER\n");
        printf("Ya no hay más turnos :'v\n");
        printf("Tablero final:\n");
        mostrarTableroFinal();
    } else {
        printf("¡TODOS LOS BARCOS DESTRUIDOS, DEFENSA EXITOSA! :D\n");
        printf("Tablero final:\n");
        mostrarTableroFinal();
    }
    
    //printf("%d", dificultad);

    for (int i = 0; i < tamano_tablero; i++) {
        free(tablero[i]);
    }
    free(tablero);
    free(Cartas.carta);
    return 0;
}