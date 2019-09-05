#include <iostream>
#include <sstream>
#include <fstream>
#include <regex>
#include <algorithm>
#include "colors.h"

using namespace std;

string getOsFullName(void)
{
	string line;
	stringstream streamOut;
	streamOut << RED << "OS" << RESET << ": ";
	ifstream osRelease ("/etc/os-release");
	
	if (osRelease.is_open())
	{
		regex regexID("^PRETTY_NAME=(.*)");
		while(getline(osRelease, line))
		{
			try {
				smatch match;
				if (regex_search(line, match, regexID) && match.size() > 1)
				{
					string result(match.str(1));
					result.erase(std::remove(result.begin(),result.end(),'\"'),result.end());
					streamOut << result << endl;
					return streamOut.str();
				}
			} catch (std::regex_error& e) {
				// Syntax error in the regular expression
			}
		}
	}
	streamOut << "Unkown OS" << endl;
	return streamOut.str();
}

string getOsShortName(void)
{
        string line;
        stringstream streamOut;
        //streamOut << RED << "OS" << RESET << ": ";
        ifstream osRelease ("/etc/os-release");

        if (osRelease.is_open())
        {
                regex regexID("^ID=(.*)");
                while(getline(osRelease, line))
                {
                        try {
                                smatch match;
                                if (regex_search(line, match, regexID) && match.size() > 1)
                                {
                                        string result(match.str(1));
                                        result.erase(std::remove(result.begin(),result.end(),'\"'),result.end());
					streamOut << result ;
                                        return streamOut.str();
                                }
                        } catch (std::regex_error& e) {
                                // Syntax error in the regular expression
                        }
                }
        }
	streamOut << "Unkown OS";
	return streamOut.str();
}
