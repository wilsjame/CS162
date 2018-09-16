/************************************************************************************************************************
Authors: Dan Mitu, Koryn Leslie-Arcaya, James Wilson, Christopher Nguyen, Brian Penny, Joycelin Orellana, Connie McClung
Due Date: 2/26/17
Paper.cpp - This is the declaration for a tool.
************************************************************************************************************************/
#ifndef TOOL_HPP
#define TOOL_HPP

#include <iostream>
using namespace std;

enum Fight_Result { PLAYER_WIN, CPU_WIN, DRAW };

class Tool
{
	protected:
		char type;
		int strength;
	public:
		virtual ~Tool() = default; 
		void set_strength(int str);
		char get_type();
		int get_strength();
		virtual Fight_Result fight(Tool* cpuTool) = 0;
};
#endif
