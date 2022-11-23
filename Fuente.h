#pragma once

#include "Color.h"
#include "Resaltador.h"
#include <string>

using namespace std;

class Fuente
{
public:
	Color COLOR;
	Resaltador RESALTADOR;
	const int NEGRITA = 1;
	const int CURSIVA = 3;
	const int SUBRAYADO = 4;
	const int INVERTIDO = 7;
	string aMinusculas(string);
	string formatoDeTexto(string texto, int color = 39, int resaltado = 49,
							bool negrita = false, bool subrayado = false,
							bool cursiva = false, bool invertir = false);

};