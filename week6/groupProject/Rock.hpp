/************************************************************************************************************************
Authors: Dan Mitu, Koryn Leslie-Arcaya, James Wilson, Christopher Nguyen, Brian Penny, Joycelin Orellana, Connie McClung
Due Date: 2/26/17
Rock.hpp - This is the header for the rock tool. Fight assumes that the computer is the argument.
************************************************************************************************************************/
#ifndef ROCK_HPP
#define ROCK_HPP

#include "Tool.hpp"
class Rock : public Tool
{
	public:
		Rock(int str);
		Rock();
		Fight_Result fight(Tool* cpuTool);
};
#endif
