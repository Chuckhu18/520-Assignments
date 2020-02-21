#include "random_process.h"

int temp = 1;

double RandomProcess::send_rand(){
    _rand_double = ((double) rand() / (RAND_MAX));// in the range 0-1
    
    // cout << "#"<< temp<<": " <<_rand_double << "\n";
    // temp++;

    return _rand_double;
}

void RandomProcess::update(){
    // cout << temp <<"\n";
    // channel("link").send(temp%2);
    channel("link").send(send_rand());
    // temp++;
}
