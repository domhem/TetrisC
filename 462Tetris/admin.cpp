#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "menu.h"
#include "loginMenu.h";
#include "admin.h";
#include "clear.h"
#include "game.h"
#include "brain.h"

using namespace std;

void Admin::displayAdminMenu()
{
	cout << "======================================================\n"
		"           #########  ###### #######  #     # \n"
		"           #   #   #  #      #     #  #     # \n"
		"           #   #   #  #####  #     #  #     # \n"
		"           #   #   #  #      #     #  #     # \n"
		"           #   #   #  ###### #     #  ####### \n"


		"======================================================\n";

	cout << "Menu Options for Admin\n"
		"1) View PlayerList\n"
		"2) Remove Players\n"
		"3) Change Settings\n"
		"4) Exit Game\n"
		">> ";

}


//function checks to see if a valid choice was made before setting it
void Admin::SetChoice(Brain &brainobj, int c)
{
	switch (c)
	{
	case 1:
	case 2:
	case 3:
	case 4:
		break;
		//if any number other than 1,2,3,4 is chosen, reset choice to 0
	default:
		c = 0;
		break;
	}

	choice = c;
	DoChoice(brainobj, choice);
}

//call the correct option according to the player choice
int Admin::DoChoice(Brain &brainobj, int choice)
{
	ifstream readFile("PlayerList.txt");
	ofstream writeFile("PlayerList.txt", ios::app);
	Admin adm1;
	int index = 0;

	switch (choice)
	{
	case 1:
		ClearScreen();
		adm1.viewPlayerList(readFile, plList);
		break;
	case 2:
		adm1.removePlayer(readFile, plList, writeFile);
		break;
	case 3:
		brainobj.DisplaySettingsMenu();
		break;
	case 4:
		return 0;
	case 0:
		cerr << "None of the options were chosen" << std::endl;
		system("pause");
		return -1;
	}
	return 0;

}

//displays list of players 
//only username, passwords not shown
void Admin::viewPlayerList(ifstream & readFile, vector<string>& plList)
{

	int count = 0;
	if (readFile.is_open())
	{
		
		//storing all the usernames and password into a vector string
		//vector<string> plList;
		string read = "";

		while (readFile >> read)
		{
			plList.push_back(read);
		}

		//display list of players
		cout << "List of usernames: " << endl;
		for (vector<string>::iterator it = plList.begin(); it != plList.end(); it += 2)
		{
			cout << count << ") " << *it << endl;
			count++;
		}


		readFile.close();
	}

}

void Admin::removePlayer(ifstream & readFile, vector<string>& plLis, ofstream & writeFile)
{
	int count = 0;
	int index = 0;
	cout << "What index would you like to remove the player from playerList?";
	cin >> index;

	if (readFile.is_open())
	{
		ClearScreen();
		viewPlayerList(readFile, plList);
		cout << endl;

	
		if (index == 0)
		{
			plList.erase(plList.begin() + index);
			plList.erase(plList.begin() + index);
		}

		else
		{
			index++;
	
			plList.erase(plList.begin() + index);
			plList.erase(plList.begin() + index);
		}

		//display list of players
		cout << "List of updated usernames: " << endl;
		for (vector<string>::iterator it = plList.begin(); it != plList.end(); it += 2)
		{
			cout << count << ") " << *it << endl;
			count++;
		}

		
	}
	readFile.close();

	/*if (writeFile.is_open())
	{
		for (int i = 0; i<plList.size(); i++)
			writeFile << plList[i];
		
		writeFile.close();
	}*/
}
