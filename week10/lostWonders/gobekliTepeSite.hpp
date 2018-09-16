/*********************************************************************
** Program name: Project 5 (Text-based Game)
** Filename: gobekliTepeSite.hpp 
** Author: James G Wilson (wilsjame)
** Date: 3/20/2017
** Description: CS 162
** GobekliTepeSite derived class header file
*********************************************************************/
#ifndef GOBEKLITEPESITE_HPP
#define GOBEKLITEPESITE_HPP

#include "artifactSite.hpp"

class GobekliTepeSite : public ArtifactSite
{
	public:
	//default constructor
	GobekliTepeSite();

	//GobekliTepeSite methods
	virtual void activateArrivalState(); 
};

#endif
