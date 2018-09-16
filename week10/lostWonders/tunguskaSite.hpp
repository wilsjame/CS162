/*********************************************************************
** Program name: Project 5 (Text-based Game)
** Filename: tunguskaSite.hpp 
** Author: James G Wilson (wilsjame)
** Date: 3/20/2017
** Description: CS 162
** TunguskaSite derived class header file
*********************************************************************/
#ifndef TUNGUSKASITE_HPP
#define TUNGUSKASITE_HPP

#include "artifactSite.hpp"

class TunguskaSite : public ArtifactSite
{
	public:
	//default constructor
	TunguskaSite();

	//TunguskaSite methods
	virtual void activateArrivalState(); 
};

#endif
