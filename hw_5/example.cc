#include "example.h"
#include <cstdlib>
#include <algorithm>

using namespace std;

bool myfunction(int a, int b) { return (abs(a) < abs(b)); }

void sort_by_magnitude(vector<double>& in){
    sort(in.begin(), in.end(), myfunction);
}
