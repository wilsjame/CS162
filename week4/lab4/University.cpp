/*********************************************************************
** Program name: University.cpp 
** Author: James G Wilson (wilsjame)
** Date: 2/6/2017
** Description: Lab4 CS 162
** This is the unviersity class definition file. It represents a 
** single university that has buildings and people. Where People is
** a parent class with students and instructors as children.
*********************************************************************/
#include "University.hpp"
#include <iostream>
#include <string>
#include <memory> //using smart pointers
#include <limits>

/*********************************************************************
** Description: constructor that is passed a string for the university's
** name, a vector of shared pointers to People, and a vector of shared
** pointers to Buildinds. Its thates these arguments and sets them
** as private members.
*********************************************************************/
University::University(std::string name, const std::vector<std::shared_ptr<People>>& persons, const std::vector<std::shared_ptr<Buildings>>& buildings)
{
	this->name = name;
	this->persons = persons;
	this->buildings = buildings;
}

/*********************************************************************
** Description: printBuildings prints the building information. It has
** no return value and no takes no arguments
*********************************************************************/
void University::printBuildings(){
	std::cout << "------" << name << " Building Information -----";
	for(int i = 0; i < buildings.size(); i++)
	{
		std::cout << std::endl;
		buildings[i]->getName();
		std::cout << std::endl;
		//commented out per requirements
		//buildings[i]->getArea();
		//std::cout << std::endl;
		buildings[i]->getAddress();
		std::cout << std::endl;
	}
}

/*********************************************************************
** Description: printPeople prints the peoples names. It has
** no return value and takes no requirements
*********************************************************************/
void University::printPeople(){
	int randomNum = (rand() % (10 - 0)) + 0;

	std::cout << "----- People Information -----\n";
	for(int i = 0; i < persons.size(); i++)
	{
		persons[i]->printName();
		std::cout << std::endl;
		//commented out per requirements
		//persons[i]->do_work(randomNum);
	}
}

/*********************************************************************
** Description: choosePerson lets the user choose which person to 
** make do work. No arguments and no return value
*********************************************************************/
void University::choosePerson(){
	bool valid = false;
	bool leftBound = false;
	bool rightBound = false;
	int choice;
	int randomNum = (rand() % (10 - 0)) + 0;

	std::cout << "Choose a person to do work by entering";
	std::cout << " their number from the list\n";

	for(int i = 0; i < persons.size(); i++)
	{
		std::cout << i + 1 << ". ";
		persons[i]->printName();
		std::cout << std::endl;
	}
	
	while(valid == false){
		std::cout << "Enter your choice within the range: ";
		while(!(std::cin >> choice)){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Wrong input, please enter a number: ";
		}

		if(choice > 0){
			leftBound = true;}
		else{
			leftBound = false;}
		if(choice < persons.size() + 1){
			rightBound = true;}
		else{
			rightBound = false;}
		if(leftBound == true && rightBound == true){
			valid = true;}
	}
	
	

	std::cout << "----- Work Summary ----- ";
	std::cout << std::endl;
	persons[choice - 1]->do_work(randomNum);
}

