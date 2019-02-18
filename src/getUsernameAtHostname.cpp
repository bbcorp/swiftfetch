#include <iostream>
#include <string>
#include <fstream>
#include "colors.h"

using namespace std;

unsigned short getUsernameAtHostname(void)
{
        unsigned short strLen(0);
        string usernameAtHostname;
        string env_user(getenv("USER"));
        if(env_user == "root") // if root display user in red
                usernameAtHostname += BOLDRED;
        else // else display in green
                usernameAtHostname += GREEN;
        usernameAtHostname += env_user + RESET;
        strLen += env_user.length();

        string line;
        ifstream hostname ("/etc/hostname");
        if (hostname.is_open())
        {
                getline (hostname,line);
                usernameAtHostname += string("@") + RED + line + RESET;
                strLen += line.length() + 1;
                hostname.close();
        }
        else cout << "Unable to open file";
        cout << usernameAtHostname << endl;

        return strLen;
}
