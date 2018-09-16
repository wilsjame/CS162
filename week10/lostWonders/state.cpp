/*********************************************************************
** Program name: Project 5 (Text-based Game)
** Filename: state.cpp 
** Author: James G Wilson (wilsjame)
** Date: 3/20/2017
** Description: CS 162
** State class definition files
*********************************************************************/
#include "state.hpp"
#include <iostream>
/*********************************************************************
** Description: default constructor
** Arguments: none
** Returns: none
*********************************************************************/
State::State()
{
}
/*********************************************************************
** Description: sets states description
** Arguments: description as a string
** Returns: none
*********************************************************************/
void State::setDescription(std::string description)
{
	this->description = description;
}
/*********************************************************************
** Description: gets the states description
** Arguments: none 
** Returns: none
*********************************************************************/
std::string State::getDescription()
{
	return this->description;
}
/*********************************************************************
** Description: adds StateInfo to the info vector
** Arguments: int for the info number, description as a string,
**		Results enum for the resulting state
** Returns: none
*********************************************************************/
void State::addInfo(int num, std::string description, Results results)
{
	StateInfo newStateInfo(num, description, results);
	this->infoStorage.push_back(newStateInfo);
}
/*********************************************************************
** Description: displays the states description
** Arguments: none
** Returns: none
*********************************************************************/
void State::displayDescription()
{
	std::cout << "\n\n" << this->getDescription() << "\n\n";
}
/*********************************************************************
** Description: displays the StateInfo 
** Arguments: none
** Returns: none
*********************************************************************/
void State::displayStateInfo()
{
	for(int infoStorageIndex = 0; infoStorageIndex < this->infoStorage.size(); infoStorageIndex++)
	{
		std::cout << this->infoStorage.at(infoStorageIndex).getNum()
			<< ") "
			<< this->infoStorage.at(infoStorageIndex).getDescription()
			<< "\n";
	}
	std::cout << std::endl;
}
/*********************************************************************
** Description: translates user's input into the matching Result enum
** Arguments: int as the user's input
** Returns: Results enum
*********************************************************************/
Results State::getResults(int num)
{
	Results result;

	for(int infoStorageIndex = 0; infoStorageIndex < this->infoStorage.size(); infoStorageIndex++)
	{
		if(num == this->infoStorage.at(infoStorageIndex).getNum())
		{
			result = this->infoStorage.at(infoStorageIndex).getResult();
		}
	}
	
	return result;
}
/*********************************************************************
** Description: displays the state info and gets user input determines
**		the results of their input
** Arguments: none
** Returns: Results enum
*********************************************************************/
Results State::run()
{
	//create input validatin object
	inputValid user;
	
	this->displayDescription();
	this->displayStateInfo();
	int userInput = user.input_integer(1, this->infoStorage.size(), ">>>");

	return this->getResults(userInput);
}	
