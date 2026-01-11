#include "const.h"

void inicializarTablero(char tablero[TABLERO][TABLERO]) {
	for (int i = 0; i < TABLERO; i++) {
		for (int j = 0; j < TABLERO; j++) {
			tablero[i][j] = VACIO;
			if (i == 1) {
				tablero[i][j] = PEON_NEGR; // Peones Negros
			}
			else if (i == 6) {
				tablero[i][j] = PEON_BLAN; // Peones Blancos
			}
		}
	}

	for (int i = 0; i < 8; i++) {

		// Fila 0: piezas negras
		if (i == 0 || i == 7) tablero[0][i] = TORRE_NEGR;        // 't'
		else if (i == 1 || i == 6) tablero[0][i] = CABALLO_NEGR; // 'h'
		else if (i == 2 || i == 5) tablero[0][i] = ALFIL_NEGR;   // 'b'
		else if (i == 3) tablero[0][i] = REINA_NEGR;               // 'q'
		else if (i == 4) tablero[0][i] = REY_NEGR;                 // 'k'

		// Fila 7: piezas blancas
		if (i == 0 || i == 7) tablero[7][i] = TORRE_BLAN;        // 'T'
		else if (i == 1 || i == 6) tablero[7][i] = CABALLO_BLAN; // 'H'
		else if (i == 2 || i == 5) tablero[7][i] = ALFIL_BLAN;   // 'B'
		else if (i == 3) tablero[7][i] = REINA_BLAN;               // 'Q'
		else if (i == 4) tablero[7][i] = REY_BLAN;                 // 'K'
	}

}

void mostrarTablero(char tablero[TABLERO][TABLERO]) {
	std::cout << "  ";
	for (int i = 1; i < TABLERO + 1; i++) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	for (int i = TABLERO; i > 0; i--) {
		std::cout << i << " ";

		for (int j = 0; j < TABLERO; j++) {
			std::cout << tablero[i - 1][j] << " ";
		}
		std::cout << std::endl;
	}
}
