/*********************************************************************
** Program name: Stack.hpp
** Author: James G Wilson (wilsjame)
** Date: 3/5/2017
** Description: Project 4 CS 162
** A dynamic stack built on a linked list. Holds pointers to Creatures
*********************************************************************/
#ifndef STACK_HPP
#define STACK_HPP
#include "Creature.hpp"

class Stack
{
	struct StackNode
	{
		Creature* loser;
		StackNode *next;
		//constructor
		StackNode(Creature* loser1, StackNode *next1 = nullptr)
		{
			loser = loser1;
			next = next1;
		}
	};
	StackNode *top;
	
	public:
	Stack() { top = nullptr; }
	~Stack();
	void push(Creature*);
	void pop(Creature* &);
	bool isEmpty() const;

	//stack exception
	class Underflow {};
};
#endif
