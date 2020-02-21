#include "filter.h"


void Filter::update(){
    _curr_val = channel("link").latest();
    if(_q.size()>=10)
        _q.pop_front();
    _q.push_back(_curr_val);
}

double Filter::value(){
    _total = 0;
    
    int que_size = _q.size();
    cout << "queue size:"<<que_size<<"\n";

    for (int i=0; i<que_size; i++){
        _total += _q.front();
        _q.pop_front();
    }

    if (que_size < 10)
        return _total/que_size;

    return _total/10;
}