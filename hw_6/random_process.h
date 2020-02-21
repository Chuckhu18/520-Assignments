#ifndef _RANDOM_PROCESS_H
#define _RANDOM_PROCESS_H
#include <iostream>
#include "elma/elma.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;
using namespace elma;



class RandomProcess : public Process {
    public:
        RandomProcess(string name) : Process(name){
            srand(time(NULL));
        }
        // srand(time(NULL));
        void init(){}
        void start(){}
        void update();

        void stop(){}

        double send_rand();

    private:
        double _rand_double;

};



#endif
