/*********************************************************************
** Program name: sumArray.cpp
** Author: James G Wilson (wilsjame)
** Date: 2/12/2017
** Description: Lab 5 CS 162
** Function definition file for sumArray
**
** What it does: sums all the integers in an array
**
** Arguments: an array of integers and the size of the array as an
** integer
**
** Returns: the sum of the array as an integer
*********************************************************************/
#include "sumArray.hpp"

int sumArray(int arr[], int size){
	
	//base case
	if(size == 0){
		return 0;
	}
	
	return arr[size - 1] + sumArray(arr, size - 1);
}


