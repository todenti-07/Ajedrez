#include <iostream>
#include "const.h"

// Buscamos la posición del rey
void buscarRey(char tablero[TABLERO][TABLERO], char rey, Coordenadas& posRey) {
    for (int i = 0; i < TABLERO; i++) {
        for (int j = 0; j < TABLERO; j++) {
            if (tablero[i][j] == rey) {
                posRey.x = i;
                posRey.y = j;
                return;
            }
        }
    }
}

bool casillaAmenazada(char tablero[TABLERO][TABLERO], Coordenadas pos, bool reyBlanco) {
    for (int i = 0; i < TABLERO; i++) {
        for (int j = 0; j < TABLERO; j++) {
            char pieza = tablero[i][j];

            // Piezas negras amenazan rey blanco
            if (reyBlanco) {
                if (pieza >= 'a' && pieza <= 'z') {
                    if ((i == pos.x || i == pos.x + 1 || i == pos.x - 1) &&
                        (j == pos.y || j == pos.y + 1 || j == pos.y - 1)) {
                        return true;
                    }
                }
            }

            // Piezas blancas amenazan rey negro
            if (!reyBlanco) {
                if (pieza >= 'A' && pieza <= 'Z') {
                    if ((i == pos.x || i == pos.x + 1 || i == pos.x - 1) &&
                        (j == pos.y || j == pos.y + 1 || j == pos.y - 1)) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

// Comprobar jaque mate
bool jaqueMate(char tablero[TABLERO][TABLERO], bool reyBlanco) {
    char rey;
    if (reyBlanco) {
        rey = REY_BLAN;
    }
    else {
        rey = REY_NEGR;
    }

    Coordenadas posRey;
    buscarRey(tablero, rey, posRey);

    // Si el rey no está amenazado, no hay jaque mate
    if (!casillaAmenazada(tablero, posRey, reyBlanco)) {
        return false;
    }

    //Revisa todas las casillas que esten cerca del rey. Está parte esta hecha con IA!!
    for (int desplazX = -1; desplazX <= 1; desplazX++) {
        for (int desplazY = -1; desplazY <= 1; desplazY++) {
            if (desplazX == 0 && desplazY == 0) continue; // misma casilla del rey

            int MoverReyX = posRey.x + desplazX;
            int MoverReyY = posRey.y + desplazY;

            if (MoverReyX >= 0 && MoverReyX < TABLERO && MoverReyY >= 0 && MoverReyY < TABLERO) {
                Coordenadas nuevaPos = { MoverReyX, MoverReyY };
                if (!casillaAmenazada(tablero, nuevaPos, reyBlanco)) {
                    return false; // Puede escapar
                }
            }
        }
    }

    return true;
}