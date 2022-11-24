#include <iostream>
#include "Menu.h"
#include "Lists.h"
#include "FileManager.hpp"

#include "TextTable.h"
#include <regex>
#include <string>
#include "main.h"

using namespace std;
 
//void menu(Lista* cuentas);
//void mostrarmenu();



int main()
{
	CircularLinkedList<int> listaCircular;
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
			FileManager f;
			std::map<std::string,std::string> mapaDatosEmpleados  = f.readFileCSV("emp.csv");

			TextTable tabla('-', '|', '+');

			crearEncabezado(mapaDatosEmpleados, tabla);

			for (auto const& x : mapaDatosEmpleados)
			{
				tabla.add(x.second);
			}
			tabla.endOfRow();
			cout << tabla;
			
			
			std::cin.ignore();
		}
            break;
		
        case 2: // ver roles
			std::cin.ignore();
    		
            break;
        case 3:{ //buscar usuario
			bool coincideRegex=false;
			string cedula("000000000");
			try{
				while (!coincideRegex) {
					system("cls");
					cout << "Ingrese Cedula:";
					cin >> cedula;
					if (regex_match(string(cedula), regex("^[0-9]{10}$"))) {
						cout << "encontro";
						system("pause");
						coincideRegex = true;
					}
					else {
						cout << "repite";
						system("pause");
					}
				}
				cout << "Busqueda:";

				

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

void crearEncabezado(std::map<std::string, std::string>& mapa, TextTable& t)
{
	for (auto const& x : mapa)
	{
		t.add(x.first);
	}
	t.endOfRow();
}
