/*********************************************************************
** Program name: main.cpp
** Author: James G Wilson (wilsjame)
** Date: 2/6/2017
** Description: Lab 4 CS 162
** This is main program for Lab 4, A University info system that stores
** and displays information about the buildings, students, and 
** instructors.
**
** Use the accompanying Makefile to create an executable file called,
** main. Run main to begin using the program! 
**
*********************************************************************/
#include "University.hpp"
#include "Student.hpp"
#include "Instructor.hpp"
#include <iostream>
#include <string>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <limits>


int main()
{
	std::string universityName = "Oregon State University";

	int choice;
	int seed;
	seed = time(0);
	srand(seed);

	//create a vector of shared pointers to People objects
	std::vector<std::shared_ptr<People>> persons
	{
		std::make_shared<Student> ("Tony Huynh"),
		std::make_shared<Instructor> ("Emma Watson")
	};

	//create a vector of shared pointers to Buildings objects
	std::vector<std::shared_ptr<Buildings>> buildings
	{
		std::make_shared<Buildings> ("Rogers Hall", 53710, "2000 SW Monroe Ave Corvallis, OR 97331"),
		std::make_shared<Buildings> ("Sackett Hall", 137517, "2901 SW Jefferson way, Corvallis, OR 97331")
	};

	//create university object
	University OSU(universityName, persons, buildings);

	//			-------MENU-------
	while(true){
		std::cout << "1) Prints Names of all the buildings\n";
		std::cout << "2) Prints names of everybody at the university\n";
		std::cout << "3) Choose a person to do work\n";
		std::cout << "4) Exit the program\n";

		//error handling
		while(!(std::cin >> choice)){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Wrong input, please enter a number: ";
		}

		switch(choice){
			case 1:
				OSU.printBuildings();
				break;
			case 2:
				OSU.printPeople();
				break;
			case 3:
				OSU.choosePerson();
				break;
			case 4:
				return 0;
			default:
				std::cout << "invalid choice\n";
		}
	}
	return 0;
}


