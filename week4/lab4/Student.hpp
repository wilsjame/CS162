/*********************************************************************
** Program name: Student.hpp
** Author: James G Wilson (wilsjame)
** Date: 2/5/2017
** Description: Lab 4 CS 162
** This is the Student class header file. See the class definition
** file for a more detailed description.
*********************************************************************/
#ifndef STUDENT_HPP
#define STUDENT_HPP
#include "People.hpp" //parent class
#include <string>

//     child          parent
class Student : public People{
	private:
		std::string name;
		int hours;
		double gpa;
	public:
		Student(std::string name);
		virtual void do_work(int hours);
};
#endif


