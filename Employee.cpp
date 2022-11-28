#include "Employee.h"
#include <stdlib.h>
#include <time.h>
#include <random>
#include <iomanip>
#define FLOAT_MIN 1
#define FLOAT_MAX 100


Employee::Employee(){
	
	srand(time(NULL));
	this->name = "not found";
	this->lastname = "not found";
	this->salary = -1;
	this->nui = "not found";
	this->overtime = FLOAT_MIN + (float)(rand()) / ((float)(RAND_MAX / (FLOAT_MAX - FLOAT_MIN)));
	this->sup_hours = FLOAT_MIN + (float)(rand()) / ((float)(RAND_MAX / (FLOAT_MAX - FLOAT_MIN)));
	this->position = "not found";
	this->totalIncome = -1;
	this->iess = -1;
	this->advance = FLOAT_MIN + (float)(rand()) / ((float)(RAND_MAX / (FLOAT_MAX - FLOAT_MIN)));
	this->totalOutput = -1;
	this->toRecieve = -1;
	
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

void Employee::set_overtime(double overtime){
	this->overtime = overtime;
}

void Employee::set_sup_hours(double salary){
	this->sup_hours = sup_hours;
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

std::string Employee::get_position(){return this->position;}

double Employee::get_salary() {return this->salary;} 

double Employee::get_overtime(){return this->overtime;}

double Employee::get_sup_hours(){return this->sup_hours;}



