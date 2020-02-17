//Main program for database
//Created by Clara Esther Stassen
//STSCLA001
//For CSC3022F Assignment 1

#include <iostream>
#include <cstdlib>
#include "database.h"

namespace STSCLA001{
	void clear(void){
		system("clear");
	}

	void menu (){
		std::cout << "0: Add student" << std::endl;
		std::cout << "1: Read database" << std::endl;
		std::cout << "2: Save database" << std::endl;
		std::cout << "3: Display given student data" << std::endl;
		std::cout << "4: Grade student" << std::endl;
		std::cout << "q: Quit" << std::endl;
		std::cout << "Enter a number (or q to quit) and press return..." << std::endl;
	}


}

int main(){
	std::string name, surname, sn, cr, fname;
	char select;	
	for (;;){
		STSCLA001::menu();
		std::cin >> select; //read user input for database option
		STSCLA001::clear();
		if (select == '0'){
			std::getline(std::cin, name); //clears input
			std::cout << "function addStudent() called" << std::endl;
			std::cout << "Enter student's first name(s):" << std::endl;
			//std::cin >> name;
			std::getline(std::cin, name);
			std::cout << "Enter student's last name:" << std::endl;
			//std::cin >> surname;
			std::getline(std::cin, surname);
			std::cout << "Enter student number:" << std::endl;
			//std::cin >> sn;
			std::getline(std::cin, sn);
			std::cout << "Enter student's class record:" << std::endl;
			std::getline(std::cin, cr);
			STSCLA001::addStudent(name, surname, sn, cr);
		}
		else if(select == '1'){
			std::cout << "function readDatabase() called" << std::endl;
			std::cout << "Enter filename to read from:" << std::endl;
			std::cin >> fname;
			STSCLA001::readDatabase(fname);
		}
		else if(select == '2'){
			std::cout << "function saveDatabase() called" << std::endl;
			std::cout << "Enter filename to save to:" << std::endl;
			std::cin >> fname;
			STSCLA001::saveDatabase(fname);
		}
		else if(select == '3'){
			std::cout << "function displayData() called" << std::endl;
			std::cout << "Enter a student number:" << std::endl;
			std::cin >> sn;
			STSCLA001::displayData(sn);
		}
		else if(select == '4'){
			std::cout << "function gradeStudent() called" << std::endl;
			std::cout << "Enter a student number:" << std::endl;
			std::cin >> sn;
			STSCLA001::gradeStudent(sn);
		}
		else if(select == 'q'){
			std::cout << "Program exiting..." << std::endl;
			break;
		}
		else{
			std::cout << "Invalid option... exiting" << std::endl;
			//system exits
			break;
		}
			}
	return 0;
}
