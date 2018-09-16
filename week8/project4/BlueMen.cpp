/*********************************************************************
** Program name: BlueMen.cpp
** Author: James G Wilson (wilsjame)
** Date: 3/4/2017
** Description: Project 4 CS 162
** This is BlueMen class definition file
** BlueMen is derived from the Creature class
** Use it to fight other creatures. Blue men have a special ability
** called mob!
*********************************************************************/
#include "Creature.hpp"
#include "BlueMen.hpp"
#include <iostream>

/*********************************************************************
** Description: constructor that sets members
** Arguments: none
** Retuns: none
*********************************************************************/
BlueMen::BlueMen(std::string name) : Creature(name){

	armor = 3;
	strength = 12;
	attackDie = 2;
	attackSides = 10;
	defenseDie = 3;
	defenseSides = 6;
	type = 'B';
}

/*********************************************************************
** Description: defends against an attack using defense and armor.
** 		Deducts strength points accordingly. Mob ability
		means every 4 strength points accounts for one
		defense die. 
** Arguments: attack roll as an int
** Retuns: none
*********************************************************************/
int BlueMen::defense(int attack){

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

		//update strength after damage inflicted
		strength -= damage;

		//display damage stats for debugging
		std::cout << strength << " - " << damage << " = ";
		std::cout << strength;
		std::cout << "\nDefending fighter's strength after attack: " << strength;
		std::cout << std::endl;

		//determine if blue man mob takes a hit
		if(strength <= 4){
			defenseDie = 1;
			std::cout << "There is only " << defenseDie;
			std::cout << " Blue Man left.\n";
		}else if(strength <= 8){
			defenseDie = 2;
			std::cout << "Blue men are mourning their fallen friend!\n";
			std::cout << "There are " << defenseDie; 
			std::cout << " left.\n";
		}else{
			defenseDie = 3;
			std::cout << "Blue Men mob is " << defenseDie;
			std::cout << " strong!\n";
		}
	}
	else{
		std::cout << "No damage inflicted!\n";
	}

	return damage;
}


