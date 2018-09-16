/*********************************************************************
** Program name: determinant.hpp
** Author: James G Wilson (wilsjame)
** Date: 1/15/2017
** Description: lab 1 CS 162
** function header file for determinant
*********************************************************************/

//include guard
#ifndef DETERMINANT_HPP
#define DETERMINANT_HPP

//determinant function header. takes two paramteres:
//1) a double pointer. which is a pointer to a pointer (array) a.k.a.
//a 2D array
//2) an integer specifying the size of the matrix to find the 
//determinant of
int determinant(int **array, int matrixSize);

//end of include guard
#endif

