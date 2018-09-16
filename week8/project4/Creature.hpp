/*********************************************************************
** Program name: Creature.hpp
** Author: James G Wilson (wilsjame)
** Date: 3/5/2017
** Description: Project 4 CS 162
** This is the Creature class decleration file
*********************************************************************/
#ifndef CREATURE_HPP
#define CREATURE_HPP
#include <string>

class Creature{

	protected:
		std::string name;
		int armor,
		    strength,
		    attackDie,
		    attackSides,
		    defenseDie,
		    defenseSides;
		char type;
	public:
		Creature(std::string name);
		virtual int attack();
		virtual int defense(int attack);
		int roll(int numDie, int sidesDie);
		int getStrength();
		int getArmor();
		void restore(int damageTotal);
		void getName();
};
#endif





