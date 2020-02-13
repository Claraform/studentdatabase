//main program
#include <iostream>
#include <cstdlib>

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
	char select;	
	for (;;){
		STSCLA001::menu();
	
	std::cin >> select; //read user input for database option

	if (select == '0'){
		std::cout << "function addStudent() called" << std::endl;
	}
	else if(select == '1'){
		std::cout << "function readDatabase() called" << std::endl;
	}
	else if(select == '2'){
		std::cout << "function saveDatabase() called" << std::endl;
	}
	else if(select == '3'){
		std::cout << "function displayData() called" << std::endl;
	}
	else if(select == '4'){
		std::cout << "function gradeStudent() called" << std::endl;
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
	STSCLA001::clear();
	}
	return 0;
}
