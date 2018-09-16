/*********************************************************************
** Program name: reverseString.cpp
** Author: James G Wilson (wilsjame)
** Date: 2/11/2017
** Description: Lab 5 CS 162
** Function definition file for reverseString
**
** What it does: prints a string backwards 
**
** Arguments: an input string
**
** Returns: 0 when the base case is reached. Outputs the reversed
** string to the console
*********************************************************************/
#include "reverseString.hpp"
#include <iostream>

int reverseString(std::string string){

	//base case
	if(string.length() == 0){
		std::cout << std::endl;
		return 0;
	}

	std::cout << string[string.length() - 1];
	reverseString( string.erase( (string.length() - 1), 1 ) );
}
