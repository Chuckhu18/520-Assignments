#ifndef _FILTER_H
#define _FILTER_H
#include "elma/elma.h"

using namespace elma;

class Filter : public Process {
    public:
        Filter(std::string name) : Process(name){}
        void read_from_chanl();

        double value();
        
};


#endif