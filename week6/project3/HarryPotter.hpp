/*********************************************************************
** Program name: HarryPotter.hpp
** Author: James G Wilson (wilsjame)
** Date: 2/18/2017
** Description: Project 3 CS 162
** This is the HarryPotter class decleration file
** HarryPotter is derived from the Creature class
*********************************************************************/
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP
#include "Creature.hpp" //parent class

class HarryPotter : public Creature{

	private:
		int revive;
	public:
		HarryPotter();

		//override keyword tells compiler that the function
		//is supposed to override a function in the base class
		virtual void defense(int attackDamage) override; 
		virtual ~HarryPotter();
};
#endif
