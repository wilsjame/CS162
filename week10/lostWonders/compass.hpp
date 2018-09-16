/*********************************************************************
** Program name: Project 5 (Text-based Game)
** Filename: compass.hpp 
** Author: James G Wilson (wilsjame)
** Date: 3/20/2017
** Description: CS 162
** Compass class header file
*********************************************************************/
#ifndef COMPASS_HPP
#define COMPASS_HPP

#include "cockpit.hpp"
#include "tunguskaSite.hpp"
#include "stonehengeSite.hpp"
#include "gobekliTepeSite.hpp"
#include "easterIsleSite.hpp"
#include "failFuelSite.hpp"
#include "failAlignmentSite.hpp"
#include "acaciaSite.hpp"
#include "enlightenmentSite.hpp"

class Compass
{
	private:
		Cockpit cockpit;
		TunguskaSite tunguskaSite;
		StonehengeSite stonehengeSite;
		GobekliTepeSite gobekliTepeSite;
		EasterIsleSite easterIsleSite;
		
		FailFuelSite failFuelSite;
		FailAlignmentSite failAlignmentSite;

		AcaciaSite acaciaSite;
		EnlightenmentSite enlightenmentSite;

		Location *currentLocation;

	public:
		//default constructor
		Compass();

		//set methods
		void setCurrentLocation(Location *currentLocation);

		//get methods
		Location* getCurrentLocation();

		//Compass methods
		void fail_fuel();
		void fail_alignment();
};

#endif
