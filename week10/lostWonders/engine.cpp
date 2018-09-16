/*********************************************************************
** Program name: Project 5 (Text-based Game)
** Filename: engine.cpp 
** Author: James G Wilson (wilsjame)
** Date: 3/20/2017
** Description: CS 162
** Engine class definition file
*********************************************************************/
#include "engine.hpp"
#include <iostream>
/*********************************************************************
** Description: default constructor
** Arguments: none
** Returns: none
*********************************************************************/
Engine::Engine()
{
	std::cout << "\n*Game Running*\n";
}
/*********************************************************************
** Description: checks the airplanes fuel level
** Arguments: none
** Returns: none
*********************************************************************/
void Engine::checkFuel()
{
	if(this->player.getFuel() <= 0)
	{
		this->compass.fail_fuel();
	}
}
/*********************************************************************
** Description: checks the cosmos alignment
** Arguments: none
** Returns: none
*********************************************************************/
void Engine::checkAlignment()
{
	if(this->player.getAlignment() <= 0)
	{
		this->compass.fail_alignment();
	}
}
/*********************************************************************
** Description: checks which location the player is and their atifact
**		search status
** Arguments: none
** Returns: none
*********************************************************************/
void Engine::checkStatus()
{
	//get artifact retrieved is a Location method that returns a bool
	if(this->compass.getCurrentLocation()->getArtifactRetrieved() == true)
	{
		this->player.aquireArtifact(compass.getCurrentLocation()->getArtifact());
	}
}
/*********************************************************************
** Description: shows the players current stats
** Arguments: none
** Returns: none
*********************************************************************/
void Engine::showStats()
{
	std::cout << this->player.getName() << std::endl;
	this->player.displayArtifacts();
	std::cout << std::endl;
	this->player.displayFuel();
	this->player.displayAlignment();
	std::cout << std::endl;
}
/*********************************************************************
** Description: main driver for the game
** Arguments: none
** Returns: none
*********************************************************************/
void Engine::run()
{
	while(this->compass.getCurrentLocation() != NULL)
	{
	
		this->checkFuel();
		this->checkAlignment();
		this->checkStatus();

		std::cout << "\n\n\n";
		this->showStats();
		this->compass.setCurrentLocation(compass.getCurrentLocation()->run());
		this->player.decreaseFuel();
		this->player.decreaseAlignment();

	}
}
