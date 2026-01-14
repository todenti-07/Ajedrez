#pragma once

#include "const.h"

bool movimientoPeonValido(char tablero[TABLERO][TABLERO], int sx, int sy, int dx, int dy, bool blancas);

bool movimientoTorreValido(char tablero[TABLERO][TABLERO], int sx, int sy, int dx, int dy, bool blancas);

bool movimientoAlfilValido(char tablero[TABLERO][TABLERO], int sx, int sy, int dx, int dy, bool blancas);

bool movimientoCaballoValido(char tablero[TABLERO][TABLERO], int sx, int sy, int dx, int dy, bool blancas);

bool movimientoReinaValido(char tablero[TABLERO][TABLERO], int sx, int sy, int dx, int dy, bool blancas);

bool movimientoReyValido(char tablero[TABLERO][TABLERO], int sx, int sy, int dx, int dy, bool blancas);

void comprobarMovimientoCualquiera(char tablero[TABLERO][TABLERO], Coordenadas& posInicial, Coordenadas& posFinal, bool esTurnoJ1);

bool esPiezaPropia(char pieza, bool blancas);

bool esPiezaRival(char pieza, bool blancas);