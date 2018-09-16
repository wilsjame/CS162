/*********************************************************************
** Program name: main.cpp
** Author: James G Wilson (wilsjame)
** Date: 2/4/2017
** CS 162 Project 2 
** Description: Main program to test the List and Item classes
** Use the accompanied Makefile to compile an executable called main
** and run
*********************************************************************/
#include <iostream>
#include "List.hpp"
#include <limits>

int main()
{
	int choice;
	List list;

	while(true){
		std::cout << "1. add item\n";
		std::cout << "2. remove last item\n";
		std::cout << "3. display\n";
		std::cout << "4. exit\n";

		//error handling
		while(!(std::cin >> choice))
		{
			//clear errors
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Wrong input, please enter a number: ";
		}	

		switch(choice){
			case 1:
				list.addItem();
				break;
			case 2:
				list.removeItem();
				break;
			case 3:
				list.displayList();
				break;
			case 4:
				return 0;
			default:
				std::cout << "invalid choice";
		}
	}
	return 0;
}
