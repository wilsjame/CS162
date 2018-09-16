/********************************************************************
** Program name: main.cpp
** Author: James G Wilson (wilsjame)
** Date: 3/18/2017
** Description: CS 162
*********************************************************************/
#include "inputValid.hpp"
#include "main_menu.hpp" //menu functions
#include "engine.hpp"
#include <iostream>
#include <ctime>   //random number seeding
#include <cstdlib> //random number generator


int main()
{
	//seed random number generator
	unsigned seed;
	seed = time(0);
	srand(seed);

	int choice;
	inputValid userMenu;

	//ask user if they want to play a new game
	do
	{
		displayIntro();
		choice = userMenu.input_integer(1,2,">>>");
		if(choice == 1)
		{
			displayLetter();
			
			//create new game engine object to begin 
			Engine newGame;
			newGame.run();
		}

		//ask if user wants to play again
		std::cout << "Do you want to play again?\n"
			<< "1) Yes\n"
			<< "2) No\n";
		choice = userMenu.input_integer(1,2,">>>");

	}while(choice != 2);

	std::cout << "The letter evaporates into a "
		<< "millions shining particles and is gone.\n";

	return 0;
}
