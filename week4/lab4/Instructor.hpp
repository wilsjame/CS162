/*********************************************************************
** Program name: Instructor.hpp
** Author: James G Wilson (wilsjame)
** Date: 2/5/2017
** Description: Lab 4 CS 162
** This is instructor class header file. Please see the class definition
** file for more detailed description.
*********************************************************************/
#ifndef INSTRUCTOR_HPP
#define INSTRCUTOR_HPP
#include "People.hpp" //parent class
#include <string>

//	child		   parent
class Instructor : public People{
	private:
		std::string name;
		int hours;
		double rating;
	public:
		Instructor(std::string name);
		virtual void do_work(int hours);
};
#endif
