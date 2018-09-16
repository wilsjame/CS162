/*********************************************************************
** Program name: Queue.hpp
** Author: James G Wilson (wilsjame)
** Date: 2/27/2017
** Description: Lab 7 CS 162
** This is the Queue class header file, see the definition file
** for a detailed description
*********************************************************************/
#ifndef QUEUE_HPP
#define QUEUE_HPP

class Queue
{
	//nodes will be structs in the linked list
	struct QueueNode
	{
		int data;
		QueueNode *NEXT;
		QueueNode *PREV;
		
		//constructor
		QueueNode(int data1, QueueNode *next1 = nullptr, QueueNode *prev1 = nullptr)
		{
			data = data1;
			NEXT = next1;
			PREV = prev1;
		}
	};
	//these track the front and back of the queue
	QueueNode *front;
	QueueNode *back;

	public:
	//constructor and desctructor
	Queue();
	~Queue();

	//member functions
	void addBack(int dataIn);
	int getFront();
	int removeFront();
	void display();
	bool isEmpty();
	bool isFull();
	
};
#endif
			
