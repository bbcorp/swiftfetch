#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <list>
#include "colors.h"

using namespace std;

string getModelInfos(void)
{
	stringstream streamOut;
	streamOut << RED << "Model" << RESET << ": ";
	list<string> modelInfosFilePaths = {"/sys/devices/virtual/dmi/id/sys_vendor", "/sys/devices/virtual/dmi/id/product_name", "/sys/devices/virtual/dmi/id/product_version"};
        string line;
	for (string filePath : modelInfosFilePaths)
	{
        	ifstream modelInfosFile(filePath);
        	if (modelInfosFile.is_open())
        	{
                	getline (modelInfosFile,line);
			streamOut << line << " ";
                modelInfosFile.close();
        	}
        	else
			streamOut << "Unable to open file ";
	}
	streamOut << endl;
	return streamOut.str();
}
