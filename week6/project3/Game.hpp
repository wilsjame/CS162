/*********************************************************************
** Program name: Game.hpp
** Author: James G Wilson (wilsjame)
** Date: 2/18/2017
** Description: Project 3 CS 162
** This is the Game class header file
*********************************************************************/
#ifndef GAME_HPP 
#define GAME_HPP
#include "Creature.hpp"

class Game{

	private:
		Creature* c1;
		Creature* c2;
		int firstStrike,
		    round = 1;
		bool stillStanding = true;
	public:
		Game();
		int getChoice();
		void fight(Creature* fighter1, Creature* fighter2);
};
#endif



