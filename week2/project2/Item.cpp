/*********************************************************************
** Program name: Item.cpp
** Author: James G Wilson (wilsjame)
** Date: 2/4/2017
** Description: Project 2 CS 162
** This is the Item class definition file. 
** Abstraction: This class represents an item on ones grocery shopping
** list. 
** It is used with the List class, where Item objects are stored in 
** a dynamic array. An Item can be created with either a defualt 
** constructor that acts as an empty item place holder or with 
** arguments to create a user specified item.
*********************************************************************/
#include "Item.hpp"

/*********************************************************************
** Description: default constructor creates an empty item
** Parameters: none. Return: none
*********************************************************************/
Item::Item()
{
	itemName = "";
	unit = "";
	quantity = 0;
	unitPrice = 0;

	extendedPrice = 0;
}

/*********************************************************************
** Description: constructor creates a user specified item
** Parameters: Item name as a string, unit as a string, quantity as 
** an integer, and unit price as a double.
** Return: none
*********************************************************************/
Item::Item(std::string itemName, std::string unit, int quantity,
		double unitPrice)
{
	this->itemName = itemName;
	this->unit = unit;
	this->quantity = quantity;
	this->unitPrice = unitPrice;

	extendedPrice = quantity * unitPrice; //int * double
}

/*********************************************************************
** Description: getItemName returns the item name
** 
*********************************************************************/
std::string Item::getItemName() const
{
	return itemName;
}

/*********************************************************************
** Description: displayItem prints all the private members of Item
** 
*********************************************************************/
void Item::displayItem()
{
	std::cout << std::endl;
	std::cout << "Name: " << itemName << std::endl;
	std::cout << "unit: " << unit << std::endl;
	std::cout << "Price: $" << unitPrice << std::endl;
	std::cout << "Quantity: " << quantity << std::endl;
	std::cout << "Extended Price: $" << extendedPrice << std::endl;
	std::cout << std::endl;
}

/*********************************************************************
** Description: getItemName returns the extended price
** 
*********************************************************************/
double Item::getExtendedPrice()
{
	return extendedPrice;
}

/*********************************************************************
** Description: overloaded operator == compares to item objects 
** name private members using the getItemName function
*********************************************************************/
bool operator== (const Item &a, const Item &b)
{
	return (a.getItemName() == b.getItemName());
}
