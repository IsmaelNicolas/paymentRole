#include <iostream>
#include "Menu.h"
#include "FileManager.hpp"

#include "TextTable.h"
#include "Utils.h"
#include <regex>
#include <string>

using namespace std;

//void menu(Lista* cuentas);
//void mostrarmenu();

int main()
{
	CircularLinkedList<int> listaCircular;
	Menu menu;
	int opcion, transaccion;
	string opcMenu[] = { "Crear Usuario","Ver roles de pago","Buscar Usuario","Salir" };
	string SubMenuTransacciones[] = { "Retiro","Deposito","Atras" };
	string SubMenuMostrar[] = { "Ver usuario","Eliminar usuario","Modificar usuario","Atras" };

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
			std::cin.ignore();

		}
			  break;

		case 2: {// ver roles
			FileManager f;
			List::simple<Employee> l = f.readFileCSV("emp.csv");
			system("cls");
			l.print_list();
			std::cin.ignore();
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
					if (!l.buscarCedula(cedula)) {
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
			transaccion = menu.hacerMenu("Usuario", SubMenuMostrar, 4);
		}
			  break;

		default:
			system("cls");
			break;
		}

	} while (opcion > 0 && opcion < 4);




}

void crearEncabezado(std::map<std::string, std::string>& mapa, TextTable& t)
{
	for (auto const& x : mapa)
	{
		t.add(x.first);
	}
	t.endOfRow();
}
