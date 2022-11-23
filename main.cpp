#include <iostream>
#include "Menu.h"

using namespace std;
 
//void menu(Lista* cuentas);
//void mostrarmenu();

using namespace std;

int main()
{

    Menu menu;
    int opcion,transaccion;
    string opcMenu[] = {"Crear Cuenta","Movimientos","Mostrar","Salir"};
    string SubMenuTransacciones[] = {"Retiro","Deposito","Atras"};
    string SubMenuMostrar[] = { "Mostrar Cuentas","Buscar una cuenta","Atras" };

    do
    {   
        opcion = menu.hacerMenu("Mini-Bank", opcMenu, 4);

        switch (opcion)
        {
        case 1:

            break;

        case 2:

                transaccion = menu.hacerMenu("Realizar Trasaccion", SubMenuTransacciones, 3);
    
            break;
        case 3:

            transaccion = menu.hacerMenu("Mostrar Cuentas", SubMenuMostrar, 3);

            break;

        default:
            system("cls");
            break;
        }

    } while (opcion > 0 && opcion <4);
    
    
    

}
