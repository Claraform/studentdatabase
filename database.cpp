//Database source code
//Created by Clara Esther Stassen
//STSCLA001
//For CSC3022F Assignment 1

#include "database.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

namespace STSCLA001{
	vector<StudentRecord> studentData;
	//function to split a string by a delimiter
	vector<string> split(string s, char delim){
		istringstream iss(s);
		vector<string> result;
		string token;
		while(getline(iss, token, delim)){
			result.push_back(token);
		}
		return result;
	}
	//checks whether class record is numerical
	bool digitsOnly(string c){
		//return !c.empty() && all_of(c.begin(), c.end(), ::isdigit);
		return (c.find_first_not_of("0123456789") == string::npos);
	}
	//check whether student data is valid
	bool checkValid(StudentRecord s){
		if (s.studentNumber == "" || s.name == "" || s.surname == ""){
			return false;
		}
		string grades = s.classRecord;
		istringstream iss(grades);
		int gradeSum;
		string temp;
		while (getline(iss, temp, ' ')){
			if(!digitsOnly(temp)){
				return false;
			}
			else if (stoi(temp) > 100 || stoi(temp) < 0){
				return false;
			}	
		}
		return true;
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
				return;
			}
		}
		//create new student
		StudentRecord newstudent;
		newstudent.name = n;
		newstudent.surname = sn;
		newstudent.studentNumber = snumber;
		newstudent.classRecord = crecord;
		if (checkValid(newstudent)){
			//if student data valid, add to database
			studentData.push_back(newstudent);	
			cout << "Student " << snumber << " added to database." << endl;
		}
		else{
			cout << "Invalid student data - not added to database" << endl;
		}
	}

	void readDatabase(string filename){
		studentData.clear();
		ifstream in(filename);
		string st;
		char delim =',';
		if (!in){
			cout << "Failed to open file" << endl;
			return;
		}
		while (in){
			getline(in, st, '\n');
			if (st == ""){
				//ignore end of file
				return;
			}
			vector<string> data = split(st, delim);
			StudentRecord s;
			s.name = data[0];
			s.surname = data[1];
			s.studentNumber = data[2];
			s.classRecord = data[3];
			bool duplicate;
			//check whether student data is a duplicate
			for (int i = 0; i < studentData.size(); i++){
				if (studentData[i].studentNumber == s.studentNumber){
					duplicate = true;
					cout << "Duplicate data for " << s.studentNumber << " found, updating information" << endl;
					studentData[i].classRecord = s.classRecord;
					studentData[i].name = s.name;
					studentData[i].surname = s.surname;		
				}
			}
			if (checkValid(s) && !duplicate){ 
				//if student data valid and not a duplicate, add to database
				studentData.push_back(s);
			}
			//addStudent(data[0], data[1], data[2], data[3]);
		}
		in.close();	
	}
	void saveDatabase(string filename){
		ofstream ofs;
		ofs.open(filename);
		for (int i = 0; i < studentData.size(); i++){
			StudentRecord s = studentData[i];
			ofs << s.name << "," << s.surname << "," << s.studentNumber << "," << s.classRecord << endl;
		}
		ofs.close();
	}

	void displayData(string snumber){
		for(int i = 0; i < studentData.size(); i++){
			if (studentData[i].studentNumber == snumber){				
				StudentRecord match = studentData[i];
				cout << "Data for student " << match.studentNumber << ":" << endl;
				cout << "Full Name: " << match.name << " " << match.surname << endl;
				cout << "Grades: " << match.classRecord << endl;
				return;
			}
		}
		cout << "No data found for student " << snumber << endl;
	}
	void gradeStudent(string snumber){
		for(int i = 0; i < studentData.size(); i++){
			if (studentData[i].studentNumber == snumber){
				string grades = studentData[i].classRecord;
				istringstream iss(grades);
				int counter=0;
				int gradeSum=0;
				string temp;
				while (getline(iss, temp, ' ')){
					counter++; //tracks how many grade items student has
					gradeSum = gradeSum + stoi(temp); //sums up all grade items
				}
				int gradeAve = gradeSum/counter;
				cout << "Grade average for " << snumber << " is: " << gradeAve << "%" <<endl;
				return;
			}
		}
		cout << "No data found for student " << snumber << endl;
	}

}
