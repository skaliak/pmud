#include "cmdPrompt.h"
#include <iostream>

using std::cout;

CmdPrompt::CmdPrompt()
{
	promptText = "Command (h for help): ";

	commands['n'] = "north";
	commands['s'] = "south";
	commands['e'] = "east";
	commands['w'] = "west";
	commands['l'] = "look around";
}

void CmdPrompt::showHelp()
{

}