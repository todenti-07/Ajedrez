#include <iostream>

#define TABLERO 8
#define VACÍO '*'

int main (){
	char tablero[TABLERO][TABLERO] = {};

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
	return 0;
}