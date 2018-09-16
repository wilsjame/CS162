/*********************************************************************
** Program name: LoadedDie.cpp
** Author: James G Wilson (wilsjame)
** Date: 1/30/2017
** Description: lab3 CS 162
** LoadedDie class implementation file
**
** This is child class of the parent class Die. It represents a loaded
** die that is skewed to roll high values within its range. Use it as
** you would the Die class.
*********************************************************************/
#include "LoadedDie.hpp"
#include <cstdlib>	//using rand()

/*********************************************************************
** Description: default constructor
** Sets the number of sides to 4.
*********************************************************************/
LoadedDie::LoadedDie() : Die() //base constructor initialization
{
	this->sides = 4;
}

/*********************************************************************
** Description: constructor
** Is passed the number of sides as an int and sets the number of 
** sides
*********************************************************************/
LoadedDie::LoadedDie(int sides) : Die(sides) //base constructor initialization
{
	this->sides = sides;
}

/*********************************************************************
** Description: roll is a virtual inherited function
** Roll is skewed to roll values in the upper half of its range. where
** its range is 1 - sides. 
*********************************************************************/
int LoadedDie::roll()
{
	int result = (rand() % (sides - (sides / 2))) 
			+ (sides / 2);

	return result;
}

