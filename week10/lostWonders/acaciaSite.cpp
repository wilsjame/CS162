/*********************************************************************
** Program name: Project 5 (Text-based Game)
** Filename: acaciaSite.cpp 
** Author: James G Wilson (wilsjame)
** Date: 3/20/2017
** Description: CS 162
** AcaciaSite class definition file
*********************************************************************/
#include "acaciaSite.hpp"
#include <string>
/*********************************************************************
** Description: default constructor
** Arguments: none
** Returns: none
*********************************************************************/
AcaciaSite::AcaciaSite()
{
	this->setLore("Acacia Tree");
	this->activateState();
	this->approach();
	this->ignite();
	this->setImageFile("./images/acacia.txt");
}
/*********************************************************************
** Description: sets a new location
** Arguments: pointer to a location
** Returns: none
*********************************************************************/
void AcaciaSite::setCockpitLocation(Location* cock_pit)
{
	this->cock_pit = cock_pit;
}
/*********************************************************************
** Description: sets a new location
** Arguments: pointer to a location
** Returns: none
*********************************************************************/
void AcaciaSite::setEnlightenment(Location *enlightenment)
{
	this->enlightenment = enlightenment;
}
/*********************************************************************
** Description: allows user to interact with the location
** Arguments: none
** Returns: none
*********************************************************************/
void AcaciaSite::activateState()
{
	std::string acaciaTree1 =
		"You see the beautiful acacia tree in the distance.\n"
		"What do you do?\n";

	std::string choice_one = "Approach the tree";

	this->activeState.setDescription(acaciaTree1);
	this->activeState.addInfo(1, choice_one, APPROACH);
}
/*********************************************************************
** Description: allows user to interact with the acacia tree
** Arguments: none
** Returns: none
*********************************************************************/
void AcaciaSite::approach()
{
	std::string acaciaTree2 =
		"You stand before the beautiful acacia tree.\n"
		"What do you do?\n";

	std::string choice_one = "Light it on fire";

	this->arrival.setDescription(acaciaTree2);
	this->arrival.addInfo(1, choice_one, IGNITE);
}
/*********************************************************************
** Description: displays the final location state before enlightenment
** Arguments: none
** Returns: noen
*********************************************************************/
void AcaciaSite::ignite()
{
	std::string acaciaTree3 =
		"The tree bursts into flames and you are transported\n"
		"to another dimension!\n";

	std::string choice_one = "Hold on tight";

	this->burning.setDescription(acaciaTree3);
	this->burning.addInfo(1, choice_one, ENLIGHTENMENT);
}
/*********************************************************************
** Description: allows the user to interact with the acacia tree
**		location
** Arguments: none
** Returns: pointer to a location
*********************************************************************/
Location* AcaciaSite::run()
{
	this->displayLocation();
	Location *nextLocation = this;
	
	switch(this->currentState->run())
	{
		case ACTIVE:
			currentState = &activeState;
			break;
		case APPROACH:
			currentState = &arrival;
			//bug fix:
			//setArtifactRetrieved(true);
			break;
		case IGNITE:
			currentState = &burning;
			break;
		case ENLIGHTENMENT:
			nextLocation = enlightenment;
			break;
	}
}
