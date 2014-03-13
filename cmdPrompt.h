#ifndef CMDPROMPT_H
#define CMDPROMPT_H

#include <map>


using std::string;
using std::map;

class CmdPrompt
{
public:
	CmdPrompt();
	void showHelp();
	char getCommand();		//this should allow showHelp to be called, and should loop until a valid cmd is entered
	void processCommand();  //how is the command actually executed?  should this be in a different class?
private:
	string promptText;
	map<char, string> commands;  //maybe the value type should be direction enum?
};



#endif // !CMDPROMPT_H
