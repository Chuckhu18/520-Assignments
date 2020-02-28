#ifndef __CHASER_AGENT__H
#define __CHASER_AGENT__H 

#include "enviro.h"

using namespace enviro;

class ChaserController : public Process, public AgentInterface {

    public:
    ChaserController() : Process(), AgentInterface() {}

    void init() {
        goal_x = 0;
        goal_y = 0;
        watch("goal_change", [this](Event e) {
            goal_x = e.value()["x"];
            goal_y = e.value()["y"];
        });
    }
    void start() {}
    void update() {
        move_toward(goal_x, goal_y);
        // track_velocity(20,0);
    }
    void stop() {}

    double goal_x, goal_y;

};

class Chaser : public Agent {
    public:
    Chaser(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    ChaserController c;
};

DECLARE_INTERFACE(Chaser)

#endif