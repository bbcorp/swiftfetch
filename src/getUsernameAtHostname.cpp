#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "colors.h"
#include "getStdoutFromShell.h"

using namespace std;

string getUsernameAtHostname(unsigned short& strLen)
{
        strLen = 0;
        string usernameAtHostname("");
	string user("");
	if (getenv("USER") == nullptr)
	{
		user = getStdoutFromShell("whoami");
		user.erase(remove(user.begin(), user.end(), '\n'), user.end());
	}
	else
        	user = getenv("USER");
        if(user == "root") // if root display user in red
              	usernameAtHostname += BOLDRED;
        else // else display in green
                usernameAtHostname += GREEN;
        usernameAtHostname += user + RESET;
        strLen += user.length();

        string line("");
        ifstream hostname ("/etc/hostname");
        if (hostname.is_open())
        {
                getline (hostname,line);
                usernameAtHostname += string("@") + RED + line + RESET + "\n";
                strLen += line.length() + 1;
                hostname.close();
        }
        else return "Unable to open file\n";

        return usernameAtHostname;
}
