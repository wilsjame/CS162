/*********************************************************************
** Program name: Medusa.cpp
** Author: James G Wilson (wilsjame)
** Date: 2/18/2017
** Description: Project 3 CS 162
** This is Medusa class definition file
** Medusa is derived from the Creature class
** Use it to fight other creatures. Medusa has a special ability
** called glare!
*********************************************************************/
#include "Creature.hpp"
#include "Medusa.hpp"
#include <iostream>

/*********************************************************************
** Description: constructor that sets members
** Arguments: none
** Retuns: none
*********************************************************************/
Medusa::Medusa(){

	armor = 3;
	strength = 8;
	attackDie = 2;
	attackSides = 6;
	defenseDie = 1;
	defenseSides = 6;
}

/*********************************************************************
** Description: rolls attack dice if a 12 is rolled Medusa's glare
**		immediatly elimiates the opponent!
** Arguments: none
** Retuns: attack roll as an int
*********************************************************************/
int Medusa::attack(){

	std::cout << "Beware Medusa's Glare\n";

	int attackRoll;

	//roll attack dice and display the result
	attackRoll = roll(attackDie, attackSides);
	std::cout << "Attack roll: " << attackRoll << std::endl;
	
	//determine if glare special ability is activated
	if(attackRoll == 12){
		attackRoll = 421;
		std::cout << "Medusa's glare turns the opponent\n";
		std::cout << "to stone!\n";
	}

	return attackRoll;
}

/*********************************************************************
** Description: destructor ...
** Arguments: none
** Retuns: none
*********************************************************************/
Medusa::~Medusa(){

	std::cout << "Medusa has snakes for hair and\n";
	std::cout << "looking into her eyes will turn you to stone!\n";
}
