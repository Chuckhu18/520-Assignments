#ifndef _B_FSM_H
#define _B_FSM_H

#include <iostream>
#include "elma/elma.h"

using namespace elma;
using namespace std;

class BetterStateMachine : public StateMachine{
    BetterStateMachine(string name) : StateMachine(name) {
    }

    json to_json() const;

    
}


#endif