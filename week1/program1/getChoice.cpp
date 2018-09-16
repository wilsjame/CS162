/*********************************************************************
** Program name: getChoice.cpp
** Author: James G Wilson (wilsjame)
** Date: 1/22/2016
** Description: To be used with the getMenu function
*********************************************************************/

/*********************************************************************
** Description: getChoice function
** This function gets the users input, validates it, and returns it
*********************************************************************/
#include <iostream>

int getChoice()
{
	int choice;

	std::cin >> choice;
	while(choice < 1 || choice > 2)
	{
		std::cout << "That is not a valid choice. Re-enter.";
		std::cin >> choice;
	}
	return choice;
}


