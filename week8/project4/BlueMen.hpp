/*********************************************************************
** Program name: BlueMen.hpp
** Author: James G Wilson (wilsjame)
** Date: 3/4/2017
** Description: Project 4 CS 162
** This is the BlueMen class decleration file
** BlueMen is derived from the Creature class
*********************************************************************/
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
#include "Creature.hpp" //parent class
#include <string>

class BlueMen : public Creature{

	public:
		BlueMen(std::string name);

		//override keyword tells compiler that the function
		//is supposed to override a function in the base class
		virtual int defense(int attack) override; 

};
#endif
