#include "Menu.h"
#include "Consola.h"
#include <conio.h>
#include "Fuente.h"

int Menu::hacerMenu(string mensaje, string* opciones, int indice) {

    Fuente fnt;
    pantalla.ajustarVentana(800,100);
    int seleccion = 1;
    int tecla;
    bool bandera = true;
    int x(5),y(2);
    
    do {
        system("cls");
        //CONSOLE_TEXTMODE_BUFFER;
        pantalla.gotoxy(x, y);
        cout <<fnt.formatoDeTexto(mensaje,fnt.COLOR.ROJO,49,true,true) << endl;
        //pantalla.gotoxy(20, 14);
        //cout << (char)175;

        for (int i = 0; i < indice; i++) {
            if (seleccion == i + 1) {
                
                pantalla.gotoxy(x+10, y+2 + i);

                cout <<  fnt.formatoDeTexto(*(opciones+i),fnt.COLOR.GRIS_CLARO,fnt.RESALTADOR.AZUL,true) <<endl;
            }
            else {
                
                pantalla.gotoxy(x+11, y+2 + i);
                cout << *(opciones + i);
            }
        }

        do {
            tecla = _getch();
        } while (tecla != ARRIBA && tecla != ABAJO && tecla != ENTER);

        switch (tecla) {
        case ARRIBA:
            seleccion--;
            if (seleccion <= 0) {
                seleccion = indice;
            }
            break;
        case ABAJO:
            seleccion++;
            if (seleccion > indice) {
                seleccion = 1;
            }
            break;
        case ENTER:
            bandera = false;
            break;
        }

    } while (bandera);
    
    return seleccion;

}
