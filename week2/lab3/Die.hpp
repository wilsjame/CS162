/*********************************************************************
** Program name: Die.hpp
** Author: James G Wilson (wilsjame)
** Date: 1/30/2017
** Description: Lab3 CS 162
** Die class decleration file
**
** See the class definition file, Die.cpp, for a detailed 
** description of this class.
*********************************************************************/
#ifndef DIE_HPP
#define DIE_HPP

class Die{
	protected:
		int sides;
	public:
		Die();
		Die(int sides);
		virtual int roll(); 
};
#endif

