#pragma once

#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include<string>
#include"Fuente.h"

#define ARRIBA     72
#define IZQUIERDA  75
#define DERECHA    77
#define ABAJO      80
#define ESC        27
#define ENTER      13

using namespace std;

class Consola
{

private:
    
public:
    void ocultarCursor();
    void cambiarColor(int,int fondo = 128);
    void mostrarCursor();
    void gotoxy(int x, int y);
    void ajustarVentana(int, int);
    Consola();
    
    enum Colores {
        Gris = 7,
        Azul = 1,
        Verde = 10,
        Cyan = 11,
        Rojo = 12,
        Morado = 13,
        Amarillo = 14,
        Blanco = 15
    };
    
    

};


