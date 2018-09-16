//14.3 checkpoint
#include <iostream>

void showMe(int arg); //prototype

int main()
{
	int num = 0;

	showMe(num);
	return 0;
}

/*********************************************************************
** Description: showMe function
** 
*********************************************************************/
void showMe(int arg)
{
	if(arg < 10){
		showMe(++arg);
	}
	else{
		std::cout << arg << std::endl;
	}
}

