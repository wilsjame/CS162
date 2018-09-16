/*********************************************************************
** Program name: main.cpp
** Author: James G Wilson (wilsjame)
** Date: 2/11/2017
** Description: Lab 5 CS 162
**
** Main program to be used for testing three recursive functions.
** 
** Use the accompanying Makefile to compile an executable file 
** named main. 
*********************************************************************/
#include "reverseString.hpp"
#include "sumArray.hpp"
#include "triangleNum.hpp"
#include <iostream>
#include <limits>
#include <string> //for stoi

void increaseCapacity(int* &arr, int& arrCount, int& arrCapacity); //function prototype

int main(){
	
	int choice, //menu choice
	    arrNum, //use with case 2
	    arrCount, //use with case 2
	    arrCapacity, //use with case 2
	    sum, //use with case 2
	    num; //use with case 3

	std::string string, //use with case 1
		arrInput; // use with case 2

	bool carryOn; //use with case 2

	while(true){
		//menu options
		std::cout << "----- Pick A Function -----\n";
		std::cout << "1) revereString function\n";
		std::cout << "2) sumArray function\n";
		std::cout << "3) triangleNum function\n";
		std::cout << "4) Exit the program\n";

		//menu selection error handling
		while(!(std::cin >> choice)){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid choice\n";
			//display menu options again
			std::cout << "----- Pick A Function -----\n";
			std::cout << "1) revereString function\n";
			std::cout << "2) sumArray function\n";
			std::cout << "3) triangleNum function\n";
			std::cout << "4) Exit the program\n";
		}
		carryOn = true; //use with case 2

		switch(choice){
			case 1:
				//reverse string function
				std::cout << "Enter a string to reverse: ";
				std::cin.ignore();
				std::getline(std::cin, string); 
				reverseString(string); //function call
				break;
			case 2:
				//sumArray function
				//define dynamic array of int
				int* arr;
				arrCount = 0;
				arrCapacity = 4;
				arr = new int[arrCapacity];

				std::cin.ignore();
				std::cout << "Enter a number to add"; 
				std::cout << " to the array. Enter";
				std::cout << " q or Q to stop.\n";

				while(carryOn){
					try{
						std::getline(std::cin, arrInput);

						if(arrInput == "q" || arrInput == "Q"){
							carryOn = false;
							//function call
							sum = sumArray(arr, arrCount); 
							std::cout << "The sum is: ";
							std::cout << sum << std::endl;
							std::cout << std::endl;
						}
						else{
							//convert user input to a integer
							arrNum = std::stoi(arrInput);
							//if no error carry on
							if(arrCount == arrCapacity){
								increaseCapacity(arr, arrCount, arrCapacity);
							}
							//add num to array
							arr[arrCount] = arrNum;
							arrCount++;
						}
					}catch(...){
						//error handling
						std::cout << "Invalid input. Please try again\n";
					}
				}
				//delete arr
				delete [] arr;
				arr = NULL;

				break;
			case 3:
				//triangleNum
				std::cout << "Enter an intger: ";
				while(!(std::cin >> num)){

					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Please enter a number: ";
				}
				std::cout << "The triange number is: ";
				std::cout << triangleNum(num); //function call
				std::cout << std::endl;

				break;
			case 4:
				std::cout << "Goodbye\n";
				return 0;
			default:
				std::cout << "Invalid choice\n";
		}
	}
	return 0;
}

/*********************************************************************
** Description: increaseCapacity increments the array capacity. When the
** array size equals the array the capacity the function is called.
** No arguments or return value
*********************************************************************/
void increaseCapacity(int* &arr, int& arrCount, int& arrCapacity){

	arrCapacity++; 

	//create temp list with the doubled capacity
	int* newArr;
	newArr = new int[arrCapacity];

	//transfer the current array contents into the new array
	for(int i = 0; i < arrCount; i++){
		newArr[i] = arr[i];
	}

	//free memory
	delete [] arr;
	arr = NULL;

	//replace arr with newArr
	arr = new int[arrCapacity];
	for(int i = 0; i < arrCount; i++){
		arr[i] = newArr[i];
	}

	//free memory
	delete [] newArr;
	newArr = NULL;
}
