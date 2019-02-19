#include <iostream>
#include <cstdlib>
#include "colors.h"

using namespace std;

void getTerminalInfos(void)
{
	char *env_tty(getenv("TTY"));
	if (env_tty != nullptr)
		cout << RED << "Terminal" << RESET << ": " << env_tty << endl;
	else
	{
		env_tty = getenv("SSH_TTY");
		if (env_tty != nullptr)
			cout << RED << "Terminal" << RESET << ": " << env_tty << endl;
	}
}
