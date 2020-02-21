#ifndef _FILTER_H
#define _FILTER_H
#include "elma/elma.h"
#include <deque>
#include <iostream>

using namespace elma;
using namespace std;

class Filter : public Process {
    public:
        Filter(std::string name) : Process(name){
            _total = 0;
        }
        // void read_from_chanl();
        void init(){}
        void start(){}
        void update();
        void stop(){}

        double value();

    private:
        double _total;
        double _curr_val;

        deque <double> _q;
};


#endif