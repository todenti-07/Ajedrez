#include "const.h"

void juegoJugable(char tablero[TABLERO][TABLERO]) {
	int respuestaPiezaCInicial, respuestaPiezaFInicial;
	int respuestaPiezaCFinal, respuestaPiezaFFinal;
	bool juegoAcabado = false;
	bool esTurnoJ1 = true;

	std::cout << "\nInicia el jugador de piezas blancas. Indica la posición de la pieza que quieras mover: (columna, fila)" << std::endl;
	while (!juegoAcabado) {
		while (esTurnoJ1) { //Jugador 1
			std::cin >> respuestaPiezaCInicial;
			std::cin >> respuestaPiezaFInicial;
			std::cout << "Indica la posición a la que quieres que se mueva la pieza: (columna, fila)";
			std::cin >> respuestaPiezaCFinal;
			std::cin >> respuestaPiezaFFinal;
			// Ajuste de índices para el tablero.
			// Se tiene que limitar al jugador para que no pueda mover piezas del oponente.
			// Se tiene que limitar al jugador para que pueda mover las piezas a las posiciones posibles.
			tablero[respuestaPiezaCFinal][respuestaPiezaFFinal] = tablero[respuestaPiezaCInicial][respuestaPiezaFInicial];
			tablero[respuestaPiezaCInicial][respuestaPiezaFInicial] = VACIO;
			esTurnoJ1 = false;
		}
		while (!esTurnoJ1) { //Jugador 2
			std::cin >> respuestaPiezaCInicial;
			std::cin >> respuestaPiezaFInicial;
			std::cout << "Indica la posición a la que quieres que se mueva la pieza: (columna, fila)";
			std::cin >> respuestaPiezaCFinal;
			std::cin >> respuestaPiezaFFinal;
			// Ajuste de índices para el tablero.
			// Se tiene que limitar al jugador para que no pueda mover piezas del oponente.
			// Se tiene que limitar al jugador para que pueda mover las piezas a las posiciones posibles.
			tablero[8 - respuestaPiezaCFinal * -1][8 - respuestaPiezaFFinal * -1] = tablero[respuestaPiezaCInicial][respuestaPiezaFInicial];
			tablero[respuestaPiezaCInicial][respuestaPiezaFInicial] = VACIO;
			esTurnoJ1 = true;
		}
	}



}

int main() {
	char tablero[TABLERO][TABLERO] = {};

	inicializarTablero(tablero);

	mostrarTablero(tablero);

	juegoJugable(tablero);

	return 0;
}