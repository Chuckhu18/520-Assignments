#include "random_process.h"


/*
RandomProcess::RandomProcess(string name) : Process(name){    
    srand(time(NULL));
}
RandomProcess::RandomProcess(){    
    srand(time(NULL));
}*/


double RandomProcess::send_rand(){
    _rand_double = ((double) rand() / (RAND_MAX));// in the range 0-1
    cout << "rand num:" <<_rand_double << endl;

    return _rand_double;
}

void RandomProcess::update(){
    channel("link").send(send_rand());
    // if ( channel("link").nonempty() ){
    //     channel("link").send(send_rand());
    // }
}
