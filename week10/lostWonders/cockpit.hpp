/*********************************************************************
** Program name: Project 5 (Text-based Game)
** Filename: cockpit.hpp 
** Author: James G Wilson (wilsjame)
** Date: 3/20/2017
** Description: CS 162
** Cockpit class header file
** the cockpit will act as your home location where you can choose
** different destinations to travel to.
*********************************************************************/
#ifndef COCKPIT_HPP
#define COCKPIT_HPP

#include "location.hpp"

		//parent class
class Cockpit : public Location
{
	protected:
		Location *Tunguska,
			 *Stonehenge,
			 *Gobekli_Tepe,
			 *Easter_Isle,
			 *Acacia_Tree;

	public:
		//default constructor
		Cockpit();

		//set methods
		void setTunguskaLocation(Location *Tunguska);
		void setStonehengeLocation(Location *Stonehenge);
		void setGobekli_TepeLocation(Location *Gobekli_Tepe);
		void setEaster_IsleLocation(Location *Easter_Isle);
		void setAcacia_TreeLocation(Location *Acacia_Tree);

		//Ccckpit methods
		void checkArtifactsRetrieved();
		void activateState();
		void deactivatedState();
		
		virtual Location *run();
};

#endif
