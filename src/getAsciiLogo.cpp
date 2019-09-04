#include <iostream>
#include "colors.h"

using namespace std;

string getAsciiLogo(string osName)
{
	string asciiLogo;

	if (osName == "debian")
		asciiLogo = BOLDWHITE + R"***(
       _,met$$$$$gg.
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
			
	else if (osName == "ubuntu")
		asciiLogo = 
	RED + R"***(
            .-/+oossssoo+/-.
        `:+ssssssssssssssssss+:`
      -+ssssssssssssssssssyyssss+-
    .ossssssssssssssssss)***" + WHITE + R"***(dMMMNy)***" + RED + R"***(sssso.
   /sssssssssss)***" + WHITE + R"***(hdmmNNmmyNMMMMh)***" + RED + R"***(ssssss/
  +sssssssss)***" + WHITE + R"***(hm)***" + RED + R"***(yd)***" + WHITE + R"***(MMMMMMMNddddy)***" + RED + R"***(ssssssss+
 /ssssssss)***" + WHITE + R"***(hNMMM)***" + RED + R"***(yh)***" + WHITE + R"***(hyyyyhmNMMMNh)***" + RED + R"***(ssssssss/
.ssssssss)***" + WHITE + R"***(dMMMNh)***" + RED + R"***(ssssssssss)***" + WHITE + R"***(hNMMMd)***" + RED + R"***(ssssssss.
+ssss)***" + WHITE + R"***(hhhyNMMNy)***" + RED + R"***(ssssssssssss)***" + WHITE + R"***(yNMMMy)***" + RED + R"***(sssssss+
oss)***" + WHITE + R"***(yNMMMNyMMh)***" + RED + R"***(ssssssssssssss)***" + WHITE + R"***(hmmmh)***" + RED + R"***(ssssssso
oss)***" + WHITE + R"***(yNMMMNyMMh)***" + RED + R"***(sssssssssssssshmmmh)***" + RED + R"***(ssssssso
+ssss)***" + WHITE + R"***(hhhyNMMNy)***" + RED + R"***(ssssssssssss)***" + WHITE + R"***(yNMMMy)***" + RED + R"***(sssssss+
.ssssssss)***" + WHITE + R"***(dMMMNh)***" + RED + R"***(ssssssssss)***" + WHITE + R"***(hNMMMd)***" + RED + R"***(ssssssss.
 /ssssssss)***" + WHITE + R"***(hNMMM)***" + RED + R"***(yh)***" + WHITE + R"***(hyyyyhdNMMMNh)***" + RED + R"***(ssssssss/
  +sssssssss)***" + WHITE + R"***(dm)***" + RED + R"***(yd)***" + WHITE + R"***(MMMMMMMMddddy)***" + RED + R"***(ssssssss+
   /sssssssssss)***" + WHITE + R"***(hdmNNNNmyNMMMMh)***" + RED + R"***(ssssss/
    .ossssssssssssssssss)***" + WHITE + R"***(dMMMNy)***" + RED + R"***(sssso.
      -+sssssssssssssssss)***" + WHITE + R"***(yyy)***" + RED + R"***(ssss+-
        `:+ssssssssssssssssss+:`
            .-/+oossssoo+/-.)***" + RESET;

	return asciiLogo;
}
