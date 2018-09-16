/*********************************************************************
** Program name: Queue.cpp
** Author: James G Wilson (wilsjame)
** Date: 2/27/2017
** Description: Lab 7 CS 162
** The Queue class represents a circular linked list queue abstract
** data type. Queues are "first in first out" ADT's. This class allows
** one to add nodes, show the front node, remove the front node, 
** and display the entire queue. 
*********************************************************************/
#include "Queue.hpp"
#include <iostream>


/*********************************************************************
** Description: default constructor sets NEXT and PREV to nullptr.
**		Mitagates if user trys to remove or show front before
**		adding data
** Arguments: none
** Returns: none
*********************************************************************/
Queue::Queue()
{
	front = back = nullptr;

}

/*********************************************************************
** Description: checks if queue is empty or full. Then
**		either creates a new node and adds it to the back or
**		changes an existing empty node as the new back
** Arguments: a postive integer
** Returns: void
*********************************************************************/
void Queue::addBack(int dataIn)
{
	if(isEmpty()) //queue is empty, create the first node
	{
		front = new QueueNode(dataIn, front, front);
		back = front;
		back->NEXT= front;
	}
	else if(isFull()) //queue is full, create a new back node
	{
		//create a new back node          //NEXT  PREV
		back->NEXT = new QueueNode(dataIn, front, back);
		//set back to the newly created node above
		back = back->NEXT;
	}
	else //empty (-1) node after back, no need to use new
	{
		back = back->NEXT;
		back->data = dataIn;
	}
}

/*********************************************************************
** Description: returns the data value in the front node, if the 
**		queue is empty returns -1.
** Arguments: none
** Returns: int as the data value or -1 if empty
*********************************************************************/
int Queue::getFront()
{
	if(isEmpty())
	{
		//Queue Empty
		std::cout << "Error: Queue Empty\n";
		return -1;
	}
	else
	{
		return front->data;
	}
}

/*********************************************************************
** Description: Removes the first node by setting its data equal to 
**		-1 and shifts the front to the next node.
** Arguments: none
** Returns: -1 if the queue is empty, 0 otherwise
*********************************************************************/
int Queue::removeFront()
{
	if(isEmpty())
	{
		//Queue Empty
		std::cout << "Error: Queue Empty\n";
		return -1;
	}
	else
	{
		//set the current front data to -1 meaning empty
		//then move the front node
		front->data = -1;
		front = front->NEXT;
		return 0;
	}
}

/*********************************************************************
** Description: prints the contents of the queue to the console
** Arguments: none 
** Returns: none
*********************************************************************/
void Queue::display()
{
	//check if the queue is empty
	if(!isEmpty())
	{
		std::cout << "Printing the queue:   ";
		//temp used to traverse queue
		QueueNode *traverse = front;
		//temp used to signal the end of the queue 
		//QueueNode *tempBack = back;
		
		//print the first node
		std::cout << traverse->data << "   ";

		//traverse until the back node is reached
		while(traverse != back)
		{
			traverse = traverse->NEXT;
			std::cout << traverse->data << "   ";
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
** Description: checks if the queue is empty
** Arguments: none
** Returns: bool, true means the queue is empty, false otherwise
*********************************************************************/
bool Queue::isEmpty()
{
	//if the user has not added any values front will be 
	//nullptr, if the user has added items but removed them all
	//both front and back data will be -1
	if(front == nullptr)
	{
		//List is empty with nullptrs
		return true;
	}
	else if(front->data == -1 && back->data == -1)
	{
		//List is empty with -1's
		return true;
	}
	else
	{
		//List is not empty
		return false;
	}
}

/*********************************************************************
** Description: checks if queue is full. If the data in the node after
**		back is -1 then the queue is not full.
** Arguments: none
** Returns: bool, true means the queue is full, false otherwise
*********************************************************************/
bool Queue::isFull()
{
	//create a temp QueueNode to test the node after back
	QueueNode *temp;
	temp = back->NEXT;

	//checks the data in the node just after back
	if(temp->data == -1)
	{
		//List is not full
		return false;
	}
	else
	{
		//List is full
		return true;
	}
}

/*********************************************************************
** Description: desstructor deletes new memory
** Arguments: none
** Returns: none
*********************************************************************/
Queue::~Queue()
{
	//break the linked list by deleting one node and setting it
	//to nullptr
	QueueNode *garbage = back->NEXT;
	delete back;
	garbage->PREV= nullptr;

	//traverse the list as usual while cleaning up nodes
	QueueNode *tempGarbage = garbage;
	while(garbage != nullptr)
	{
		garbage = garbage->NEXT;
		tempGarbage->NEXT = nullptr;
		delete tempGarbage;
		tempGarbage = garbage;
	}

}

