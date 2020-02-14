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
	vector<string> split(string s, char delim){
		istringstream iss(s);
		vector<string> result;
		string token;
		while(getline(iss, token, delim)){
			result.push_back(token);
		}
	}

	void addStudent(std::string n, std::string sn, std::string snumber, std::string crecord){
		for(int i = 0; i < studentData.size(); i++){
			//check if student already exists in database
			if (studentData[i].studentNumber == snumber){
				cout << "Student " << snumber << " already exists in database... updating data.." << endl;
				//update info
				studentData[i].name = n;
				studentData[i].surname = sn;
				studentData[i].classRecord = crecord; 
			}
			else{
				//add new student
				StudentRecord newstudent;
				newstudent.name = n;
				newstudent.surname = sn;
				newstudent.studentNumber = snumber;
				newstudent.classRecord = crecord;
				studentData.push_back(newstudent);	
				cout << "Student " << snumber << " added to database." << endl;
			}
		}
	}	
	void readDatabase(std::string filename){
		ifstream in(filename);
		string st;
		char delim =',';
		while (getline(in, st)){
			vector<string> data = split(st, delim);
			addStudent(data[0], data[1], data[2], data[3]);
		}	
	}
	void saveDatabase(std::string filename){

	}
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
