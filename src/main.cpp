#include <stdlib.h>
#include "getUsernameAtHostname.h"
#include "printUnderline.h" 
#include "getOsName.h"
#include "getKernel.h"
#include "getUptime.h"
#include "getShellInfos.h"

using namespace std;

int main(int argc, char *argv[])
{
	printUnderline(getUsernameAtHostname());
        getOsName();
        getKernel();
        getUptime();
	getShellInfos();
        return EXIT_SUCCESS;
}
