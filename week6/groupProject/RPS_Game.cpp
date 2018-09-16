/************************************************************************************************************************
Authors: Dan Mitu, Koryn Leslie-Arcaya, James Wilson, Christopher Nguyen, Brian Penny, Joycelin Orellana, Connie McClung
Due Date: 2/26/17
RPS_Game.hpp - This is the declaration for a RPS Game which pits a human against a CPU. Dynamic memory is automatically
allocated and freed each time play() is called, so no copy constructor/destructor/assignment operator is needed.
************************************************************************************************************************/
#include "RPS_Game.hpp"

RPS_Game::RPS_Game() : 
human(NULL), computer(NULL), human_wins(0), computer_wins(0), draws(0)
{
	srand(time(NULL)); //makes rand() more random
}

//sets the tools for the CPU and Human
//has them fight
//records the score
//once the user is done, displays the score table
void RPS_Game::play()
{
	bool again;
	do //does again and again until user enters "e" for the tool
	{
		again = set_tools(); 
		if(again)
		{
			//display the chosen tools
			char human_symbol = human->get_type();
			char computer_symbol = computer->get_type();
			cout << "Human -> " << human_symbol << " vs. " << computer_symbol << " <- Computer" << endl;

			//perform the fight
			Fight_Result result = human->fight(computer);
			switch(result)
			{
				case PLAYER_WIN:
					cout << "Human wins!" << endl;
					++human_wins;
					break;
				case CPU_WIN:
					cout << "Computer wins!" << endl;
					++computer_wins;
					break;
				case DRAW:
					cout << "Draw!" << endl;
					++draws;
					break;
			}
			cout << "RESULT..." << endl;
			cout << "Human Wins: " << human_wins << endl;
			cout << "Computer Wins: " << computer_wins << endl;
			cout << "Draws: " << draws << endl;

			//free memory so we can do this again.
			delete human;
			human = NULL;
			delete computer;
			computer = NULL;
		}
	}while(again);

	cout << "RESULT..." << endl;
	cout << "Human Wins: " << human_wins << endl;
	cout << "Computer Wins: " << computer_wins << endl;
	cout << "Draws: " << draws << endl;
}

//gets the tool from the user
//maybe gets the extra strength from the user
//randomly chooses computer's tool
//allocates memory for both
//true - ready to go; false - user wants to quit
//false - no memory is allocated
bool RPS_Game::set_tools()
{
	//user chooses tool
	char user_tool = choose_tool();

	//user wants to quit so get out
	if(user_tool == 'e')
	{
		return false;
	}

	//does the user want to cheat?
	cout << "Cheat by adding extra strength?\n1. Yes\n2. No" << endl;
	int user_strength_choice = input_integer(1, 2, "Enter #: ");
	int strength = 1;

	//enter strength for cheat
	if(user_strength_choice == 1)
	{
		strength = input_integer(1, "Enter Extra Strength #: ");
	}

	//create tool for human
	switch(user_tool)
	{
		case 'r':
			human = new Rock(strength);
			break;
		case 'p':
			human = new Paper(strength);
			break;
		case 's':
			human = new Scissors(strength);
			break;
		default: //will never happen
			return false;
	}

	//randomly select computer tool
	switch(rand() % 3 + 1)
	{
		case 1: //rock
			computer = new Rock();
			break;
		case 2: //paper
			computer = new Paper();
			break;
		case 3: //scissors
			computer = new Scissors();
			break;
		default: //will never happen
			break;
	}

	return true;
}

//asks the user which tool they want and returns a char representing it
//'e' means exit
char RPS_Game::choose_tool()
{
	//choose tool
	cout << "1. rock\n2. paper\n3. scissors\n0. exit" << endl;
	int user_tool_choice = input_integer(0, 3, "Enter #: ");

	//debugging
	cout << "User tool choice = " << user_tool_choice << endl;

	switch(user_tool_choice)
	{
		case 1: return 'r'; //rock
		case 2: return 'p'; //paper
		case 3: return 's'; //scissors
		default: return 'e'; //exit
	}
}

//forces user to input an integer
//returns that input
int RPS_Game::input_integer(string prompt)
{
	string user_input;
	bool input_is_valid = false;
	int return_integer;

	do
	{
		cout << prompt;
		getline(cin, user_input);

		try //convert the user input into an integer
		{
			//check for digits
			if(!(user_input.find_first_not_of("-0123456789")))
			{
				throw runtime_error("non-numeric character inputed");
			}
			return_integer = stoi(user_input);
			input_is_valid = true;

		} catch(const exception& e)
		{
			//number could not be converted.
			cout << "Error: \"" << user_input << "\" is invalid." << endl;
			input_is_valid = false;
		}

	} while(!input_is_valid);

	return return_integer;
}

//forces user to input a min integer
//returns that input
int RPS_Game::input_integer(int min, string prompt)
{
	int user_input;
	bool input_is_valid;
	do
	{
		user_input = input_integer(prompt);
		if(user_input < min)
		{
			input_is_valid = false;
			cout << "Error: enter an integer that's at least " << min << "." << endl;
		} else {
			input_is_valid = true;
		}
	} while(!input_is_valid);

	return user_input;
}

//forces user to input an integer within a range
//returns that input
int RPS_Game::input_integer(int min, int max, string prompt)
{
	if(min > max)
	{
		throw invalid_argument("min is greater than max");
	}

	int user_input;
	bool input_is_valid;
	do
	{
		user_input = input_integer(prompt);
		if((user_input > max) || (user_input < min))
		{
			input_is_valid = false;
			cout << "Error: enter an integer that's between " << min << " and " << max << "." << endl;
		} else {
			input_is_valid = true;
		}
	} while(!input_is_valid);

	return user_input;
}

//forces the user to enter either y/n
//if yes, returns true
//if no, returns false
bool RPS_Game::again(string prompt)
{
	vector<string> yes = {"y", "Y", "yes", "Yes", "YES"};
	vector<string> no = {"n", "N", "no", "No", "NO"};
	bool inputIsValid;
	bool yesSelected;
	string userInput; 
	cout << prompt;
	do
	{
		getline(cin, userInput);
		if(find(yes.begin(), yes.end(), userInput) != yes.end())
		{
			yesSelected = true;
			inputIsValid = true;
		} else if (find(no.begin(), no.end(), userInput) != no.end())
		{
			yesSelected =  false;
			inputIsValid = true;
		} else {
			cout << "Error: please enter either y/n." << endl;
		}
	}while(!inputIsValid);
	return yesSelected;
}
