/*********************************************************************
** Program name: Buildings.hpp
** Author: James G Wilson (wilsjame)
** Date: 2/5/2017
** Description: Lab 4 CS 162
** This is the buildings class header file. Please see the class
** definition file for a detailed description of the class
*********************************************************************/
#ifndef BUILDINGS_HPP
#define BUILDINGS_HPP
#include <string>

class Buildings{
	private:
		std::string name, address;
		int size;
	public:
		Buildings();
		Buildings(std::string name, int size, std::string address);
		void getName();
		void getArea();
		void getAddress();
};
#endif
