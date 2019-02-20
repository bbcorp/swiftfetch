#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "colors.h"

using namespace std;

void getModelInfos(void)
{
	cout << RED << "Model" << RESET << ": ";
	list<string> modelInfosFilePaths = {"/sys/devices/virtual/dmi/id/sys_vendor", "/sys/devices/virtual/dmi/id/product_name", "/sys/devices/virtual/dmi/id/product_version"};
        string line;
	for (string filePath : modelInfosFilePaths)
	{
        	ifstream modelInfosFile(filePath);
        	if (modelInfosFile.is_open())
        	{
                	getline (modelInfosFile,line);
                /*unsigned first = line.find('"');
                unsigned last = line.find_last_of('"');
                cout << RED << "OS" << RESET << ": " << line.substr(first + 1,last-first - 1) << endl; // + 1 & - 1 in order to not include delimiter*/
			cout << line << " ";
                modelInfosFile.close();
        	}
        	else
			cout << "Unable to open file";
	}
	cout << endl;
}
