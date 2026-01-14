#include "const.h"
#include "movimientosVerificados.h"

bool esPiezaPropia(char pieza, bool blancas) {
	if (blancas) return pieza >= 'A' && pieza <= 'Z';
	else return pieza >= 'a' && pieza <= 'z';
}

bool esPiezaRival(char pieza, bool blancas) {
	if (blancas) return pieza >= 'a' && pieza <= 'z';
	else return pieza >= 'A' && pieza <= 'Z';
}

bool movimientoPeonValido(char tablero[TABLERO][TABLERO], int sx, int sy, int dx, int dy, bool blancas) {
	int direccion = blancas ? -1 : 1;
	int deltaX = dx - sx;
	int deltaY = dy - sy;

	if (deltaX == 0 && deltaY == direccion && tablero[dy][dx] == VACIO) {
		return true;
	}

	int filaInicial = blancas ? 6 : 1;
	if (sx == filaInicial && deltaX == 0 && deltaY == 2 * direccion &&
		tablero[sy + direccion][sx] == VACIO && tablero[dy][dx] == VACIO) {
		return true;
	}

	int capturaDiagX = (deltaX > 0) ? deltaX : -deltaX;
	if (capturaDiagX == 1 && deltaY == direccion && esPiezaRival(tablero[dy][dx], blancas)) {
		return true;
	}

	return false;
}

bool movimientoTorreValido(char tablero[TABLERO][TABLERO], int sx, int sy, int dx, int dy, bool blancas) {
	if (sx != dx && sy != dy) return false;

	int stepX = (dx > sx) ? 1 : (dx < sx ? -1 : 0);
	int stepY = (dy > sy) ? 1 : (dy < sy ? -1 : 0);

	int x = sx + stepX;
	int y = sy + stepY;

	while (x != dx || y != dy) {
		if (tablero[y][x] != VACIO) return false;
		x += stepX;
		y += stepY;
	}

	char dest = tablero[dy][dx];
	if (esPiezaPropia(dest, blancas)) return false;

	return true;
}

bool movimientoAlfilValido(char tablero[TABLERO][TABLERO], int sx, int sy, int dx, int dy, bool blancas) {
	int deltaX = dx - sx;
	int deltaY = dy - sy;

	int absX = (deltaX > 0) ? deltaX : -deltaX;
	int absY = (deltaY > 0) ? deltaY : -deltaY;

	if (absX != absY) return false;

	int stepX = (dx > sx) ? 1 : -1;
	int stepY = (dy > sy) ? 1 : -1;

	int x = sx + stepX;
	int y = sy + stepY;

	while (x != dx || y != dy) {
		if (tablero[y][x] != VACIO) return false;
		x += stepX;
		y += stepY;
	}

	char dest = tablero[dy][dx];
	if (esPiezaPropia(dest, blancas)) return false;

	return true;
}

bool movimientoCaballoValido(char tablero[TABLERO][TABLERO], int sx, int sy, int dx, int dy, bool blancas) {
	int deltaX = dx - sx;
	int deltaY = dy - sy;

	int absX = (deltaX > 0) ? deltaX : -deltaX;
	int absY = (deltaY > 0) ? deltaY : -deltaY;

	if (!((absX == 2 && absY == 1) || (absX == 1 && absY == 2))) return false;

	char dest = tablero[dy][dx];
	if (esPiezaPropia(dest, blancas)) return false;

	return true;
}

bool movimientoReinaValido(char tablero[TABLERO][TABLERO], int sx, int sy, int dx, int dy, bool blancas) {
	int deltaX = dx - sx;
	int deltaY = dy - sy;

	int absX = (deltaX > 0) ? deltaX : -deltaX;
	int absY = (deltaY > 0) ? deltaY : -deltaY;

	if (sx != dx && sy != dy && absX != absY) return false;

	int stepX = (dx > sx) ? 1 : (dx < sx ? -1 : 0);
	int stepY = (dy > sy) ? 1 : (dy < sy ? -1 : 0);

	int x = sx + stepX;
	int y = sy + stepY;

	while (x != dx || y != dy) {
		if (tablero[y][x] != VACIO) return false;
		x += stepX;
		y += stepY;
	}

	char dest = tablero[dy][dx];
	if (esPiezaPropia(dest, blancas)) return false;

	return true;
}

bool movimientoReyValido(char tablero[TABLERO][TABLERO], int sx, int sy, int dx, int dy, bool blancas) {
	int deltaX = dx - sx;
	int deltaY = dy - sy;

	int absX = (deltaX > 0) ? deltaX : -deltaX;
	int absY = (deltaY > 0) ? deltaY : -deltaY;

	if (absX > 1 || absY > 1) return false;
	if (absX == 0 && absY == 0) return false;

	char dest = tablero[dy][dx];
	if (esPiezaPropia(dest, blancas)) return false;

	return true;
}

void comprobarMovimientoCualquiera(char tablero[TABLERO][TABLERO], Coordenadas& posInicial, Coordenadas& posFinal, bool esTurnoJ1) {
	int ix = -1, iy = -1;

	// Validar coordenadas iniciales
	while (posInicial.x < 1 || posInicial.x > TABLERO || posInicial.y < 1 || posInicial.y > TABLERO) {
		std::cout << "Coordenadas fuera del tablero! Vuelve a escribir (columna, fila): ";
		std::cin >> posInicial.x >> posInicial.y;
	}

	ix = posInicial.x - 1;
	iy = posInicial.y - 1;

	// Validar que sea pieza propia
	char pieza = tablero[iy][ix];
	bool esPropiaValida = esTurnoJ1 ? esPiezaPropia(pieza, true) : esPiezaPropia(pieza, false);

	while (!esPropiaValida) {
		std::cout << "No puedes mover las piezas del oponente! Elige otra pieza (columna, fila): ";
		std::cin >> posInicial.x >> posInicial.y;

		while (posInicial.x < 1 || posInicial.x > TABLERO || posInicial.y < 1 || posInicial.y > TABLERO) {
			std::cout << "Coordenadas fuera del tablero! Vuelve a escribir (columna, fila): ";
			std::cin >> posInicial.x >> posInicial.y;
		}

		ix = posInicial.x - 1;
		iy = posInicial.y - 1;
		pieza = tablero[iy][ix];
		esPropiaValida = esTurnoJ1 ? esPiezaPropia(pieza, true) : esPiezaPropia(pieza, false);
	}

	// Validar coordenadas finales
	while (posFinal.x < 1 || posFinal.x > TABLERO || posFinal.y < 1 || posFinal.y > TABLERO) {
		std::cout << "Coordenadas finales fuera del tablero! Vuelve a escribir (columna, fila): ";
		std::cin >> posFinal.x >> posFinal.y;
	}
}