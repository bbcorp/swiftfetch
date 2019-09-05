#include <iostream>
#include <algorithm>
#include <sstream>
#include <regex>
#include "colors.h"

using namespace std;

void deleteAnsiEscapeColor(string & stringAnsiColor)
{
	regex regexAnsiEscapesSequencesColor("\033[[[:digit:]]+m");
	stringAnsiColor = regex_replace(stringAnsiColor, regexAnsiEscapesSequencesColor, "");
}

string fillWithSpaces(string asciiLogo, unsigned short totalLength)
{
	stringstream streamAsciiWithColors(asciiLogo);
	deleteAnsiEscapeColor(asciiLogo);
	stringstream streamAsciiRaw(asciiLogo);
	stringstream streamOut;
	string lineAscii;
	string lineAsciiWithColors;
	unsigned short lineAsciiSize(0);
	while (getline(streamAsciiRaw, lineAscii) && getline(streamAsciiWithColors, lineAsciiWithColors))
	{
		if (lineAscii.size() < totalLength)
		{
			lineAsciiSize = lineAscii.size();
			for (int i = 0; i < totalLength - lineAsciiSize ; i++)
				lineAsciiWithColors += " ";
		}
		streamOut << lineAsciiWithColors << endl;
 	}
	return streamOut.str();
}


string getAsciiLogo(string osName)
{
	string asciiLogoWithColors;
	unsigned short totalLength(0);

	if (osName == "debian")
{
		asciiLogoWithColors = WHITE + R"***(       _,met$$$$$gg.
    ,g$$$$$$$$$$$$$$$P.
  ,g$$P"     """Y$$.".
 ,$$P'              `$$$.
',$$P       ,ggs.     `$$b:
`d$$'     ,$P"'   )***" + RED + R"***(.)***" + WHITE + R"***(    $$$ 
 $$P      d$'     )***" + RED + R"***(,)***" + WHITE + R"***(    $$P 
 $$:      $$.   )***" + RED + R"***(-)***" + WHITE + R"***(    ,d$$'
 $$;      Y$b._   _,d$P'
 Y$$.    )***" + RED + R"***(`.)***" + WHITE + R"***(`"Y$$$$P"'
 `$$b      )***" + RED + R"***("-.__)***" + WHITE + R"***(
  `Y$$
   `Y$$.
     `$$b.
       `Y$$b.
          `"Y$b._
              `"""
)***" + RESET;

	totalLength = 35;
}			
	else if (osName == "ubuntu")
{
		asciiLogoWithColors = RED + R"***(            .-/+oossssoo+/-.)***" + RESET + "\n"
+ RED + R"***(        `:+ssssssssssssssssss+:`)***" + RESET + "\n"
+ RED + R"***(      -+ssssssssssssssssssyyssss+-)***" + RESET + "\n"
+ RED + R"***(    .ossssssssssssssssss)***" + WHITE + R"***(dMMMNy)***" + RED + R"***(sssso.)***" + RESET + "\n"
+ RED + R"***(   /sssssssssss)***" + WHITE + R"***(hdmmNNmmyNMMMMh)***" + RED + R"***(ssssss/)***" + RESET + "\n"
+ RED + R"***(  +sssssssss)***" + WHITE + R"***(hm)***" + RED + R"***(yd)***" + WHITE + R"***(MMMMMMMNddddy)***" + RED + R"***(ssssssss+)***" + RESET + "\n"
+ RED + R"***( /ssssssss)***" + WHITE + R"***(hNMMM)***" + RED + R"***(yh)***" + WHITE + R"***(hyyyyhmNMMMNh)***" + RED + R"***(ssssssss/)***" + RESET + "\n"
+ RED + R"***(.ssssssss)***" + WHITE + R"***(dMMMNh)***" + RED + R"***(ssssssssss)***" + WHITE + R"***(hNMMMd)***" + RED + R"***(ssssssss.)***" + RESET + "\n"
+ RED + R"***(+ssss)***" + WHITE + R"***(hhhyNMMNy)***" + RED + R"***(ssssssssssss)***" + WHITE + R"***(yNMMMy)***" + RED + R"***(sssssss+)***" + RESET + "\n"
+ RED + R"***(oss)***" + WHITE + R"***(yNMMMNyMMh)***" + RED + R"***(ssssssssssssss)***" + WHITE + R"***(hmmmh)***" + RED + R"***(ssssssso)***" + RESET + "\n"
+ RED + R"***(oss)***" + WHITE + R"***(yNMMMNyMMh)***" + RED + R"***(sssssssssssssshmmmh)***" + RED + R"***(ssssssso)***" + RESET + "\n"
+ RED + R"***(+ssss)***" + WHITE + R"***(hhhyNMMNy)***" + RED + R"***(ssssssssssss)***" + WHITE + R"***(yNMMMy)***" + RED + R"***(sssssss+)***" + RESET + "\n"
+ RED + R"***(.ssssssss)***" + WHITE + R"***(dMMMNh)***" + RED + R"***(ssssssssss)***" + WHITE + R"***(hNMMMd)***" + RED + R"***(ssssssss.)***" + RESET + "\n"
+ RED + R"***( /ssssssss)***" + WHITE + R"***(hNMMM)***" + RED + R"***(yh)***" + WHITE + R"***(hyyyyhdNMMMNh)***" + RED + R"***(ssssssss/)***" + RESET + "\n"
+ RED + R"***(  +sssssssss)***" + WHITE + R"***(dm)***" + RED + R"***(yd)***" + WHITE + R"***(MMMMMMMMddddy)***" + RED + R"***(ssssssss+)***" + RESET + "\n"
+ RED + R"***(   /sssssssssss)***" + WHITE + R"***(hdmNNNNmyNMMMMh)***" + RED + R"***(ssssss/)***" + RESET + "\n"
+ RED + R"***(    .ossssssssssssssssss)***" + WHITE + R"***(dMMMNy)***" + RED + R"***(sssso.)***" + RESET + "\n"
+ RED + R"***(      -+sssssssssssssssss)***" + WHITE + R"***(yyy)***" + RED + R"***(ssss+-)***" + RESET + "\n"
+ RED + R"***(        `:+ssssssssssssssssss+:`)***" + RESET + "\n"
+ RED + R"***(            .-/+oossssoo+/-.)***" + RESET;
	totalLength = 45;
}
	return fillWithSpaces(asciiLogoWithColors, totalLength);
}
