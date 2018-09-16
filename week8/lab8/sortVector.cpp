/*********************************************************************
** Description: uses a selection sort algorithm to sort values in a
**		vector in ascending order.
		Using the selection sort algorithm from page 619
		in C++ Early Objects 9th ed.
** Arguments: a vector passed by value, string of the output file name
** Returns: none
********************************************************************/
#include "sortVector.hpp"
#include <fstream>
#include <iostream>

void sortVector(std::vector<int> vectorIn, std::string fileName)
{
	int startScan, minIndex, minValue;
	std::ofstream outputFile;

	//selection sort algorithm
	for(startScan = 0; startScan < (vectorIn.size() - 1); startScan++)
	{
		minIndex = startScan;
		minValue = vectorIn[startScan];

		for(int index = startScan + 1; index < vectorIn.size(); index++)
		{
			if(vectorIn[index] < minValue)
			{
				minValue = vectorIn[index];
				minIndex = index;
			}
		}
		vectorIn[minIndex] = vectorIn[startScan];
		vectorIn[startScan] = minValue;
	}

	//display sorted vector test
	std::cout << "sorted vector: ";
	for(int val : vectorIn)
	{
		std::cout << val;
	}
	std::cout << std::endl;
	
	//write sorted vector to a text file
	fileName.append(".txt");	//make output file a text file
	outputFile.open(fileName);
	for(int val : vectorIn)
	{
		outputFile << val << '\n';
	}
	outputFile.close();

	std::cout << "Sorted values written to: " << fileName;
	std::cout << std::endl;
	std::cout << "-----------------------------------\n";
}

