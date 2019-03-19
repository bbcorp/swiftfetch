#include <stdlib.h>
#include <iostream>
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

using namespace std;

void printAll(void)
{
	cout << printUnderline(getUsernameAtHostname());
	cout << printCols();
	cout << getOsName();
	cout << getKernel();
	cout << getCpuInfos();
	cout << getUptime();
	cout << getLoadAvg();
	cout << getMemUsage();
	cout << getModelInfos();
	cout << getShellInfos();
	cout << getTerminalInfos();
}


int main(int argc, char *argv[])
{
        printAll();
	return EXIT_SUCCESS;
}
