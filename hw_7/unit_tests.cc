#include "gtest/gtest.h"
#include "elma/elma.h"
#include "robot.h"
#include "BetterStateMachine.h"

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

    TEST(BETTER_FSM, Toggle) {
        Mode off("off"), on("on");
        BetterStateMachine fsm("better fsm");

        fsm.set_initial(off)
        .set_propagate(false)
        .add_transition("switch", off, on)
        .add_transition("switch", on, off);

        // fsm.to_json().dump();

        json j = fsm.to_json();
        ASSERT_EQ(j["name"], "better fsm");
        ASSERT_EQ(j["states"].size(), 2);
        // ETC.
    }


}
