/*********************************************************************
** Program name: Buffer.cpp
** Author: James G Wilson (wilsjame)
** Date: 3/11/2017
** Description: Lab 9 CS 162
** this is the buffer class definitions file. The Buffer class 
** is used to demonstrate the functionality of a standard queue 
** abstract data type (ADT) using standard temmplate library (STL)
** containers. Specifically the deque container.
*********************************************************************/
#include "Buffer.hpp"
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <limits>
#include <string>

/*********************************************************************
** Description: default constructor
** Arguments: none
** Returns: none
** Walks user through implementing the Buffer class
*********************************************************************/
Buffer::Buffer()
{
	//get user inputs
	roundsTotal = input_integer(0, 9001, "Enter the total number of rounds to test the Buffer: ");
	chanceAdd = input_integer(0, 100, "Enter a chance in the range [0,100], where 100 = %100, that a number will be added to the Queue :");
	chanceRemove= input_integer(0, 100, "Enter a chance in the range [0,100], where 100 = %100, that a number will be removed from the Queue :");

	for(roundsCount; roundsCount < roundsTotal + 1; roundsCount++)
	{
		add(chanceAdd);
		remove(chanceRemove);
		displayResults();
	}
}

/*********************************************************************
** Description: generates a random integer between min and max 
** Arguments: integers representing the min and max range 
** Returns: a random integer
*********************************************************************/
int Buffer::genRand(int min, int max)
{
	int random;

	random = rand() % (max - min + 1) + min;

	return random;
}

/*********************************************************************
** Description: may or may not add a number to the queue depending 
**		the user specified percentage
** Arguments: an int representing the chance a number will be added
** Returns: none
*********************************************************************/
void Buffer::add(int percentChance)
{
	std::cout << std::endl;
	//generate a random num 1-100
	//if percent chance is within range then add to queue
	while(percentChance >= genRand(1,100))
	{
		//random num is is specified range
		iBuffer.push_back(genRand(0, 100));	//removes from back
		std::cout << "Random push successful!";
		return;
	}

	std::cout << "Random push unsuccessful.";
}

/*********************************************************************
** Description: may or may not remove a number from the queue depending
		on the user specified percentage
** Arguments: an int representing the chance a number will be removed
		from the queue
** Returns: none
*********************************************************************/
void Buffer::remove(int percentChance)
{
	std::cout << std::endl;
	//cannot remove an element from an empty queue
	if(iBuffer.empty())
	{
		std::cout << "Removal unsuccessful, empty buffer.";
	}
	else
	{
		//generate a random num 1-100
		//if percent chance is within range then remove from queue
		while(percentChance >= genRand(1,100))
		{
			//random num is is specified range
			iBuffer.pop_front();	//removes from front
			std::cout << "Removal successful!";
			return;
		}

		std::cout << "Removal unsuccessful.";
	}
}

/*********************************************************************
** Description: calculates the average length of the queue 
** Arguments: none
** Returns: an int representing the average length of the queue
*********************************************************************/
double Buffer::calcAverageLength()
{
	std::cout << "\nprev average length: " << averageLengthPrev;
	std::cout << "\nbuffer size: " << iBuffer.size();
	std::cout << "\nround: " << roundsCount;

	averageLength = (( averageLengthPrev * (roundsCount - 1) + iBuffer.size() ) / roundsCount);
	averageLengthPrev = averageLength;

	return averageLength;
}

/*********************************************************************
** Description: displays the contents of the queue and the average length
** Arguments: none
** Returns: none
*********************************************************************/
void Buffer::displayResults()
{
	std::cout << "\nCurrent buffer contents:   "; 

	for(int index = 0; index < iBuffer.size(); index++)
	{
		std::cout << iBuffer[index] << "   ";
	}

	std::cout << "\nCurrent average length:     " << calcAverageLength();
	std::cout << std::endl;
}

/*********************************************************************
** Description: gets a user input for an integer
** Arguments: none
** Returns: an integer
*********************************************************************/
int Buffer::input_integer(std::string prompt)
{
	std::string user_input;
	bool input_is_valid = false;
	int return_integer;

	do
	{
		std::cout << prompt;
		getline(std::cin, user_input);

		try //convert the user input into an integer
		{
			//check for digits
			if(!(user_input.find_first_not_of("-0123456789")))
			{
				throw std::runtime_error("non-numeric character inputed");
			}
			return_integer = stoi(user_input);
			input_is_valid = true;

		} catch(const std::exception& e)
		{
			//number could not be converted.
			std::cout << "Error: \"" << user_input << "\" is invalid." << std::endl;
			input_is_valid = false;
		}

	} while(!input_is_valid);

	return return_integer;
}

/*********************************************************************
** Description: gets a user input for an integer in a range
** Arguments: none
** Returns: an integer
*********************************************************************/
//forces user to input an integer within a range
//returns that input
int Buffer::input_integer(int min, int max, std::string prompt)
{
	if(min > max)
	{
		throw std::invalid_argument("min is greater than max");
	}

	int user_input;
	bool input_is_valid;
	do
	{
		user_input = input_integer(prompt);
		if((user_input > max) || (user_input < min))
		{
			input_is_valid = false;
			std::cout << "Error: enter an integer that's between " << min << " and " << max << "." << std::endl;
		} else {
			input_is_valid = true;
		}
	} while(!input_is_valid);

	return user_input;
}
