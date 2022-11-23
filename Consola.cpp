#include "Consola.h"

Consola::Consola() {
    SetConsoleTitle("MiniBank");
    ocultarCursor();
}

void Consola::ocultarCursor() {

    CONSOLE_CURSOR_INFO cci = { 100, FALSE }; // El segundo miembro de la estructura indica si se muestra el cursor o no.

    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);

}

void Consola::mostrarCursor() {

    CONSOLE_CURSOR_INFO cci = { 100, TRUE }; // El segundo miembro de la estructura indica si se muestra el cursor o no.

    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);

}

void Consola::gotoxy(int x, int y) {

    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);

}

void Consola::ajustarVentana(int ancho,int alto) {

    _COORD size;
    _SMALL_RECT rect;
    size.X = ancho;
    size.Y = alto;

    rect.Top = 0;
    rect.Left = 0;
    rect.Right = ancho - 1;
    rect.Bottom = alto - 1;

    HANDLE _console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleScreenBufferSize(_console, size);
    SetConsoleWindowInfo(_console, TRUE, &rect);

}

void Consola::cambiarColor(int texto, int fondo) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD wColor = ((fondo & 0x0F) << 4) + (texto & 0x0F); 
    SetConsoleTextAttribute(h, wColor);
}