#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <list>
#include "colors.h"

using namespace std;

string getModelInfos(void)
{
	string stringOut;
	//streamOut << RED << "Model" << RESET << ": ";
	list<string> modelInfosFilePaths = {"/sys/devices/virtual/dmi/id/sys_vendor", "/sys/devices/virtual/dmi/id/product_name", "/sys/devices/virtual/dmi/id/product_version"};
        string line;
	for (string filePath : modelInfosFilePaths)
	{
        	ifstream modelInfosFile(filePath);
        	if (modelInfosFile.is_open())
        	{
                	getline (modelInfosFile,line);
			stringOut += line + " ";
                	modelInfosFile.close();
        	}
	}
	if (stringOut.length() > 0) // We did gather model info
		stringOut = RED + "Model" + RESET + ": " + stringOut;
		 
	//streamOut << endl;
	return stringOut;
}
