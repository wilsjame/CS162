/*********************************************************************
** Program name: Game.cpp
** Author: James G Wilson (wilsjame)
** Date: 2/17/2017
** Description: Project 3 CS 162
** Game represents the battle arena where creatures fight.
** Choose two creatures to fight and watch the battle happen!
*********************************************************************/
#include "Game.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include <iostream>
#include <limits> //input error handling
#include <cstdlib>

/*********************************************************************
** Description: gets user inputs for fight, then starts fight
** Arguments: none
** Retuns: none
*********************************************************************/
Game::Game(){

	int fighter1,
	    fighter2;
	bool endProgram = false;

	std::cout << "Select Fighter 1\n";
	fighter1 = getChoice();

	std::cout << "Select Fighter 2\n";
	fighter2 = getChoice();

	//create new creatures based off of fighters chosen
	switch(fighter1){
		case 1:
			//vampire
			c1 = new Vampire();
			break;
		case 2:
			//barbarian
			c1 = new Barbarian();
			break;
		case 3:
			//Blue Men
			c1 = new BlueMen();
			break;
		case 4:
			//Medusa
			c1 = new Medusa();
			break;
		case 5:
			//Harry Potter
			c1 = new HarryPotter();
			break;
		case 6:
			std::cout << "Goodbye\n";
			endProgram = true;
			break;
		default:
			std::cout << "Invalid choice\n";
			endProgram = true;
			break;
	}

	//check if user chose to quit the program
	if(endProgram){
		fighter2 = 6;
	}

	switch(fighter2){
		case 1:
			//vampire
			c2 = new Vampire();
			break;
		case 2:
			//barbarian
			c2 = new Barbarian();
			break;
		case 3:
			//Blue Men
			c2 = new BlueMen();
			break;
		case 4:
			//Medusa
			c2 = new Medusa();
			break;
		case 5:
			//Harry Potter
			c2 = new HarryPotter();
			break;
		case 6:
			std::cout << "Goodbye\n";
			endProgram = true;
			break;
		default:
			std::cout << "Invalid choice\n";
			endProgram = true;
			break;
	}

	if(!endProgram){

	//call fight function
	fight(c1, c2);
	}

	//delete new fighters
	delete c1;
	c1 = NULL;
	delete c2;
	c2 = NULL;
	

}

/*********************************************************************
** Description: displays figher menu and gets users fighter pick
** Arguments: none
** Retuns: int representing the fighter choice
*********************************************************************/
int Game::getChoice(){

	int fighterChoice;

	do{
		//fighter menu options
		std::cout << "----- Choose Your Fighters! -----\n";
		std::cout << "Please enter a valid menu option\n";
		std::cout << "1) Vampire\n";
		std::cout << "2) Barbarian\n";
		std::cout << "3) Blue Men\n";
		std::cout << "4) Medusa\n";
		std::cout << "5) Harry Potter\n";
		std::cout << "6) Exit the program\n";

		//menu selection error handling
		while(!(std::cin >> fighterChoice)){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid choice\n";
			//display menu options again
			std::cout << "----- Choose Your Fighters! -----\n";
			std::cout << "Please enter a valid menu option\n";
			std::cout << "1) Vampire\n";
			std::cout << "2) Barbarian\n";
			std::cout << "4) Medusa\n";
			std::cout << "5) Harry Potter\n";
			std::cout << "6) Exit the program\n";
		}
	}while(fighterChoice < 1 || fighterChoice > 6);
	return fighterChoice;
}

/*********************************************************************
** Description: has two creatures fight one another
** Arguments: two pointers to creatures objects
** Retuns: void, display winner
*********************************************************************/
void Game::fight(Creature* fighter1, Creature* fighter2){
	
	//determine first strike by generating a random number [1-2]
	firstStrike = (rand() % 2 + 1);
	std::cout << "Fighter " << firstStrike << " will attack first\n";

	do{
		switch(firstStrike){
			case 1:
				//fighter 1 attacks
				std::cout << "Fighter 1 attacks!\n";
				fighter2->defense(fighter1->attack());
				std::cout << "Round: " << round++;
				std::cout << " results: ";

				//check if a fighter was defeated
				if(fighter2->getStrength() <= 0){
					std::cout << "Fighter 1 wins!\n";
					stillStanding = false;
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
				fighter1->defense(fighter2->attack());
				std::cout << "Round: " << round++;
				std::cout << " results: ";

				//check if a fighter was defeated
				if(fighter1->getStrength() <= 0){
					std::cout << "Fighter 2 wins!\n";
					stillStanding = false;
				}
				else{
					std::cout << "The brawl continues...\n";
					std::cout << std::endl;
				}
				firstStrike = 1;
		}
		}while(stillStanding); //continue fighting until one fighter is eliminated
}
