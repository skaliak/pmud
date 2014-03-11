#ifndef CMDPROMPT_H
#define CMDPROMPT_H

#include <vector>

using std::string;
using std::vector;

class MyClass
{
public:
	MyClass(){}
	void showHelp();
	void showPrompt();
	void processCommand();  //how is the command actually executed?  should this be in a different class?
private:
	vector<char> commands;
};



#endif // !CMDPROMPT_H
