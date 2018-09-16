/*********************************************************************
** Program name: Project 5 (Text-based Game)
** Filename: stonehengeSite.cpp 
** Author: James G Wilson (wilsjame)
** Date: 3/20/2017
** Description: CS 162
** StonehengeSite derived class definition file
*********************************************************************/
#include "stonehengeSite.hpp"
/*********************************************************************
** Description: default constructor
** Arguments: none
** Returns: none
*********************************************************************/
StonehengeSite::StonehengeSite()
{
	this->setImageFile("./images/stonehenge.txt");

	this->setLore("Stonehenge Site");
	this->activateArrivalState();
	this->setArtifact(STONEHENGE);
}
/*********************************************************************
** Description: excavate artifact
** Arguments: none
** Returns: none
*********************************************************************/
void StonehengeSite::activateArrivalState()
{
	std::string arrivalLore = "You touch base in Stonehenge";


	std::string choice_one = "Dig";

	this->arrival.setDescription(arrivalLore);
	this->arrival.addInfo(1, choice_one, FIND_ARTIFACT);
}

