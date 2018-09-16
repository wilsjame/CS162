/*********************************************************************
** Program name: Buffer.hpp
** Author: James G Wilson (wilsjame)
** Date: 3/11/2017
** Description: Lab 9 CS 162
** this is the Buffer class header file, see the class definitions file
** for a more detailed description.
*********************************************************************/
#ifndef BUFFER_HPP
#define BUFFER_HPP
#include <cstdlib>	//using random
#include <deque>
#include <string>

class Buffer
{
	private:
		std::deque<int> iBuffer;
		int length,
		    chanceAdd,
		    chanceRemove,
		    roundsTotal,
		    roundsCount = 1;

		double averageLengthPrev = 0,
		       averageLength;

	public:
		Buffer();
		int genRand(int min, int max);
		void add(int percentChance); 
		void remove(int percentChance);
		double calcAverageLength();
		void displayResults();
		int input_integer(std::string prompt);
		int input_integer(int min, int max, std::string prompt);
};
#endif 
