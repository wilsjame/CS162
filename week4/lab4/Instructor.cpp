/*********************************************************************
** Program name: Instructor.cpp
** Author: James G Wilson (wilsjame)
** Date: 2/5/2017
** Description: Lab 4 CS 162
** This is the Instructor class definition file. The instructor class
** is a child of the peoeple class. An instructor has all the same
** traits as a person with the addition of an instructor rating
*********************************************************************/
#include "Instructor.hpp"
#include <cstdlib>	//using rand()
#include <iostream>

/*********************************************************************
** Description: constructor initializes a random instructor rating
** (5.0 - 0.0) for the instructor. Takes the instructors name
*********************************************************************/
Instructor::Instructor(std::string name) : People(name) //base constructor
{
	this->name = name;

	//between 0.0 and 5.0
	double number = rand() % 50 + 0;
	this->rating = number / 10;
}

/*********************************************************************
** Description: do_work is a virtual function of the parent class 
** People. Takes a random int as a parameter that represents how 
** many hours of homework they've done. It prints this value.
*********************************************************************/
//virtual function
void Instructor::do_work(int hours){
	std::cout << name << " graded papers for " << hours <<" hours.\n";
	//commented out per requirements
	//std::cout << "Rating: " << rating << std::endl;
}


