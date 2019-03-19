#include <iostream>
#include <fstream>
#include <sstream>
#include "colors.h"

using namespace std;

string getOsName(void)
{
	stringstream streamOut;
        string line;
        ifstream osRelease ("/etc/os-release");
        if (osRelease.is_open())
        {
                getline (osRelease,line);
                unsigned first = line.find('"');
                unsigned last = line.find_last_of('"');
                streamOut << RED << "OS" << RESET << ": " << line.substr(first + 1,last-first - 1) << endl;; // + 1 & - 1 in order to not include delimiter
                osRelease.close();
		return streamOut.str();
        }
        else
		return "Unable to open file";
}
