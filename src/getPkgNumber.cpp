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

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}


using namespace std;



string getPkgNumber(void)
{
	stringstream streamOut;
	string numberPackages;
	ifstream dpkg("/usr/bin/dpkg-query");
	if (dpkg.good())
	{
		streamOut << RED << "Packages" << RESET << ": ";
		numberPackages = exec("dpkg-query -f '${binary:Package}\n' -W|wc -l");
		numberPackages.erase(remove(numberPackages.begin(), numberPackages.end(), '\n'), numberPackages.end());
		streamOut << numberPackages << " (dpkg)" << endl;
	}
	return streamOut.str();
/*        strLen = 0;
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
                usernameAtHostname += string("@") + RED + line + RESET + "\n";
                strLen += line.length() + 1;
                hostname.close();
        }
        else return "Unable to open file\n";

        return usernameAtHostname;*/
}
