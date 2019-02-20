#include <iostream>
#include <string>
#include <list>
#include "colors.h"

using namespace std;

void printCols(void)
{
	list<string> colors = { BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE };
	for (string color : colors)
	{
		cout << color;
		for (short i = 0; i < 3; i++)
		{
			cout << "\u2588" ;
		}
		cout << RESET;
	}
	cout << endl << endl;
}
