/*********************************************************************
** Program name: Barbarian.hpp
** Author: James G Wilson (wilsjame)
** Date: 3/4/2017
** Description: Project 4 CS 162
** This is the Barbarian class decleration file
** Barbarian is a derived from the Creature class
*********************************************************************/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include "Creature.hpp" //parent class
#include <string>

class Barbarian : public Creature{

	public:
		Barbarian(std::string name);
};
#endif


