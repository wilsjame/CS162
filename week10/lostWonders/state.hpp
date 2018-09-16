/*********************************************************************
** Program name: Project 5 (Text-based Game)
** Filename: state.hpp
** Author: James G Wilson (wilsjame)
** Date: 3/20/2017
** Description: CS 162
** State class header file
** includes StateInfo struct 
*********************************************************************/
#ifndef STATE_HPP
#define STATE_HPP

#include "inputValid.hpp" 
#include <iostream>
#include <string>
#include <vector>


enum Results { NOTHING, ENLIGHTENMENT, FAIL_FUEL, FAIL_ALIGNMENT,  
		SEARCH_ARTIFACT, FIND_ARTIFACT, COCKPIT,  
		TUNGUSKA_LOCATION, STONEHENGE_LOCATION,
		GOBEKLI_TEPE_LOCATION, EASTER_ISLE_LOCATION,
		ACACIA_TREE_LOCATION, DEACTIVE, ACTIVE, APPROACH, IGNITE };
		
struct StateInfo
{
	int num;
	std::string description;
	Results result;

	//struct constructor
	StateInfo(int num, std::string description, Results result)
	{
		this->num= num;
		this->description = description;
		this->result = result;
	}

	int getNum()
	{
		return this->num;
	}

	std::string getDescription()
	{
		return this->description;
	}

	Results getResult()
	{
		return this->result;
	}
};

class State
{
	protected:
		int num;
		std::string description;
		std::vector<StateInfo> infoStorage;
	
	public:
		//default constructor
		State();

		//set methods
		void setDescription(std::string description);

		//get methods
		std::string getDescription();

		//state methods
		void addInfo(int num, std::string description, Results result);
		void displayDescription();
		void displayStateInfo();
		Results getResults(int num);
		Results run();
};

#endif
