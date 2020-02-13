//database
//code to convert a string to an int adapted from techiedelight.com

#include "database.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

namespace STSCLA001{
	vector<StudentRecord> studentData;
	//function definitions
	void add_student(std::string name, std::string surname, std::string snumber, std::string crecord);
	void readDatabase(std::string filename);
	void saveDatabase(std::string filename);
	void displayData(std::string snumber){
		for(int i = 0; i < studentData.size(); i++){
			if (studentData[i].studentNumber == snumber){				
				StudentRecord match = studentData[i];
				cout << "Data for student " << match.studentNumber << ":" << endl;
				cout << "Full Name: " << match.name << " " << match.surname << endl;
				cout << "Grades: " << match.classRecord << endl;
			}
		}	
	}
	void gradeStudent(std::string snumber){
		for(int i = 0; i < studentData.size(); i++){
			if (studentData[i].studentNumber == snumber){				
				string grades = studentData[i].classRecord;
				istringstream iss(grades);
				string temp;
				string delim = " ";
				vector<string> grades_split;
				while (!iss.eof()){
					iss >> temp;
					grades_split[i] = temp;
				}
				int gradeSum = 0;
				for (int i = 0; i < grades_split.size(); i++){
					try{
						int a = stoi(grades_split[i]);
						gradeSum = gradeSum + a;
					}
					catch (invalid_argument const &e)
					{
						cout << "Bad input: std::invalid_argument thrown" << '\n';
					}
					catch (out_of_range const &e)
					{
						cout << "Integer overflow: std::out_of_range thrown" << '\n';
					}
				}

				int gradeAve = gradeSum / grades_split.size();
			}
		}
	}
}
