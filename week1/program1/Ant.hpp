/*********************************************************************
** Program name: Ant.hpp
** Author: James G Wilson (wilsjame)
** Date: 1/22/2016
** Description: Program 1 CS 162
** Ant.hpp is the Ant class specification file. See the class 
** definition Ant.cpp for a detailed description
*********************************************************************/
#ifndef ANT_HPP
#define ANT_HPP
enum direction {UP, DOWN, LEFT, RIGHT};

class Ant
{
	private:
		char** grid;
		char color;
		
		direction currentDirection;

		int rows,
		    columns,
		    movX,
		    movY,
		    moves;

	public:
		Ant(int, int);
		
		void placeAnt(int, int, int),
		     flipDirection(direction),
		     printGrid();
		
		char checkColor(int x, int y);

		~Ant();
};
#endif
