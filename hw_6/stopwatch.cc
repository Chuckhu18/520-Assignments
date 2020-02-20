#include <iostream>
#include "stopwatch.h"
#include "elma/elma.h"

using namespace std::chrono;
using namespace std;


void Stopwatch::start(){// starts the timer
    if (status == RUNNING || status == UNINITIALIZED)
        _time_start = high_resolution_clock::now();

    status = RUNNING;
    // cout << status << "\n";
    // cout << "start timer:"<< _time_start.count() << endl;
}

void Stopwatch::stop(){// stops the timer
    if (status == RUNNING)
        _time_end = high_resolution_clock::now();

    status = STOPPING;
    // cout << status << "\n";
    // cout << "end timer:"<< _time_end.count() << endl;
}

void Stopwatch::reset(){// sets stopwatch to zero
    status == UNINITIALIZED;
    // cout << status << "\n";
}

double Stopwatch::get_minutes(){
    return minutes_type(_time_end - _time_start).count();
}

double Stopwatch::get_seconds(){
    if(status == UNINITIALIZED){
        // cout << status << "\n";
        return 0.0;
    }
    return seconds_type(_time_end - _time_start).count();
}

double Stopwatch::get_milliseconds(){
    return milliseconds_type(_time_end - _time_start).count();
}

double Stopwatch::get_nanoseconds(){
    return nanoseconds_type(_time_end - _time_start).count();
}
