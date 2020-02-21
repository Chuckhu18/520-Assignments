#include "integrator.h"
#include <iostream>


void Integrator::update(){
    _current_val = channel("link").latest();
    _sum += delta() * _current_val;
    cout <<"delta:"<< delta() <<endl;
}

double Integrator::value(){
    return _sum;
}

