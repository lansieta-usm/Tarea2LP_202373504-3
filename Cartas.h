#ifndef H_CARTAS
#define H_CARTAS

#define CANONROTO ((void *)1)
#define DISPAROSIMPLE ((void *)111)
#define DISPAROGRANDE ((void *)112)
#define DISPAROLINEAL ((void *)113)
#define DISPARORADAR ((void *)114)
#define DISPARO500KG ((void *)115)
// Estas definiciones ayudan a hacer una mejor identificación de las funciones void de disparos y si un cañón está roto

typedef struct Mano
{
    void ** carta;
    int disponibles;
} Mano;

extern int eleccion_carta_copia;
extern int counter_barcos;

extern Mano Cartas;
void inicializarMazo();
void mostrarMazo();
void actualizarMazo();
void usarCarta();

void * disparoSimple(int x, int y);
void * disparoGrande(int x, int y);
void * disparoLineal(int x, int y);
void * disparoRadar(int x, int y);
void * disparo500KG(int x, int y);

#endif