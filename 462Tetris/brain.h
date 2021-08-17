#pragma once

class Brain
{
public:

	size_t gamespeed=20000;
	//change the gamespeed
	void SetSpeed();
	
	void DisplaySettingsMenu();
	void SetChoice(int c);
	int DoChoice(int c);

private:
	//default difficulty is 5, ranges from 1-10
	int difficulty = gamespeed / 4000;

};