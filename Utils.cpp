#include "Utils.h"

Employee Utils::get_data(){
	
	Employee emp;
	std::string str_data;
	std::cout<<"Cedula: ";
	std::cin>>str_data; emp.set_nui(str_data);
	//validar cedula y ver si existe
	str_data= "";
	std::cout<<"\nApellido: ";
	std::cin>>str_data; emp.set_lastname(str_data);
	str_data= "";
	std::cout<<"\nNombre: ";
	std::cin>>str_data; emp.set_name(str_data);
	str_data= "";
	std::cout<<"\nCargo: ";
	std::cin>>str_data; emp.set_position(str_data);
	
	
	return emp;
}