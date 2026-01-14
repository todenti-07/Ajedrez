#include "const.h"
#include "jaqueMate.h"

bool jaqueMate(char tablero[TABLERO][TABLERO], bool esReyBlanco) {
	char rey = esReyBlanco ? 'K' : 'k';
	int reyX = -1, reyY = -1;

	// Encontrar posicion del rey
	for (int i = 0; i < TABLERO; i++) {
		for (int j = 0; j < TABLERO; j++) {
			if (tablero[i][j] == rey) {
				reyY = i;
				reyX = j;
				break;
			}
		}
		if (reyX != -1) break;
	}

	// Si no encuentra el rey, es jaque mate
	if (reyX == -1) return true;

	return false;
}