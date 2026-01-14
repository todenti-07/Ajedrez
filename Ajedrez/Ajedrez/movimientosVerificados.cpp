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
		std::cout << "Movimiento no permitido para el peon blanco. Introduce de nuevo las coordenadas finales: \n";
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
		std::cout << "Movimiento no permitido para el peon negro. Introduce de nuevo las coordenadas finales: \n";
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

void verificarMovimientoAlfilN(char tablero[TABLERO][TABLERO], Coordenadas posInicial, Coordenadas posFinal) {
	
	for (int i = 0; i < TABLERO; i++) { // Horizontal
		for (int j = 0; j < TABLERO; j++) { // Vertical
			if (tablero[posInicial.x + j][posInicial.y + j] != '~' || tablero[posInicial.x - j][posInicial.y + j] != '~' || tablero[posInicial.x + j][posInicial.y - j] != '~' || tablero[posInicial.x - j][posInicial.y - j] != '~') {
				while (tablero[posInicial.x][posInicial.y] < 'a' || tablero[posInicial.x][posInicial.y] > 'z') {
					std::cout << "No puedes eliminar tus propias piezas! Elige otro movimiento: (columna, fila)";
					std::cin >> posFinal.x;
					std::cin >> posFinal.y;
				}
			}
		}
	}
}

void verificarMovimientoTorreB(char tablero[TABLERO][TABLERO], Coordenadas posInicial, Coordenadas posFinal) {
	
	if (posInicial.x != posFinal.x && posInicial.y != posFinal.y) {
		std::cout << "La torre solo se mueve en horitzontal o vertical.\n";
		return;
	}

	if (tablero[posFinal.x][posFinal.y] >= 'A' && tablero[posFinal.x][posFinal.y] <= 'Z') {
		std::cout << "No puedes eliminar tus propias piezas.\n";
		return; 
	}

	std::cout << "Movimiento valido!\n"; 
}

void verificarMovimientoTorreN(char tablero[TABLERO][TABLERO], Coordenadas posInicial, Coordenadas posFinal) {
	
	if (posInicial.x != posFinal.x && posInicial.y != posFinal.y) {
		std::cout << "La torre solo se mueve en horizontal o vertical.\n";
		return;
	}

	if (tablero[posFinal.x][posFinal.y] >= 'a' && tablero[posFinal.x][posFinal.y] <= 'z') {
		std::cout << "No puedes eliminar tus propias piezas.\n";
		return;
	}

	std::cout << "Movimiento valido!\n";
}

//Caballos hechos con IA!!
void verificarMovimientoCaballoB(char tablero[TABLERO][TABLERO], Coordenadas posInicial, Coordenadas posFinal) {

	int dx = abs(posFinal.x - posInicial.x);
	int dy = abs(posFinal.y - posInicial.y);

	if ((dx == 2 && dy == 1) || (dx == 1 && dy == 2)) {

		if (tablero[posFinal.x][posFinal.y] >= 'A' && tablero[posFinal.x][posFinal.y] <= 'Z') {
			std::cout << "No puedes eliminar tus propias piezas.\n";
		}
		else {
			std::cout << "Movimiento valido!\n";
		}
	}
	else {
		std::cout << "Movimiento invalido del caballo. Introduce nuevas coordenadas:\n";
		std::cin >> posFinal.x;
		std::cin >> posFinal.y;
		verificarMovimientoCaballoB(tablero, posInicial, posFinal);
	}
}

void verificarMovimientoCaballoN(char tablero[TABLERO][TABLERO], Coordenadas posInicial, Coordenadas posFinal) {

	int dx = abs(posFinal.x - posInicial.x);
	int dy = abs(posFinal.y - posInicial.y);

	if ((dx == 2 && dy == 1) || (dx == 1 && dy == 2)) {

		if (tablero[posFinal.x][posFinal.y] >= 'a' && tablero[posFinal.x][posFinal.y] <= 'z') {
			std::cout << "No puedes eliminar tus propias piezas.\n";
		}
		else {
			std::cout << "Movimiento valido!\n";
		}
	}
	else {
		std::cout << "Movimiento invalido del caballo. Introduce nuevas coordenadas:\n";
		std::cin >> posFinal.x;
		std::cin >> posFinal.y;
		verificarMovimientoCaballoN(tablero, posInicial, posFinal);
	}
}

void verificarMovimientoReinaB(char tablero[TABLERO][TABLERO], Coordenadas posInicial, Coordenadas posFinal) {

	if (posInicial.x == posFinal.x || posInicial.y == posFinal.y ||
		posFinal.x - posInicial.x == posFinal.y - posInicial.y || 
		posFinal.x - posInicial.x == -(posFinal.y - posInicial.y)) { 

		if (tablero[posFinal.x][posFinal.y] >= 'A' && tablero[posFinal.x][posFinal.y] <= 'Z') {
			std::cout << "No puedes eliminar tus propias piezas.\n";
		}
		else {
			std::cout << "Movimiento valido\n";
		}

	}
	else {
		std::cout << "Movimiento invalido de la reina.\n";
	}
}

void verificarMovimientoReinaB(char tablero[TABLERO][TABLERO], Coordenadas posInicial, Coordenadas posFinal) {

	if (posInicial.x == posFinal.x || posInicial.y == posFinal.y ||
		posFinal.x - posInicial.x == posFinal.y - posInicial.y ||
		posFinal.x - posInicial.x == -(posFinal.y - posInicial.y)) {

		if (tablero[posFinal.x][posFinal.y] >= 'a' && tablero[posFinal.x][posFinal.y] <= 'z') {
			std::cout << "No puedes eliminar tus propias piezas.\n";
		}
		else {
			std::cout << "Movimiento valido\n";
		}

	}
	else {
		std::cout << "Movimiento invalido de la reina.\n";
	}
}

void verificarMovimientoReyB(char tablero[TABLERO][TABLERO], Coordenadas posInicial, Coordenadas posFinal) {

	if ((posFinal.x == posInicial.x + 1 || posFinal.x == posInicial.x - 1 || posFinal.x == posInicial.x) &&
		(posFinal.y == posInicial.y + 1 || posFinal.y == posInicial.y - 1 || posFinal.y == posInicial.y)) {

		if (posFinal.x == posInicial.x && posFinal.y == posInicial.y) {
			std::cout << "Movimiento invalido del rey.\n";
		}
		else if (tablero[posFinal.x][posFinal.y] >= 'A' && tablero[posFinal.x][posFinal.y] <= 'Z') {
			std::cout << "No puedes eliminar tus propias piezas.\n";
		}
		else {
			std::cout << "Movimiento valido!\n";
		}
	}
	else {
		std::cout << "Movimiento invalido del rey. Introduce nuevas coordenadas:\n";
		std::cin >> posFinal.x;
		std::cin >> posFinal.y;
		verificarMovimientoReyB(tablero, posInicial, posFinal);
	}
}

void verificarMovimientoReyN(char tablero[TABLERO][TABLERO], Coordenadas posInicial, Coordenadas posFinal) {

	if ((posFinal.x == posInicial.x + 1 || posFinal.x == posInicial.x - 1 || posFinal.x == posInicial.x) &&
		(posFinal.y == posInicial.y + 1 || posFinal.y == posInicial.y - 1 || posFinal.y == posInicial.y)) {

		if (posFinal.x == posInicial.x && posFinal.y == posInicial.y) {
			std::cout << "Movimiento invalido del rey.\n";
		}
		else if (tablero[posFinal.x][posFinal.y] >= 'a' && tablero[posFinal.x][posFinal.y] <= 'z') {
			std::cout << "No puedes eliminar tus propias piezas.\n";
		}
		else {
			std::cout << "Movimiento valido!\n";
		}
	}
	else {
		std::cout << "Movimiento invalido del rey. Introduce nuevas coordenadas:\n";
		std::cin >> posFinal.x;
		std::cin >> posFinal.y;
		verificarMovimientoReyN(tablero, posInicial, posFinal);
	}
}
