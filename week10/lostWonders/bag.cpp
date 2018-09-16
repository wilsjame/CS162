/*********************************************************************
** Program name: Project 5 (Text-based Game)
** Filename: bag.cpp 
** Author: James G Wilson (wilsjame)
** Date: 3/20/2017
** Description: CS 162
** Bag class definition file
*********************************************************************/
#include "bag.hpp"
#include <iostream>
/*********************************************************************
** Description: default constructor
** Arguments: none
** Returns: none
*********************************************************************/
Bag::Bag()
{
	this->clear();
}
/*********************************************************************
** Description: clears bag of artifacts
** Arguments: none
** Returns: none
*********************************************************************/
void Bag::clear()
{
	for(int bagIndex = 0; bagIndex < 4; bagIndex++) 
	{
		this->bag[bagIndex] = NONE;
	}
}
/*********************************************************************
** Description: adds an artifact to the bag
** Arguments: enum type Artifacts
** Returns: none
*********************************************************************/
void Bag::addArtifact(Artifacts artifact)
{
	this->bag[artifact] = artifact;
}
/*********************************************************************
** Description: displays an empty artifact slot
** Arguments: none
** Returns: none
*********************************************************************/
void Bag::displayNone()
{
	std::cout << "[Artifact Slot]";
}
/*********************************************************************
** Description: displays Tunguska artifact
** Arguments: none
** Returns: none
*********************************************************************/
void Bag::displayTunguska()
{
	std::cout << " [Tunguska Artifact] ";
}
/*********************************************************************
** Description: displays Stonehenge artifact
** Arguments: none
** Returns: none
*********************************************************************/
void Bag::displayStonehenge()
{
	std::cout << " [Stonehenge Artifact] ";
}
/*********************************************************************
** Description: displays Gobekli_Tepe artifact
** Arguments: none
** Returns: none
*********************************************************************/
void Bag::displayGobekli_Tepe()
{
	std::cout << " [Gobekli_Tepe Artifact] ";
}
/*********************************************************************
** Description: displays Easter_Isle artifact
** Arguments: none
** Returns: none
*********************************************************************/
void Bag::displayEaster_Isle()
{
	std::cout << " [Easter_Isle Artifact] ";
}
/*********************************************************************
** Description: displays bag slots 
** Arguments: none
** Returns: none
*********************************************************************/
void Bag::displayBag()
{
	std::cout << "Bag: ";

	for(int bagIndex = 0; bagIndex < 4; bagIndex++) 
	{

		switch(this->bag[bagIndex])
		{
			case NONE:
					this->displayNone();
					break;
			case TUNGUSKA:
					this->displayTunguska();
					break;
			case STONEHENGE:
					this->displayStonehenge();
					break;
			case GOBEKLI_TEPE:
					this->displayGobekli_Tepe();
					break;
			case EASTER_ISLE:
					this->displayEaster_Isle();
					break;
			default: break;

		}
	}
}
