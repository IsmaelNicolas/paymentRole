#include <fstream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <map>
#include "Employee.h"
#include "Lists.h"

class FileManager
{
	public:
		FileManager();
		List::simple<Employee> readFileCSV(std::string);
		void writeFileCSV(std::string,Employee);
		
	private:	
		std::fstream file;
		
};