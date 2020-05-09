#include <iostream>
#include <typeinfo>
#include "vconsignee.hpp"

using namespace std;

// Converts boolean result (0/1) to a readable string (false/true)
string condToString(bool cond) {
  return ((cond) ? "true" : "false");
};


void testsVConsignee() {
  // Creating a VConsignee with multiple lockers with 2 different volumes
  vector<pair<unsigned int,unsigned int> > listLockers {
    make_pair<unsigned int, unsigned int>(5, 50),
    make_pair<unsigned int, unsigned int>(5, 70)
  };
  VConsignee vcons = VConsignee(listLockers);
  vector<pair<unsigned int,unsigned int> > listLockers2 {};
  VConsignee vcons2 = VConsignee(listLockers2);

  // Checking if VConsignee is full (when it isn't)
  cout << "isFull when not : " << condToString(vcons.isFull()) << endl;
  // Checking if VConsignee is full when there is no locker
  cout << "isFull when 0 locker : " << condToString(vcons2.isFull()) << endl;

  vcons2.check();
}


int main() {
  testsVConsignee();
}