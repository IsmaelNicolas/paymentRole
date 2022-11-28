#include "Filemanager.hpp"

FileManager::FileManager() {
	
}

List::simple<Employee> FileManager::readFileCSV(std::string filePath){
	
	Employee tmp;
	std::fstream file;
	List::simple<Employee> lista;
	std::string row = "";
	std::string data = "";

	std::string keys[] = {"Apellido","Nombre","Cedula","Sueldo","Cargo","HS","HE"};

	file.open(filePath);
	
	if(file.fail()){
		std::cout<<"Imposible abrir el archivo";
		std::exit(1);
	}
	
	while(std::getline(file,row)){
		
		std::stringstream dataProcess(row);
		
		std::getline(dataProcess,data,',');
		tmp.set_lastname(data);

		std::getline(dataProcess,data,',');
		tmp.set_name(data);

		std::getline(dataProcess,data,',');
		tmp.set_nui(data);
		
		std::getline(dataProcess,data,',');
		tmp.set_salary(std::stod(data));

		std::getline(dataProcess,data,',');
		tmp.set_position(data);
		
		std::getline(dataProcess,data,',');
		tmp.set_sup_hours(std::stod(data));

		std::getline(dataProcess,data,',');
		tmp.set_overtime(std::stod(data));

		lista.push_back(tmp);	
	}
	
	file.close();
	
	return lista;
}

void FileManager::writeFileCSV(std::string filePath,Employee emp){
	
	std::ofstream file;
	file.open(filePath,std::ios_base::app);
	
	file<< emp.get_lastname() << "," << emp.get_name() << "," << emp.get_nui() << "," << emp.get_salary() << "\n";
	
	file.close();
	
}
