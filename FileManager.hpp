#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <map>


class FileManager
{
	public:
		FileManager();
		std::map<std::string,std::string> readFileCSV(std::string);
		void writeFileCSV(std::string);
		
	private:	
		std::fstream file;
		
};