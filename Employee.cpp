#include "Employee.h"


Employee::Employee(){
	this->name = "not found";
	this->lastname =  "not found";
	this->salary = -1;
	this->nui = "not found";
	this->overtime = -1;
	this->sup_hours = -1;
	this->position = "not found";
}

void Employee::set_nui(std::string nui){
	this->nui = nui;
}

void Employee::set_name(std::string name){
	this->name = name;
}

void Employee::set_lastname(std::string lastname){
	this->lastname = lastname;
}

void Employee::set_salary(double salary){
	this->salary = salary;
}

std::string Employee::get_nui() {return this->nui;}

std::string Employee::get_name() {return this->name;}

std::string Employee::get_lastname() {return this->lastname;}

double Employee::get_salary() {return this->salary;} 