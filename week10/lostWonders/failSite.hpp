/*********************************************************************
** Program name: Project 5 (Text-based Game)
** Filename: failSite.hpp 
** Author: James G Wilson (wilsjame)
** Date: 3/20/2017
** Description: CS 162
** FailSite class header file
*********************************************************************/
#ifndef FAILSITE_HPP
#define FAILSITE_HPP

#include "location.hpp"

class FailSite : public Location
{
	public:
		//default constructor
		FailSite();

		//FailSite method
		virtual Location* run();
};

#endif
