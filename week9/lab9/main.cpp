/*********************************************************************
** Program name: main.cpp
** Author: James G Wilson (wilsjame)
** Date: 3/11/2017
** Description: Lab 9 CS 162
** This is main program used to test the Buffer and Palindrome classes.
**
** Use the accompanying makefile to create an executable file named
** main to run the program
*********************************************************************/
#include "Buffer.hpp"
#include "Palindrome.hpp"
#include <cstdlib>	//using random
#include <ctime>	//used to seed random 
#include <iostream>

int main()
{
	//seed random num generator
	unsigned seed;	
	seed = time(0);
	srand(seed);

	std::cout << "\n\n========Buffer Test========\n\n";
	Buffer newBuffer;
	std::cout << "\n\n========Palindrome Test========\n\n";
	Palindrome newPalindrome;
	std::cout << std::endl;

	return 0;
}
