/*********************************************************************
** Program name: James G Wilson (wilsjame)
** Author: James G Wilson (wilsjame)
** Date: 2/17/2017
** Description: Project 3 CS 162
** This is the Barbarian class definition file
** Barbarian is derived from the Creature class
** Use it to fight other creatures. It is a generic Creature
*********************************************************************/
#include "Creature.hpp"
#include "Barbarian.hpp"
#include <iostream>

/*********************************************************************
** Description: constructor that sets members
** Arguments: none
** Retuns: none
*********************************************************************/
Barbarian::Barbarian(){

	armor = 0;
	strength = 12;
	attackDie = 2;
	attackSides = 6;
	defenseDie = 2;
	defenseSides = 6;
}

/*********************************************************************
** Description: destructor ...
** Arguments: none
** Retuns: none
*********************************************************************/
Barbarian::~Barbarian(){

	std::cout << "Barbarians are wild\n";
}

		




