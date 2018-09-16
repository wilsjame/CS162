/*********************************************************************
** Program name: Item.hpp
** Author: James G Wilson (wilsjame)
** Date: 2/4/2017
** Description: Project 2 CS 162
** This is the Item class header file. See the class definition file,
** Item.cpp, for a detailed description of the class and its functions
*********************************************************************/
#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>
#include <iostream>

class Item{
	private:

		std::string itemName,
			    unit;

		int quantity;

		double unitPrice,
		       extendedPrice;
	public:

		Item();
		Item(std::string itemName, std::string unit,
				int quantity, double unitPrice);

		std::string getItemName() const;
		void displayItem();
		double getExtendedPrice();

		//overload == operator prototype
		friend bool operator== (const Item &a, const Item &b);
};
#endif
