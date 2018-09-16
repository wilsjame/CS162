/************************************************************************************************************************
Authors: Dan Mitu, Koryn Leslie-Arcaya, James Wilson, Christopher Nguyen, Brian Penny, Joycelin Orellana, Connie McClung
Due Date: 2/26/17
Tool.cpp - This is the implementation for a tool.
************************************************************************************************************************/
#include "Tool.hpp"

// Description: This function sets the tool's strength attribute to the parameter.
void Tool::set_strength(int str)
{
	strength = str;
}

// Description: This function returns the tool's type attribute.
char Tool::get_type()
{
	return type;
}

// Description: This function returns the tool's strength attribute.
int Tool::get_strength()
{
	return strength;
}
