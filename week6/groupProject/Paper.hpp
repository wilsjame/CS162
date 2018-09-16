/************************************************************************************************************************
Authors: Dan Mitu, Koryn Leslie-Arcaya, James Wilson, Christopher Nguyen, Brian Penny, Joycelin Orellana, Connie McClung
Due Date: 2/26/17
Paper.hpp - This is the declaration for the paper tool. Fight assumes that the computer is the argument.
************************************************************************************************************************/

// Description: This is the header file for the Paper class.
#ifndef PAPER_HPP
#define PAPER_HPP

#include "Tool.hpp"
class Paper : public Tool
{
	public:
		Paper(int str);	
		Paper();
		Fight_Result fight(Tool* cpuTool);
};
#endif
