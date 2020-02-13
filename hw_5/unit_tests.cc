#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include <cctype>
#include <numeric>      // std::accumulate
#include "example.h"
#include "db.h"

namespace {

  using namespace std;

  TEST(Example,Sort){
    double mya[] = {3,-2,1};
    vector<double> myvector (mya, mya+3);
    sort_by_magnitude(myvector);

    cout << "myvector contains:";
    for (vector<double>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
      cout << ' ' << *it;
    cout << endl;
  }

  TEST(Example,Prime){
    int n = 100;
    vector<int> myvector = primes(n);

    cout << "primes less than "<< n <<":";
    for (auto it=myvector.begin(); it!=myvector.end(); ++it)
      cout << ' ' << *it;
    cout << endl;
  }
  
  TEST(Example,Tuple){
    int n = 1000;
    vector<int> v = primes(n);
    
    tuple<int, int> temp;
    cout << "twin primes less than "<< n <<":";
    vector<tuple<int,int>> twin_p = twins(v);

    cout<<'[';
    for ( const auto& i : twin_p ) {
      cout <<'('<< get<0>(i) <<','<< get<1>(i)<<')'<< ',';
    }
    cout<<']'<<endl;

  }

  TEST(DB, Insert){
    DB db;
    db.insert("Mars", 1.234, 2.345)
      .insert("Jupiter", 123.232, 23123.23)
      .insert("Mercury", 4545.34, 43434.34);
    try{
      db.insert("Mars", 1.1111, 2.2222);
    } catch (runtime_error e) {
      ASSERT_STREQ(e.what(),"Name already exists");
    }
  }

  TEST(DB, FindbyName){
    DB db;
    db.insert("Mars", 1.234, 2.345)
      .insert("Earth",0,0);
    try{
      db.find_by_name("Mercury");
      FAIL();
    } catch (runtime_error e) {
      ASSERT_STREQ(e.what(), "Could not find row by name");
    }
  }

  TEST(DB, CreateTestData){
    DB db;
    db.creat_test_data(100);
    cout<<"size: "<< db.size() <<endl;

    for(int i=0; i<db.size(); i++){
      DB::Row row = db.find(i);
      cout << KEY(row)<<":"<<NAME(row)<<", "<<MASS(row)<<", "<<DISTANCE(row)<<endl;
    }
  }

  TEST(DB, Accumulate){
    DB db;
    db.creat_test_data(5);
    for(int i=0; i<db.size(); i++){
      DB::Row row = db.find(i);
      cout << KEY(row)<<":"<<NAME(row)<<", "<<MASS(row)<<", "<<DISTANCE(row)<<endl;
    }
    double total_mass = db.accumulate([](DB::Row row) { return MASS(row); });
    cout << "total mass:"<<total_mass<<endl;
  }

  TEST(DB, Avg){
    DB db;
    db.creat_test_data(5);
    for(int i=0; i<db.size(); i++){
      DB::Row row = db.find(i);
      cout << KEY(row)<<":"<<NAME(row)<<", "<<MASS(row)<<", "<<DISTANCE(row)<<endl;
    }

    cout<<"avg mass" << db.average_mass() <<endl;
    cout<<"avg distance" << db.average_distance() <<endl;
  }

}

