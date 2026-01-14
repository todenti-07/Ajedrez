#include "const.h"
#include "tableroRelacion.h"
#include "movimientosVerificados.h"

void juegoJugable(char tablero[TABLERO][TABLERO]) {
	Coordenadas posInicial, posFinal;
	bool juegoAcabado = false;
	bool esTurnoJ1 = true;

	std::cout << "\nInicia el jugador de piezas blancas. Indica la posicion de la pieza que quieras mover: (columna, fila)" << std::endl;
	while (!juegoAcabado) {
		mostrarTablero(tablero);

		if (esTurnoJ1) {
			std::cout << "\nTurno BLANCAS. Indica (columna, fila) origen: ";
		}
		else {
			std::cout << "\nTurno NEGRAS. Indica (columna, fila) origen: ";
		}

		std::cin >> posInicial.x >> posInicial.y;
		std::cout << "Indica (columna, fila) destino: ";
		std::cin >> posFinal.x >> posFinal.y;

		comprobarMovimientoCualquiera(tablero, posInicial, posFinal, esTurnoJ1);

		int sx = posInicial.x - 1;
		int sy = posInicial.y - 1;
		int dx = posFinal.x - 1;
		int dy = posFinal.y - 1;

		char pieza = tablero[sy][sx];
		bool valido = false;

		switch (pieza) {
		case 'P':
			valido = movimientoPeonValido(tablero, sx, sy, dx, dy, true);
			break;
		case 'p':
			valido = movimientoPeonValido(tablero, sx, sy, dx, dy, false);
			break;
		case 'T':
			valido = movimientoTorreValido(tablero, sx, sy, dx, dy, true);
			break;
		case 't':
			valido = movimientoTorreValido(tablero, sx, sy, dx, dy, false);
			break;
		case 'H':
			valido = movimientoCaballoValido(tablero, sx, sy, dx, dy, true);
			break;
		case 'h':
			valido = movimientoCaballoValido(tablero, sx, sy, dx, dy, false);
			break;
		case 'B':
			valido = movimientoAlfilValido(tablero, sx, sy, dx, dy, true);
			break;
		case 'b':
			valido = movimientoAlfilValido(tablero, sx, sy, dx, dy, false);
			break;
		case 'Q':
			valido = movimientoReinaValido(tablero, sx, sy, dx, dy, true);
			break;
		case 'q':
			valido = movimientoReinaValido(tablero, sx, sy, dx, dy, false);
			break;
		case 'K':
			valido = movimientoReyValido(tablero, sx, sy, dx, dy, true);
			break;
		case 'k':
			valido = movimientoReyValido(tablero, sx, sy, dx, dy, false);
			break;
		}

		if (!valido) {
			std::cout << "Movimiento NO valido.\n";
			continue;
		}

		// Promocion del peon
		if ((pieza == 'P' && dy == 0) || (pieza == 'p' && dy == 7)) {
			pieza = (pieza == 'P') ? 'Q' : 'q';
		}

		tablero[dy][dx] = pieza;
		tablero[sy][sx] = VACIO;

		esTurnoJ1 = !esTurnoJ1;

		// Comprobar rey capturado
		bool reyBlancoVivo = false;
		bool reyNegroVivo = false;

		for (int i = 0; i < TABLERO; i++) {
			for (int j = 0; j < TABLERO; j++) {
				if (tablero[i][j] == 'K') reyBlancoVivo = true;
				if (tablero[i][j] == 'k') reyNegroVivo = true;
			}
		}

		if (!reyBlancoVivo) {
			std::cout << "\nJAQUE MATE! Ganan las NEGRAS.\n";
			juegoAcabado = true;
		}
		else if (!reyNegroVivo) {
			std::cout << "\nJAQUE MATE! Ganan las BLANCAS.\n";
			juegoAcabado = true;
		}
	}
}