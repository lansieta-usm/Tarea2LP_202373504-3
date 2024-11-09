#ifndef H_TABLERO
#define H_TABLERO

#define TARGETFALLADO ((void *)11)
#define TARGETACERTADO ((void *)10)
#define TARGETOCULTO2 ((void *)22)
#define TARGETOCULTO3 ((void *)33)
#define TARGETOCULTO4 ((void *)44)
#define TARGETOCULTO5 ((void *)55)
#define TARGET2 ((void *)2)
#define TARGET3 ((void *)3)
#define TARGET4 ((void *)4)
#define TARGET5 ((void *)5)
// Estas definiciones ayudan a hacer una mejor identificación a cada slot del tablero

extern void *** tablero;
extern int tamano_tablero;
extern int total_barcos;

void inicializarTablero(int tamano);
void generarBarcos(int tamano, int dificultad);
void mostrarTablero();
void mostrarTableroFinal();

#endif
