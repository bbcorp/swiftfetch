#include <stdlib.h>
#include "getUsernameAtHostname.h"
#include "printUnderline.h" 
#include "getOsName.h"
#include "getKernel.h"
#include "getTerminalInfos.h"
#include "getUptime.h"
#include "getLoadAvg.h"
#include "getShellInfos.h"
#include "getCpuInfos.h"

using namespace std;

int main(int argc, char *argv[])
{
	printUnderline(getUsernameAtHostname());
        getOsName();
        getKernel();
	getTerminalInfos();
        getUptime();
	getLoadAvg();
	getShellInfos();
	getCpuInfos();
        return EXIT_SUCCESS;
}
