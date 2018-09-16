/*********************************************************************
** Description: use a linear search algorithm to find a value in a vector
**		using linear search from page 604 in C++ Early Objects 9th
** Arguments: vector passed by constant reference
** Returns: int position in vector of value or -1 if not found
*********************************************************************/
#include "searchVector.hpp"

int searchVector(std::vector<int> const &vectorIn, int target)
{
	int index = 0;		//subscript to search array
	int position = -1;	//record position of target
	bool found = false; 	//flag to indicate if target found

	while(index < vectorIn.size() && !found)
	{
		if(vectorIn[index] == target)	//if value is found
		{
			found = true;		//set flag
			position = index;	//record targets subscript
		}
		index++;			//go to next element
	}
	return position;			//return position, or -1
}

