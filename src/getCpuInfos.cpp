#include <iostream>
#include <fstream>
#include <iomanip>
#include "colors.h"

using namespace std;

void getCpuInfos(void)
{
        string line;
	string cpuModelName;
	unsigned short cpuCoresCount(0);
	bool cpuModelNameFound = false;
	float cpuFrequency(0.0);
	bool cpuFrequencyFound = false;
        ifstream cpuInfos("/proc/cpuinfo");
        if (cpuInfos.is_open())
        {
                while (getline(cpuInfos,line))
		{
			if (!cpuModelNameFound && line.find("model name") != string::npos) // CPU Model Name
			{
				cpuModelName = line.substr(line.find(":") + 2, line.length()); // +2 : don't include delimiter and space
				cpuModelNameFound = true;
			}
			else if (line.find("processor") != std::string::npos) // Logical cores
                		cpuCoresCount++;
			else if (!cpuFrequencyFound && line.find("cpu MHz") != string::npos) // CPU Frequency
			{
				cpuFrequency = stof(line.substr(line.find(":") + 2, line.length())) / 1000; // +2 : don't include delimiter and space
				cpuFrequencyFound = true;
			}
			
		}
		cout << RED << "CPU" << RESET << ": ";
		cout << cpuModelName << " (" << cpuCoresCount << ") @ " << setprecision(3) << cpuFrequency << "GHz" << endl;
                cpuInfos.close();
        }
        else
		cout << "Unable to open file" << endl;
}
