/*********************************************************************
** Program name: Project 5 (Text-based Game)
** Filename: stonehengeSite.hpp 
** Author: James G Wilson (wilsjame)
** Date: 3/20/2017
** Description: CS 162
** StonehengeSite derived class header file
*********************************************************************/
#ifndef STONEHENGESITE_HPP
#define STONEHENGESITE_HPP

#include "artifactSite.hpp"

class StonehengeSite : public ArtifactSite
{
	public:
	//default constructor
	StonehengeSite();

	//StonehengeSite methods
	virtual void activateArrivalState(); 
};

#endif
