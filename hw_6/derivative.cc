#include "derivative.h"
#include <iostream>


double last_x=0;

void Derivative::update(){
    // _last_x = last_x;
    last_x = _current_x;
    _current_x = channel("link").latest();
    

}

double Derivative::value(){
    _sum = (_current_x - last_x) / delta();
    cout<<"sum:"<<_sum<<"\n";
    return _sum;
}

