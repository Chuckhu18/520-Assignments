// #ifndef _B_FSM_H
// #define _B_FSM_H

#include <iostream>
#include <json/json.h>
#include <set>
#include "elma/elma.h"

using namespace elma;
using namespace std;
using nlohmann::json;

class BetterStateMachine : public StateMachine{

    public:
    
    BetterStateMachine(string name) : StateMachine(name) {
        this->name = name;
    }

        // {
        //     "name": "binary counter",
        //     "states": ["on", "off"],
        //     "transitions": [
        //         {
        //             "from": "on",
        //             "to": "off",
        //             "when": "switch"
        //         },
        //         {
        //             "from": "off",
        //             "to": "on",
        //             "when": "switch"
        //         }
        //     ]
        // };

    json to_json() const{
        json j = {{"name",name}};
        json k;

        set<string> states;

        // for(int i =0; i<_transitions.size(); i++){}
        for (auto i : _transitions) {
            states.insert(i.from().name());
            states.insert(i.to().name());
            json x;
            x["from"] = i.from().name();
            x["to"] = i.to().name();
            x["when"] = i.event_name();
            k.push_back(x);
        }
        
        j["states"] = states;
        j["transitions"] = k;

        return j;
    }

    private:
        string name;
   
};


// #endif