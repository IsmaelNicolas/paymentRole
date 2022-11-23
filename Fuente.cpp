#include "Fuente.h"

string Fuente::formatoDeTexto(string texto, int color, int resaltado,
    bool negrita, bool subrayado,
    bool cursiva, bool invertir)
{

    string cadena = " \033[" + to_string(color) + ";" + to_string(resaltado);
    
    if (negrita) cadena += ";" + to_string(NEGRITA);

    if (subrayado) cadena += ";" + to_string(SUBRAYADO);

    if (cursiva) cadena += ";" + to_string(CURSIVA);

    if (invertir) cadena += ";" + to_string(INVERTIDO);


    cadena += "m" + texto + " \033[0m";

    return cadena;

}

string Fuente::aMinusculas(string cadena) {
    for (int i = 0; i < cadena.length(); i++) cadena[i] = tolower(cadena[i]);
    return cadena;
}