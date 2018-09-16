/*********************************************************************
** Program name: Project 5 (Text-based Game)
** Filename: player.cpp 
** Author: James G Wilson (wilsjame)
** Date: 3/20/2017
** Description: CS 162
** Player class definition file
*********************************************************************/
#include "player.hpp"
#include <iostream>
#include <string>
#include <cstdlib> //random number generator
/*********************************************************************
** Description: Default constructor
** Arguments: none
** Returns: none
*********************************************************************/
Player::Player()
{
	this->setName("Player 1");
	this->setFuel(100);
	this->setAlignment(100);
}
/*********************************************************************
** Description: sets Player name
** Arguments: string representing player name
** Returns: none
*********************************************************************/
void Player::setName(std::string name)
{
	this->name = name;
}
/*********************************************************************
** Description: sets airplane's fuel tank level
** Arguments: int representing fuel level
** Returns: none
*********************************************************************/
void Player::setFuel(int fuel)
{
	this->fuel = fuel;
}
/*********************************************************************
** Description: sets cosmos alignment level
** Arguments: int representing cosmos alignment
** Returns: none
*********************************************************************/
void Player::setAlignment(int alignment)
{
	this->alignment = alignment;
}
/*********************************************************************
** Description: gets Player's name
** Arguments: none
** Returns: string representing player's name
*********************************************************************/
std::string Player::getName()
{
	return this->name;
}
/*********************************************************************
** Description: gets fuel level
** Arguments: none
** Returns: int representing fuel level 
*********************************************************************/
int Player::getFuel()
{
	return this->fuel;
}
/*********************************************************************
** Description: gets alignment level
** Arguments: none
** Returns: int representing alignment level 
*********************************************************************/
int Player::getAlignment()
{
	return this->alignment;
}
/*********************************************************************
** Description: decreases airplane's fuel level
** Arguments: none
** Returns: none
*********************************************************************/
void Player::decreaseFuel()
{
	if((rand() % 2 + 1) == 1)
	{
		//use fuel
		this->fuel -= 1;
	}
	else
	{
		//refill a little
		this->fuel += (rand() % 8 + 4); 
	}
}
/*********************************************************************
** Description: decrease cosmos alignment
** Arguments: none
** Returns: none
*********************************************************************/
void Player::decreaseAlignment()
{
	this->alignment -= (rand() % 7 + 1);
}
/*********************************************************************
** Description: displays fuel level
** Arguments: none
** Returns: none
*********************************************************************/
void Player::displayFuel()
{
	std::cout << "Fuel Tank: " << this->getFuel() << "%" << std::endl;
}
/*********************************************************************
** Description: displays cosmos alignment level
** Arguments: none
** Returns: none
*********************************************************************/
void Player::displayAlignment()
{
	std::cout << "Cosmos Alignment status: ";

	if(this->alignment > 90)
	{
		std::cout << "The universe is glowing, all is well for now.";
	}
	else if(this->alignment > 70) 
	{
		std::cout << "The stars appear to be losing some shine.";
	}
	else if(this->alignment > 50)
	{
		std::cout << "The window of opportunity is nearly halved.";
	}
	else if(this->alignment > 30)
	{
		std::cout << "Have haste time is running out!";
	}
	else
	{
		std::cout << "The cosmos will soon be misaligned.";
	}

	std::cout << std::endl;
}
/*********************************************************************
** Description: displays the contents of the your bag
** Arguments: none
** Returns: none
*********************************************************************/
void Player::displayArtifacts()
{
	this->bag.displayBag();
}

/*********************************************************************
** Description: adds artifact to Player's bag 
** Arguments: Artifact
** Returns: none
*********************************************************************/
void Player::aquireArtifact(Artifacts artifact)
{
	this->bag.addArtifact(artifact);
}
/*********************************************************************
** Description: clears Player's bag of artifacts
** Arguments: none
** Returns: none
*********************************************************************/
void Player::clearArtifacts()
{
	std::cout << "\nBag cleared\n";
	this->bag.clear();
}
