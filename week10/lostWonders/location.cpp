/*********************************************************************
** Program name: Project 5 (Text-based Game)
** Filename: location.cpp 
** Author: James G Wilson (wilsjame)
** Date: 3/20/2017
** Description: CS 162
** Location class definition file
*********************************************************************/
#include "location.hpp"
/*********************************************************************
** Description: default constructor
** Arguments: none
** Returns: none
*********************************************************************/
Location::Location()
{
	this->setCurrentState(activeState);
	this->setArtifactRetrieved(false);
	this->setArtifactActivated(false);
}
/*********************************************************************
** Description: sets Location's lore 
** Arguments: string representing the lore for the current state
** Returns: none
*********************************************************************/
void Location::setLore(std::string lore)
{
	this->lore = lore;
}
/*********************************************************************
** Description: sets Location's image file 
** Arguments: image file's location and name as a string
** Returns: none
*********************************************************************/
void Location::setImageFile(std::string imageFile)
{
	this->imageFile = imageFile;
}
/*********************************************************************
** Description: sets Location's artifact
** Arguments: Artifact enum
** Returns: none
*********************************************************************/
void Location::setArtifact(Artifacts artifact)
{
	this->artifact = artifact;
}
/*********************************************************************
** Description: sets if the artifact has been retrieved from the 
**		location
** Arguments: bool
** Returns: none
*********************************************************************/
void Location::setArtifactRetrieved(bool artifactRetrieved)
{
	this->artifactRetrieved = artifactRetrieved;
}
/*********************************************************************
** Description: sets if the artifact has been activated at the location
** Arguments: bool
** Returns: none
*********************************************************************/
void Location::setArtifactActivated(bool artifactActivated)
{
	this->artifactActivated = artifactActivated;
}
/*********************************************************************
** Description: sets the state of the location
** Arguments: State passed by reference
** Returns: none
*********************************************************************/
void Location::setCurrentState(State &currentState)
{
	this->currentState = &currentState;
}
/*********************************************************************
** Description: sets fuel failure location 
** Arguments: pointer to a Location
** Returns: none
*********************************************************************/
void Location::setFail_fuelLocation(Location *fail_fuel)
{
	this->fail_fuel = fail_fuel;
}
/*********************************************************************
** Description: sets cosmos misalignment failure location
** Arguments: pointer to a Location
** Returns: none
*********************************************************************/
void Location::setFail_alignmentLocation(Location *fail_alignment)
{
	this->fail_alignment = fail_alignment;
}
/*********************************************************************
** Description: gets Location's lore
** Arguments: none
** Returns: lore as a string
*********************************************************************/
std::string Location::getLore()
{
	return this->lore;
}
/*********************************************************************
** Description: gets Locations image file
** Arguments: none
** Returns: image file location and name as a string
*********************************************************************/
std::string Location::getImageFile()
{
	return this->imageFile;
}
/*********************************************************************
** Description: gets the Artifact for the site
** Arguments: none
** Returns: enum Artifacts type
*********************************************************************/
Artifacts Location::getArtifact()
{
	return this->artifact;
}
/*********************************************************************
** Description: gets the retrieval status of the artifact
** Arguments: none
** Returns: none
*********************************************************************/
bool Location::getArtifactRetrieved()
{
	return this->artifactRetrieved;
}
/*********************************************************************
** Description: gets the artifact activation status
** Arguments: none
** Returns: none
*********************************************************************/
bool Location::getArtifactActivated()
{
	return this->artifactActivated;
}
/*********************************************************************
** Description: displays image
** Arguments: none
** Returns: none
*********************************************************************/
void Location::displayImage()
{
	std::ifstream image(this->getImageFile());
	std::string asciiChars;
	while(getline(image, asciiChars))
	{
		std::cout << asciiChars << std::endl;
	}
	image.close();
}
/*********************************************************************
** Description: displays Location information (image and lore)
** Arguments: none
** Returns: none
*********************************************************************/
void Location::displayLocation()
{
	this->displayImage();
	std::cout << "\n\n" << this->getLore() << "\n\n";
}
