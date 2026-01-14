#include "const.h"
#include "tableroRelacion.h"
#include "juegoRelacion.h"

int main() {
    char tablero[TABLERO][TABLERO];

    inicializarTablero(tablero);

    juegoJugable(tablero);

    return 0;
}