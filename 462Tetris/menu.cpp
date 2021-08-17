#include <iostream>
#include <iomanip>
#include "menu.h"
#include "game.h"
#include "brain.h"

#include "loginMenu.h";

using namespace std;

void Menu::DisplayWelcomeInterface()
{
	
	cout << "======================================================\n"
		"           #########  ###### #######  #     # \n"
		"           #   #   #  #      #     #  #     # \n"
		"           #   #   #  #####  #     #  #     # \n"
		"           #   #   #  #      #     #  #     # \n"
		"           #   #   #  ###### #     #  ####### \n"


		"======================================================\n";

	cout << "Menu Options\n"
		"1) Start New Game\n"
		"2) Change Settings\n"
		"3) Exit Game\n"
		">> ";

}


//function checks to see if a valid choice was made before setting it
void Menu::SetChoice(Game &gameobj, Brain &brainobj, int c)
{
	switch(c)
	{
		case 1:
		case 2:
		case 3:
			break;
			//if any number other than 1,2,3 is chosen, reset choice to 0
		default:
			c = 0;
			break;
	}

	choice = c;
	DoChoice(gameobj, brainobj, choice);
}

//call the correct option according to the player choice
int Menu::DoChoice(Game &gameobj, Brain &brainobj, int choice)
{
	
	switch (choice)
	{
	case 1:
		gameobj.StartNewGame(gameobj, brainobj);
		break;
	case 2:
		brainobj.DisplaySettingsMenu();
		break;
	case 3:
		return 0;
	case 0:
		cerr << "None of the options were chosen" << std::endl;
		system("pause");
		return -1;
	}
	return 0;

}
