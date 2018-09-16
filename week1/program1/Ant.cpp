/*********************************************************************
** Program name: Ant.cpp
** Author: James G Wilson (wilsjame)
** Date: 1/20/2016
** Description: Program 1 CS 162
** Ant.cpp is the Ant class implementation (definition) file
** This class represents a Langton's Ant simulation. It represents
** the ant and the board upon which the ant will maneuver. It should
** be used with appropriate values that will determine the size of 
** the board, where the ant starts on the board, and the number of
** steps the ant will take. 
*********************************************************************/
#include "Ant.hpp"
#include <iostream>
#include <unistd.h>

/*********************************************************************
** Description: Ant constructor
** Takes two integers as grid dimensions and dynamically creates a 
** 2D array filled with black spaces
*********************************************************************/
Ant::Ant(int inputRows, int inputCols)
{
	//add 2 extra rows and columns for borders
	rows = inputRows + 2;
	columns = inputCols + 2;

	//initialize dynamic 2D array
	grid = new char*[rows];

	for(int i = 0; i < rows; i++)
	{
		grid[i] = new char[columns];
	}
	
	//fill left border with characters
	for(int i = 0; i < rows - 1; i++)
	{
		for(int j = 0; j == 0; j++)
		{
			grid[i][j] = '|';
		}
	}
	//fill right border with characters
	for(int i = 1; i < rows - 1; i++)
	{
		for(int j = columns - 1; j == columns - 1; j++)
		{
			grid[i][j] = '|';
		}
	}
	//fill top border with characters
	for(int i = 0; i == 0; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			grid[i][j] = '-';
		}
	}
	//fill bottom border with characters
	for(int i = rows - 1; i == rows - 1;  i++)
	{
		for(int j = 0; j < columns; j++)
		{
			grid[i][j] = '-';
		}
	}
	//fill inbounds array with characters
	for(int i = 1; i < rows - 1; i++)
	{
		for(int j = 1; j < columns - 1; j++)
		{
			grid[i][j] = '#';
		}
	}
}
	
/*********************************************************************
** Description: printGrid
** Takes no parameters and no return value. Prints the current state
** of the grid in the console.
*********************************************************************/
void Ant::printGrid()
{
	for(int i = 0; i < rows; i++)
	{
		std::cout << std::endl;

		for(int j = 0; j < columns; j++)
		{
			std::cout << " ";
			std::cout << grid[i][j];
		}
	}
	std::cout << std::endl;
}

/*********************************************************************
** Description: checkColor
** Takes two integers that specify a location on the grid and returns
** a character value that represents the color at that location.
*********************************************************************/
char Ant::checkColor(int x, int y)
{
	//black
	if(grid[x][y] == '#')
	{
		color = '#';
	}
	//white
	else if(grid[x][y] == 'O')
	{
		color = 'O';
	}
	//out of bounds
	else
	{
		color = 'X';
	}

	return color;
}

/*********************************************************************
** Description: flipDirection
** Takes an enumerated datatype direction and flips it around 180 deg 
** no return value, it only changes the private data member.
*********************************************************************/
void Ant::flipDirection(direction inputDirection)
{
	if(inputDirection == UP)
	{
		currentDirection = DOWN;
	}
	else if(inputDirection == DOWN)
	{
		currentDirection = UP;
	}
	else if(inputDirection == LEFT)
	{
		currentDirection = RIGHT;
	}
	else if(inputDirection == RIGHT)
	{
		currentDirection = LEFT;
	}
}

/*********************************************************************
** Description: placeAnt
** Begins the simulation by taking three parameters. The x and y 
** location of the ant and the number steps all as integers.
** No return value 
*********************************************************************/
void Ant::placeAnt(int x, int y, int inputMoves)
{
	//end simulation if the board is too small
	if(rows == 3 || columns == 3)
	{
		std::cout << "The grid is too small! ";
		std::cout << "The Ant can't take any steps :(\n";
		return;;
	}
		
	movX = x;
	movY = y;

	moves = inputMoves;

	//set starting direction
	currentDirection = UP;

	//Beginning of simulation block
	//loop for number of moves 
	for(int i = 0; i < moves; i++)
	{
		std::cout << "step ";
		std::cout << i + 1;
		std::cout << " out of ";
		std::cout << moves;
		sleep(1);
	//check color before placing ant
	if(checkColor(movX, movY) == '#')
	{
		//place ant on black
		grid[movX][movY] = '@';
		printGrid();
		//check next square depending on current direction
		do
		{
		switch(currentDirection)
		{
		//because original square is black change direction 90 deg to the left AND
		//change the original square to white
			//check the above square
			case UP: if(checkColor(movX - 1, movY) == '#' || checkColor(movX - 1, movY) == 'O')
				 {
					 //if the above sqaure is in bounds i.e. black or white then
					 //change the current square to white 
					 grid[movX][movY] = 'O';
					 //if the above square is black then turn left
					 if(checkColor(movX - 1, movY) == '#')
					 {
						 currentDirection = LEFT;
					 }
					 else //the above sqaure is white so turn right
					 {
						 currentDirection = RIGHT;
					 }
					 //set the next move to the above square
					 movX -= 1;
				 }
				 break;
			//check the below square
			case DOWN: if(checkColor(movX + 1, movY) == '#' || checkColor(movX + 1, movY) == 'O')
				   {
					 //change the current square to white 
					 grid[movX][movY] = 'O';
					 //if the sqaure below is black then turn right
					 if(checkColor(movX + 1, movY) == '#')
					 {
						 currentDirection = RIGHT;
					 }
					 else //the sqaure below is white so turn left
					 {
						 currentDirection = LEFT;
					 }
					 //set next move to the below square
					 movX += 1;
				   }
				   break;
			//check the square to the left
			case LEFT: if(checkColor(movX, movY - 1) == '#' || checkColor(movX, movY - 1) == 'O')
				   {
					 //change the current square to white 
					 grid[movX][movY] = 'O';
					 //if the square the left is black then turn down
					 if(checkColor(movX, movY - 1) == '#')
					 {
						 currentDirection = DOWN;
					 }
					 else //the square below is white so turn UP
					 {
						 currentDirection = UP;
					 }
					 //set next move to the left square
					 movY -= 1;
				   }
				   break;
			//check the square to the right
			case RIGHT: if(checkColor(movX, movY + 1) == '#' || checkColor(movX, movY + 1) == 'O')
				    {
					 //change the current square to white 
					 grid[movX][movY] = 'O';
					 //if the square the right is black then turn UP
					 if(checkColor(movX, movY + 1) == '#')
					 {
						 currentDirection = UP;
					 }
					 else //the square the right is white so turn DOWN
					 {
						 currentDirection = DOWN;
					 }
					 //set next move to the right square
					 movY += 1;
				    }
				    break;
		}
		//if no cases matched then the next move is out of bounds so flip direction
		//and send ant back on the board
		if(checkColor(movX, movY) == 'X')
		{
			flipDirection(currentDirection);
		}
		}
		//keep on loop while the the ant has not moved
		while(checkColor(movX, movY) == 'X');
	}
	else if(checkColor(movX, movY) == 'O')
	{
		//place ant on white
		grid[movX][movY] = '@';
		//print board
		printGrid();
		//check next square depending on current direction
		do
		{
		switch(currentDirection)
		{
		//because original square is white change direction 90 deg to the right AND
		//change the original square to black 
			//check the above square
			case UP: if(checkColor(movX - 1, movY) == '#' || checkColor(movX - 1, movY) == 'O')
				 {
					 //if the above sqaure is in bounds i.e. black or white then
					 //change the current square to black
					 grid[movX][movY] = '#';
					 //if the above square is white then turn right
					 if(checkColor(movX - 1, movY) == 'O')
					 {
						 currentDirection = RIGHT;
					 }
					 else //the above square is black so turn left
					 {
						 currentDirection = LEFT;
					 }
					 //set the next move to the above square
					 movX -= 1;
				 }
				 break;
			//check the below square
			case DOWN: if(checkColor(movX + 1, movY) == '#' || checkColor(movX + 1, movY) == 'O')
				   {
					 //change the current square to black 
					 grid[movX][movY] = '#';
					 //if the below square is white then turn left
					 if(checkColor(movX + 1, movY) == 'O')
					 {
						 currentDirection = LEFT;
					 }
					 else //the below square is black so turn right
					 {
						 currentDirection = RIGHT;
					 }
					 //set next move to the below square
					 movX += 1;
				   }
				   break;
			//check the square to the left
			case LEFT: if(checkColor(movX, movY - 1) == '#' || checkColor(movX, movY - 1) == 'O')
				   {
					 //change the current square to black 
					 grid[movX][movY] = '#';
					 //if the square to the left is white then turn UP
					 if(checkColor(movX, movY -1) == 'O')
					 {
						 currentDirection = UP;
					 }
					 else //the square to the left is black so turn down
					 {
						 currentDirection = DOWN;
					 }
					 //set next move to the left square
					 movY -= 1;
				   }
				   break;
			//check the square to the right
			case RIGHT: if(checkColor(movX, movY + 1) == '#' || checkColor(movX, movY + 1) == 'O')
				    {
					 //change the current square to black 
					 grid[movX][movY] = '#';
					 //if the square to the right is white then turn DOWN
					 if(checkColor(movX, movY + 1) == 'O')
					 {
						 currentDirection = DOWN;
					 }
					 else //the square to the right is black so turn UP
					 {
						 currentDirection = UP;
					 }
					 //set the next move to the right square
					 movY += 1;
				    }
				    break;
		}
		//if the ant hits a wall flip turn it around and send it back on the board
		if(checkColor(movX, movY) == 'X')
		{
			flipDirection(currentDirection);
		}
		}
		while(checkColor(movX, movY) == 'X');
	}
}
}

/*********************************************************************
** Description: Destructor
** Deallocates memory allocated by initializing the grid array.
*********************************************************************/
Ant::~Ant()
{
	//deallocate memory
	for(int i = 0; i < rows; i++)
	{
		delete [] grid[i];
	}
	delete [] grid;
	grid = NULL;
}
	
	
