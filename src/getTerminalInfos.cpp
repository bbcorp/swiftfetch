#include <iostream>
#include <sstream>
#include <cstdlib>
#include "colors.h"

using namespace std;

string getTerminalInfos(void)
{
	stringstream streamOut;
	char *env_tty(getenv("TTY"));
	if (env_tty != nullptr)
		streamOut << RED << "Terminal" << RESET << ": " << env_tty << endl;
	else
	{
		env_tty = getenv("SSH_TTY");
		if (env_tty != nullptr)
			streamOut << RED << "Terminal" << RESET << ": " << env_tty << endl;
	}
	return streamOut.str();
}
