#include <iostream>
#include <cstdlib>
#include "colors.h"

using namespace std;

void getLoadAvg(void)
{
	double averages[3];
	getloadavg(averages, 3);
	cout << RED << "Load averages" << RESET << ": ";
	cout << averages[0] << ", " << averages[1] << ", " << averages[2] << endl;
}	
