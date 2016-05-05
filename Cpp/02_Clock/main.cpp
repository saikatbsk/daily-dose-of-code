/* ==================================================================
 * A program to implement  the clock class, and display difference in
 * two clocks.
 * ==================================================================
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Clock {
    int hour;
    int minute;
public:
    void read(int hr, int min);
    char * get();
    int cvt2sec();  //-- Converts time into seconds
    char * timeDiffInString(int secondClockInSeconds);
};

void Clock::read(int hr, int min) {
    if(min > 59) {
        hr += min / 60;
        min = min % 60;
    }

    if(hr > 23)
        hr = 0;

    hour = hr;
    minute = min;
}

char * Clock::get() {
    char * time = (char *)malloc(sizeof(char) * 5);

    sprintf(time, "%02d:%02d", hour, minute);

    return time;
}

int Clock::cvt2sec() {
    return ((hour * 3600) + (minute * 60));
}

char * Clock::timeDiffInString(int secondClockInSeconds) {
    int d, hr, min;
    char * diff = (char *)malloc(sizeof(char) * 128);

    d = abs(cvt2sec() - secondClockInSeconds);
    hr = d / 3600;
    min = (d % 3600) / 60;

    sprintf(diff, "%02d hours and %02d minutes", hr, min);

    return diff;
}

int main() {
    int hr, min;
    Clock clk[2];

    for(int i = 0 ; i < 2 ; i++) {
        cout << "Enter time for clock [" << i << "]..\n";

        cout << "Hour: ";
        cin >> hr;

        cout << "Minute: ";
        cin >> min;

        clk[i].read(hr, min);

        cout << "Clock [" << i << "] time: " << clk[i].get() << "\n";
    }

    cout << "The difference in time is of "
         << clk[0].timeDiffInString(clk[1].cvt2sec())
         << ".\n";

    return 0;
}
