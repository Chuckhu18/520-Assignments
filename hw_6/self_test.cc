#include "gtest/gtest.h"
#include "elma/elma.h"
#include "stopwatch.h"

#define SLEEP std::this_thread::sleep_for(std::chrono::milliseconds(1500))

using namespace std;
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
    cout << w.get_seconds() << "s\n"; // still about 1.5

    w.start();
    SLEEP;
    w.stop();
    cout << w.get_seconds() << "s\n"; // about 3.0

    w.reset();
    cout << w.get_seconds() << "s\n"; // 0.0
}