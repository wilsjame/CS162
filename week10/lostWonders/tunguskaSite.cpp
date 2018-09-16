/*********************************************************************
** Program name: Project 5 (Text-based Game)
** Filename: tunguskaSite.cpp 
** Author: James G Wilson (wilsjame)
** Date: 3/20/2017
** Description: CS 162
** TunguskaSite derived class definition file
*********************************************************************/
#include "tunguskaSite.hpp"
/*********************************************************************
** Description: default constructor
** Arguments: none
** Returns: none
*********************************************************************/
TunguskaSite::TunguskaSite()
{
	this->setImageFile("./images/tunguska.txt");

	this->setLore("Tunguska Site");
	this->activateArrivalState();
	this->setArtifact(TUNGUSKA);
}
/*********************************************************************
** Description: excavate artifact
** Arguments: none
** Returns: none
*********************************************************************/
void TunguskaSite::activateArrivalState()
{
	std::string arrivalLore = "You touch base in Tunguska, Siberia";


	std::string choice_one = "Dig";

	this->arrival.setDescription(arrivalLore);
	this->arrival.addInfo(1, choice_one, FIND_ARTIFACT);
		
}

