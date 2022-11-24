#include "Filemanager.hpp"
#include "Lists.h"



FileManager::FileManager() {
	
}

std::map<std::string,std::string> FileManager::readFileCSV(std::string filePath){
	
	List::simple<std::map<std::string,std::string>> lista;
	std::string row = "";
	std::string data = "";
	std::map<std::string,std::string> mapa;
	std::string keys[] = {"Apellido","Nombre","Cedula","Sueldo","Cargo","HS","HE"};
	this->file.open(filePath);
	
	if(file.fail()){
		std::cout<<"Imposible abrir el archivo";
		std::exit(1);
	}
	int i(0);
	while(std::getline(this->file,row)){
		i = 0;
		std::stringstream dataProcess(row);
		
		while(std::getline(dataProcess,data,',')){
			mapa[keys[i]] = data;
			i+=1;
		}
		
		lista.push_back(mapa);
		
	}
	
	//lista.print_list();
	
	return mapa;
}
