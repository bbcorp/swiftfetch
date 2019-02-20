#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <list>
#include "colors.h"

using namespace std;

/*
Calculation source : https://github.com/dylanaraps/neofetch/wiki/Frequently-Asked-Questions#linux-is-neofetchs-memory-output-correct
Authors : dylanaraps https://github.com/dylanaraps & kominex https://github.com/konimex
License : MIT licence https://github.com/dylanaraps/neofetch/blob/master/LICENSE.md
Copyright (c) 2016-2018 Dylan Araps
*/

long sumMem(string line)
{
	list<string> listMemInfos = { "^MemTotal: (.*)", "^Shmem: (.*)", "^MemFree: (.*)", "^Buffers: (.*)", "^Cached: (.*)", "^SReclaimable: (.*)" };
	for (string memInfo : listMemInfos)
	{
		try {
			std::smatch match;
			if (regex_search(line, match, regex(memInfo)) && match.size() > 1) {
				if (!memInfo.compare("^MemTotal: (.*)") || !memInfo.compare("^Shmem: (.*)"))
					return stoi(match.str(1));
				else
					return -stoi(match.str(1));
			}
		} catch (std::regex_error& e) {
			// Syntax error in the regular expression
		}
	}
	return 0;
}

void getLongFromRegex(string line, string sregex, unsigned long &result)
{
	if (!result) // Modify it only if we have no result
	{
		try {
			std::smatch match;
			if (regex_search(line, match, regex(sregex)) && match.size() > 1)
				result = stoi(match.str(1));
			} catch (std::regex_error& e) {
				 // Syntax error in the regular expression
			}
	}
}

void getMemUsage(void)
{
	string line;
	unsigned long memUsed(0);
	unsigned long memTotal(0);
	ifstream memInfos("/proc/meminfo");
        if (memInfos.is_open())
	{
		while (getline(memInfos,line))
		{
			memUsed += sumMem(line);
			getLongFromRegex(line, "^MemTotal: (.*)", memTotal);
		}
		cout << RED << "Memory" << RESET << ": ";
		cout << memUsed / 1024 << "MiB / ";
		cout << memTotal / 1024 << "MiB" << endl;
	}
	else
		cout << "Unable to open file" << endl;		
}
