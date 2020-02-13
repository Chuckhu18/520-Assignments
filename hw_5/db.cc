#include <exception>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "db.h"

using namespace std;

DB::DB() : _next_key(0) {}

double DB::accumulate(function<double(const Row)> f) const{

}


int DB::size() const{
    int re_size = 0;
    for(auto [key,value]: _data){
        re_size++;
        // cout<<re_size<<' ';
    }
    return re_size;
}

DB &DB::creat_test_data(int n){
    srand(time(NULL));
    for(int i=0; i<n; i++){
        double new_mass = (rand() % 100000 + 1)/99.99; // in the range 0.01-1,000
        double new_dis = (rand() % 100000000 +1)/9.9 ;// in the range 0.1-10,000,000
        string new_name = randomName();

        // cout<<"==============="<<endl;
        // cout << new_name << endl;
        // cout << new_mass << endl;
        // cout << new_dis << endl;
        insert(new_name, new_mass, new_dis);
    }

    return *this;
}

string randomName() {
    char consonents[] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z'};
    char vowels[] = {'a','e','i','o','u','y'};
    string name = "";

    int random = 0;
    int count = 0;

    for(int i = 0; i < 8; i++) {
        random = rand() % 2;
        if(random < 2 && count < 2) {
            name = name + consonents[rand() % 19];
            count++;
        }else {
            name = name + vowels[rand() % 5];
            count = 0;
        }
    }
    return name;
}

DB::Row DB::find_by_name(const string name) const{
    int flag = 0;
    Row re_row;
    for(auto [key,value]: _data){
        Row row = to_row(key,value);
        if (NAME(row) == name){
            flag++;
            re_row = to_row(key,value);
        }
    }
    if(flag == 0)
        throw runtime_error("Could not find row by name");

    return re_row;
}
DB &DB::insert(const string name, double mass, double distance) {
    for(auto [i,j]: _data){
        Row row = to_row(i,j);
        if (NAME(row) == name)
            throw runtime_error("Name already exists");
    }

    int key = _next_key++;
    _data[key] = make_tuple(name, mass, distance);
    return *this;

}

DB &DB::drop(int key) {

    auto e = _data.find(key);

    if ( e != _data.end() ) {
        _data.erase (e);
    }

    return *this;
}

DB::Row DB::to_row(int key, const DB::Value value) const {
    return make_tuple(key, get<0>(value), get<1>(value), get<2>(value));
}

DB::Row DB::find(int key) const {

    auto e = _data.find(key);

    if ( e != _data.end() ) {
        return to_row(key,e->second);
    } else {
        throw runtime_error("Could not find an entry with the given key");
    }

}

vector<DB::Row> DB::where(function<bool(const DB::Row)> f) const {
    vector<Row> rows;

    for( auto [key, value] : _data ) {
        auto row = to_row(key,value);
        if ( f(row) == true ) {
            rows.push_back(row);
        }
    }

    return rows;

}

