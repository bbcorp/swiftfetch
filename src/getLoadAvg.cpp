#include <iostream>
#include <sstream>
#include <cstdlib>
#include "colors.h"

using namespace std;

string getLoadAvg(void)
{
	stringstream streamOut;
	double averages[3];
	getloadavg(averages, 3);
	streamOut << RED << "Load averages" << RESET << ": ";
	streamOut << averages[0] << ", " << averages[1] << ", " << averages[2] << endl;
	return streamOut.str();
}	
