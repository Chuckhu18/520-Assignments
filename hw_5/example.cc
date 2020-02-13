#include "example.h"
#include <cstdlib>
#include <algorithm>

using namespace std;

bool compare(int a, int b) { return (abs(a) < abs(b)); }

void sort_by_magnitude(vector<double>& in){
    sort(in.begin(), in.end(), compare);
}

vector<int> primes(int n){
    int * arr;
    arr = new (nothrow) int[n];
    vector<int> re_vec;
    for (int i=0; i<n; i++){
      arr[n]=0;
    }

    for (int i = 2; i < n; i++) {
        for (int j = i * i; j < n; j+=i) {
            arr[j - 1] = 1;
            }
        }
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] == 0){
            // cout << i << " ";
            re_vec.push_back(i);
        }
    }
    delete[] arr;
    return re_vec;
}

vector<tuple<int,int>> twins(vector<int> nums){
    vector<tuple<int,int>> twin_p;
    tuple<int,int> re;
    vector<int> in = nums;
    // cout<<"size of input vector: "<<in.size()<<endl;
    for (int i=1; i<nums.size(); i++)
        if(nums[i]-nums[i-1]==2){
            re = make_tuple(nums[i-1], nums[i]);
            twin_p.push_back(re);
            // cout<< get<0>(re)<<' '<<get<1>(re)<<endl;
        }

    return twin_p;
}

