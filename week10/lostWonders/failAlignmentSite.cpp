/*********************************************************************
** Program name: Project 5 (Text-based Game)
** Filename: failAlignmentSite.cpp 
** Author: James G Wilson (wilsjame)
** Date: 3/20/2017
** Description: CS 162
** FailAlignmentSite class definition file
*********************************************************************/
#include "failAlignmentSite.hpp"
#include <iostream>
/*********************************************************************
** Description: default constructor
** Arguments: none
** Returns: none
*********************************************************************/
FailAlignmentSite::FailAlignmentSite()
{
	this->setImageFile("./images/cosmos.txt");
	std::string failLore= 
		"The cosmos have misaligned and the artifacts vanish.\n";

	this->setLore(failLore);
}
