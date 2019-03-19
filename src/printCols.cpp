#include <iostream>
#include <string>
#include <list>
#include "colors.h"

using namespace std;

string printCols(void)
{
	string stringOut("");
	list<string> colors = { BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE };
	for (string color : colors)
	{
		stringOut += color;
		for (short i = 0; i < 3; i++)
		{
			stringOut += "\u2588" ;
		}
		stringOut += RESET;
	}
	stringOut += "\n\n";
	return stringOut;
}
