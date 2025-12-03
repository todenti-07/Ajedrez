#include <iostream>

#define TABLERO 8
#define VACÍO '*'

#define PEÓN_BLAN 'P'
#define TORRE_BLAN 'T'
#define CABALLO_BLAN 'H'
#define ALFIL_BLAN 'B'
#define REINA_BLAN 'Q'
#define REY_BLAN 'K'

#define PEÓN_NEGR 'p'
#define TORRE_NEGR 't'
#define CABALLO_NEGR 'h'
#define ALFIL_NEGR 'b'
#define REINA_NEGR 'q'
#define REY_NEGR 'k'

void inicializarTablero(char tablero[TABLERO][TABLERO]) {
	for (int i = 0; i < TABLERO; i++) {
		for (int j = 0; j < TABLERO; j++) {
			tablero[i][j] = VACÍO;
			if (i == 1) {
				tablero[i][j] = 'p'; // Peones Negros
			}
			else if (i == 6) {
				tablero[i][j] = 'P'; // Peones Blancos
			}
		}
	}
	tablero[0][0] = TORRE_NEGR;
	tablero[0][1] = CABALLO_NEGR;
	tablero[0][2] = ALFIL_NEGR;
	tablero[0][3] = REINA_NEGR;
	tablero[0][4] = REY_NEGR;
	tablero[0][5] = ALFIL_NEGR;
	tablero[0][6] = CABALLO_NEGR;
	tablero[0][7] = TORRE_NEGR;

	tablero[7][0] = TORRE_BLAN;
	tablero[7][1] = CABALLO_BLAN;
	tablero[7][2] = ALFIL_BLAN;
	tablero[7][3] = REINA_BLAN;
	tablero[7][4] = REY_BLAN;
	tablero[7][5] = ALFIL_BLAN;
	tablero[7][6] = CABALLO_BLAN;
	tablero[7][7] = TORRE_BLAN;
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

int main() {
	char tablero[TABLERO][TABLERO] = {};

	inicializarTablero(tablero);

	mostrarTablero(tablero);

	return 0;
}