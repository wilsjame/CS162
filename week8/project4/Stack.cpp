
/*********************************************************************
** Program name: Stack.cpp
** Author: James G Wilson (wilsjame)
** Date: 3/5/2017 
** Description: Project 4 CS 162
** A dynamic stack built on a linked list. Holds pointers to Creatures
*********************************************************************/
#include "Stack.hpp"

/*********************************************************************
** Description: pushes argument onto stack
** Arguments: pointer to Creature
** Returns: none
*********************************************************************/
void Stack::push(Creature* loser)
{
	top = new StackNode(loser, top);
}

/*********************************************************************
** Description: removes value at the top of the stack and copies it
**		into the variable passed an argument
** Arguments:
** Returns:
*********************************************************************/
void Stack::pop(Creature* &popLoser)
{
	StackNode *temp;

	if(isEmpty()) 
	{
		throw Stack::Underflow(); 
	}
	else
	{
		//pop value off top of stack
		popLoser = top->loser;
		temp = top;
		top = top->next;
		delete temp;
	}
}

/*********************************************************************
** Description: checks if stack is empty
** Arguments: none
** Returns: bool true is stack is empty, false otherwise
*********************************************************************/
bool Stack::isEmpty() const
{
	return top == nullptr;
}

/*********************************************************************
** Description: destructor deletes memory
** Arguments:
** Returns:
*********************************************************************/
Stack::~Stack()
{
	StackNode * garbage = top;
	while(garbage != nullptr)
	{
		top = top->next;
		garbage->next = nullptr;
		delete garbage;
		garbage = top;
	}
}



