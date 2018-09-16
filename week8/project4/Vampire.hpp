/*********************************************************************
** Program name: Vampire.hpp
** Author: James G Wilson (wilsjame)
** Date: 3/4/2017
** Description: Project 4 CS 162
** This is the Vampire class decleration file
** Vampire is derived from the Creature class
*********************************************************************/
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP
#include "Creature.hpp" //parent class
#include <string>

class Vampire : public Creature{

	public:
		Vampire(std::string name);

		//override keyword tells compiler that the function
		//is supposed to override a function in the base class
		virtual int  defense(int attack) override; 

};
#endif


