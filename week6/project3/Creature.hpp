/*********************************************************************
** Program name: Creature.hpp
** Author: James G Wilson (wilsjame)
** Date: 2/18/2017
** Description: Project 3 CS 162
** This is the Creature class decleration file
*********************************************************************/
#ifndef CREATURE_HPP
#define CREATURE_HPP

class Creature{

	protected:
		int armor,
		    strength,
		    attackDie,
		    attackSides,
		    defenseDie,
		    defenseSides;
	public:
		virtual int attack();
		virtual void defense(int attack);
		int roll(int numDie, int sidesDie);
		int getStrength();
		int getArmor();
		virtual ~Creature() = 0;
};
#endif





