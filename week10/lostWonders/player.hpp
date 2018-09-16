/*********************************************************************
** Program name: Project 5 (Text-based Game)
** Filename: player.hpp 
** Author: James G Wilson (wilsjame)
** Date: 3/20/2017
** Description: CS 162
** Player class header file
*********************************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include "bag.hpp" //where Artifacts enum is declared

class Player
{
	private:
		std::string name;
		Bag bag;

		//Time limit mechanisms
		int fuel,	
		    alignment;

		public:
		//default constructor
		Player();

		//set methods
		void setName(std::string name);
		void setFuel(int fuel);
		void setAlignment(int alignment);

		//get methods
		std::string getName();
		int getFuel();
		int getAlignment();

		//Player methods
		void decreaseFuel();
		void decreaseAlignment();
		void displayFuel();
		void displayAlignment();
		void displayArtifacts();
		void aquireArtifact(Artifacts artifact);
		void clearArtifacts();
};

#endif
