/*********************************************************************
** Program name: University.hpp
** Author: James G Wilson (wilsjame)
** Date: 2/5/2017
** Description: Lab 4 CS 162
** This is university class header file. Please see the class definition
** file for a detailed class description
*********************************************************************/
#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP
#include <string>
#include "People.hpp"
#include "Buildings.hpp"
#include <memory> //using smart pointers
#include <vector>

class University{
	private:
		std::string name;

		//vector of shared pointers to People (instructors and students)
		std::vector<std::shared_ptr<People>> persons;

		//vector of shared pointers to Buildings objects
		std::vector<std::shared_ptr<Buildings>> buildings;
	public:
		University(std::string name, const std::vector<std::shared_ptr<People>>& persons, const std::vector<std::shared_ptr<Buildings>>& buildings);

		void printBuildings();
		void printPeople();
		void choosePerson();
};
#endif
	
		
		


