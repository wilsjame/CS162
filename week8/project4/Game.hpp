/*********************************************************************
** Program name: Game.hpp
** Author: James G Wilson (wilsjame)
** Date: 3/5/2017
** Description: Project 4 CS 162
** This is the Game class header file
*********************************************************************/
#ifndef GAME_HPP 
#define GAME_HPP
#include "Creature.hpp"
#include "Queue.hpp"

class Game{

	private:
		int firstStrike,
		    p1Points = 0,
		    p2Points = 0;
	public:
		Game();
		int showLosers();
		int fight(Creature* fighter1, Creature* fighter2);
		void determineWinner();
};
#endif

