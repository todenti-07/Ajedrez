#pragma once
#include <iostream>

#define TABLERO 8
#define VACIO '*'

#define PEON_BLAN 'P'
#define TORRE_BLAN 'T'
#define CABALLO_BLAN 'H'
#define ALFIL_BLAN 'B'
#define REINA_BLAN 'Q'
#define REY_BLAN 'K'

#define PEON_NEGR 'p'
#define TORRE_NEGR 't'
#define CABALLO_NEGR 'h'
#define ALFIL_NEGR 'b'
#define REINA_NEGR 'q'
#define REY_NEGR 'k'

void inicializarTablero(char tablero[TABLERO][TABLERO]);
void mostrarTablero(char tablero[TABLERO][TABLERO]);
