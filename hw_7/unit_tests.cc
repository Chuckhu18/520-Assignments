#include "gtest/gtest.h"
#include "elma/elma.h"
#include "robot.h"

using namespace std::chrono;
using namespace elma;

namespace {
   
    TEST(Robot, Event) {

        Robot robot("What a very nice robot.");

        Manager m;
        m.schedule(robot, 10_ms)
         .init()
         .start();

        EXPECT_EQ(robot.current().name(), "Wander");
        m.emit(Event("intruder detected"));
        EXPECT_EQ(robot.current().name(), "Make Noise");
        m.emit(Event("proximity warning"));
        EXPECT_EQ(robot.current().name(), "Evade");
        m.emit(Event("battery full"));
        EXPECT_EQ(robot.current().name(), "Evade");  

        // ETC

    }


}
