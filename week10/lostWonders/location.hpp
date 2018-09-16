/*********************************************************************
** Program name: Project 5 (Text-based Game)
** Filename: location.hpp 
** Author: James G Wilson (wilsjame)
** Date: 3/20/2017
** Description: CS 162
** Location class header file
** Locatin is an abtract base class
*********************************************************************/
#ifndef LOCATION_HPP
#define LOCATION_HPP

#include "state.hpp"
#include "bag.hpp" //using Artifacts enum
#include "inputValid.hpp"
#include <string>
#include <iostream>
#include <fstream> //operate on image files

class Location
{
	protected:
		std::string lore;
		std::string imageFile;
		
		State activeState,
		      deactiveState,
		      *currentState;
		      
		Location *fail_fuel,
			 *fail_alignment;
		Artifacts artifact;
		bool	artifactRetrieved;
		bool	artifactActivated;
	
	public:
		//default constructor
		Location();

		//set methods
		void setLore(std::string lore);
		void setImageFile(std::string imageFile);
		void setArtifact(Artifacts artifact);
		void setArtifactRetrieved(bool artifactRetrieved);
		void setArtifactActivated(bool artifactActivated);
		void setCurrentState(State &currentState);
		void setFail_fuelLocation(Location *fail_fuel);
		void setFail_alignmentLocation(Location *fail_alignment);

		//get methods
		std::string getLore();
		std::string getImageFile();
		Artifacts getArtifact();
		bool getArtifactRetrieved();
		bool getArtifactActivated();

		//Location methods
		void displayImage();
		void displayLocation();

		//abtract base class
		//pure virtual function
		virtual Location *run() = 0;
};

#endif
