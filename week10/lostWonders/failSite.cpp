/*********************************************************************
** Program name: Project 5 (Text-based Game)
** Filename: failSite.cpp 
** Author: James G Wilson (wilsjame)
** Date: 3/20/2017
** Description: CS 162
** FailSite class definition file
*********************************************************************/
#include "failSite.hpp"
#include <iostream>
/*********************************************************************
** Description: default constructor
** Arguments: none
** Returns: none
*********************************************************************/
FailSite::FailSite()
{
}
/*********************************************************************
** Description: prompts user to play again
** Arguments: none
** Returns: null pointer to a location
*********************************************************************/
Location* FailSite::run()
{
	this->displayLocation();
	return nullptr;
}
