#ifndef _STOPWATCH_H
#define _STOPWATCH_H

#include <chrono>
#include <ratio>

using namespace std::chrono;

class Stopwatch {
    public:
        typedef enum {RUNNING, 
                      STOPPING,
                      UNINITIALIZED} status_type;

        typedef duration<double> seconds_type;
        typedef duration<double, std::nano> nanoseconds_type;
        typedef duration<double, std::milli> milliseconds_type;
        typedef duration<double, std::ratio<60>> minutes_type;

        Stopwatch();
        void start();              // starts the timer
        void stop();               // stops the timer
        void reset();              // sets stopwatch to zero
        double get_minutes();      // number of minutes counted, as a double
        double get_seconds();      // number of seconds counted, as a double
        double get_milliseconds(); // number of milliseconds counted, as a double
        double get_nanoseconds();  // number of nanoseconds counted, as a double

        status_type status;
        // int status = 0;

    // private:
        high_resolution_clock::time_point _time_start;
        high_resolution_clock::time_point _time_end;
        high_resolution_clock::duration _duration;

};


#endif