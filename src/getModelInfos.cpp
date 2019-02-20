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
			cout << line << " ";
                modelInfosFile.close();
        	}
        	else
			cout << "Unable to open file";
	}
	cout << endl;
}
