#include "example.h"
#include <cstdlib>
#include <algorithm>

using namespace std;

bool myfunction(int a, int b) { return (abs(a) < abs(b)); }

void sort_by_magnitude(vector<double>& in){
    sort(in.begin(), in.end(), myfunction);
}

vector<int> primes(int n){
    int * arr;
    arr = new (nothrow) int[n];
    vector<int> re_vec;
    for (int i=0; i<n; i++){
      arr[n]=0;
    }

    for (int i = 2; i < 30; i++) {
        for (int j = i * i; j < 30; j+=i) {
            arr[j - 1] = 1;
            }
        }
    for (int i = 1; i < 30; i++) {
        if (arr[i - 1] == 0){
            cout << i << "\t";
            re_vec.push_back(i);
        }
    }
    delete[] arr;
    return re_vec;
}