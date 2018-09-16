/*********************************************************************
** Program name: Project 5 (Text-based Game)
** Filename: easterIsleSite.cpp 
** Author: James G Wilson (wilsjame)
** Date: 3/20/2017
** Description: CS 162
** EasterIsleSite derived class definition file
*********************************************************************/
#include "easterIsleSite.hpp"
/*********************************************************************
** Description: default constructor
** Arguments: none
** Returns: none
*********************************************************************/
EasterIsleSite::EasterIsleSite()
{
	this->setImageFile("./images/easter_island.txt");

	this->setLore("Easter Island Site");
	this->activateArrivalState();
	this->setArtifact(EASTER_ISLE);
}
/*********************************************************************
** Description: excavate artifact
** Arguments: none
** Returns: none
*********************************************************************/
void EasterIsleSite::activateArrivalState()
{
	std::string arrivalLore = "You touch base in Easter Island";


	std::string choice_one = "Dig";

	this->arrival.setDescription(arrivalLore);
	this->arrival.addInfo(1, choice_one, FIND_ARTIFACT);
}
