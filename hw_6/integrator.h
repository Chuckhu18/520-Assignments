#ifndef _INTEGRATOR_H
#define _INTEGRATOR_H

#include "elma/elma.h"

using namespace std;
using namespace elma;

class Integrator : public Process {
    public:
        Integrator(string name) : Process(name){
            _sum = 0;
        }

        void init(){}
        void start(){}
        void update();
        void stop(){}

        double value();

    private:
        double _sum;
        double _current_val;

};



#endif
