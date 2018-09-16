/*********************************************************************
** Program name: Project 5 (Text-based Game)
** Filename: acaciaSite.hpp 
** Author: James G Wilson (wilsjame)
** Date: 3/20/2017
** Description: CS 162
** AcaciaSite class header file
*********************************************************************/
#ifndef ACACIASITE_HPP
#define ACACIASITE_HPP

#include "location.hpp"

class AcaciaSite : public Location
{
	protected:
		State arrival,
		      burning;
		Location *enlightenment,
			 *cock_pit;
	public:
		//default constructor
		AcaciaSite();

		//set methods
		void setCockpitLocation(Location *cock_pit);
		void setEnlightenment(Location *enlightenment);

		//AcaciaSite methods
		void activateState();
		void deactivatedState();
		void approach();
		void ignite();

		virtual Location* run();
};

#endif
