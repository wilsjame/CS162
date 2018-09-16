/************************************************************************************************************************
Authors: Dan Mitu, Koryn Leslie-Arcaya, James Wilson, Christopher Nguyen, Brian Penny, Joycelin Orellana, Connie McClung
Due Date: 2/26/17
RPS_Game.hpp - This is the declaration for a RPS Game which pits a human against a CPU. Dynamic memory is automatically
allocated and freed each time play() is called, so no copy constructor/destructor/assignment operator is needed.
************************************************************************************************************************/
#include "Tool.hpp"
#include "Rock.hpp"
#include "Paper.hpp"
#include "Scissors.hpp"
#include <iostream>
#include <string> //for user input
#include <cstdlib> //for rand()
#include <ctime> //for srand(time(NULL))
#include <vector> //for again()
#include <algorithm> //for find()

#ifndef RPS_GAME_HPP
#define RPS_GAME_HPP
using std::cout;
using std::cin;
using std::endl;
using std::string;

class RPS_Game
{
	private:
		Tool * human;
		Tool * computer;
		unsigned int human_wins;
		unsigned int computer_wins;
		unsigned int draws;
		bool set_tools(); //creates the tools
		char choose_tool(); //prompts the user to select a tool
		int input_integer(string prompt); //helper function for input validation
		int input_integer(int min, string prompt); //helper function for input validation
		int input_integer(int min, int max, string prompt); //helper function for input validation
		bool again(string prompt);
	public:
		RPS_Game();
		void play(); //initiates the game
};
#endif
