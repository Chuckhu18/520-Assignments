#ifndef _DERIVATIVE_H
#define _DERIVATIVE_H

#include "elma/elma.h"

using namespace std;
using namespace elma;

class Derivative : public Process {
    public:
        Derivative(string name) : Process(name){
            _sum = 0;
            _current_x=0;
        }

        void init(){}
        void start(){}
        void update();
        void stop(){}

        double value();

    private:
        double _sum;
        double _current_x;
        double _last_x;

};


#endif