#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "colors.h"

using namespace std;

string testDebian(void)
{
	string rawAsciiString = BOLDWHITE + R"***(
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

	return rawAsciiString;
}
