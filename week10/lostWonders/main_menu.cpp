/*********************************************************************
** Program name: Project 5 (Text-based Game)
** Filename: main_menu.cpp 
** Author: James G Wilson (wilsjame)
** Date: 3/20/2017
** Description: CS 162
** main_menu definitions file
** contains main menu function definitions
*********************************************************************/
#include "main_menu.hpp"
#include <iostream>
/*********************************************************************
** Description: Displays main menu to the user
** Arguments: none
** Returns: none
*********************************************************************/
void displayIntro()
{
	std::cout << "\n\n\n" 
		<< "You are a renowned archaeologist planning your "  
		<< "next expedition.\n"
		<< "Out of the blue you receive an anonymous letter.\n"
		<< "It emits a strange aura, one beyond normallcy, as "
		<< "you hold it in your hand.\n\n"
		<< "You are compelled to open it and sense adventure "
		<< "is forthcoming.\n"
		<< "1) Open the mysterious letter.\n"
		<< "2) Toss it in the trash.\n"
		<< std::endl;
}
/*********************************************************************
** Description: Displays the contents of the letter
** Arguments: none
** Returns: none
*********************************************************************/
void displayLetter()
{
	std::cout << "\n\n\n"
		<< "The cosmos have aligned and the ancient talismans "
		<< "have revealed themselves, "
		<< "but only for a short while!\n"
		<< "Travel the globe to these megalithic sites "
		<< "and collect all of them to reveal their purpose."
		<< "\n\n"
		<< "Letter in hand, you hop in your plane and get "
		<< "going...\n"
		<< "\n (Hint: Easter Island is far away and takes "
		<< "a lot of fuel to there)"
		<< std::endl;
}
