#include <iostream>
#include <cstdlib>
#include "const.h"
#include "tableroRelacion.h"

void verificarMovimientoPeonB(char tablero[TABLERO][TABLERO], Coordenadas posInicial, Coordenadas posFinal) {
	
	if (posInicial.y == 7 && posInicial.y - 2 == posFinal.y || posInicial.y - 1 == posFinal.y) {
		std::cout << "Es posible el movimiento";
	}
	else if (posInicial.x - 1 != '~' && posFinal.y - 1 || posInicial.x + 1 != '~' && posFinal.y - 1) { // Captura diagonal
		std::cout << "Es posible el movimiento";
	}
	else {
		std::cout << "Movimiento no permitido para el peón blanco. Introduce de nuevo las coordenadas finales: \n";
		std::cin >> posFinal.x;
		std::cin >> posFinal.y;
		verificarMovimientoPeonB(tablero, posInicial, posFinal);
	}

}

void verificarMovimientoPeonN(char tablero[TABLERO][TABLERO], Coordenadas posInicial, Coordenadas posFinal) {
	if (posInicial.y == 2 && posInicial.y + 2 == posFinal.y || posInicial.y + 1 == posFinal.y) {
		std::cout << "Es posible el movimiento";
	}
	else if (posInicial.x - 1 != '~' && posFinal.y + 1 || posInicial.x + 1 != '~' && posFinal.y + 1) { // Captura diagonal
		std::cout << "Es posible el movimiento";
	}
	else {
		std::cout << "Movimiento no permitido para el peón negro. Introduce de nuevo las coordenadas finales: \n";
		std::cin >> posFinal.x;
		std::cin >> posFinal.y;
		verificarMovimientoPeonN(tablero, posInicial, posFinal);
	}
}

void verificarMovimientoAlfilB(char tablero[TABLERO][TABLERO], Coordenadas posInicial, Coordenadas posFinal) {
	
	for (int i = 0; i < TABLERO; i++) { // Horizontal
		for (int j = 0; j < TABLERO; j++) { // Vertical
			if (tablero[posInicial.x + j][posInicial.y + j] != '~' || tablero[posInicial.x - j][posInicial.y + j] != '~' || tablero[posInicial.x + j][posInicial.y - j] != '~' || tablero[posInicial.x - j][posInicial.y - j] != '~'){
				while (tablero[posInicial.x][posInicial.y] < 'A' || tablero[posInicial.x][posInicial.y] > 'Z') {
					std::cout << "No puedes eliminar tus propias piezas! Elige otro movimiento: (columna, fila)";
					std::cin >> posFinal.x;
					std::cin >> posFinal.y;
				}
			}
		}
	}

}