/*********************************************************************
** Program name: HarryPotter.cpp
** Author: James G Wilson (wilsjame)
** Date: 3/4/2017
** Description: Project 4 CS 162
** This is HarryPotter class definition file
** HarryPotter is derived from the Creature class
** Use it fight other creatures. Harry Potter can revive himself
** once! He comes back even stronger!
*********************************************************************/
#include "Creature.hpp"
#include "HarryPotter.hpp"
#include <iostream>

/*********************************************************************
** Description: constructor that sets members
** Arguments: none
** Retuns: none
*********************************************************************/
HarryPotter::HarryPotter(std::string name) : Creature(name){

	armor = 0;
	strength = 10;
	attackDie = 2;
	attackSides = 6;
	defenseDie = 2;
	defenseSides = 6;
	type = 'h';

	revive = 1; //initialize harry's revives;
}

/*********************************************************************
** Description: defends against an attack using defense and armor.
** 		Deducts strength points accordingly. Harry has one
**		revive and comes back to life with double his 
** 		orginial strength.
** Arguments: attack roll as an int
** Retuns:
*********************************************************************/
int HarryPotter::defense(int attack){

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

		//display attack and defense stats for debugging
		std::cout << "Defending fighter's strength before attack: " << strength;
		std::cout << std::endl;
		std::cout << "Strength - damage\n";

		strength -= damage;

		std::cout << strength << " - " << damage << " = ";
		std::cout << strength;
		std::cout << "\nDefending fighter's strength after attack: " << strength;
		std::cout << std::endl;

		//Howgwarts: Harry has one revive and comes back to life with 20 strength
		if(strength <= 0 && revive == 1){
			std::cout << "Ginny Weasley revided Harry Potter!\n";
			std::cout << "Harry's back with even greater strength!";
			strength = 20;
			revive--;
		}
	}
	else{
		std::cout << "No damage inflicted!\n";
	}

	return damage;
}

