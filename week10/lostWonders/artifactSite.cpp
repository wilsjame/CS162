/*********************************************************************
** Program name: Project 5 (Text-based Game)
** Filename: artifactSite.cpp 
** Author: James G Wilson (wilsjame)
** Date: 3/20/2017
** Description: CS 162
** ArtifactSite abstract base class definition file
*********************************************************************/
#include "artifactSite.hpp"
#include <string>
/*********************************************************************
** Description: default constructor
** Arguments: none
** Returns: none
*********************************************************************/
ArtifactSite::ArtifactSite() : Location()
{
	this->activateState();
	this->deactivatedState();
	this->activateFoundState();
}
/*********************************************************************
** Description: sets the neighboring locations
** Arguments: pointer to a location
** Returns: none
*********************************************************************/
void ArtifactSite::setCockpit(Location *cock_pit)
{
	this->cock_pit = cock_pit;
}
/*********************************************************************
** Description: gives a brief description of the artifact site before
**		the artifact is found. Activates search state
** Arguments: none
** Returns: none
*********************************************************************/
void ArtifactSite::activateState()
{
	std::string arrivalLore = "You land at the artifact site\n"; 

	std::string choice_one = "Excavate artifact";

	this->activeState.setDescription(arrivalLore);
	this->activeState.addInfo(1, choice_one, SEARCH_ARTIFACT);
}
/*********************************************************************
** Description: gives a brief descriptin of the aritfact site after
**		the artifact has been found. Activates already found 
**		state
** Arguments: none
** Returns: none
*********************************************************************/
void ArtifactSite::deactivatedState()
{
	std::string alreadyFoundLore = "You've already found the artifact here\n";

	std::string choice_one = "Get back in your plane";

	this->deactiveState.setDescription(alreadyFoundLore);
	this->deactiveState.addInfo(1, choice_one, COCKPIT);
}
/*********************************************************************
** Description: activates the state of finding the artifact
** Arguments: none
** Returns: none
*********************************************************************/
void ArtifactSite::activateFoundState()
{
	std::string foundLore = "You found the artifact!\n";

	std::string choice_one = "You found the artifact here go back to your place";

	this->artifactFound.setDescription(foundLore);
	this->artifactFound.addInfo(1, choice_one, FIND_ARTIFACT);
}
/*********************************************************************
** Description: allows the user to interact with the location
** Arguments: none
** Returns: pointer to a location
*********************************************************************/
Location* ArtifactSite::run()
{
	this->displayLocation();
	Location *nextLocation = this;
	
	switch(this->currentState->run())
	{
		case SEARCH_ARTIFACT:
			currentState = &arrival;
			//bugfix: set the artifact to found
			this-> setArtifactRetrieved(true);
			break;
		case FIND_ARTIFACT:
			currentState = &artifactFound;
			//bugfix: set next location to cockpit
			nextLocation = cock_pit;
			break;
		case DEACTIVE:
			currentState = &deactiveState;
			break;
		case COCKPIT:
			nextLocation = cock_pit;
			break;
		case FAIL_FUEL:
			nextLocation = fail_fuel;
			break;
		case FAIL_ALIGNMENT:
			nextLocation = fail_alignment;
			break;
		default:
			break;
	}

	std::cout << "\nreturning the next location\n";
	return nextLocation;
}

