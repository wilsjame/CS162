/*********************************************************************
** Program name: People.cpp
** Author: James G Wilson (wilsjame)
** Date: 2/5/2170
** Description: Lab 4 CS 162
** This is People class definition file. The people class represents
** students and instructors involved with the university. Students
** and instructors are child classes of the base class People. 
*********************************************************************/
#include "People.hpp"
#include <cstdlib>	//using rand()
#include <iostream>

/*********************************************************************
** Description: default constructor creates an empty student. No
** arguments and no return value
*********************************************************************/
People::People(){
	name = "";
	age = 0;
}

/*********************************************************************
** Description: constructor takes a string and sets the
** persons name. Randomly the sets the persons age  
*********************************************************************/
People::People(std::string name){
	this->name = name;
	age = (rand() % (71 - 18)) + 18;
}

/*********************************************************************
** Description: printName prints the name of the person. Take no
** arguments and returns no value
*********************************************************************/
void People::printName(){
	std::cout << name;
}

/*********************************************************************
** Description: do_work is a virtual function takes hours as an int
** and sets the value. No return value
*********************************************************************/
//virtual continues on through all derived classes
void People::do_work(int hours){
	this->hours = hours;
}




	




