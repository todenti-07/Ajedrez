#include <iostream>
#include "const.h"
#include "movimientosVerificados.h"

void comprobarMovimientoCualquiera(char tablero[TABLERO][TABLERO], Coordenadas posInicial, Coordenadas posFinal, bool esTurnoJ1) {
	// Ajuste de índices para el tablero.
	while (posFinal.x <= 8 || posFinal.x > 0) {
		std::cout << "Ese número no se encuentra en el tablero!";
		std::cin >> posFinal.x;
	}
	while (posFinal.y <= 8 || posFinal.y > 0) {
		std::cout << "Ese número no se encuentra en el tablero!";
		std::cin >> posFinal.y;
	}
	// Se tiene que limitar al jugador para que no pueda mover piezas del oponente. 
	while (tablero[posInicial.x][posInicial.y] < 'A' || tablero[posInicial.x][posInicial.y] > 'Z') {
		std::cout << "No puedes mover las piezas del oponente! Elige otra pieza: (columna, fila)";
		std::cin >> posInicial.x;
		std::cin >> posInicial.y;
	}
	// Se tiene que limitar al jugador para que pueda mover las piezas a las posiciones posibles.
	while (tablero[posFinal.x][8 - posFinal.y * -1] != VACIO) {
		std::cout << "No puedes mover la pieza a esa posición! Elige otra posición: (columna, fila)";
		std::cin >> posFinal.x;
		std::cin >> posFinal.y;
	}
}

void juegoJugable(char tablero[TABLERO][TABLERO]) {

	Coordenadas posInicial, posFinal;
	bool juegoAcabado = false;
	bool esTurnoJ1 = true;

	std::cout << "\nInicia el jugador de piezas blancas. Indica la posición de la pieza que quieras mover: (columna, fila)" << std::endl;
	while (!juegoAcabado) {
		while (esTurnoJ1) { //Jugador 1
			std::cin >> posInicial.x;
			std::cin >> posInicial.y;
			std::cout << "Indica la posición a la que quieres que se mueva la pieza: (columna, fila)";
			std::cin >> posFinal.x;
			std::cin >> posFinal.y;
			comprobarMovimientoCualquiera(tablero, posInicial, posFinal, esTurnoJ1);
			tablero[posFinal.x][8 - posFinal.y * -1] = tablero[posInicial.x][posInicial.y];
			tablero[posInicial.x][posInicial.y] = VACIO;
			esTurnoJ1 = false;
		}
		while (!esTurnoJ1) { //Jugador 2
			std::cin >> posInicial.x;
			std::cin >> posInicial.y;
			std::cout << "Indica la posición a la que quieres que se mueva la pieza: (columna, fila)";
			std::cin >> posFinal.x;
			std::cin >> posFinal.y;
			comprobarMovimientoCualquiera(tablero, posInicial, posFinal, esTurnoJ1);
			tablero[posFinal.x][8 - posFinal.y * -1] = tablero[posInicial.x][posInicial.y];
			tablero[posInicial.x][posInicial.y] = VACIO;
			esTurnoJ1 = true;
		}
	}
}
