#include "gtest/gtest.h"
#include "elma/elma.h"

#include "stopwatch.h"
#include "random_process.h"
#include "filter.h"

#define SLEEP std::this_thread::sleep_for(std::chrono::milliseconds(1500))

using namespace std;
/*
TEST(SELF, STOPWATCH){

    Stopwatch w; // should set the stopwatch to 0 seconds
    w.start();
    SLEEP;
    w.stop();
    cout << w.get_seconds() << "s = "; // about 1.5 s
    cout << w.get_milliseconds() << "ms = "; //about 1.5e3 ms
    cout << w.get_nanoseconds() << "ns = "; //about 1.5e9 ns
    cout << w.get_minutes() << "m\n"; // minutes
    SLEEP;
    cout << w.get_nanoseconds() << "ns\n"; // still about 1.5

    w.start();
    SLEEP;
    cout << w.get_nanoseconds() << "ns\n"; // 3s
    SLEEP;
    SLEEP;
    w.stop();
    cout << w.get_nanoseconds() << "ns\n"; // about 6.0s

    w.reset();
    cout << w.get_nanoseconds() << "ns\n"; // 0.0
}
*/

TEST(SELF, Process) {
    elma::Manager m;
    
    RandomProcess r("random numbers");
    Filter f("filter");
    elma::Channel link("link");

    m.schedule(r, 1_ms)
     .schedule(f, 1_ms)
     .add_channel(link)
     .init()
     .run(100_ms);
     
     cout << "Average of lastest 10 values is " << f.value() <<endl;
}