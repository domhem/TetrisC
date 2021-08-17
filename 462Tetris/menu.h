#pragma once

class Game;
class Brain;

class Menu
{
public:
	int choice;
	void SetChoice(Game &obj, Brain &obj2, int c);
	void DisplayWelcomeInterface();

private:
	//int getChoice() { return choice; }
	int DoChoice(Game &obj, Brain &obj2, int choice);
};