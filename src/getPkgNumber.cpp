#include <string>
#include <fstream>
#include <sstream>
#include <sys/stat.h>
#include <unistd.h>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <algorithm>
#include "colors.h"

using namespace std;

string exec(const char* cmd) {
    array<char, 128> buffer;
    string result("");
    unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}





string getPkgNumber(void)
{
	stringstream streamOut;
	string numberPackages("");
	ifstream dpkg("/usr/bin/dpkg-query");
	if (dpkg.good())
	{
		streamOut << RED << "Packages" << RESET << ": ";
		numberPackages = exec("dpkg-query -f '${binary:Package}\n' -W|wc -l");
		numberPackages.erase(remove(numberPackages.begin(), numberPackages.end(), '\n'), numberPackages.end());
		streamOut << numberPackages << " (dpkg)" << endl;
	}
	return streamOut.str();
}
