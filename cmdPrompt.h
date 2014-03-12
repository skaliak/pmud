#ifndef CMDPROMPT_H
#define CMDPROMPT_H

#include <vector>

using std::string;
using std::vector;

class CmdPrompt
{
public:
	CmdPrompt();
	void showHelp();
	void showPrompt();		//this should allow showHelp to be called, and should loop until a valid cmd is entered
	void processCommand();  //how is the command actually executed?  should this be in a different class?
private:
	string promptText;
	vector<char> commands;
};



#endif // !CMDPROMPT_H
