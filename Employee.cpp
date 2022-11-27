#include "Employee.h"


Employee::Employee(){
	this->name = "not found";
	this->lastname =  "not found";
	this->salary = -1;
	this->nui = "not found";
	this->overtime = -1;
	this->sup_hours = -1;
	this->position = "not found";
	this->totalIncome = -1;
	this->iess=-1;
	this->advance=-1;
	this->totalOutput=-1;
	this->toRecieve=-1;
	
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

void Employee::set_position(std::string position){
	this->position =position;
}

void Employee::calculateIessIncome(){
	this->totalIncomeIess=this->salary+this->sup_hours;
}

void Employee::calculateReserveFund(){
	this->reserveFund=this->totalIncomeIess*reserveFundConst;
}

void Employee::calculateTotalIncome(){
	this->totalIncome=this->totalIncomeIess+this->reserveFund;
}

void Employee::calculateIess(){
	this->iess=this->totalIncomeIess*iessConst;
}

void Employee::calculateTotalOutput(){
	this->totalOutput=this->iess+this->advance;
}

void Employee::calculateToRecieve(){
	this->toRecieve =this->totalIncome-this->totalOutput;
}

std::string Employee::get_nui() {return this->nui;}

std::string Employee::get_name() {return this->name;}

std::string Employee::get_lastname() {return this->lastname;}

double Employee::get_salary() {return this->salary;} 