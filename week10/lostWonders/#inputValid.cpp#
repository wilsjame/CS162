/*********************************************************************
** Program name: inputValid.cpp
** Author: James G Wilson (wilsjame)
** Date: 3/18/2017
** Description: input validation class definition file
*********************************************************************/
#include "inputValid.hpp"
#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>



//forces user to input an integer
//returns that input
int inputValid::input_integer(std::string prompt)
{
	std::string user_input;
	bool input_is_valid = false;
	int return_integer;

	do
	{
		std::cout << prompt;
		std::getline(std::cin, user_input);

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

//forces user to input a min integer
//returns that input
int inputValid::input_integer(int min, std::string prompt)
{
	int user_input;
	bool input_is_valid;
	do
	{
		user_input = input_integer(prompt);
		if(user_input < min)
		{
			input_is_valid = false;
			std::cout << "Error: enter an integer that's at least " << min << "." << std::endl;
		} else {
			input_is_valid = true;
		}
	} while(!input_is_valid);

	return user_input;
}

//forces user to input an integer within a range
//returns that input
int inputValid::input_integer(int min, int max, std::string prompt)
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

//forces the user to enter either y/n
//if yes, returns true
//if no, returns false
bool inputValid::again(std::string prompt)
{
	std::vector<std::string> yes = {"y", "Y", "yes", "Yes", "YES"};
	std::vector<std::string> no = {"n", "N", "no", "No", "NO"};
	bool inputIsValid;
	bool yesSelected;
	std::string userInput; 
	std::cout << prompt;
	do
	{
		std::getline(std::cin, userInput);
		if(std::find(yes.begin(), yes.end(), userInput) != yes.end())
		{
			yesSelected = true;
			inputIsValid = true;
		} else if (std::find(no.begin(), no.end(), userInput) != no.end())
		{
			yesSelected =  false;
			inputIsValid = true;
		} else {
			std::cout << "Error: please enter either y/n." << std::endl;
		}
	}while(!inputIsValid);
	return yesSelected;
}
