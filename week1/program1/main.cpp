/*********************************************************************
** Program name: main.cpp
** Author: James G Wilson (wilsjame)
** Date: 1/22/2016
** Description: Project 1 Implementing Langton's Ant CS 162
** This program gets user inputs and implements the Ant class with 
** them. The Ant class runs a simulation of Langton's Ant. To run 
** this program use the accompanying Makefile to compile and create
** an executable program.
*********************************************************************/
#include <iostream>
#include <cstdlib> //required for random number generator
#include <unistd.h> //required for sleep
#include "Ant.hpp"

//menu function prototypes
void displayMenu();
int getChoice();

int main()
{
	int numRows, 
	    numCols,
	    numSteps,
	    startRow,
	    startCol,
	    choice = 1,
	    menuChoice;

	while(choice == 1) //introduce program title
	{
		std::cout << "\n Langton's Ant  Simulator\n\n";
	do //get grid rows 
	{
	std::cout << "\nEnter an integer value for the number of\n";
	std::cout << "grid rows then press enter: ";
	std::cin >> numRows;
	}
	while(numRows <= 0);

	do //get grid columns
	{
	std::cout << "\nEnter an integer value for the number of\n";
	std::cout << "grid columns then press enter: ";
	std::cin >> numCols;
	}
	while(numCols <= 0);

	do //get number of steps
	{
	std::cout << "\nEnter an integer value for the number of\n";
	std::cout << "steps the ant will take: ";
	std::cin >> numSteps;
	}
	while(numSteps <= 0);

	//prompt user to choose between a random start or choice
	do
	{
	std::cout << "Enter 1 to start the ant in a random location\n";
	std::cout << "Enter 2 to choose a start point for the ant: ";
	std::cin >> menuChoice; 
	}
	while(menuChoice != 1 && menuChoice != 2);

	switch(menuChoice)
	{
	case (1): 
      //seed random number generator
      srand(time(0));
      //random number range is 1 to max where max is numRows or numCols
      startRow = rand() % numRows + 1;
      startCol = rand() % numCols + 1;
      break;

	case (2): 
	//get a starting row and columns that are both inbounds
	do
	{
	std::cout << "\nEnter an integer value that is inbounds\n";
	std::cout << "for the starting ";
	std::cout << "row location of the ant then press enter: ";
	std::cin >> startRow;
	}
	while(startRow <= 0 || startRow > numRows); 
      
	do
	{
	std::cout << "\nEnter an integer value that is inbounds\n";
	std::cout << "for the starting ";
	std::cout << "column location of the ant then press enter: ";
	std::cin >> startCol;
	}
	while(startCol <= 0 || startCol > numCols);
	break;
	}

	//initialize the grid the ant will walk on by
	//creating a new Ant class instance by passing 
	//it two integer values as the dimensions of the board
	Ant newAnt(numRows, numCols);

	//Print the grid in the console. There is no return value
	//and no arguments
	newAnt.printGrid();
	std::cout << "# is black, O is white, and @ is the ant\n";
	std::cout << "start row is: ";
	std::cout << startRow;
	std::cout << "\nstart column is: "; 
	std::cout << startCol;
	std::cout << std::endl;
	sleep(1);
	
	//begin the Ant walking by placing the ant
	//by passing placeAnt three integer values:
	//the starting location on the grid and the number
	//of steps the ant will take. There is no return value
	newAnt.placeAnt(startRow, startCol, numSteps);

	//Menu asks user to rerun or quit program.
	
	//Displays the program menu. There is no return value
	displayMenu();
	//Gets the users choice from the displayMenu and returns
	//the choice as an int
	choice = getChoice();
	}

	std::cout << "\n\nprogram over\n";

	return 0;
}

