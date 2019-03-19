#include <iostream>
#include <sstream>
#include <string>
#include "getStdoutFromShell.h"
#include "colors.h"

using namespace std;

string getShellInfos(void)
{
	stringstream streamOut;
        string env_shell(getenv("SHELL"));
        if(env_shell == "/usr/bin/zsh")
        {
                string zshVersion(getStdoutFromShell("/usr/bin/zsh --version"));
                zshVersion = zshVersion.substr(0, zshVersion.find("\n", 0) + 1); // + 1 to also delete carriage return itself
                streamOut << RED << "Shell" << RESET << ": " << zshVersion;
        }
        else if(env_shell == "/bin/bash")
        {
                string bashVersion(getStdoutFromShell("/bin/bash --version"));
                // bash --version output multiples lines and not "short" version
                bashVersion = bashVersion.substr(0, bashVersion.find("\n", 0) + 1); // + 1 to also delete carriage return itself
                streamOut << RED << "Shell" << RESET << ": " << bashVersion;
        }
	return streamOut.str();

}
