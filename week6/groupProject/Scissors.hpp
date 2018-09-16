/************************************************************************************************************************
Authors: Dan Mitu, Koryn Leslie-Arcaya, James Wilson, Christopher Nguyen, Brian Penny, Joycelin Orellana, Connie McClung
Due Date: 2/26/17
Scissors.hpp - This is the header for the scissors tool. Fight assumes that the computer is the argument.
************************************************************************************************************************/
#ifndef SCISSORS_HPP
#define SCISSORS_HPP
#include "Tool.hpp"

class Scissors : public Tool
{
	public:
		Scissors(int str);
		Scissors();
		Fight_Result fight(Tool* cpuTool);
};
#endif