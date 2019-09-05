#include <iostream>
#include <chrono>
#include <ratio>
#include <fstream>
#include <sstream>
#include "colors.h"

using namespace std;

string getUptime(void)
{
	stringstream streamOut;
        typedef chrono::duration<unsigned short, ratio<86400>> days;
        double uptime_seconds;

	streamOut << RED << "Uptime" << RESET << ": ";
        if (ifstream("/proc/uptime", ios::in) >> uptime_seconds)
        {
                chrono::seconds uptime_sec(static_cast<unsigned long long>(uptime_seconds));

                chrono::minutes uptime_min(chrono::duration_cast<chrono::minutes>(uptime_sec));
                uptime_sec -= uptime_min;

                chrono::hours uptime_hour(chrono::duration_cast<chrono::hours>(uptime_min));
                uptime_min -= uptime_hour;

                days uptime_day(chrono::duration_cast<days>(uptime_hour));
                uptime_hour -= uptime_day;

                if(uptime_day > days(0) && uptime_hour > chrono::hours(0) && uptime_min > chrono::minutes(0))
                        streamOut << uptime_day.count() << "d, " << uptime_hour.count() << "h, " << uptime_min.count() << "m" << endl;
                else if(uptime_hour > chrono::hours(0) && uptime_min > chrono::minutes(0))
                        streamOut << uptime_hour.count() << "h, " << uptime_min.count() << "m" << endl;
                else
                        streamOut << uptime_min.count() << "m" << endl;
		return streamOut.str();
        }
	// Uptime not found
	streamOut << "uptime not found" << endl;
	return streamOut.str();
}
