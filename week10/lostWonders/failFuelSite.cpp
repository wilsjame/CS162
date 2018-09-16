/*********************************************************************
** Program name: Project 5 (Text-based Game)
** Filename: failFuelSite.cpp 
** Author: James G Wilson (wilsjame)
** Date: 3/20/2017
** Description: CS 162
** FailFuelSite class definition file
*********************************************************************/
#include "failFuelSite.hpp"
#include <iostream>
/*********************************************************************
** Description: default constructor
** Arguments: none
** Returns: none
*********************************************************************/
FailFuelSite::FailFuelSite()
{
	this->setImageFile("./images/crash.txt");
	std::string failLore= 
		"You're plane runs out of fuel and crashes.\n";

	this->setLore(failLore);
}
