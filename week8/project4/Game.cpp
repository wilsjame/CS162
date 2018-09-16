/*********************************************************************
** Program name: Game.cpp
** Author: James G Wilson (wilsjame)
** Date: 3/5/2017
** Description: Project 4 CS 162
** Game represents the battle arena where creatures fight.
** Choose two creatures to fight and watch the battle happen!
*********************************************************************/
#include "Queue.hpp"
#include "Game.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "Stack.hpp"
#include <iostream>
#include <limits> //input error handling
#include <cstdlib>
#include <string>

/*********************************************************************
** Description: gets user inputs for fight, then starts fight
** Arguments: none
** Retuns: none
*********************************************************************/
Game::Game(){

	//create loser stack
	Stack loserPile;
	
	std::cout << "\n\n----------------------------------\n\n";
	std::cout << "Create Player 1 Team\n";
	Queue player1;
	player1.display();
	std::cout << "\n\n----------------------------------\n\n";
	std::cout << "Create Player 2 Team\n";
	Queue player2;
	player2.display();

	//fight until one team is queue is empty
	while(!player1.isEmpty() && !player2.isEmpty())
	{
		//check which fighter won te round
		if(fight(player1.getFront(), player2.getFront()) == 1) //fighter 1 wins
		{
			p1Points++; //give player 1 a point
			//remove players 2 fallen fighter
			std::cout << "\n#### PLAYER 2 DEFEATED ####\n";
			std::cout << "Removing Player 2 Fighter: ";
			player2.getFighterName();		//display losers name
			loserPile.push(player2.getFront()); 	//push loser to loser stack
			player2.removeFront();			//remove loser from fighte queue 
			std::cout << std::endl;

			//send fighter 1 to the back of the line
			//and remove from front
			std::cout << "Player 1 Winning Fighter: ";
			player1.getFighterName();
			std::cout << " Goes to the back of the line with some health restored!\n";
			player1.addBack();
			player1.removeFront();	
			std::cout << "New line up for Player 1: \n";
			player1.display();
			std::cout << "\n<><><><><><>\n";
		}
		else //fighter 2 wins
		{
			p2Points++; //give player 2 a point
			//remove players 1 fallen fighter
			std::cout << "\n#### PLAYER 1 FIGHTER DEFEATED ####\n";
			std::cout << "Removing Player 1 Fighter: ";
			player1.getFighterName();		//display losers name
			loserPile.push(player1.getFront()); 	//push loser to loser stack
			player1.removeFront();			//remove loser from fighter queue
			std::cout << std::endl;

			//send fighter 2 to the back of the line
			//and remove from front
			std::cout << "Player 2 Winning Fighter: ";
			player2.getFighterName();
			std::cout << " Goes to the back of the line with some health restored!\n";
			player2.addBack();
			player2.removeFront();	
			std::cout << "New line up for Player 2: \n";
			player2.display();
			std::cout << "\n<><><><><><>\n";
		}
	}
	
	//determine winner and display results
	determineWinner();


	//show loser pile
	
	if(showLosers() == 1)
	{
		std::cout << "Displaying the loser pile (stack): \n";
		Creature * losers;
		while(!loserPile.isEmpty())
		{
			std::cout << std::endl;
			loserPile.pop(losers);
			losers->getName();
		}
		std::cout << "\n ^ First Loser on Bottom ^\n";
	}
}

/*********************************************************************
** Description: displays figher menu and gets users fighter pick
** Arguments: none
** Retuns: int representing the fighter choice
*********************************************************************/
int Game::showLosers(){

	int choice;

	do{
		//fighter menu options
		std::cout << "\n----- Display Contents of Loser Pile?-----\n";
		std::cout << "Please enter a valid menu option\n";
		std::cout << "1) Yes\n";
		std::cout << "2) No\n";

		//menu selection error handling
		while(!(std::cin >> choice)){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid choice\n";
			//display menu options again
			std::cout << "\n----- Display Contents of Loser Pile?-----\n";
			std::cout << "Please enter a valid menu option\n";
			std::cout << "1) Yes\n";
			std::cout << "2) No\n";
		}
	}while(choice < 1 || choice > 2);
	return choice;
}

/*********************************************************************
** Description: has two creatures fight one another
** Arguments: two pointers to creatures objects
** Retuns: returns an int. 1 if fighter 1 wins, 2 otherwise. 
**		displays winner as well
*********************************************************************/
int Game::fight(Creature* fighter1, Creature* fighter2){
	
	bool stillStanding = true;
	int round = 1,
	    damageTotal = 0;
	//determine first strike by generating a random number [1-2]
	firstStrike = (rand() % 2 + 1);
	std::cout << "Fighter " << firstStrike << " will attack first\n";

	do{
		switch(firstStrike){
			case 1:
				//fighter 1 attacks
				std::cout << "Fighter 1 attacks!\n";
				damageTotal += fighter2->defense(fighter1->attack());
				std::cout << "Round: " << round++;
				std::cout << " results: ";

				//check if a fighter was defeated
				if(fighter2->getStrength() <= 0){
					std::cout << "Fighter 1 wins!\n";
					fighter1->restore(damageTotal); //restore health based on damage
					stillStanding = false;
					return 1;
				}
				else{
					std::cout << "The brawl continues...\n";
					std::cout << std::endl;
				}
			case 2:
				//if a fighter has fallen break out of switch
				if(stillStanding == false){
					break;
				}

				//fighter 2 attacks
				std::cout << "Fighter 2 attacks!\n";
				damageTotal += fighter1->defense(fighter2->attack());
				std::cout << "Round: " << round++;
				std::cout << " results: ";

				//check if a fighter was defeated
				if(fighter1->getStrength() <= 0){
					std::cout << "Fighter 2 wins!\n";
					fighter2->restore(damageTotal); //restore health based on damage
					stillStanding = false;
					return 2;
				}
				else{
					std::cout << "The brawl continues...\n";
					std::cout << std::endl;
				}
				firstStrike = 1;
		}
		}while(stillStanding); //continue fighting until one fighter is eliminated
}

/*********************************************************************
** Description: determines the winner and displays results
** Arguments: none
** Returns: none
*********************************************************************/
void Game::determineWinner(){
	std::cout << "\n\n<><><><><><><><><><><><><><><><>\n";
	std::cout << "<><><><><><>FINAL RESULTS<><><><><><>\n\n";
	std::cout << "Player 1 Points (wins): " << p1Points;
	std::cout << "\nPlayer 2 Points (wins): " << p2Points;
	std::cout << std::endl;

	if(p1Points > p2Points)
	{
		std::cout << "Player 1 Wins!\n";
	}
	else if (p2Points > p1Points)
	{
		std::cout << "Player 2 Wins!\n";
	}
	else
	{
		std::cout << "Tie\n";
	}
}

