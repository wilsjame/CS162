/*********************************************************************
** Program name: readMatrix.cpp
** Author: James G Wilson (wilsjame)
** Date: 1/15/2017
** Description: lab 1 CS 162
** Function definition file for readMatrix.cpp
*********************************************************************/
#include "readMatrix.hpp"
#include <iostream>

/*********************************************************************
** Description: function definition of readMatrix
** readMatrix gets user inputs for a matrix and inputs them into a 
** 2D array.
** readMatrix takes two parameters: a double pointer (2D array) and
** the matrix size as an integer.
** readMatrix has no return value.
*********************************************************************/
void readMatrix(int **array, int matrixSize)
{
	 
	//get user inputs for size 2x2 matrix
	if(matrixSize == 4)
	{
		for(int row = 0; row < 2; ++row)
		{

			//prompt user to enter values by row
			std::cout << "Enter values in row ";
			std::cout << row + 1;
			std::cout << "\nPress enter ";
			std::cout << "after each input.\n";

			//get user inputs for each column in current 
			//row
			for(int col = 0; col < 2; ++col) 
			{
				std::cin >> array[row][col];
			}
		}
	}

	//get user inputs for size 3x3 matrix
	else
	{
		for(int row = 0; row < 3; ++row)
		{

			//prompt user to enter values by row
			std::cout << "Enter values in row ";
			std::cout << row + 1;
			std::cout << "\nPress enter "; 
			std::cout << "after each input.\n";

			//get user inputs for each column in current
			//row
			for(int col = 0; col < 3; ++col) 
			{
				std::cin >> array[row][col];
			}
		}
	}
}



		
	


