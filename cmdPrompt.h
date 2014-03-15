#ifndef CMDPROMPT_H
#define CMDPROMPT_H

#include <map>
#include <string>

using std::string;
using std::map;

class CmdPrompt
{
public:
	CmdPrompt();
	void showHelp();
	char getCommand();		//this should allow showHelp to be called, and should loop until a valid cmd is entered
	string askPlayerName();
	void showGreeting();
	//bool processCommand();  //how is the command actually executed?  should this be in a different class?  It's in GameController
	void message(string theMessage);
private:
	string promptText;
	map<char, string> commands;  //maybe the value type should be direction enum?
};



#endif // !CMDPROMPT_H
