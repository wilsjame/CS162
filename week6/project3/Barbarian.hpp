/*********************************************************************
** Program name: Barbarian.hpp
** Author: James G Wilson (wilsjame)
** Date: 2/18/2017
** Description: Project 3 CS 162
** This is the Barbarian class decleration file
** Barbarian is a derived from the Creature class
*********************************************************************/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include "Creature.hpp" //parent class

class Barbarian : public Creature{

	public:
		Barbarian();
		virtual ~Barbarian();
};
#endif


