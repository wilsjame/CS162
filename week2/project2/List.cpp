/*********************************************************************
** Program name: List.cpp
** Author: James G Wilson (wilsjame)
** Date: 2/4/2017
** Description: Project 2 CS 162
** This is the List class definition file.
** Abstraction: This class represents A grocery shopping list.
** It is used with the Item class and has a dynamic array of Items
** as a private member. It can add items, remove items, and display 
** the current state of the list. The when items are added, memory
** is dynamically allocated when the list reaches capacity.
*********************************************************************/
#include "List.hpp"
#include <limits> //used with error checking

/*********************************************************************
** Description: default constructor initializes the dynamic array
** of empty items to a capcity of 4
*********************************************************************/
List::List()
{
	listCurrent = 0;
	listCapacity = 4; //initial capacity is 4

	currentList = new Item[listCapacity]; 
}

/*********************************************************************
** Description: checkDuplicate checks if an items name is on the list
** Takes the item name as a string and returns true if the item is
** already on the list and false otherwise
*********************************************************************/
bool List::checkDuplicate(std::string itemName)
{
	bool duplicate = false;

	//create a temp Item for overloaded == testing
	//only the first argument will be passed the rest will be NULL 
	Item newItem(itemName, "", 0, 0);

	//check if item is already in cart
	for(int i = 0; i < listCurrent; i++)
	{
		if(newItem == currentList[i])
		{
			std::cout << "\nItem is already on the list!";
			std::cout << std::endl;
			duplicate = true;
		}
	}

	return duplicate;
}

/*********************************************************************
** Description: addItem adds a new item object to the list
** print prompts get user inputs and create a new item. No return 
** value
*********************************************************************/
void List::addItem()
{
	std::string itemName,
		    unit;
	int quantity;
	double unitPrice;
	
	//Get user inputs for a new item while check for name duplicates
	std::cin.ignore();
	do{
		std::cout << std::endl;
		std::cout << "Enter an item name to add: ";
		std::getline(std::cin, itemName);
	}
	while(checkDuplicate(itemName));

	std::cout << "Enter the item unit type (i.e. can, box, ";
	std::cout << "pound, ounce, 22oz, 6 pack, etc.): ";
	std::getline(std::cin, unit);

	//error check for integer
	std::cout << "Enter the quantity: ";
	while(!(std::cin >> quantity) || quantity <= 0)
	{
		if(!std::cin)
		{
			//clear errors (like failbit flag)
			std::cin.clear();

			//throw away the rest of the line
			//while(std::cin.get() != '\n');
	
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "Wrong input, please enter a number: ";
		}
		else
		{
			std::cout << "Wrong input, please enter a number ";
			std::cout << "greater than zero: ";
		}
	}

	//error check for double number
	std::cout << "Enter the price: ";
	while(!(std::cin >> unitPrice) || unitPrice < 0)
	{
		if(!std::cin)
		{
			//clear errors (like failbit flag)
			std::cin.clear();

			//throw away the rest of the line
			//while(std::cin.get() != '\n');
	
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "Wrong input, please enter a number: ";
		}
		else{
			std::cout << "Wrong input, please enter a positive number: ";
		}
	}
	
	//if the cart is full increase its size
	if(listCurrent == listCapacity){
		increaseCapacity();
	}

	//show user the list capacity. It doubles when reached
	std::cout << "Dynamic list capacity is " << listCapacity;
	std::cout << std::endl;

	//add item to cart
	currentList[listCurrent] = Item(itemName, unit, quantity, unitPrice);  

	listCurrent++;
	
}

/*********************************************************************
** Description: increaseCapacity doubles the list capacity.
** When the amount of items on the becomes greater than the list
** capacity the capacity is doubled. No arguments or return value
*********************************************************************/
void List::increaseCapacity()
{
	std::cout << "\nincreaseCapacity called";
	listCapacity *= 2 ; //double the list capacity

	//create temp list with the doubled list capacity
	Item* newList = new Item[listCapacity];

	//transfer the current list items into the new list
	for(int i = 0; i < listCurrent; i++){ 
		newList[i] = currentList[i];
	}

	//free memory
	delete [] currentList;
	currentList = NULL;

	//replace current list with the new list
	currentList = new Item[listCapacity];
	for(int i = 0; i < listCurrent; i++){ 
		currentList[i] = newList[i];
	}

	//free memory
	delete [] newList;
	newList = NULL;
}

/*********************************************************************
** Description: removeItem removes the last item added to the list
** no arguments or return value
** *********************************************************************/
void List::removeItem()
{
	if(listCurrent == 0){
		std::cout << "\nThe list is empty!\n";
	}
	else
	{
		listCurrent--;

		//create temp list
		Item* newList = new Item[listCapacity];

		//transfer the current list items into the new list
		//subtracting one item (the last item added)
		for(int i = 0; i < listCurrent; i++){ 
			newList[i] = currentList[i];
		}

		//free memory
		delete [] currentList;
		currentList = NULL;

		//replace current list with the new list
		currentList = new Item[listCapacity];
		for(int i = 0; i < listCurrent; i++){ 
			currentList[i] = newList[i];
		}
	
		//free memory
		delete [] newList;
		newList = NULL;
	}
}

/*********************************************************************
** Description: getTotalPrice returns the total price of all the 
** items on the list as a double. No arguments
*********************************************************************/
double List::totalPrice()
{
	double totalPrice = 0;

	//calculate total price
	for(int i = 0; i < listCurrent; i++){
		totalPrice += currentList[i].getExtendedPrice();
	}

	return totalPrice;
}

/*********************************************************************
** Description: displayList prints out all the items on the list
** no arguments or return values
*********************************************************************/
void List::displayList()
{
	//display items
	for(int i = 0; i < listCurrent; i++){
		currentList[i].displayItem();
	}

	//display total price
	std::cout << "--------------------";
	std::cout << "Total Price: $";
	std::cout << totalPrice();
	std::cout << std::endl;
}

/*********************************************************************
** Description: Destructor deletes all memory created with new
** 
*********************************************************************/
List::~List()
{ 
	//free memory
	delete [] currentList;
	currentList = NULL;
}
