/*********************************************************************
** Program name: People.hpp
** Author: James G Wilson (wilsjame)
** Date: 2/5/2017
** Description: Lab 4 CS 162
** This is People class header file. The people class represents 
** people who are involved with university. These people can either 
** be a student or an instructor but not both.
** People is the parent class for the child classes, Student and 
** Instructor.
*********************************************************************/
#ifndef PEOPLE_HPP
#define PEOPLE_HPP
#include <string>

class People{
	protected:
		std::string name;
		int hours;
		int age;
	public:
		People();
		People(std::string name);
		void printName();
		virtual void do_work(int hours);
};
#endif
