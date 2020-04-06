#include <iostream>
#include <typeinfo>
#include "vconsignee.hpp"

using namespace std;

// Converts boolean result (0/1) to a readable string (false/true)
string condToString(bool cond) {
  return ((cond) ? "true" : "false");
};


void testsVConsignee() {
  vector<pair<unsigned int,unsigned int> > listLockers { make_pair<unsigned int, unsigned int>(50, 5), make_pair<unsigned int, unsigned int>(70, 5) };
  VConsignee vcons = VConsignee(listLockers);

  vcons.check();
}


int main() {
  testsVConsignee();
}