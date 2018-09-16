/*********************************************************************
** Program name: Project 5 (Text-based Game)
** Filename: gobekliTepeSite.cpp 
** Author: James G Wilson (wilsjame)
** Date: 3/20/2017
** Description: CS 162
** GobekliTepeSite derived class definition file
*********************************************************************/
#include "gobekliTepeSite.hpp"
/*********************************************************************
** Description: default constructor
** Arguments: none
** Returns: none
*********************************************************************/
GobekliTepeSite::GobekliTepeSite()
{
	this->setImageFile("./images/gobekli_tepe.txt");

	this->setLore("Tunguska Site");
	this->activateArrivalState();
	this->setArtifact(GOBEKLI_TEPE);
}
/*********************************************************************
** Description: excavate artifact
** Arguments: none
** Returns: none
*********************************************************************/
void GobekliTepeSite::activateArrivalState()
{
	std::string arrivalLore = "You touch base in Gobekli Tepe, Turkey";


	std::string choice_one = "Dig";

	this->arrival.setDescription(arrivalLore);
	this->arrival.addInfo(1, choice_one, FIND_ARTIFACT);
}

