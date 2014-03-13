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
	commands['q'] = "quit";
	commands['h'] = "help";
}

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