#include "Utils.h"
#include "FileManager.hpp"

Employee Utils::get_data(){
	
    Employee emp;
    std::string str_data;
    bool incorrectID = true;
    bool IdExists = true;
    FileManager f;
    List::simple<Employee> l = f.readFileCSV("emp.csv");
    while (!incorrectID || IdExists) {
        system("cls");
        std::cout << "Cedula: ";
        std::cin >> str_data;
        std::cin.ignore();
        emp.set_nui(str_data);
        incorrectID = !notValidID(str_data);
        if (l.buscarCedula(str_data)) {
            system("cls");
            std::cout << "Cedula existente ingresa una nueva" << std::endl;
            system("pause");
            IdExists = true;
        }
        else {
            IdExists = false;
        }
    }
    str_data = "";
	std::cout<<"\nApellido: ";
	std::cin>>str_data; emp.set_lastname(str_data);
	str_data= "";
	std::cout<<"\nNombre: ";
	std::cin>>str_data; emp.set_name(str_data);
	str_data= "";
	std::cout<<"\nCargo: ";
	std::cin>>str_data; emp.set_position(str_data);
	
    bool sueldoCorrecto = false;
    while (!sueldoCorrecto) {
        str_data= "";
        std::cout<<"\nSueldo: ";
        std::cin>>str_data; 
        if (!regex_match(std::string(str_data), std::regex("^[0-9]*\.[0-9]{2}$"))) {
            std::cout << "Sueldo invalido (ej: 29.30)" << std::endl;
            system("pause");
            system("cls");
        }
        else {
            sueldoCorrecto = true;
        }
    }
        emp.set_salary(std::stod(str_data));
	
	return emp;
}

bool Utils::notValidID(std::string& _id)
{
    if (!regex_match(std::string(_id), std::regex("^[0-9]{10}$"))) {
        std::cout << "Cedula invalida" << std::endl;
        system("pause");
        return true;
    }

    int temp;
    int sum_par = 0;
    int sum_impar = 0;
    int sum;

    int i = 1;
    std::string digits = _id.substr(0, _id.size() - 1);
    for (char& c : digits)
    {
        int digit = c - '0';
        if (i % 2 == 0) {
            sum_par += digit;
        }
        else {
            if ((digit * 2) > 9)
            {
                sum_impar += (digit * 2) - 9;
            }
            else
            {
                sum_impar += (digit * 2);
            }
        }
        i++;
    }

    sum = sum_par + sum_impar;
    int verifier = _id.at(_id.size() - 1) - '0';
    int higher = (10 - (sum % 10)) + sum;

    if (sum % 10 == 0)
    {
        return verifier != 0;
    }
    if ((higher - sum) == verifier) {
        return false;
    }
    else {
        std::cout << "\nLa cedula ingresada es invalida" << std::endl;
        system("pause");
        return true;
    }
    
}

/*
List::simple<Employee> Utils::deleteEmployee(Employee emp){
	
	FileManager f;
    List::simple<Employee> l = f.readFileCSV("emp.csv");
	Node<Employee>* tmp = l.get_node();
	l.print_list();
	while(tmp->next != NULL){
		if(emp == tmp->data ){
			//std::cout<<"eliminando: \n"<<emp;
			l.erase(emp);
			std::cout<<"Eliminado correctamente.."<<std::endl;
			return;
		}
		tmp = tmp->next;
	}
	
	std::cout<<"No se pudo eliminar"<<std::endl;
	
}
*/

