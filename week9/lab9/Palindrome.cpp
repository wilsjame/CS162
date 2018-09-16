/*********************************************************************
** Program name: Palindrome.cpp
** Author: James G Wilson (wilsjame)
** Date: 3/12/2017
** Description: Lab 9 CS 162
** This is the Palindrome class definition file.
** The palindrome class uses the STL stack containder to reverse a
** string input and output a palindrome.
*********************************************************************/
#include "Palindrome.hpp"
#include <string>
#include <iostream>
#include <stack>

/*********************************************************************
** Description: default constructor
** Arguments: none
** Returns: none
*********************************************************************/
Palindrome::Palindrome()
{
	//get a string user input
	std::cout << "Enter a string to create a palindrome: ";
	std::getline(std::cin, stringInput);

	//input string characters into the stack
	for(int stringIndex = 0; stringIndex < stringInput.length(); stringIndex++)
	{
		charStack.push(stringInput[stringIndex]);
	}

	//output palindrome
	std::cout << "Palindrome: ";
	std::cout << stringInput;		//first half 
	while(!charStack.empty())		//second half 
	{
		std::cout << charStack.top();	//show the top stack value
		charStack.pop();
	}
}
