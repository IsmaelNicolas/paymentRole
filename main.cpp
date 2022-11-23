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
    string opcMenu[] = {"Crear Usuario","Ver roles de pago","Buscar Usuario","Salir"};
    string SubMenuTransacciones[] = {"Retiro","Deposito","Atras"};
    string SubMenuMostrar[] = { "Ver usuario","Eliminar usuario","Modificar usuario","Atras" };

    do
    {   
        opcion = menu.hacerMenu("Rol de pago", opcMenu, 4);

        switch (opcion)
        {
        case 1: // Crear

            break;

        case 2: // ver roles

    
            break;
        case 3:{ //buscar usuario
			string cedula("000000000");
			try{
				system("cls");
				cout<<"Ingrese Cedula:";
				cin>>cedula;
			}catch(...){
								
			}
            transaccion = menu.hacerMenu("Usuario", SubMenuMostrar, 4);
		}
            break;
		
        default:
            system("cls");
            break;
        }

    } while (opcion > 0 && opcion <4);
    
    
    

}
