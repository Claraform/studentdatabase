#ifndef DATABASE_H
#define DATABASE_H

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
	void add_student(std::string name, std::string surname, std::string snumber, std::string crecord);
	void readDatabase(std::string filename);
	void saveDatabase(std::string filename);
	void displayData(std::string snumber);
	void gradeStudent(std::string snumber);
}
#endif
