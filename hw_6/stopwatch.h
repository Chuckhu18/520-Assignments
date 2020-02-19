#ifndef _STOPWATCH_H
#define _STOPWATCH_H

class Stopwatch {
    public:
        void start();              // starts the timer
        void stop();               // stops the timer
        void reset();              // sets stopwatch to zero
        double get_minutes();      // number of minutes counted, as a double
        double get_seconds();      // number of seconds counted, as a double
        double get_milliseconds(); // number of milliseconds counted, as a double
        double get_nanoseconds();  // number of nanoseconds counted, as a double

    private:
        int minites;

};


#endif