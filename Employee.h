#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "consts.hpp"
#include <iostream>
#include <string>

class Employee
{
	public:
		//friend class Node<T>;
		//constructor		
		Employee();
		//setter 
		void set_nui(std::string);
		void set_name(std::string);
		void set_lastname(std::string); 
		void set_salary(double);
		void set_position(std::string);
		void set_overtime(double);
		void set_sup_hours(double);
		void setAdvance(double);
		//getter
		std::string get_nui();
		std::string get_name();
		std::string get_lastname();
		std::string get_position();
		double get_overtime();
		double get_sup_hours(); 
		double get_salary();
		//methods
		friend std::ostream &operator <<(std::ostream&out,const Employee &emp){
			out<<std::endl<<"{"<<std::endl;
			out<<"	name: "<<emp.name<<","<<std::endl;
			out<<"	lastname: "<<emp.lastname<<","<<std::endl;
			out<<"	nui: "<<emp.nui<<","<<std::endl;
			out<<"	salary: $"<<emp.salary<<","<<std::endl;
			out<<"	position: "<<emp.position<<","<<std::endl;
			out<<"	overtime: $"<<emp.overtime<<","<<std::endl;
			out<<"	supplementary hours: $"<< emp.sup_hours<<","<<std::endl;
			out<<"}";
			return out;
		}
		void calculateIessIncome();
		void calculateReserveFund();
		void calculateTotalIncome();
		void calculateIess();		
		void calculateTotalOutput();
		void calculateToRecieve();
	public:
		std::string nui;
		std::string name;
		std::string lastname;
		std::string position;
		double salary;
		double sup_hours;
		double overtime;
		double totalIncomeIess;
		double reserveFund;
		double totalIncome;
		double iess;
		double advance;
		double totalOutput;
		double toRecieve;

		
};

#endif