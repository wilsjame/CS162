/*********************************************************************
** Program name: LoadedDie.hpp
** Author: James G Wilson (wilsjame)
** Date: 1/30/2017
** Description: lab3 CS 162
** LoadedDie class decleration file
**
** See the class decleration file, LoadedDie.cpp, for a detailed 
** description of this class.
*********************************************************************/
#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP
#include "Die.hpp"

//    child         parent
class LoadedDie : public Die
{
	public:
		int sides;
	public:
		LoadedDie();		
		LoadedDie(int sides);	
		virtual int roll();
};
#endif

