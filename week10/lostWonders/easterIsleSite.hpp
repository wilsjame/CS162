/*********************************************************************
** Program name: Project 5 (Text-based Game)
** Filename: easterIsleSite.hpp 
** Author: James G Wilson (wilsjame)
** Date: 3/20/2017
** Description: CS 162
** EasterIsleSite derived class header file
*********************************************************************/
#ifndef EASTERISLESITE_HPP
#define EASTERISLESITE_HPP

#include "artifactSite.hpp"

class EasterIsleSite : public ArtifactSite
{
	public:
	//default constructor
	EasterIsleSite();

	//EasterIsleSite methods
	virtual void activateArrivalState(); 
};

#endif
