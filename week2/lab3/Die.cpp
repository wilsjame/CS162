/*********************************************************************
** Program name: Die.cpp
** Author: James G Wilson (wilsjame)
** Date: 1/30/2017
** Description: Lab3 CS 162
** Die class implementation file
**
** This class represents the a die used that is used with the Game
** class. It is the parent class of the LoadedDie. The is initialized
** with the number of sides. The dice has a member functin that
** rolls the dice returning a random value within the range of its
** number of sides.
*********************************************************************/
#include "Die.hpp"
#include <cstdlib>	//using rand(), seed in main function

/*********************************************************************
** Description: default constructor
** Sets the number of sides to 4.
*********************************************************************/
Die::Die()
{
	sides = 4;
}

/*********************************************************************
** Description: contstructor
** Is passed the number of sides as an int and sets the number of sides
** member.
*********************************************************************/
Die::Die(int sides)
{
	this->sides = sides;
}

/*********************************************************************
** Description: rollDice
** Sets the rollValue to a random integer in the range of 1 - sides.
** Returns the value as the roll result. Virtual tag means that
** child classes can use this exact function with different results
*********************************************************************/
//virtual continues on through all derived classes
int Die::roll()
{
	int result = rand() % sides + 1;

	return result;
}


