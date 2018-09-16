/*********************************************************************
** Program name: Queue.hpp
** Author: James G Wilson (wilsjame)
** Date: 3/5/2017
** Description: project 4 CS 162
** This is the Queue class header file, see the definition file
** for a detailed description
**
** The struct data field now holds pointers to creature objects
*********************************************************************/
//#pragma once
#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "Stack.hpp"
#include "Creature.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include <string>

class Queue
{
	//nodes will be structs in the linked list
	struct QueueNode
	{
		Creature* fighter; //nodes will be holding pointers to creatures
		QueueNode *NEXT;
		//constructor to use after team has been created
		QueueNode(Creature* fighter1, QueueNode *next1 = nullptr)
		{
			fighter = fighter1;
			NEXT = next1;
		}

 		//constructor to use when creating the team
		QueueNode(int choice, std::string name, QueueNode *next1 = nullptr)
		{
			//create new creatures based off of fighter choice
			switch(choice){
				case 1:	fighter = new Vampire(name);
							break;
				case 2:	fighter = new Barbarian(name);
							break;
				case 3:	fighter = new BlueMen(name);
							break;
				case 4:	fighter = new Medusa(name);
							break;
				case 5:	fighter = new HarryPotter(name);
							break;
			}
			NEXT = next1;
		}
	};
	//this is the base front it will be used in the destructor for total memory deallocation
	QueueNode *baseFront;

	//these track the front and back of the queue
	QueueNode *front;
	QueueNode *back;

	public:
	//constructor and desctructor
	Queue();
	~Queue();

	//member functions
	void createTeam(int fighterType, std::string name);
	void addBack();
	Creature* getFront();
	void removeFront();
	void display();
	void getFighterName();
	bool isEmpty();
	int input_integer(std::string prompt);
	int input_integer(int min, int max, std::string prompt);
	int getChoice();
};
#endif
			
