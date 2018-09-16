/*********************************************************************
** Program name: main.cpp
** Author: James G Wilson (wilsjame)
** Date: 3/3/2017
** Description: CS162 Lab8 CS 162
** This main program implements and tests the following:
	linear searching algorithm,
	sorting algorithm,
	binary searching algorithm.
** The program also performs file I/O operations
**
** Use the accompanying Makefile to create an executable named main
*********************************************************************/
#include "createData.hpp"
#include "searchVector.hpp"
#include "sortVector.hpp"
#include "binarySearch.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int main()
{
	const int TARGET = 0;

	std::vector<int> original,
		beginning,
		middle,
		end,
		originalSorted,
		beginningSorted,
		middleSorted,
		endSorted;

	std::fstream inOutFile;

	int val,	//used for transfering data between text files and  vectors
	    result;	//stores search algorithm result 

	std::string fileName;	//stores file name inputted by user

	//****************create data files****************
	std::cout << "------------Create .txt files-------------\n\n";
	std::cout << "creating data file...\n";
	createData();
	std::cout << "done.\n\n";

	std::cout << "The target value is: " << TARGET << std::endl;
	std::cout << "----------------------------------------\n";

	//****************search for target value****************
	//using linear search from page 604 in C++ Early Objects 9th ed.
	std::cout << "\n----------------Linear Search----------------\n\n";

	//read data from text file into vector
	//original
	inOutFile.open("original.txt");
	if(inOutFile.fail())
	{
		std::cout << "The file was not found.";
		return 1;
	}

	std::cout << "Reading original.txt into vector..\n";
	while(inOutFile >> val)
	{
		std::cout << val << "  ";
		original.push_back(val);
	}
	
	inOutFile.close();

	std::cout << "\nThe original vectors values:\n";
	for(int &vectorVal : original)
	{
		std::cout << vectorVal << "  ";
	}

	std::cout << "\nSearching the vector for the target value, 0...\n";
	result = searchVector(original, TARGET);

	if(result == -1)
	{
		std::cout << "Target value " << TARGET << " not found\n";
		std::cout << "---------------------------------------\n\n";
	}
	else
	{
		std::cout << "The target value " << TARGET << " is located at the ";
		std::cout << result + 1 << " position\n";	//add one to result to account for 0 place
		std::cout << "---------------------------------------\n\n";

	}

	//beginning
	inOutFile.open("beginning.txt");
	if(inOutFile.fail())
	{
		std::cout << "The file was not found.";
		return 1;
	}

	std::cout << "Reading beginning.txt into vector..\n";
	while(inOutFile >> val)
	{
		std::cout << val << "  ";
		beginning.push_back(val);
	}
	
	inOutFile.close();

	std::cout << "\nThe beginning vectors values:\n";
	for(int &vectorVal : beginning)
	{
		std::cout << vectorVal << "  ";
	}

	std::cout << "\nSearching the vector for the target value, 0...\n";
	result = searchVector(beginning, TARGET);

	if(result == -1)
	{
		std::cout << "Target value " << TARGET << " not found\n";
		std::cout << "---------------------------------------\n\n";
	}
	else
	{
		std::cout << "The target value " << TARGET << " is located at the ";
		std::cout << result + 1 << " position\n";	//add one to result to account for 0 place
		std::cout << "---------------------------------------\n\n";
	}

	//middle
	inOutFile.open("middle.txt");
	if(inOutFile.fail())
	{
		std::cout << "The file was not found.";
		return 1;
	}

	std::cout << "Reading middle.txt into vector..\n";
	while(inOutFile >> val)
	{
		std::cout << val << "  ";
		middle.push_back(val);
	}
	
	inOutFile.close();

	std::cout << "\nThe middle vectors values:\n";
	for(int &vectorVal : middle)
	{
		std::cout << vectorVal << "  ";
	}

	std::cout << "\nSearching the vector for the target value, 0...\n";
	result = searchVector(middle, TARGET);

	if(result == -1)
	{
		std::cout << "Target value " << TARGET << " not found\n";
		std::cout << "---------------------------------------\n\n";
	}
	else
	{
		std::cout << "The target value " << TARGET << " is located at the ";
		std::cout << result + 1 << " position\n";	//add one to result to account for 0 place
		std::cout << "---------------------------------------\n\n";
	}

	//end
	inOutFile.open("end.txt");
	if(inOutFile.fail())
	{
		std::cout << "The file was not found.";
		return 1;
	}

	std::cout << "Reading end.txt into vector..\n";
	while(inOutFile >> val)
	{
		std::cout << val << "  ";
		end.push_back(val);
	}
	
	inOutFile.close();

	std::cout << "\nThe end vectors values:\n";
	for(int &vectorVal : end)
	{
		std::cout << vectorVal << "  ";
	}

	std::cout << "\nSearching the vector for the target value, 0...\n";
	result = searchVector(end, TARGET);

	if(result == -1)
	{
		std::cout << "Target value " << TARGET << " not found\n";
		std::cout << "---------------------------------------\n\n";
	}
	else
	{
		std::cout << "The target value " << TARGET << " is located at the ";
		std::cout << result + 1 << " position\n";	//add one to result to account for 0 place
		std::cout << "---------------------------------------\n\n";
	}

	//****************sort a set of values and use a binary search****************
	//using sorting algorithm from page 619 and
	//using binary search from page 607 in C++ Early Objects 9th ed.

	std::cout << "------------Sorting and Binary Search-------------\n\n";
	//Sorting original
	//get file name to output sorted vector to
	std::cout << "Enter the filename you wish to output the sorted original vector to: ";
	getline(std::cin, fileName);
	std::cout << "You inputted: " << fileName << std::endl;

	//sort vector and write sorted vector to a file
	sortVector(original, fileName);
	fileName.append(".txt");
	
	//read data from text file into vector
	//original
	inOutFile.open(fileName);
	if(inOutFile.fail())
	{
		std::cout << "The file was not found.";
		return 1;
	}

	std::cout << "Reading " << fileName << " into vector..\n";
	while(inOutFile >> val)
	{
		std::cout << val << "  ";
		originalSorted.push_back(val);
	}
	
	inOutFile.close();

	std::cout << "\nThe originalSorted vectors values:\n";
	for(int &vectorVal : originalSorted)
	{
		std::cout << vectorVal << "  ";
	}

	std::cout << "\nSearching the vector for the target value, 0...\n";
	result = binarySearch(originalSorted, TARGET);

	if(result == -1)
	{
		std::cout << "Target value " << TARGET << " not found\n";
		std::cout << "---------------------------------------\n\n";
	}
	else
	{
		std::cout << "The target value " << TARGET << " is located at the ";
		std::cout << result + 1 << " position\n";	//add one to result to account for 0 place
		std::cout << "---------------------------------------\n\n";

	}

	//Sorting beginning
	//get file name to output sorted vector to
	std::cout << "Enter the filename you wish to output the sorted beginning vector to: ";
	getline(std::cin, fileName);
	std::cout << "You inputted: " << fileName << std::endl;

	//sort vector and write sorted vector to a file
	sortVector(beginning, fileName);
	fileName.append(".txt");
	
	//read data from text file into vector
	//beginning
	inOutFile.open(fileName);
	if(inOutFile.fail())
	{
		std::cout << "The file was not found.";
		return 1;
	}

	std::cout << "Reading " << fileName << " into vector..\n";
	while(inOutFile >> val)
	{
		std::cout << val << "  ";
		beginningSorted.push_back(val);
	}
	
	inOutFile.close();

	std::cout << "\nThe beginningSorted vectors values:\n";
	for(int &vectorVal : beginningSorted)
	{
		std::cout << vectorVal << "  ";
	}

	std::cout << "\nSearching the vector for the target value, 0...\n";
	result = binarySearch(beginningSorted, TARGET);

	if(result == -1)
	{
		std::cout << "Target value " << TARGET << " not found\n";
		std::cout << "---------------------------------------\n\n";
	}
	else
	{
		std::cout << "The target value " << TARGET << " is located at the ";
		std::cout << result + 1 << " position\n";	//add one to result to account for 0 place
		std::cout << "---------------------------------------\n\n";

	}

	//Sorting middle
	//get file name to output sorted vector to
	std::cout << "Enter the filename you wish to output the sorted middle vector to: ";
	getline(std::cin, fileName);
	std::cout << "You inputted: " << fileName << std::endl;

	//sort vector and write sorted vector to a file
	sortVector(middle, fileName);
	fileName.append(".txt");
	
	//read data from text file into vector
	//middle
	inOutFile.open(fileName);
	if(inOutFile.fail())
	{
		std::cout << "The file was not found.";
		return 1;
	}

	std::cout << "Reading " << fileName << " into vector..\n";
	while(inOutFile >> val)
	{
		std::cout << val << "  ";
		middleSorted.push_back(val);
	}
	
	inOutFile.close();

	std::cout << "\nThe middleSorted vectors values:\n";
	for(int &vectorVal : middleSorted)
	{
		std::cout << vectorVal << "  ";
	}

	std::cout << "\nSearching the vector for the target value, 0...\n";
	result = binarySearch(middleSorted, TARGET);

	if(result == -1)
	{
		std::cout << "Target value " << TARGET << " not found\n";
		std::cout << "---------------------------------------\n\n";
	}
	else
	{
		std::cout << "The target value " << TARGET << " is located at the ";
		std::cout << result + 1 << " position\n";	//add one to result to account for 0 place
		std::cout << "---------------------------------------\n\n";

	}

	//Sorting end
	//get file name to output sorted vector to
	std::cout << "Enter the filename you wish to output the sorted end vector to: ";
	getline(std::cin, fileName);
	std::cout << "You inputted: " << fileName << std::endl;

	//sort vector and write sorted vector to a file
	sortVector(end, fileName);
	fileName.append(".txt");
	
	//read data from text file into vector
	//end
	inOutFile.open(fileName);
	if(inOutFile.fail())
	{
		std::cout << "The file was not found.";
		return 1;
	}

	std::cout << "Reading " << fileName << " into vector..\n";
	while(inOutFile >> val)
	{
		std::cout << val << "  ";
		endSorted.push_back(val);
	}
	
	inOutFile.close();

	std::cout << "\nThe endSorted vectors values:\n";
	for(int &vectorVal : endSorted)
	{
		std::cout << vectorVal << "  ";
	}

	std::cout << "\nSearching the vector for the target value, 0...\n";
	result = binarySearch(endSorted, TARGET);

	if(result == -1)
	{
		std::cout << "Target value " << TARGET << " not found\n";
		std::cout << "---------------------------------------\n\n";
	}
	else
	{
		std::cout << "The target value " << TARGET << " is located at the ";
		std::cout << result + 1 << " position\n";	//add one to result to account for 0 place
		std::cout << "---------------------------------------\n\n";

	}

	std::cout << "Goodbye\n";

	return 0;
}
