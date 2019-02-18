#include <iostream>
#include <chrono>
#include <ratio>
#include <fstream>
#include "colors.h"

using namespace std;

void getUptime(void)
{
        typedef chrono::duration<unsigned short, ratio<86400>> days;

        double uptime_seconds;
        if (ifstream("/proc/uptime", ios::in) >> uptime_seconds)
        {
                chrono::seconds uptime_sec(static_cast<unsigned long long>(uptime_seconds));

                chrono::minutes uptime_min(chrono::duration_cast<chrono::minutes>(uptime_sec));
                uptime_sec -= uptime_min;

                chrono::hours uptime_hour(chrono::duration_cast<chrono::hours>(uptime_min));
                uptime_min -= uptime_hour;

                days uptime_day(chrono::duration_cast<days>(uptime_hour));
                uptime_hour -= uptime_day;

                cout << RED << "Uptime" << RESET << ": ";
                if(uptime_day > days(0) && uptime_hour > chrono::hours(0) && uptime_min > chrono::minutes(0))
                        cout << uptime_day.count() << "d, " << uptime_hour.count() << "h, " << uptime_min.count() << "m" << endl;
                else if(uptime_hour > chrono::hours(0) && uptime_min > chrono::minutes(0))
                        cout << uptime_hour.count() << "h, " << uptime_min.count() << "m" << endl;
                else
                        cout << uptime_min.count() << "m" << endl;
        }
}
