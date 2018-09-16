/*********************************************************************
** Program name: Project 5 (Text-based Game)
** Filename:  bag.hpp
** Author: James G Wilson (wilsjame)
** Date: 3/20/2017
** Description: CS 162
** Bag class header file
*********************************************************************/
#ifndef BAG_HPP
#define BAG_HPP

enum Artifacts {NONE, TUNGUSKA, STONEHENGE, GOBEKLI_TEPE, EASTER_ISLE};

class Bag
{
	private:
		//bag holds 4 items
		Artifacts bag[4];
	public:
		//default constructor
		Bag();

		//Bag methods
		void clear();
		void addArtifact(Artifacts artifact);
		void displayNone();
		void displayTunguska();
		void displayStonehenge();
		void displayGobekli_Tepe();
		void displayEaster_Isle();
		void displayBag();
};

#endif
