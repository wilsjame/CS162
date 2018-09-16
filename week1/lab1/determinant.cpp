/*********************************************************************
** Program name: determinant.cpp
** Author: James G Wilson (wilsjame)
** Date: 1/15/2017
** Description: lab 1 CS 162
** function definition of determinant 
*********************************************************************/
#include "determinant.hpp"

/*********************************************************************
** Description: function definition of determinant
** determinant calculates the determinant of a 2x2 or 3x3 matrix 
** passed to it as a double pointer (2D array).
** determinant takes two parameters: a double pointer (2D array) that
** holds the matrix values and the size of the matrix as an integer.
** determinant returns the determinant as an integer.
*********************************************************************/
int determinant(int **array, int matrixSize)
{

	//define return variable
	int determinant;

	//calculate determinant of 2x2 matrix
	if(matrixSize == 4)
	{
		determinant = array[0][0] * array[1][1] -
			array[0][1] * array[1][0];
	}

	//calculate determinant of 3x3 matrix
	else
	{
		determinant = 
			array[0][0] * (array[1][1] * array[2][2] -
					array[1][2] * array[2][1])
			- array[0][1] * (array[1][0] * array[2][2] -
					array[1][2] * array[2][0])
			+ array[0][2] * (array[1][0] * array[2][1] -
					array[1][1] * array[2][0]);
	}

	return determinant;
}


		



