#pragma once

#include "Consola.h"

class Menu
{

private:
	Consola pantalla;
public: 
	int hacerMenu(string message, string* option, int index);
	int subMenu(string* option, int index);
};

