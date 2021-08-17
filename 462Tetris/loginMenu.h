#pragma once

using namespace std;

class Game;
class Brain;

class loginMenu
{
public:
	int choice;
	int adminPass = 0;
	int userPass = 0;
	string userName;
	string pword;

	void sendNAME();
	void sendPWORD();
	void DisplayLoginMenu();
	void SetChoice(int);
	void login(ifstream &, int &, int &);
	void registerPlayer(ofstream & );
	int getUserPass();
	int getAdminPass();
	void setUserPass(int &);
	void setAdminPass(int &);

private:
	int DoChoice(int);
};


