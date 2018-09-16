/*********************************************************************
** Program name: main.cpp
** Author: James G Wilson (wilsjame)
** Date: 2/20/2017
** Description: Lab 6 CS 162
** This is the main program to run Lab 6. 
** Creates a simple list structure consisting of node objects
** The user will be able to enter values into the list and 
** manipulate the list.
**
** Use the accompanying Makefile to create an exectuable named
** main to run this program.
*********************************************************************/
#include <iostream>
#include <limits>

//define list node structure
struct ListNode{
	int value;
	ListNode *next;
	//constructor
	ListNode(int value1, ListNode *next1 = nullptr){
		value = value1;
		next = next1;
	}
};

int main(){

	int number,				
	    choice,
	    listEntries;
		
	while(true){
		//define ListNodes here so if user
		//repeats program theyre all set to null
		ListNode *head = nullptr,		
			 *tail = nullptr,
			 *beforeTailPtr = nullptr,
			 *nodePtr = nullptr;


		std::cout << "Welcome to linked list!\n";

	/*****************************************************************/
		//create linked list

		do{
			std::cout << "Enter a number: \n";
			//std::cin.ignore();

			while(!(std::cin >> number)){
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Please enter a number: ";
			}

			//add number to linked list
			if(head == nullptr){
				head = new ListNode(number);
				head->next = nullptr;
				tail = head;
			}
			else{
				//the list is not empty
				//use nodePtr to traverse the list
				nodePtr = head;
				while(nodePtr->next != nullptr){
					nodePtr = nodePtr->next;
				}

				//nodePtr->next is nullptr so nodePtr points to last node
				//Create a new node with the number added and put it
				//after the last node
				nodePtr->next = new ListNode(number);

				//set before tail pointer
				beforeTailPtr = nodePtr;
				//set tail to the last value in the list
				tail = nodePtr->next;
				tail->next = nullptr;
				nodePtr = nullptr;
			}

			//ask user if they want to enter another number
			do{
				std::cout << "\n---------------------------------------\n";
				std::cout << "Do you want another number?\n";
				std::cout << "Please enter a valid menu choice\n";
				std::cout << "1) yes\n2) no\n";

				while(!(std::cin >> choice)){
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Please enter a number: ";
				}
			}while(choice < 1 || choice > 2);
		}while(choice == 1);

	/*****************************************************************/
		//print values in list in order
		
		std::cout << "\nYour linked list is: ";
		//start at head of list
		nodePtr = head;
		while(nodePtr){
			//print value in the current node
			std::cout << nodePtr->value << "    ";
			//move on to the next node
			nodePtr = nodePtr->next;
		}
		std::cout << std::endl;

	/*****************************************************************/
		//get the head or tail value
		
			do{
				std::cout << "\n---------------------------------------\n";
				std::cout << "Do you want to get the head or tail node?\n";
				std::cout << "Please enter a valid menu choice\n";
				std::cout << "1) head\n2) tail\n";

				while(!(std::cin >> choice)){
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Please enter a number: ";
				}
			}while(choice < 1 || choice > 2);

			//per requirements if the list is empty, print a note 		
			if(head == nullptr){
				std::cout << "List is empty!!\n";
			}

			//display head node
			if(choice == 1){
				std::cout << std::endl;
				std::cout << "Head node is: " << head->value;
			}
			//display tail node
			else if(choice == 2){
				std::cout << std::endl;
				std::cout << "Tail node is: " << tail->value;
			}

	/*****************************************************************/
		//delete the head or tail value

			do{
				std::cout << "\n---------------------------------------\n";
				std::cout << "Do you want to delete the head or tail node?\n";
				std::cout << "Please enter a valid menu choice\n";
				std::cout << "1) head\n2) tail\n";

				while(!(std::cin >> choice)){
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Please enter a number: ";
				}
			}while(choice < 1 || choice > 2);

			//delete head node
			if(choice == 1){
				if(head->next == nullptr){
					delete head;
					head = nullptr;
					std::cout << "The list is now empty.\n";
				}
				else{
					nodePtr = head;
					head = head->next;
					delete nodePtr;
					nodePtr = nullptr;
					//display new head node
					std::cout << "The new head node is: " << head->value;
					std::cout << "!\n";
				}
			}
			//delete tail node
			else if(choice == 2){
				if(head->next == nullptr){
					delete head; //head and tail are the same if the node count is 1
					head = nullptr;
					std::cout << "The list is now empty.\n";
				}
				else{
					beforeTailPtr->next = nullptr;
					delete tail;
					tail = nullptr;

					//display new tail node
					std::cout << "The new tail node is: ";
					std::cout << beforeTailPtr->value;
					std::cout << "!\n";
				}
			}

	/*****************************************************************/
		//destroy the linked list

		//start at the beginning of the list
		nodePtr = head;
		while(nodePtr != nullptr){
			//garbage keeps track of node to be deleted
			ListNode *garbage = nodePtr;
			//move on the next node, if any
			nodePtr = nodePtr->next;
			//delete the "garbage" node
			delete garbage;
		}
		std::cout << "Linked list destroyed!\n";

	/*****************************************************************/
		//give user options to exit or repeat the program

		do{
			std::cout << "---------------------------------------\n";
			std::cout << "Do you want to do this again?\n";
			std::cout << "Please enter a valid menu choice\n";
			std::cout << "1) yes\n2) no\n";

			while(!(std::cin >> choice)){
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Please enter a number: ";
			}
		}while(choice < 1 || choice > 2);

		if(choice == 2){
			return 0;
		}
	}
}

