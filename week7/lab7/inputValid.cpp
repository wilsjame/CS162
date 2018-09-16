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
