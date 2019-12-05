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
	string lineAscii("");
	string lineAsciiWithColors("");
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
	string asciiLogoWithColors("");;
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
	else if (osName == "arch")
	{
		asciiLogoWithColors = CYAN + R"***(                  -`)***" + RESET + "\n"
+ CYAN + R"***(                 .o+`)***" + RESET + "\n"
+ CYAN + R"***(                `ooo/)***" + RESET + "\n"
+ CYAN + R"***(               `+oooo:)***" + RESET + "\n"
+ CYAN + R"***(              `+oooooo:)***" + RESET + "\n"
+ CYAN + R"***(              -+oooooo+:)***" + RESET + "\n"
+ CYAN + R"***(            `/:-:++oooo+:)***" + RESET + "\n"
+ CYAN + R"***(           `/++++/+++++++:)***" + RESET + "\n"
+ CYAN + R"***(          `/++++++++++++++:)***" + RESET + "\n"
+ CYAN + R"***(         `/+++ooooooooooooo/`)***" + RESET + "\n"
+ CYAN + R"***(        ./ooosssso++osssssso+`)***" + RESET + "\n"
+ CYAN + R"***(       .oossssso-````/ossssss+`)***" + RESET + "\n"
+ CYAN + R"***(      -osssssso.      :ssssssso.)***" + RESET + "\n"
+ CYAN + R"***(     :osssssss/        osssso+++.)***" + RESET + "\n"
+ CYAN + R"***(    /ossssssss/        +ssssooo/-)***" + RESET + "\n"
+ CYAN + R"***(  `/ossssso+/:-        -:/+osssso+-)***" + RESET + "\n"
+ CYAN + R"***( `+sso+:-`                 `.-/+oso:)***" + RESET + "\n"
+ CYAN + R"***(`++:.                           `-/+/)***" + RESET + "\n"
+ CYAN + R"***(.`                                 `/)***" + RESET;
		totalLength = 38;
	}

	else if (osName == "alpine")
	{
		asciiLogoWithColors = BLUE + R"***(       .hddddddddddddddddddddddh.    )***" + RESET + "\n"
+ BLUE + R"***(      :dddddddddddddddddddddddddd:)***" + RESET + "\n"
+ BLUE + R"***(     /dddddddddddddddddddddddddddd/)***" + RESET + "\n"
+ BLUE + R"***(    +dddddddddddddddddddddddddddddd+)***" + RESET + "\n"
+ BLUE + R"***(  `sdddddddddddddddddddddddddddddddds`)***" + RESET + "\n"
+ BLUE + R"***( `ydddddddddddd++hdddddddddddddddddddy`)***" + RESET + "\n"
+ BLUE + R"***(.hddddddddddd+`  `+ddddh:-sdddddddddddh.)***" + RESET + "\n"
+ BLUE + R"***(hdddddddddd+`      `+y:    .sddddddddddh)***" + RESET + "\n"
+ BLUE + R"***(ddddddddh+`   `//`   `.`     -sddddddddd)***" + RESET + "\n"
+ BLUE + R"***(ddddddh+`   `/hddh/`   `:s-    -sddddddd)***" + RESET + "\n"
+ BLUE + R"***(ddddh+`   `/+/dddddh/`   `+s-    -sddddd)***" + RESET + "\n"
+ BLUE + R"***(ddd+`   `/o` :dddddddh/`   `oy-    .yddd)***" + RESET + "\n"
+ BLUE + R"***(hdddyo+ohddyosdddddddddho+oydddy++ohdddh)***" + RESET + "\n"
+ BLUE + R"***(.hddddddddddddddddddddddddddddddddddddh.)***" + RESET + "\n"
+ BLUE + R"***( `yddddddddddddddddddddddddddddddddddy`)***" + RESET + "\n"
+ BLUE + R"***(  `sdddddddddddddddddddddddddddddddds`)***" + RESET + "\n"
+ BLUE + R"***(    +dddddddddddddddddddddddddddddd+)***" + RESET + "\n"
+ BLUE + R"***(     /dddddddddddddddddddddddddddd/)***" + RESET + "\n"
+ BLUE + R"***(      :dddddddddddddddddddddddddd:)***" + RESET + "\n"
+ BLUE + R"***(       .hddddddddddddddddddddddh.)***" + RESET;
	totalLength = 40;

	}

	else
	{
		asciiLogoWithColors = WHITE + R"***(     _)***" + RESET + "\n"
+ WHITE + R"***(    / /\)***" + RESET + "\n"
+ WHITE + R"***(   / /  \)***" + RESET + "\n"
+ WHITE + R"***(  / / /\ \___)***" + RESET + "\n"
+ WHITE + R"***(/ / /\ \__  /\)***" + RESET + "\n"
+ WHITE + R"***(/_/ /  \__/ / /)***" + RESET + "\n"
+ WHITE + R"***(\ \ \    /_/ /)***" + RESET + "\n"
+ WHITE + R"***( \_\/    \ \ \)***" + RESET + "\n"
+ WHITE + R"***(          \_\/_)***" + RESET + "\n"
+ WHITE + R"***(            /_/\)***" + RESET + "\n"
+ WHITE + R"***(            \_\/)***" + RESET;
		totalLength = 20;

	}


	return fillWithSpaces(asciiLogoWithColors, totalLength);
}
