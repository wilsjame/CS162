/*********************************************************************
** Program name: HarryPotter.hpp
** Author: James G Wilson (wilsjame)
** Date: 3/4/2017
** Description: Project 4 CS 162
** This is the HarryPotter class decleration file
** HarryPotter is derived from the Creature class
*********************************************************************/
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP
#include "Creature.hpp" //parent class
#include <string>

class HarryPotter : public Creature{

	private:
		int revive;
	public:
		HarryPotter(std::string name);

		//override keyword tells compiler that the function
		//is supposed to override a function in the base class
		virtual int defense(int attackDamage) override; 
};
#endif
