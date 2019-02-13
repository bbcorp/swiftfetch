#ifndef MAIN_H
#define MAIN_H
#include <string>

void getOsName(void);
unsigned short getUsernameAtHostname(void);
void getKernel(void);
void getUptime(void);
void printUnderline(unsigned short len);
std::string GetStdoutFromCommand(std::string cmd);
void getShellInfos(void);
int main(int argc, char *argv[]);

#endif

