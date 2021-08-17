#pragma once

using namespace std;

class loginMenu;
class Game;
class Brain;

class Admin
{
public:
	int choice;
	vector<string> plList;
	void displayAdminMenu();
	void SetChoice(Brain &, int);
	void viewPlayerList(ifstream &, vector<string>&);
	void removePlayer(ifstream &, vector<string>&, ofstream &);
	
private:
	int DoChoice(Brain &, int);
};

