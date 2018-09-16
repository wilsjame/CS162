/*********************************************************************
** Program name: Project 5 (Text-based Game)
** Filename: compass.cpp 
** Author: James G Wilson (wilsjame)
** Date: 3/20/2017
** Description: CS 162
** Compass class definition file
*********************************************************************/
#include "compass.hpp"
/*********************************************************************
** Description: default constructor sets up all the locations
**		and makes the cockpit home
** Arguments: none
** Returns: none
*********************************************************************/
Compass::Compass()
{
	//locations available from cockpit
	this->cockpit.setTunguskaLocation(&tunguskaSite);
	this->cockpit.setStonehengeLocation(&stonehengeSite);
	this->cockpit.setGobekli_TepeLocation(&gobekliTepeSite);
	this->cockpit.setEaster_IsleLocation(&easterIsleSite);
	this->cockpit.setAcacia_TreeLocation(&acaciaSite);

	this->cockpit.setFail_fuelLocation(&failFuelSite);
	this->cockpit.setFail_alignmentLocation(&failAlignmentSite);

	//locations available from tunguska
	this->tunguskaSite.setCockpit(&cockpit);

	this->tunguskaSite.setFail_fuelLocation(&failFuelSite);
	this->tunguskaSite.setFail_alignmentLocation(&failAlignmentSite);

	//locations available from stonehenge
	this->stonehengeSite.setCockpit(&cockpit);

	this->stonehengeSite.setFail_fuelLocation(&failFuelSite);
	this->stonehengeSite.setFail_alignmentLocation(&failAlignmentSite);

	//locations available from gobekliTepe
	this->gobekliTepeSite.setCockpit(&cockpit);

	this->gobekliTepeSite.setFail_fuelLocation(&failFuelSite);
	this->gobekliTepeSite.setFail_alignmentLocation(&failAlignmentSite);

	//locations available from easterIsle
	this->easterIsleSite.setCockpit(&cockpit);

	this->easterIsleSite.setFail_fuelLocation(&failFuelSite);
	this->easterIsleSite.setFail_alignmentLocation(&failAlignmentSite);

	//locations available from acaciaSite
	this->acaciaSite.setCockpitLocation(&cockpit);
	this->acaciaSite.setEnlightenment(&enlightenmentSite);

	this->acaciaSite.setFail_fuelLocation(&failFuelSite);
	this->acaciaSite.setFail_alignmentLocation(&failAlignmentSite);


	//set the current location
	setCurrentLocation(&cockpit);
}
/*********************************************************************
** Description: sets the users starting location as the cockpit
** Arguments: pointer to a Location
** Returns: none
*********************************************************************/
void Compass::setCurrentLocation(Location *currentLocation)
{
	this->currentLocation = currentLocation;
}
/*********************************************************************
** Description: gets the users current location
** Arguments: none
** Returns: a pointer to a Location
*********************************************************************/
Location* Compass::getCurrentLocation()
{
	return this->currentLocation;
}
/*********************************************************************
** Description: changes the current location to the fuel fail location
** Arguments: none
** Returns: none
*********************************************************************/
void Compass::fail_fuel()
{
	this->currentLocation = &failFuelSite;
}
/*********************************************************************
** Description: changes the current location to the alignment fail
**		location
** Arguments: none
** Returns: none
*********************************************************************/
void Compass::fail_alignment()
{
	this->currentLocation = &failAlignmentSite;
}
