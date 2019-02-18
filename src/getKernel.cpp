#include <iostream>
#include <sys/utsname.h>
#include "colors.h"

using namespace std;

void getKernel(void)
{
        struct utsname buffer;
        errno = 0;
        if (uname(&buffer) != 0) {
                perror("uname");
                exit(EXIT_FAILURE);
        }
        cout << RED << "Kernel" << RESET << ": " << buffer.release << endl;
}
