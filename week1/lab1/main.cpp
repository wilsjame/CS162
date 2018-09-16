/*********************************************************************
** Program name: main.cpp
** Author: James G Wilson (wilsjame)
** Date: 1/13/2017
** Description: lab 1 CS 162
**
** Main program module to use with the readMatrix and determinant 
** functions. 
**
** This program gets user inputs for a 2x2 or 3x3 matrix, displays
** the matrix, and calculates and outputs the determinant.
**
** Run the Makefile to create an executable program titled 'main'
*********************************************************************/
#include "readMatrix.hpp"
#include "determinant.hpp"
#include <iostream>

int main()
{

	//define variables
	int matrixSize,
	    rows,
	    cols;
	bool userInput = false;

	//prompt user with description of program and how
	//to begin
	std::cout << "This program calculates the determinant\n";
	std::cout << "of a 2x2 or 3x3 square matrix.\n\n";
	std::cout << "Input the size of the matrix to find\n";
	std::cout << "the determinant of and then press enter.\n";
	std::cout << "Input 4 for a 2x2 matrix"; 
	std::cout << "or 9 for a 3x3 matrix.";
	std::cout << "\n\n";

	//get matrix size from user
	//loop until a valid input is entered
	while(!userInput)
	{
		std::cout << "\nPlease enter a valid matrix size:";
		std::cin >> matrixSize;

		if(matrixSize == 4 || matrixSize == 9)
		{
			userInput = true;
		}
	}

	//set the rows and columns sizes
	if(matrixSize == 4)
	{
		rows = 2;
		cols = 2;
	}
	else
	{
		rows = 3;
		cols = 3;
	}

	//dynamically create a 2D array using the 'new' operator
	//and '*' indirection operator.
	//array is a pointer to a pointer
	int **array;
	array = new int*[rows];

	for(int i = 0; i < rows; ++i)
	{
		array[i] = new int[cols];
	}

/*********************************************************************
** Description: function readMatrix gets user inputs for a matrix and
** inputs them into a 2D array of integers.
** Takes two parameters: a double pointer (2D array) and the size of
** the matrix as an integer.
** Has no return value.
*********************************************************************/

	readMatrix(array, matrixSize);

	std::cout << "\nThe matrix appears as follows:\n";

	//output matrix board
	for(int i = 0; i < rows; i++)
	{

		//put a blank line between each row
		std::cout << "\n";

		for(int j = 0; j < cols; j++)
		{

			//output column values for current row
			//seperating each value with a space
			std::cout << array[i][j];
			std::cout << " ";
		}
	}
	
	//call and output the determinant
	std::cout << "\n\nThe determinant is:\n";

/*********************************************************************
** Description: function determinant calculates the determinant of an
** already stored 2x2 or 3x3 matrix passed to it as 2D array.
** Takes two parameteres: a 2D array containing values for a matrix
** and the size of the matrix as an integer.
** Returns the determinant as an integer.
*********************************************************************/

	std::cout << determinant(array, matrixSize);
	std::cout << std::endl;

	//delete dynamically allocated memory (deallocate)
	for(int i = 0; i < rows; i++)
	{
		delete [] array[i];
	}
	delete [] array;
	array = NULL;

	return 0;
}
	
	






	

