#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "loginMenu.h"
#include "clear.h"
#include "game.h"
#include "brain.h"

using namespace std;

int loginMenu::getAdminPass()
{
	return adminPass;
}

int loginMenu::getUserPass()
{
	return userPass;
}

void loginMenu::setAdminPass(int & adminPass)
{
	this->adminPass = adminPass;
}

void loginMenu::setUserPass(int & userPass)
{
	this->userPass = userPass;
}

void loginMenu::sendNAME()
{
	cout << "Enter your desired username: ";
	cin >> userName;
};

void loginMenu::sendPWORD()
{
	cout << "Enter your desired password: ";
	cin >> pword;
};

void loginMenu::DisplayLoginMenu()
{
	
	cout << "======================================================\n"
		" #####  ###### #####  ######    ###    #####\n"
		"   #    #        #    #     #    #    #     \n"
		"   #    #####    #    ######     #     #####\n"
		"   #    #        #    #   #      #          #\n"
		"   #    ######   #    #     #   ###    #####\n"


		"======================================================\n";
	
	cout << "Welcome to the login menu\n"
		"1) Login\n"
		"2) Register\n"
		"3) Exit Game\n"
		">>";

}

void loginMenu::login(ifstream & readFile, int & userPass, int & adminPass)
{
	string username;
	string password;

	//string array of the admins
	string admins[3] = { "Sarah", "Anthony", "Dominick" };

	int check = 0;

	if (readFile.is_open())
	{
		cout << "Enter userName: ";
		cin >> username;
		cout << endl;

		cout << "Enter Password: ";
		cin >> password;
		cout << endl;

		//storing all the usernames and password into a string array

		vector<string> playerList;
		string read = "";

		while (readFile >> read)
		{
			playerList.push_back(read);
		}

		cout << "scanning for username..." << endl;
		
		//
		for (int j = 0; j < playerList.size(); j += 2)
		{
			//checking if user is admin
			if (username == playerList[j] && (username == admins[0] || username == admins[1] || username == admins[2]))

			{
				ClearScreen();
				cout << "\nUsername found, checking password" << endl;
				
				if (password == playerList[j + 1])
				{
					cout << "\nWelcome Admin " << username << "!" << endl;
					check++;
					adminPass++;
					setAdminPass(adminPass);
					break;
				}

				else
				{
					cout << "Invalid password " << endl;
					
				}
			}

			//checking if player's username and password is valid
			else if (username == playerList[j] && (username != admins[0] || username != admins[1] || username != admins[2]))
			{
				ClearScreen();
				cout << "\nUsername found, checking password" << endl;
				
				if (password == playerList[j + 1])
				{
					cout << "\nWelcome User " << username << "!" << endl;
					check++;
					userPass++;
					setUserPass(userPass);
					break;
				}
				
				else
				{
					cout << "Invalid password " << endl;

				}
			}

		}

		//checking if the above if statements in the for loop were execureted
		//if not then return not valid username
		if (check == 0)
		{
			cout << "\nInvalid username or password." << endl;
		}

		readFile.close();
	}
};

void loginMenu::registerPlayer(ofstream & writeFile)
{
	loginMenu playerInfo;

	playerInfo.sendNAME();
	cout << endl;
	playerInfo.sendPWORD();
	cout << endl;

	//adding username and password to PlayerList txt file
	if (writeFile.is_open())
	{
		writeFile << playerInfo.userName << endl;
		writeFile << playerInfo.pword << endl;
		writeFile.close();
	}

	else
	{
		cout << "Unable to open file";
	}
};

//function checks to see if a valid choice was made before setting it
void loginMenu::SetChoice(int ch)
{
	switch (ch)
	{
	case 1:
	case 2:
	case 3:
		break;
		//if any number other than 1,2,3 is chosen, reset choice to 0
	default:
		ch = 0;
		break;
	}

	choice = ch;
	DoChoice(choice);
}

//call the correct option according to the player choice
int loginMenu::DoChoice(int choice)
{
	ifstream readFile("PlayerList.txt");
	ofstream writeFile("PlayerList.txt", ios::app);
	loginMenu User;

	switch (choice)
	{
	case 1:
		User.login(readFile, userPass, adminPass);
		break;
	case 2:
		User.registerPlayer(writeFile);
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






