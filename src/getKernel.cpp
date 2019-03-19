#include <iostream>
#include <sstream>
#include <sys/utsname.h>
#include "colors.h"

using namespace std;

string getKernel(void)
{
        stringstream streamOut;
	struct utsname buffer;
        errno = 0;
        if (uname(&buffer) != 0) {
                perror("uname");
                exit(EXIT_FAILURE);
        }
	streamOut <<  RED << "Kernel" << RESET << ": " << buffer.release << endl;
	return streamOut.str();
}
