#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sys/utsname.h>
#include <chrono>
#include <ratio>
#include "include/main.h"
#include "include/colors.h"

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
                cout << "OS: " << line.substr(first + 1,last-first - 1) << endl; // + 1 & - 1 in order to not include delimiter
                osRelease.close();
        }
        else cout << "Unable to open file";
}

unsigned short getUsernameAtHostname(void)
{
	unsigned short strLen(0);
        string usernameAtHostname;
	string env_user(getenv("USER"));	
	if(env_user == "root")
		usernameAtHostname += string(BOLDRED);
	else
		usernameAtHostname += string(BLUE); 
	usernameAtHostname += env_user + string(RESET);
	strLen += env_user.length();

        string line;
        ifstream hostname ("/etc/hostname");
        if (hostname.is_open())
        {
                getline (hostname,line);
                usernameAtHostname += string("@") + line;
		strLen += line.length() + 1;
                hostname.close();
        }
        else cout << "Unable to open file";
        cout << usernameAtHostname << endl;

	return strLen;
}

void getKernel(void)
{
        struct utsname buffer;
        errno = 0;
        if (uname(&buffer) != 0) {
                perror("uname");
                exit(EXIT_FAILURE);
        }
        cout << "Kernel: " << buffer.release << endl;
}

void getUptime(void)
{
        typedef chrono::duration<unsigned short, ratio<86400>> days;

        double uptime_seconds;
        if (ifstream("/proc/uptime", ios::in) >> uptime_seconds)
        {
                chrono::seconds uptime_sec(static_cast<unsigned long long>(uptime_seconds));

                chrono::minutes uptime_min(chrono::duration_cast<chrono::minutes>(uptime_sec));
	        uptime_sec -= uptime_min;

                chrono::hours uptime_hour(chrono::duration_cast<chrono::hours>(uptime_min));
	        uptime_min -= uptime_hour;
                
		days uptime_day(chrono::duration_cast<days>(uptime_hour));
	        uptime_hour -= uptime_day;

		cout << "Uptime: ";
		if(uptime_day > days(0) && uptime_hour > chrono::hours(0) && uptime_min > chrono::minutes(0))
                	cout << uptime_day.count() << "d, " << uptime_hour.count() << "h, " << uptime_min.count() << "m" << endl;
		else if(uptime_hour > chrono::hours(0) && uptime_min > chrono::minutes(0))
			cout << uptime_hour.count() << "h, " << uptime_min.count() << "m" << endl;
		else
			cout << uptime_min.count() << "m" << endl;
        }
}

void printUnderline(unsigned short len)
{
	cout << string(len, '-') << endl;
}

string GetStdoutFromCommand(string cmd)
{

        string data;
        FILE * stream;
        const int max_buffer = 256;
        char buffer[max_buffer];
	cmd.append(" 2>&1");

        stream = popen(cmd.c_str(), "r");
        if (stream) {
                while (!feof(stream))
                        if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
                pclose(stream);
        }
        return data;
}



void getShellInfos(void)
{
	string env_shell(getenv("SHELL"));
	if(env_shell == "/usr/bin/zsh")
	{
		string zshVersion(GetStdoutFromCommand("/usr/bin/zsh --version"));
		zshVersion = zshVersion.substr(0, zshVersion.find("\n", 0) + 1); // + 1 to also delete carriage return itself
		cout << "Shell: " << zshVersion;
	}
	else if(env_shell == "/bin/bash")
	{
		string bashVersion(GetStdoutFromCommand("/bin/bash --version"));
		// bash --version output multiples lines and not "short" version
		bashVersion = bashVersion.substr(0, bashVersion.find("\n", 0) + 1); // + 1 to also delete carriage return itself	
		cout << "Shell: " << bashVersion;
	}

}


int main(int argc, char *argv[])
{
	printUnderline(getUsernameAtHostname());

        getOsName();
        getKernel();
        getUptime();
	getShellInfos();
        return EXIT_SUCCESS;
}

