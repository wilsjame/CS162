/*********************************************************************
** Program name: Medusa.hpp
** Author: James G Wilson (wilsjame)
** Date: 2/18/2017
** Description: Project 3 CS 162
** This is the Medusa class decleration file
** Medusa is derived from the Creature class
*********************************************************************/
#ifndef MEDUSA_HPP
#define MEDUSA_HPP
#include "Creature.hpp" //parent class

class Medusa : public Creature{

	public:
		Medusa();

		//override keyword tells compiler that the function
		//is supposed to override a function in the base class
		virtual int attack() override; 
		virtual ~Medusa();
};
#endif
