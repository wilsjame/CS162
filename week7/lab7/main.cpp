/*********************************************************************
** Program name: main.cpp
** Author: James G Wilson (wilsjame)
** Date: 2/27/2017
** Description: Lab 7 CS 162
** This is main driver program to test the the queue class
**
** Use the accompanying makefile to create an executable named main
*********************************************************************/
#include "Queue.hpp"
#include <iostream>
#include <limits> 
#include <string>
#include <stdexcept>

//function prototypes
int input_integer(std::string prompt);

int main()
{
	//doubly linked circular (DLC) queue
	Queue DLC_Queue;
	char choice;
	int dataIn;

	while(choice != 'x')
	{
		//get valid char input from menu choices
		do{
			std::cout << std::endl;
			std::cout << "-----Doubly Linked List Queue-----\n";
			std::cout << "Choose a valid menu option\n";
			std::cout << "a. Enter a value to be added to the queue\n";
			std::cout << "b. Display first node (front) value\n";
			std::cout << "c. Remove first node (front) value\n";
			std::cout << "d. Display the queue contents\n";
			std::cout << "x. Exit\n";

			while(true)
			{
				std::cin >> choice; //grab the first character
				if(std::cin.get() != '\n') //look at next character
				{
					//clear input stream
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
					std::cout << "Aye! Only one character, please: ";
				}
				else{
					break;
				}
			}
		}while(choice != 'a' && choice != 'b' && choice != 'c' && choice != 'd' && choice != 'x');

		switch(choice)
		{
			case 'a':
				dataIn = input_integer("Enter a value to add: ");
				DLC_Queue.addBack(dataIn);
				break;
			case 'b':
				//if getFrot returns -1 skip output, queue is empty
				if(DLC_Queue.getFront() != -1) 
				{
				std::cout << "The first node (front) value is: ";
				std::cout << DLC_Queue.getFront() << std::endl; 
				}
				break;
			case 'c':
				//if removeFront returns -1 skip action, queue is empty
				if(DLC_Queue.removeFront() != -1)
				{
				std::cout << "Removing the first node (front)...\n";
				}
				break;
			case 'd':
				DLC_Queue.display();
				break;
			case 'x':
				std::cout << "Goodbye\n";
				return 0;
				break;
		}
	}
}

/*********************************************************************
** Description: forces user to input an integer
** Arguments: string for the prompt
** Returns: integer input
*********************************************************************/
int input_integer(std::string prompt)
{
	std::string user_input;
	bool input_is_valid = false;
	int return_integer;

	do
	{
		std::cout << prompt;
		getline(std::cin, user_input);

		try //convert the user input into an integer
		{
			//check for digits
			if(!(user_input.find_first_not_of("-0123456789")))
			{
				throw std::runtime_error("non-numeric character inputed");
			}
			return_integer = stoi(user_input);
			input_is_valid = true;

		} catch(const std::exception& e)
		{
			//number could not be converted.
			std::cout << "Error: \"" << user_input << "\" is invalid." << std::endl;
			input_is_valid = false;
		}

	} while(!input_is_valid);

	return return_integer;
}

