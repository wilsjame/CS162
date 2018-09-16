/*********************************************************************
** Program name: Queue.cpp
** Author: James G Wilson (wilsjame)
** Date: 3/5/2017
** Description: project 4 CS 162
** The Queue class represents a circular linked list queue abstract
** data type. Queues are "first in first out" ADT's. This class allows
** one to add nodes, show the front node, remove the front node, 
** and display the entire queue. 
*********************************************************************/
#include "Queue.hpp"

#include "Stack.hpp"
#include "Creature.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"

#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

/*********************************************************************
** Description: default constructor sets NEXT and PREV to nullptr.
**		Mitagates if user trys to remove or show front before
**		adding data.
**		Assembles users team of fighters
** Arguments: none
** Returns: none
*********************************************************************/
Queue::Queue()
{
	baseFront = front = back = nullptr;
	int numFighters,
	    fighterChoice;
	std::string name;
	
	//create team 
	//get number of fighters on the team
	std::cout << "Tournament play requires atleast 2 fighters per team!\n";
	numFighters = input_integer(2, 50, "Enter the number of fighters: ");

	//get the type of each fighter and create a new fighter node
	for(int count = 0; count < numFighters; count++)
	{
		fighterChoice = getChoice();

		std::cout << std::endl;
		std::cout << "Enter the name of fighter ";
		std::cout << count + 1 << ": ";
		
		std::cin.ignore();
		getline(std::cin, name);
	
		createTeam(fighterChoice, name);
	}
}

/*********************************************************************
** Description: checks if queue is empty or full. Then
**		creates a new node and adds it to the back 
**		New node will create a new fighter
** Arguments: an int representing the fighter choice and a string for
**		the fighters name
** Returns: void
*********************************************************************/
void Queue::createTeam(int fighterType, std::string name)
{
	if(isEmpty()) //queue is empty, create the first node
	{
		std::cout << "\nCREATING FIRST FIGHTER\n";
		baseFront = new QueueNode(fighterType, name);
		back = front = baseFront;
	}
	else	//queue is full, create a new back node
	{
		//create a new back node        	  
		back->NEXT = new QueueNode(fighterType, name);
		//set back to the newly created node above
		back = back->NEXT;
	}
}

/*********************************************************************
** Description: moves the front fighter to the back.
**		moves the creature pointer at the front to the back
**		Use when the front fighter wins and is set to the back
** Arguments: none 
** Returns: void
*********************************************************************/
void Queue::addBack()
{
		//create a new back node          
		//with the creature pointer from the front
		back->NEXT = new QueueNode(front->fighter);
		//set back to the newly created node above
		back = back->NEXT;
}

/*********************************************************************
** Description: returns the data value in the front node, 
**		
** Arguments: none
** Returns: a pointer to a creature
*********************************************************************/
Creature* Queue::getFront()
{
	if(isEmpty())
	{
		//Queue Empty
		std::cout << "Fight Queue Empty\n";
	}
	else
	{
		return front->fighter;
	}
}

/*********************************************************************
** Description: Checks if the fighter is dead or alive
**		if dead send to the loser stack
**		else if alive send the back of the lineup
** Arguments: none
** Returns: -1 if the queue is empty, 0 otherwise
*********************************************************************/
void Queue::removeFront()
{
	//create a temp node to for removal process
	//QueueNode *temp = nullptr;

	if(isEmpty())
	{
		//Queue Empty FIGHT IS OVER
		std::cout << "Queue Empty, fight is over\n";
	}
	else
	{
		//temp = front;
		front = front->NEXT;
		
		//delete temp->fighter; //delete fighter (created with new) in node
		//temp->fighter = nullptr;
		
		//delete temp;
	}
}

/*********************************************************************
** Description: prints the names of the fighters
** Arguments: none 
** Returns: none
*********************************************************************/
void Queue::display()
{
	//check if the queue is empty
	if(!isEmpty())
	{
		std::cout << "~~~~~~~~~~~~~~\n";
		std::cout << "Fighter Queue:   \n\n";
		//temp used to traverse queue
		QueueNode *traverse = front;
		
		//print the first node
		traverse->fighter->getName();

		//traverse until the back node is reached
		while(traverse != back)
		{
			std::cout << std::endl;
			traverse = traverse->NEXT;
			traverse->fighter->getName();
		}
		std::cout << std::endl;
	}
	else
	{
		//Queue is empty
		std::cout << "Error: Queue Empty\n";
	}
}

/*********************************************************************
** Description: prints name of fighter at the front
** Arguments: none
** Returns: none
*********************************************************************/
void Queue::getFighterName()
{
	front->fighter->getName();
}

/*********************************************************************
** Description: checks if the queue is empty
** Arguments: none
** Returns: bool, true means the queue is empty, false otherwise
*********************************************************************/
bool Queue::isEmpty()
{
	if(front == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*********************************************************************
** Description: gets a user input for an integer
** Arguments: none
** Returns: an integer
*********************************************************************/
int Queue::input_integer(std::string prompt)
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

/*********************************************************************
** Description: gets a user input for an integer in a range
** Arguments: none
** Returns: an integer
*********************************************************************/
//forces user to input an integer within a range
//returns that input
int Queue::input_integer(int min, int max, std::string prompt)
{
	if(min > max)
	{
		throw std::invalid_argument("min is greater than max");
	}

	int user_input;
	bool input_is_valid;
	do
	{
		user_input = input_integer(prompt);
		if((user_input > max) || (user_input < min))
		{
			input_is_valid = false;
			std::cout << "Error: enter an integer that's between " << min << " and " << max << "." << std::endl;
		} else {
			input_is_valid = true;
		}
	} while(!input_is_valid);

	return user_input;
}


/*********************************************************************
** Description: displays figher menu and gets users fighter pick
** Arguments: none
** Retuns: int representing the fighter choice
*********************************************************************/
int Queue::getChoice(){

	int fighterChoice;

	do{
		//fighter menu options
		std::cout << "----- Choose Your Fighters! -----\n";
		std::cout << "Please enter a valid menu option\n";
		std::cout << "1) Vampire\n";
		std::cout << "2) Barbarian\n";
		std::cout << "3) Blue Men\n";
		std::cout << "4) Medusa\n";
		std::cout << "5) Harry Potter\n";
		//std::cout << "6) Exit the program\n";

		//menu selection error handling
		while(!(std::cin >> fighterChoice)){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid choice\n";
			//display menu options again
			std::cout << "----- Choose Your Fighters! -----\n";
			std::cout << "Please enter a valid menu option\n";
			std::cout << "1) Vampire\n";
			std::cout << "2) Barbarian\n";
			std::cout << "4) Medusa\n";
			std::cout << "5) Harry Potter\n";
			//std::cout << "6) Exit the program\n";
		}
	}while(fighterChoice < 1 || fighterChoice > 5);
	return fighterChoice;
}

/*********************************************************************
** Description: desructor deletes new memory
** Arguments: none
** Returns: none
*********************************************************************/
Queue::~Queue()
{
	std::cout << "destructor starting..\n";
	//set the front node to original base front 	
	front = baseFront; 
	QueueNode * garbage = front;

	do
	{
		front = front->NEXT;
		garbage->NEXT = nullptr;
		delete garbage->fighter; //delete fighter (created with new) in node
		garbage->fighter = nullptr;
		delete garbage;
		garbage = front;
	}while(garbage->NEXT != nullptr);

	//delete last fighter
	//and back node
	delete back->fighter;
	back->fighter = nullptr;
	delete back;
}

