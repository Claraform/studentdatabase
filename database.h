#ifndef DATABASE_H
#define DATABASE_H
#include <string>
#include <vector>

namespace STSCLA001{
	struct StudentRecord{
		std::string name;
		std::string surname;
		std::string studentNumber;
		std::string classRecord;
	};
	//Global vector of Student Records
	extern std::vector<StudentRecord> studentData;
	//function definitions
	std::vector<std::string> split(std::string s, char delim);
	bool digitsOnly(std::string c);
	bool checkValid(STSCLA001::StudentRecord s);
	void addStudent(std::string n, std::string sn, std::string snumber, std::string crecord);
	void readDatabase(std::string filename);
	void saveDatabase(std::string filename);
	void displayData(std::string snumber);
	void gradeStudent(std::string snumber);
}
#endif
