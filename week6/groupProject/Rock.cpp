/************************************************************************************************************************
Authors: Dan Mitu, Koryn Leslie-Arcaya, James Wilson, Christopher Nguyen, Brian Penny, Joycelin Orellana, Connie McClung
Due Date: 2/26/17
Rock.cpp - This is the implementation for the rock tool. Fight assumes that the computer is the argument.
************************************************************************************************************************/
#include "Rock.hpp"

// Description: Constructor. Sets strength attribute to parameter, and type to rock.
Rock::Rock(int str)
{
	strength = str;
	type = 'r';
}

// Description: Default Constructor. Sets strength attribute to 1, and type to rock.
Rock::Rock()
{
	strength = 1;
	type = 'r';
}

// Description: This function determines the result of a fight between two tools. The player tool's
// strength is modified based on how its type compares to that of the cpu tool. After the
// modification, the two strengths are compared, and the highest one wins. If equal, it is a draw.
Fight_Result Rock::fight(Tool* cpuTool)
{
	int playerStr = this->get_strength();
	int cpuStr = cpuTool->get_strength();

	if (cpuTool->get_type() == 's')
		playerStr = playerStr * 2;

	if (cpuTool->get_type() == 'p')
		playerStr = playerStr / 2;

	if (playerStr > cpuStr)
		return PLAYER_WIN;

	else if (playerStr < cpuStr)
		return CPU_WIN;

	else
		return DRAW;
}
