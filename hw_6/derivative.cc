#include "derivative.h"


double last_x=0;

void Derivative::update(){
    _last_x = last_x;
    _current_x = channel("link").latest();
    last_x = _current_x;

}

double Derivative::value(){
    _sum = (_current_x - last_x) / delta();
    return _sum;
}

