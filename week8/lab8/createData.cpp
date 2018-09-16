/*********************************************************************
** Description: creates four unsorted text files with random integers
**		where three have target values
** Arguments: none
** Returns: bool
*********************************************************************/
#include "createData.hpp"
#include <fstream>

void createData()
{
	const int TARGET = 0;	//algorithm target value
	const int SIZE = 10;	//array size

	int original[SIZE - 1] = {1, 9, 2, 8, 3, 7, 4, 6, 5};
	int beginning[SIZE] = {1, TARGET, 9, 2, 8, 3, 7, 4, 6, 5};
	int middle[SIZE] = {1, 9, 2, 8, TARGET, 3, 7, 4, 6, 5};
	int end[SIZE] = {1, 9, 2, 8, 3, 7, 4, 6, TARGET, 5};

	std::ofstream outputFile;	//output file stream object

	//create files
	//original
	outputFile.open("original.txt");

	for(int val : original)
	{
		outputFile << val << '\n';
	}
	
	outputFile.close();

	//beginning
	outputFile.open("beginning.txt");

	for(int val : beginning)
	{
		outputFile << val << '\n';
	}
	
	outputFile.close();

	
	//middle
	outputFile.open("middle.txt");

	for(int val : middle)
	{
		outputFile << val << '\n';
	}
	
	outputFile.close();

	//end
	outputFile.open("end.txt");

	for(int val : end)
	{
		outputFile << val << '\n';
	}
	
	outputFile.close();
}

	



	

	





