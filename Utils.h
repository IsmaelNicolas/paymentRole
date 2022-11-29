#ifndef UTILS_H
#define UTILS_H

#include "Employee.h"
#include <string>
#include <iostream>
#include <regex>

class Utils
{
	public:
		static Employee get_data();
		static bool notValidID(std::string& _id);
		//static List::simple<Employee> deleteEmployee(Employee emp);
	private:
};

#endif