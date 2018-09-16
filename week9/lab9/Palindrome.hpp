/*********************************************************************
** Program name: Palindrome.hpp
** Author: James G Wilson (wilsjame)
** Date: 3/12/2170
** Description: Lab 9 CS 162
** This is the Palidrome class header file, see the class definitions
** file for a more detailed description
*********************************************************************/
#ifndef PALINDROME_HPP
#define PALINDROME_HPP
#include <string>
#include <stack>

class Palindrome
{
	private:
		std::string stringInput;
		std::stack< char > charStack; //deque stack (the default)
	public:
		Palindrome();

};
#endif
