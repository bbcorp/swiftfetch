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
#include "getAsciiLogo.h"
#include "colors.h"
#include "getPkgNumber.h"


using namespace std;

void printAll(void)
{
	stringstream streamOut("");
	unsigned short userNameAtHostnameLength(0);
	streamOut << getUsernameAtHostname(userNameAtHostnameLength);
	streamOut << printUnderline(userNameAtHostnameLength);
	streamOut << printCols();
	streamOut << getOsFullName();
	streamOut << getKernel();
	streamOut << getCpuInfos();
	streamOut << getUptime();
	streamOut << getLoadAvg();
	streamOut << getPkgNumber();
	streamOut << getMemUsage();
	streamOut << getModelInfos();
	streamOut << getShellInfos();
	streamOut << getTerminalInfos();
	stringstream streamAsciiRaw(getAsciiLogo(getOsShortName()));
	string lineAscii;
	string	lineStreamOut;

	while (getline(streamOut, lineStreamOut) && getline(streamAsciiRaw, lineAscii))
		cout << lineAscii << lineStreamOut << endl;

	while (getline(streamAsciiRaw, lineAscii))
		cout << lineAscii << endl;

	
}


int main(int argc, char *argv[])
{
        printAll();
	return EXIT_SUCCESS;
}
