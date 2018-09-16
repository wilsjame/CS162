/*********************************************************************
** Program name: Game.hpp
** Author: James G Wilson (wilsjame)
** Date: 1/30/2017
** Description: Lab3 CS 162
** Game class decleration file 
**
** See the class definition file, Game.cpp, for a detailed
** description of this class. 
*********************************************************************/
#ifndef GAME_HPP
#define GAME_HPP
#include "Die.hpp"
#include "LoadedDie.hpp"

class Game{
	private:
		
		Die* dieP1Pointer;
		Die* dieP2Pointer;


		int rounds,
		    dieP1,
		    dieP2,
		    dieP1Sides,
		    dieP2Sides,
		    winsP1, 
		    winsP2; 
	public:
		Game();
		void setRounds();
		void setDice();
		void setSides();
		void createDice();
		void rollEm();
		~Game();
};
#endif




