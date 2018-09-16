/*********************************************************************
** Program name List.hpp
** Author: James G Wilson (wilsjame)
** Date: 2/4/2017
** Description: Project 2 CS 162
** This is the List class header file. See the calss definition file,
** List.cpp, for a detailed description of the class and its functions
*********************************************************************/
#ifndef LIST_HPP
#define LIST_HPP
#include "Item.hpp"

class List{
	private:
		//dynamic array of Item objects
		Item* currentList; 

		int listCurrent,
		    listCapacity;

	public:
		List();
		bool checkDuplicate(std::string itemName);
		void addItem();
		void increaseCapacity();
		void removeItem();
		double totalPrice();
		void displayList();
		~List();
};
#endif



