#include <iostream>
#include "stopwatch.h"
#include "elma/elma.h"

using namespace std::chrono;
using namespace std;

Stopwatch::Stopwatch(){
    _duration = high_resolution_clock::duration::zero();
    status == UNINITIALIZED;
}
void Stopwatch::start(){
    // if (status == RUNNING || status == UNINITIALIZED)
    _time_start = high_resolution_clock::now();

    status = RUNNING;
}

void Stopwatch::stop(){
    // if (status == RUNNING)
    _time_end = high_resolution_clock::now();

    _duration += (_time_end - _time_start);
    status = STOPPING;
}

void Stopwatch::reset(){
    status = UNINITIALIZED;
    _duration = high_resolution_clock::duration::zero();
}

double Stopwatch::get_minutes(){
    return minutes_type(_duration).count();
}

double Stopwatch::get_seconds(){
    if(status == UNINITIALIZED){
        return 0.0;
    }
    if(status = RUNNING)
        return seconds_type(high_resolution_clock::now() - _time_start).count();

    return seconds_type(_duration).count();
}

double Stopwatch::get_milliseconds(){
    return milliseconds_type(_duration).count();
}

double Stopwatch::get_nanoseconds(){
    return nanoseconds_type(_duration).count();
}
