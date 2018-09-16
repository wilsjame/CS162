/*********************************************************************
** Program name: Student.cpp
** Author: James G Wilson (wilsjame)
** Date: 2/5/2017
** Description: Lab 4 CS 162
** This is the Student class definition file. The Student class is
** a child of the people class. A student has all the same traits
** a person with the addition of a GPA.
*********************************************************************/
#include "Student.hpp"
#include <cstdlib>	//using rand()
#include <iostream>
#include <random>

/*********************************************************************
** Description: constructor intitializes a random GPA  (4.0 - 0.) for 
** the student. Takes the students name
*********************************************************************/
Student::Student(std::string name) : People(name) //base constructor initialization
{
	this->name = name;

	//between 0.0 and 4.0
	double number = rand() % 40 + 0;
	this->gpa = number / 10;
}
	
/*********************************************************************
** Description: do_work is a virtual function of the parent class
** People. Takes a random int as a paramter that represents how
** many hours of homework they've done. It prints this value. 
** 
*********************************************************************/
//virtual function
void Student::do_work(int hours){
	std::cout << name << " did " << hours << " hours of homework.\n";
	//commented out per requirements
	//std::cout << "GPA: " << gpa << std::endl;
}
