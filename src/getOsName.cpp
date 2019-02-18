#include <iostream>
#include <fstream>
#include "colors.h"

using namespace std;

void getOsName(void)
{
        string line;
        ifstream osRelease ("/etc/os-release");
        if (osRelease.is_open())
        {
                getline (osRelease,line);
                unsigned first = line.find('"');
                unsigned last = line.find_last_of('"');
                cout << RED << "OS" << RESET << ": " << line.substr(first + 1,last-first - 1) << endl; // + 1 & - 1 in order to not include delimiter
                osRelease.close();
        }
        else cout << "Unable to open file";
}
