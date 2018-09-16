/*********************************************************************
** Program name: inputValid.hpp
** Author: James G Wilson (wilsjame)
** Date: 3/18/2017
** Description: input validation class header file
*********************************************************************/
#ifndef INPUTVALID_HPP
#define INPUTVALID_HPP
#include <string>

class inputValid
{
	public:
		int input_integer(std::string prompt);
		int input_integer(int min, std::string prompt);
		int input_integer(int min, int max, std::string prompt);
		bool again(std::string prompt);
};
#endif


