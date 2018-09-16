/*********************************************************************
** Program name: main.cpp
** Author: James G Wilson (wilsjame)
** Date: 3/17/2017
** Description: Lab 10 CS 162
**
** This lab measures and compares the running time of recursive
** and iterative implementations of the Fibonacci Numbers Calculation.
**
** Use the accompanying Makefile to create an executable named main
** to run the program.
**
** Fibonacci algorithms taken from: https://www.codeproject.com/Tips/109443/Fibonacci-Recursive-and-Non-Recursive-C
*********************************************************************/
#include  <iostream>
#include <ctime>	//C library, using clock

//function prototypes
int FibonacciNR(const int &n);
int FibonacciR(const int &n);

int main()
{
	//set up clock
	clock_t start;	
	int	N;
	double durationNR,
	       duration;

	//set up results columns
	std::cout << "\nN        Iterative Time         Recursive Time\n";

	//10
	//Non-Recursive 
	start = clock();
	N = 10;
	std::cout << N << "       ";
	FibonacciNR(N); 
	durationNR = (clock() - start) / (double) CLOCKS_PER_SEC;
	std::cout << durationNR << "                      ";

	//Recursive
	start = clock();
	FibonacciR(N);
	duration = (clock() - start) / (double) CLOCKS_PER_SEC;
	std::cout << duration << std::endl;

	//20
	//Non-Recursive 
	start = clock();
	N = 20;
	std::cout << N << "       ";
	FibonacciNR(N); 
	durationNR = (clock() - start) / (double) CLOCKS_PER_SEC;
	std::cout << durationNR << "                      ";

	//Recursive
	start = clock();
	FibonacciR(N);
	duration = (clock() - start) / (double) CLOCKS_PER_SEC;
	std::cout << duration << std::endl;

	//30
	//Non-Recursive 
	start = clock();
	N = 30;
	std::cout << N << "       ";
	FibonacciNR(N); 
	durationNR = (clock() - start) / (double) CLOCKS_PER_SEC;
	std::cout << durationNR << "                      ";

	//Recursive
	start = clock();
	FibonacciR(N);
	duration = (clock() - start) / (double) CLOCKS_PER_SEC;
	std::cout << duration << std::endl;

	//40
	//Non-Recursive 
	start = clock();
	N = 40;
	std::cout << N << "       ";
	FibonacciNR(N); 
	durationNR = (clock() - start) / (double) CLOCKS_PER_SEC;
	std::cout << durationNR << "                      ";

	//Recursive
	start = clock();
	FibonacciR(N);
	duration = (clock() - start) / (double) CLOCKS_PER_SEC;
	std::cout << duration << std::endl;

	//41
	//Non-Recursive 
	start = clock();
	N = 41;
	std::cout << N << "       ";
	FibonacciNR(N); 
	durationNR = (clock() - start) / (double) CLOCKS_PER_SEC;
	std::cout << durationNR << "                      ";

	//Recursive
	start = clock();
	FibonacciR(N);
	duration = (clock() - start) / (double) CLOCKS_PER_SEC;
	std::cout << duration << std::endl;

	//42
	//Non-Recursive 
	start = clock();
	N = 42;
	std::cout << N << "       ";
	FibonacciNR(N); 
	durationNR = (clock() - start) / (double) CLOCKS_PER_SEC;
	std::cout << durationNR << "                      ";

	//Recursive
	start = clock();
	FibonacciR(N);
	duration = (clock() - start) / (double) CLOCKS_PER_SEC;
	std::cout << duration << std::endl;

	//43
	//Non-Recursive 
	start = clock();
	N = 43;
	std::cout << N << "       ";
	FibonacciNR(N); 
	durationNR = (clock() - start) / (double) CLOCKS_PER_SEC;
	std::cout << durationNR << "                      ";

	//Recursive
	start = clock();
	FibonacciR(N);
	duration = (clock() - start) / (double) CLOCKS_PER_SEC;
	std::cout << duration << std::endl;

	//44
	//Non-Recursive 
	start = clock();
	N = 44;
	std::cout << N << "       ";
	FibonacciNR(N); 
	durationNR = (clock() - start) / (double) CLOCKS_PER_SEC;
	std::cout << durationNR << "                      ";

	//Recursive
	start = clock();
	FibonacciR(N);
	duration = (clock() - start) / (double) CLOCKS_PER_SEC;
	std::cout << duration << std::endl;

	//45
	//Non-Recursive 
	start = clock();
	N = 45;
	std::cout << N << "       ";
	FibonacciNR(N); 
	durationNR = (clock() - start) / (double) CLOCKS_PER_SEC;
	std::cout << durationNR << "                      ";

	//Recursive
	start = clock();
	FibonacciR(N);
	duration = (clock() - start) / (double) CLOCKS_PER_SEC;
	std::cout << duration << std::endl;

	//46
	//Non-Recursive 
	start = clock();
	N = 46;
	std::cout << N << "       ";
	FibonacciNR(N); 
	durationNR = (clock() - start) / (double) CLOCKS_PER_SEC;
	std::cout << durationNR << "                      ";

	//Recursive
	start = clock();
	FibonacciR(N);
	duration = (clock() - start) / (double) CLOCKS_PER_SEC;
	std::cout << duration << std::endl;

	//47
	//Non-Recursive 
	start = clock();
	N = 47;
	std::cout << N << "       ";
	FibonacciNR(N); 
	durationNR = (clock() - start) / (double) CLOCKS_PER_SEC;
	std::cout << durationNR << "                      ";

	//Recursive
	start = clock();
	FibonacciR(N);
	duration = (clock() - start) / (double) CLOCKS_PER_SEC;
	std::cout << duration << std::endl;

	//48
	//Non-Recursive 
	start = clock();
	N = 48;
	std::cout << N << "       ";
	FibonacciNR(N); 
	durationNR = (clock() - start) / (double) CLOCKS_PER_SEC;
	std::cout << durationNR << "                      ";

	//Recursive
	start = clock();
	FibonacciR(N);
	duration = (clock() - start) / (double) CLOCKS_PER_SEC;
	std::cout << duration << std::endl;


	//set up results columns
	std::cout << "\nN          Iterative Time         Recursive Time\n";

	//100000000
	//Non-Recursive 
	start = clock();
	N = 100000000; 
	std::cout << N << "   ";
	FibonacciNR(N); 
	durationNR = (clock() - start) / (double) CLOCKS_PER_SEC;
	std::cout << durationNR << "                    ";

	//Recursive
	std::cout << "Very Large" << std::endl;

	//1000000000
	//Non-Recursive 
	start = clock();
	N = 1000000000;
	std::cout << N << "   ";
	FibonacciNR(N); 
	durationNR = (clock() - start) / (double) CLOCKS_PER_SEC;
	std::cout << durationNR << "                    ";

	//Recursive
	std::cout << "Very Large" << std::endl;

	//2000000000
	//Non-Recursive 
	start = clock();
	N = 2000000000;
	std::cout << N << "   ";
	FibonacciNR(N); 
	durationNR = (clock() - start) / (double) CLOCKS_PER_SEC;
	std::cout << durationNR << "                    ";

	//Recursive
	std::cout << "Very Large" << std::endl;

		return 0;

}

/*********************************************************************
** Description: non recursive fibonacci number calculator
** Arguments: integer constant passed by reference
** Returns: the nth fibonacci number
*********************************************************************/
int FibonacciNR(const int &n)
{
	int first =0;
   	int second=1;
   	int counter=2;
   	while(counter < n)
   	{
   		int temp=second;
   		second=first+second;
   		first=temp;
   		++counter;
   	}
   	if(n==0)
   		return 0;
   	else	
   		return first+second;
}

/*********************************************************************
** Description: recursive fibonacci number calculator
** Arguments: integer constant passed by reference
** Returns: the nth fibonacci number
*********************************************************************/
int FibonacciR(const int &n){
   	if(n==0)
   		return 0;
   	else if(n==1)
   		return 1;
   	return FibonacciR(n-1) + FibonacciR(n-2);
}
