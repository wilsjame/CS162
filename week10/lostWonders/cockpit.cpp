/*********************************************************************
** Program name: Project 5 (Text-based Game)
** Filename: cockpit.cpp 
** Author: James G Wilson (wilsjame)
** Date: 3/20/2017
** Description: CS 162
** Cockpit class definition file
*********************************************************************/
#include "cockpit.hpp"
#include <string>
/*********************************************************************
** Description: default constructor
** Arguments: none
** Returns: none
*********************************************************************/
Cockpit::Cockpit() : Location()
{
	this->setLore("Cockpit");
	this->activateState();
	this->deactivatedState();
	this->setImageFile("./images/airplane.txt");
}
/*********************************************************************
** Description: sets Tunguska location
** Arguments: pointer to a Location
** Returns: none
*********************************************************************/
void Cockpit::setTunguskaLocation(Location *Tunguska)
{
	this->Tunguska = Tunguska;
}
/*********************************************************************
** Description: sets Stonehenge location
** Arguments: pointer to a Location
** Returns: none
*********************************************************************/
void Cockpit::setStonehengeLocation(Location *Stonehenge)
{
	this->Stonehenge = Stonehenge;
}
/*********************************************************************
** Description: sets Gobekli_Tepe location
** Arguments: pointer to a Location
** Returns: none
*********************************************************************/
void Cockpit::setGobekli_TepeLocation(Location *Gobekli_Tepe)
{
	this->Gobekli_Tepe = Gobekli_Tepe;
}
/*********************************************************************
** Description: sets Easter_Isle location
** Arguments: pointer to a Location
** Returns: none
*********************************************************************/
void Cockpit::setEaster_IsleLocation(Location *Easter_Isle)
{
	this->Easter_Isle = Easter_Isle;
}
/*********************************************************************
** Description: sets Acacia_Tree location
** Arguments: pointer to a Location
** Returns: none
*********************************************************************/
void Cockpit::setAcacia_TreeLocation(Location *Acacia_Tree)
{
	this->Acacia_Tree = Acacia_Tree;
}
/*********************************************************************
** Description: checks if every artifact has been recovered. If so,
**		the activated state is deactivated.
** Arguments: none
** Returns: none
*********************************************************************/
void Cockpit::checkArtifactsRetrieved()
{
	if(this->Tunguska->getArtifactRetrieved() 
	&& this->Stonehenge->getArtifactRetrieved()
	&& this->Gobekli_Tepe->getArtifactRetrieved()
	&& this->Easter_Isle->getArtifactRetrieved())
	{
		this->setCurrentState(deactiveState);
	}
}

/*********************************************************************
** Description: displays the cockpit options while there are still
**		artifacts to find.
** Arguments: none
** Returns: none
*********************************************************************/
void Cockpit::activateState()
{
	std::string lore = 
		"Where shall you fly?\n";
	std::string choice_one = "Tunguska";
	std::string choice_two = "Stonehenge";
	std::string choice_three = "Gobekli Tepe";
	std::string choice_four = "Easter Island";

	this->activeState.setDescription(lore);
	this->activeState.addInfo(1, choice_one, TUNGUSKA_LOCATION);
	this->activeState.addInfo(2, choice_two, STONEHENGE_LOCATION);
	this->activeState.addInfo(3, choice_three, GOBEKLI_TEPE_LOCATION);
	this->activeState.addInfo(4, choice_four, EASTER_ISLE_LOCATION);
}
/*********************************************************************
** Description: when all the artifacts are found the active state 
**		changes
** Arguments: none
** Returns: none
*********************************************************************/
void Cockpit::deactivatedState()
{
	std::string lore = 
		"You have found all the artifacts. Your plane does not"
		"\nrespond to your control! It is taking you somewhere!\n";

	std::string choice_one = "Give in and let the artifacts take control";

	this->deactiveState.setDescription(lore);
	this->deactiveState.addInfo(1, choice_one, ACACIA_TREE_LOCATION);
}
/*********************************************************************
** Description:
** Arguments:
** Returns:
*********************************************************************/
Location* Cockpit::run()
{
	this->displayLocation();
	this->checkArtifactsRetrieved();
	Location *nextLocation;

	//switching off Results enum
	switch(this->currentState->run())
	{
		case TUNGUSKA_LOCATION:
			nextLocation = Tunguska;
			break;
		case STONEHENGE_LOCATION:
			nextLocation = Stonehenge;
			break;
		case GOBEKLI_TEPE_LOCATION:
			nextLocation = Gobekli_Tepe;
			break;
		case EASTER_ISLE_LOCATION:
			nextLocation = Easter_Isle;
			break;
		case ACACIA_TREE_LOCATION:
			nextLocation = Acacia_Tree;
			break;
		default:
			std::cout << "switched to defualt\n";
			nextLocation = this;
	}

	std::cout << "Switch exited\n";
	return nextLocation;
}
