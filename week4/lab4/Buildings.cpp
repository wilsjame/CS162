/*********************************************************************
** Program name: Buildings.cpp
** Author: James G Wilson (wilsjame)
** Date: 2/5/2017
** Description: Lab 4 CS 162
** This is the buildings class definition file. It will be used with 
** the university class. Each building will have a name, sq footage,
** and address. The buildings are all university buildings
*********************************************************************/
#include "Buildings.hpp"
#include <iostream>

/*********************************************************************
** Description: default constructor sets all the private members
** to NULL values. No arguments and no return value
*********************************************************************/
Buildings::Buildings(){
	name = "";
	size = 0;
	address = "";
}

/*********************************************************************
** Description: construtor gets a string, integer, and string 
** passed to it to initialize the name, size, and address of the
** building
*********************************************************************/
Buildings::Buildings(std::string name, int size, std::string address){
	this->name = name;
	this->size = size;
	this->address = address;
}

/*********************************************************************
** Description: getName prints the building the name. No argument
** and no return value
*********************************************************************/
void Buildings::getName(){
	std::cout << "Building Name: " << name;
}

/*********************************************************************
** Description: getArea prints the building square footage. No argument
** and no return value
*********************************************************************/
void Buildings::getArea(){
	std::cout << "Area: " << size << " sq ft";
}

/*********************************************************************
** Description: getAddress prints the building address. No argument
** and no return value
*********************************************************************/
void Buildings::getAddress(){
	std::cout << "Address: " << address;
}
