/*********************************************************************
** Program name: Project 5 (Text-based Game)
** Filename: enlightenmentSite.cpp 
** Author: James G Wilson (wilsjame)
** Date: 3/20/2017
** Description: CS 162
** EnlightenmentSite class definition file
*********************************************************************/
#include "enlightenmentSite.hpp"
#include <iostream>
/*********************************************************************
** Description: default constructor
** Arguments: none
** Returns: none
*********************************************************************/
EnlightenmentSite::EnlightenmentSite()
{
	this->setImageFile("./images/enlightenment.txt");
	std::string enlightenment= 
		"You have been enlightened by the burning acacia tree.\n";

	this->setLore(enlightenment);
}
