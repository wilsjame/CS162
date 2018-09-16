/*********************************************************************
** Program name: Game.cpp
** Author: James G Wilson (wilsjame)
** Date: 1/30/2017
** Description: Lab3 CS 162
** Game class implementation file
**
** This class represents the war dice game. It includes a two die
** objects- one for each player. The die can be either normal or
** loaded. It uses these dice to simulate the war dice game. All you
** need to do is initialize a Game class instance with the default
** constructor and the game begins! The class has been broken down 
** into functions that are utilized in the defualt constructor. 
*********************************************************************/
#include "Game.hpp"
#include <iostream>

/*********************************************************************
** Description: defualt constructor
** 
*********************************************************************/
Game::Game()
{
	std::cout << "---------------WAR DICE-------------\n";
	winsP1 = 0;
	winsP2 = 0;

	//set the number of rounds
	setRounds();

	//get and set dice type 
	setDice();

	//get and set the number of dice sides
	setSides();

	//dynamically create dice with sides 
	createDice();

	//play the game 
	for(int r = 0; r < rounds; r++){
		rollEm();
	}

	//display die type used 
	
	std::cout << "-----------RESULTS----------\n";
	std::cout << "\nPlayer 1 was rolling a ";
	if(dieP1 == 1){
		std::cout << "normal die\n";
	}
	else{
		std::cout << "loaded die\n";
	}

	std::cout << "Player 2 was rolling a ";
	if(dieP2 == 1){
		std::cout << "normal die\n";
	}
	else{
		std::cout << "loaded die\n";
	}

	//display rounds won
	//std::cout << "----------------------------";
	std::cout << "Player 1 won " << winsP1 << " rounds!\n";
	std::cout << "Player 2 won " << winsP2 << " rounds!";
	std::cout << std::endl;

	//display final result
	if(winsP1 > winsP2)
	{
		std::cout << "Player 1 is the winner!";
		std::cout << " Nice!\n";
	}
	else if(winsP2 > winsP1)
	{
		std::cout << "Player 2 is the winner!";
		std::cout << " Way to go!\n";
	}
	else{
		std::cout << "It's a draw.\n";
	}
}	

/*********************************************************************
** Description: setRounds
** Sets the numbers of rounds with a user input
** No arguments and no return value
*********************************************************************/
void Game::setRounds()
{
	int rounds;

	do{
	//get number of rounds to play
	std::cout << "Enter the number of rounds to play: ";
	std::cin >> rounds;
	}
	while(rounds <= 0);

	//equate user inputted rounds to private member rounds
	this->rounds = rounds;
}

/*********************************************************************
** Description: setDice
** Gets and sets the Die type for players 1 and 2
** No arguments and no return value
*********************************************************************/
void Game::setDice()
{
	//get player1 die type
	do{
		std::cout << "\nChoose player 1's die type:\n"; 
		std::cout << "Enter 1 or 2\n";
		std::cout << "1. Normal die\n" << "2. Loaded die";
		std::cout << std::endl;
		std::cin >> dieP1;
	}
	while(dieP1 != 1 && dieP1 !=2);

	//get player 2 die type
	do{
		std::cout << "\nChoose player 2's die type:\n"; 
		std::cout << "Enter 1 or 2\n";
		std::cout << "1. Normal die\n" << "2. Loaded die";
		std::cout << std::endl;
		std::cin >> dieP2;
	}
	while(dieP2 != 1 && dieP2 !=2);
}

/*********************************************************************
** Description: setSides
** Gets and sets the number of sides for each dice
** No arguments and no return value
*********************************************************************/
void Game::setSides()
{
	//get sides for player 1
	do{
		std::cout << "\nEnter the number of sides for player ";
		std::cout << "1's die: ";
		std::cin >> dieP1Sides;
		if(dieP1Sides <= 3)
		{
			std::cout << "\nA Die must have 4 or more sides!";
		}
	}
	while(dieP1Sides <=3);

	//get sides for player 2
	do{
		std::cout << "Enter the number of sides for player ";
		std::cout << "2's die: ";
		std::cin >> dieP2Sides;
		if(dieP2Sides <= 3)
		{
			std::cout << "\nA Die must have 4 or more sides!";
		}
	}
	while(dieP2Sides <=3);
}

/*********************************************************************
** Description: createDice
** Dynamically creates die for players 1 and 2
** No arguments and no return value
*********************************************************************/
void Game::createDice()
{
	//dynamically create player 1's die with sides
	switch(dieP1)
	{
		case 1: dieP1Pointer = new Die(dieP1Sides);
			break;
		case 2: dieP1Pointer = new LoadedDie(dieP1Sides);
	}
	//dynamically create player 2's die with sides
	switch(dieP2)
	{
		case 1: dieP2Pointer = new Die(dieP2Sides);
			break;
		case 2: dieP2Pointer = new LoadedDie(dieP2Sides);
	}
}

/*********************************************************************
** Description: rollEm
** Uses the Die member functions to roll the dice for players 1 and 2
** Rolls only once per call.
** Displays the value for each players roll and the winner or draw
** if tied.
** No arguments no return value
*********************************************************************/
void Game::rollEm()
{
	int p1Roll,
	    p2Roll;

	//roll player 1's die, set p1Roll, and print
	std::cout << "----------------------------";
	p1Roll = dieP1Pointer->roll();
	std::cout << "\nPlayer 1 rolled: ";
	std::cout << p1Roll << std::endl;

	//roll player 2's die, set p2Roll, and print
	p2Roll = dieP2Pointer->roll();
	std::cout << "\nPlayer 2 rolled: ";
	std::cout << p2Roll << std::endl;

	//assign wins or declare draw
	if(p1Roll > p2Roll)
	{
		std::cout << "\nPlayer 1 wins this round!\n";
		winsP1++;
	}
	else if(p2Roll > p1Roll)
	{
		std::cout << "\nPlayer 2 wins this round!\n";
		winsP2++;
	}
	else{
		std::cout << "Draw\n";
	}

	//display total rounds won by each user
	std::cout << "Player 1 has won: ";
	std::cout << winsP1 << " rounds.\n";
	std::cout << "Player 2 has won: ";
	std::cout << winsP2 << " rounds.\n";
}

/*********************************************************************
** Description: descructor
** Deallocates the memory from the dynamically created Die objects.
** Prevents memory leaks.
*********************************************************************/
Game::~Game()
{
	delete dieP1Pointer;
	delete dieP2Pointer;
	dieP1Pointer = NULL;
	dieP1Pointer = NULL;
}
