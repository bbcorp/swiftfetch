#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include "getUsernameAtHostname.h"
#include "printUnderline.h" 
#include "getOsName.h"
#include "getKernel.h"
#include "getTerminalInfos.h"
#include "getUptime.h"
#include "getLoadAvg.h"
#include "getShellInfos.h"
#include "getCpuInfos.h"
#include "getMemUsage.h"
#include "getModelInfos.h"
#include "printCols.h"
#include "testDebian.h"

using namespace std;

void printAll(void)
{
	stringstream streamOut("");
	streamOut << printUnderline(getUsernameAtHostname());
	streamOut << printCols();
	streamOut << getOsName();
	streamOut << getKernel();
	streamOut << getCpuInfos();
	//streamOut << getUptime(); //FIXME uptime display broken
	streamOut << getLoadAvg();
	streamOut << getMemUsage();
	streamOut << getModelInfos();
	streamOut << getShellInfos();
	streamOut << getTerminalInfos();
	
	stringstream streamAsciiRaw(testDebian());
	string lineAscii;
	string	lineStreamOut;

	while (getline(streamAsciiRaw, lineAscii) && getline(streamOut, lineStreamOut))
		cout << lineAscii << lineStreamOut << endl;

	while (getline(streamAsciiRaw, lineAscii))
		cout << lineAscii << endl;
}


int main(int argc, char *argv[])
{
        printAll();
	return EXIT_SUCCESS;
}
