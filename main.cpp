#include <iostream>
#include <chrono>

using namespace std;

int main() {
  char nts1[] = "Test";
  string str1 (nts1);
  hash<string> str_hash;
  cout << str_hash(str1);
  // using namespace chrono;
  // chrono::milliseconds ms = chrono::duration_cast< chrono::milliseconds >(
  //   chrono::system_clock::now().time_since_epoch()
  // );
  // cout << ms.count() << endl;
  chrono::high_resolution_clock::time_point t1, t2;
  try{

    t1 = chrono::high_resolution_clock::now();
    int64_t t11 = chrono::duration_cast<chrono::milliseconds>(t1.time_since_epoch()).count();
  cout << t11  << endl;
  }catch(const exception e){
    throw e;
  }
  try {
    t2 = chrono::high_resolution_clock::now();
    int64_t t21 = chrono::duration_cast<chrono::milliseconds>(t2.time_since_epoch()).count();
  cout << t21 << endl;
  }catch(const exception e){
    throw e;
  }
  
  // chrono::milliseconds ms2 = chrono::duration_cast< chrono::milliseconds >(
  //   chrono::system_clock::now().time_since_epoch()
  // );
  // cout << ms2.count() << endl;
  // cout << t2.time_since_epoch().count() << endl;
}