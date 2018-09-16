/*********************************************************************
** Program name: main.cpp
** Author: James G Wilson (wilsjame)
** Date: 1/30/2017
** Description: lab3 CS 162
**
** Main program module. Run the Makefile to create an executable
** program titled 'main'.
**
** main will utilize the following classes: Game, Die, and LoadedDie.
**
** A simulated variation on the classic game War will be played
** between two players using dice. The dice can be either normal or
** or loaded. The number of sides on each dice and the number of
** rounds to play will be chosen by you. The game ends when the rounds
** are up and the results are displayed. The highest roll wins!
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.hpp"

int main()
{
	int seed;
	seed = time(0);
	srand(seed);

	std::cout << std::endl;

	Game newGame;

	std::cout << std::endl;

	return 0;
}
