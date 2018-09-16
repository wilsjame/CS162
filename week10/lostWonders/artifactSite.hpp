/*********************************************************************
** Program name: Project 5 (Text-based Game)
** Filename: artifactSite.hpp
** Author: James G Wilson (wilsjame)
** Date: 3/20/2017
** Description: CS 162
** ArtifactSite abstract base class header file
*********************************************************************/
#ifndef ARTIFACTSITE_HPP
#define ARTIFACTSITE_HPP

#include "location.hpp"
#include "bag.hpp"
		    
class ArtifactSite : public Location
{
	protected:
		State arrival,
		      artifactFound;
		Location *cock_pit;
	public:
		//default constructor
		ArtifactSite();

		//set methods
		void setCockpit(Location *cock_pit);

		//ArtifactSite methods
		virtual void activateState();
		virtual void deactivatedState();
		virtual void activateFoundState();
		virtual Location *run();

		//abtract base class
		//pure virtual function
		virtual void activateArrivalState() = 0;
};

#endif


