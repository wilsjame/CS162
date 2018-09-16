/*********************************************************************
** Program name: Project 5 (Text-based Game)
** Filename: engine.hpp
** Author: James G Wilson (wilsjame)
** Date: 3/20/2017
** Description: CS 162
** Engine class header file
*********************************************************************/
#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "player.hpp"
#include "compass.hpp"

class Engine 
{
	private:
		Player player;
		Compass compass;
	public:
		//default constructor
		Engine();

		//Engine methods
		void checkFuel();
		void checkAlignment();
		void checkStatus();
		void showStats();
		void run();
};

#endif
