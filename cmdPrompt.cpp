/*
Peter Lindberg
CS165 w2014
Final Project
*/
#include "cmdPrompt.h"
#include <iostream>
#include <string>
#include <cctype>

using std::cout;
using std::cin;
using std::getline;
using std::string;


CmdPrompt::CmdPrompt()
{
	promptText = "\nCommand (h for help): ";

	commands['n'] = "north";
	commands['s'] = "south";
	commands['e'] = "east";
	commands['w'] = "west";
	commands['l'] = "look around";
	commands['f'] = "fight creature";
	commands['t'] = "take item";
	commands['i'] = "inventory";
	commands['q'] = "quit";
	commands['h'] = "help";

	//showGreeting();  //moved to gameController
}

string CmdPrompt::askPlayerName()
{
	string name;
	bool invalidInput = true;

	do
	{
		cout << "\nPlease enter your name: ";
		getline(cin, name);

		if (name != "")  //check if cmd is a key in the map
		{
			invalidInput = false;
			cout << "\nGreetings, " << name << "!\n";
			return name;
		}
		else
		{
			cout << "\nInvalid input\n";
		}

	} while (invalidInput);
	

}

/*  Made a real version of this in gameController 
void CmdPrompt::showGreeting()
{
	cout << "\n\nTHIS IS A PLACEHOLDER\ngame title/greeting goes here\n\n";
}
*/

void CmdPrompt::showHelp()
{
	cout << "\nAvailable commands are:\n";
	for (auto it = commands.begin(); it != commands.end(); ++it)
	{
		cout << it->second << "\n";
	}
	cout << "\nOnly the first letter of the command must be entered.\n";
}

char CmdPrompt::getCommand()  //only accepts valid commands from the player
{
	char cmd;
	bool invalidInput = true;
	string input;

	do
	{
		cout << promptText;
		getline(cin, input);
		cmd = input[0];
		cmd = tolower(cmd);
		if (commands.count(cmd) == 1)  //check if cmd is a key in the map
		{
			invalidInput = false;
			cout << commands[cmd] << "\n";
			return cmd;
		}
		else
		{
			cout << "\nInvalid command\n";
		}

	} while (invalidInput);

}

void CmdPrompt::message(string msg)
{
	//what was this for?
}