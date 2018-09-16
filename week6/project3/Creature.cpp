/*********************************************************************
** Program name: Creature.cpp
** Author: James G Wilson (wilsjame)
** Date: 2/18/2017
** Description: Project 3 CS 162
** This is the Creature class definition file
*********************************************************************/
#include "Creature.hpp"
#include <iostream>
#include <cstdlib> //using random

/*********************************************************************
** Description: rolls attack dice
** Arguments: none

*********************************************************************/
int Creature::attack(){

	int attackRoll;

	//roll attack dice and display the result
	attackRoll = roll(attackDie, attackSides);
	std::cout << "Attack roll: " << attackRoll << std::endl;

	return attackRoll;
}

/*********************************************************************
** Description: defends against an attack using defense and armor.
** 		Deducts strength points accordingly
** Arguments: attack roll as an int
** Retuns: none
*********************************************************************/
void Creature::defense(int attack){

	int defenseRoll,
	    damage;

	//roll defense dice and display the result
	defenseRoll = roll(defenseDie, defenseSides);
	std::cout << "Defense roll: " << defenseRoll << std::endl;

	//calculate resulutant attack damage:
	damage = (attack - defenseRoll - armor);

	std::cout << "Attack damage = attack - defenseRoll - armor\n";
	std::cout << damage << " = " << attack << " - " << defenseRoll;
	std::cout << " - " << armor << std::endl;
	
	//calculate resultant strength points
	if(damage > 0){
		std::cout << "Defending fighter's strength before attack: " << strength;
		std::cout << std::endl;
		std::cout << "Strength - damage\n";

		strength -= damage;

		std::cout << strength << " - " << damage << " = ";
		std::cout << strength;
		std::cout << "\nDefending fighter's strength after attack: " << strength;
		std::cout << std::endl;
	}
	else{
		std::cout << "No damage inflicted!\n";
	}
}

/*********************************************************************
** Description: rolls one or more die with variable sides. 
** Arguments: an int for the number of die to roll and an int for
** the number of sides those die have.
** Returns: the sum of rolls as an int
*********************************************************************/
int Creature::roll(int numDie, int sidesDie){

	//reset sum to 0 so rolls don't compuound
	int sum = 0;

	for(int rolls = 0; rolls < numDie; rolls++){
		sum += (rand() % sidesDie + 1);
	}

	return sum;
}

/*********************************************************************
** Description: getter for strength member
** Arguments: none
** Retuns: strength member as an int
*********************************************************************/
int Creature::getStrength(){

	return strength;
}

/*********************************************************************
** Description: getter for armor
** Arguments: none
** Retuns: armor method as an int
*********************************************************************/
int Creature::getArmor(){

	return armor;
}

/*********************************************************************
** Description: pure virtual descructor
** Arguments: none
** Retuns: none
*********************************************************************/
Creature::~Creature(){
	//std::cout << "Creature desctructor called\n";
}





	






