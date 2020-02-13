//database

#include "database.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

namespace STSCLA001{
	extern std::vector<StudentRecord> studentData;
	//function definitions
	void add_student(std::string name, std::string surname, std::string snumber, std::string crecord);
	void readDatabase(std::string filename);
	void saveDatabase(std::string filename);
	void displayData(std::string snumber);
	void gradeStudent(std::string snumber);
}
