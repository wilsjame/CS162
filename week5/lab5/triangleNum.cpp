/*********************************************************************
** Program name: triangleNum.cpp
** Author: James G Wilson (wilsjame)
** Date: 2/13/2017
** Description: Lab 5 CS 162
** Function definition file for triangleNum
**
** What it does: Returns the triangle number for an integer. For example:
** the triangle number of 5 is 5+4+3+2+1 = 15
**
** Arguments: an integer 
**
** Returns: the triangle number of the input integer
*********************************************************************/
#include "triangleNum.hpp"

int triangleNum(int num){
	
	//base case
	if(num == 0){
		return 0;
	}

	return num + triangleNum(num-1);
}


