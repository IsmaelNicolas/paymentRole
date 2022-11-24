#include <iostream>
#include "Menu.h"
#include "Lists.h"
#include "FileManager.hpp"

using namespace std;
 
//void menu(Lista* cuentas);
//void mostrarmenu();

using namespace std;

int main()
{
	CircularLinkedList<int> l;
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
        case 1:{ // Crear
        	system("cls");
        	
			l.insertEnd(1);
			l.insertEnd(2);
			l.insertEnd(4);
			l.insertEnd(3);
			l.printList();
			
			FileManager f;
			std::map<std::string,std::string> mapa  = f.readFileCSV("emp.csv");
			
			for (auto const& x : mapa)
			{
			    std::cout << x.first  // string (key)
			              << ':' 
			              << x.second // string's value 
			              << std::endl;
			}
			
			
			std::cin.ignore();
		}
            break;
		
        case 2: // ver roles
			std::cin.ignore();
    		
            break;
        case 3:{ //buscar usuario
			string cedula("000000000");
			try{
				system("cls");
				cout<<"Ingrese Cedula:";
				cin>>cedula;
			}catch(...){
				cout<<"Cedula incorrecta";			
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
