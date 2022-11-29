#include <iostream>
#include "Menu.h"
#include "FileManager.hpp"

#include "Utils.h"
#include <regex>
#include <string>

using namespace std;

int main()
{
	CircularLinkedList<int> listaCircular;
	Menu menu;
	int opcion, transaccion;
	string opcMenu[] = { "Crear Usuario","Ver roles de pago","Buscar Usuario","Salir" };
	string SubMenuMostrar[] = { "Ver usuario","Eliminar usuario","Atras" };
	Node<Employee>* busquedaEmp = nullptr;
	do
	{
		opcion = menu.hacerMenu("Rol de pago", opcMenu, 4);

		switch (opcion)
		{
		case 1: { // Crear
			system("cls");
			FileManager f;
			Employee emp = Utils::get_data();
			f.writeFileCSV("emp.csv", emp);
			std::cout<<emp;
			std::cin.ignore();
		}
		break;
		case 2: {
			FileManager f;
			List::simple<Employee> l = f.readFileCSV("emp.csv");
			system("cls");
			l.printTable();
			system("pause");
		}
		break;
		case 3: { //buscar usuario
			bool validData = false;
			std::string cedula("000000000");
			while (!validData) {
				system("cls");
				std::cout << "Ingrese Cedula:";
				std::cin >> cedula;
				if (regex_match(string(cedula), regex("^[0-9]{10}$"))) {
					validData = true;
					FileManager f;
					List::simple<Employee> l = f.readFileCSV("emp.csv");
					busquedaEmp = l.buscarCedula(cedula);
					if (!busquedaEmp) {
						std::cout << "no se encontro la cedula" << std::endl;
						system("pause");
						validData = false;
					}
				}
				else {
					std::cout << "repite";
					system("pause");
				}
			}
			std::cout << "Busqueda:";
			std::cin.ignore();
			transaccion = menu.hacerMenu("Usuario", SubMenuMostrar, 3);
			
			switch(transaccion){
				case 1:
					system("cls");
					std::cout << "Perfil" << std::endl;
					std::cout << busquedaEmp->data << endl;
					std::cin.ignore();
					break;
				case 2:{				
					system("cls");
					std::cout<<"Eliminando empleado:";
					std::cout<<busquedaEmp->data;
					FileManager f;
					f.eraseFileLine("emp.csv",busquedaEmp->data);
					
					std::cin.ignore();
					}
					break;
			}
	
		}
		break;
		default:
			system("cls");
			break;
		}

	} while (opcion > 0 && opcion < 4);




}

