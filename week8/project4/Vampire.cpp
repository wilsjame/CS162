/*********************************************************************
** Program name: Vampire.cpp
** Author: James G Wilson (wilsjame)
** Date: 3/4/2017
** Description: Project 4 CS 162
** This is Vampire class definition file
** Vampire is derived from the Creature class
** Use it to fight other creatures. Vampire has a special ability
** called charm!
*********************************************************************/
#include "Creature.hpp"
#include "Vampire.hpp"
#include <iostream>
#include <cstdlib> //using random

/*********************************************************************
** Description: constructor that sets members
** Arguments: none
** Retuns: none
*********************************************************************/
Vampire::Vampire(std::string name) : Creature(name){

	armor = 1;
	strength = 18;
	attackDie = 1;
	attackSides = 12;
	defenseDie = 1;
	defenseSides = 6;
	type = 'v';
}

/*********************************************************************
** Description: defends against an attack using defense and armor.
** 		Deducts strength points accordingly. Charm ability
		makes the attack go %50 of the time
** Arguments: attack roll as an int
** Retuns: none
*********************************************************************/
int Vampire::defense(int attack){

	int defenseRoll,
	    damage,
	    charm;

	//generate a 50/50 chance for charm
	charm = (rand() % 100 + 0);
	std::cout << "Charm is at %" << charm << std::endl;

	if(charm < 50){

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
	}else{
		std::cout << "Charm was succesful! No damage inflicted.\n";
	}

	return damage;
}


