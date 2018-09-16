/*********************************************************************
** Description: use a binary search algorithm to find a value in a vector
**		using binary search from page 607 in C++ Early Objects 9th
** Arguments: vector passed by constant reference
** Returns: int position in vector of value or -1 if not found
*********************************************************************/
#include "binarySearch.hpp"

int binarySearch(std::vector<int> const &vectorIn, int target)
{
	int first = 0,			//first array element
	    last = vectorIn.size() - 1,		//last array element
	    middle,			//midpoint of search
	    position = -1;		//position of search value

	bool found = false;		//flag

	while(!found && first <= last)
	{
		middle = (first + last) / 2;	//calculate midpoint
		if(vectorIn[middle] == target)	//if target is found
		{
			found = true;
			position = middle;
		}
		else if(vectorIn[middle] > target) //if target is in lower half
		{
			last = middle -1;
		}
		else //value is in upper half
		{
			first = middle + 1;
		}
	}
	return position;
}

