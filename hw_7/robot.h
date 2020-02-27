#ifndef _ROBOT_H
#define _ROBOT_H

#include <iostream>
#include "elma/elma.h"

using namespace elma;
using namespace std;
/* robot.h sudo
class Robot : public State/StateMachine
init => setup all states and transitions
//=> Microwave.h

class Mode // for states
// for all other states 
//=> ToggleSwitch


State -> Robot
Process -> StateMachine
*/

class Mode : public State {
    public:
    Mode() : State() {}
    Mode(string name) : State(name) {}
    void entry(const Event& e) {
        cout << "entering " + name() << "\n";
    }
    void during() {}
    void exit(const Event&) {}
};

class Robot : public StateMachine{
    public:
    Robot(string name) : StateMachine(name) {
        set_initial(Wander);
        add_transition("intruder detected", Wander, Make_Noise);
        add_transition("reset", Make_Noise, Wander);
        add_transition("reset", Evade, Make_Noise);
        add_transition("proximity warning", Make_Noise, Evade);
        add_transition("battery low", Evade, Find_Recharge_Station);
        add_transition("battery low", Wander, Find_Recharge_Station);
        add_transition("found recharge station", Find_Recharge_Station, Recharge);
        add_transition("battery full", Recharge, Wander);
    }

    private:
    Mode Wander = Mode("Wander");
    Mode Make_Noise = Mode("Make Noise");
    Mode Evade = Mode("Evade");
    Mode Recharge = Mode("Recharge");
    Mode Find_Recharge_Station = Mode("Find Recharge Station");
};


#endif