/*********************************************************************
** Program name: BlueMen.hpp
** Author: James G Wilson (wilsjame)
** Date: 2/18/2017
** Description: Project 3 CS 162
** This is the BlueMen class decleration file
** BlueMen is derived from the Creature class
*********************************************************************/
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
#include "Creature.hpp" //parent class

class BlueMen : public Creature{

	public:
		BlueMen();

		//override keyword tells compiler that the function
		//is supposed to override a function in the base class
		virtual void defense(int attack) override; 
		virtual ~BlueMen();

};
#endif
