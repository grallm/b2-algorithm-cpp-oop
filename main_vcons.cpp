#include <iostream>
#include <typeinfo>
#include "vconsignee.hpp"

using namespace std;

// Converts boolean result (0/1) to a readable string (false/true)
string condToString(bool cond) {
  return ((cond) ? "true" : "false");
};


void testsLuggages() {
  cout << endl << "TESTS FOR CLASSES Luggage" << endl;

  Luggage* trunk = new Trunk(10,5,5);
  cout << "Trunk(10, 5, 5) volume: " << trunk->getVolume() << endl;
  
  Luggage* backpack = new Backpack(1, 11);
  cout << "Backpack(1, 11) volume: " << backpack->getVolume() << endl;
}

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

  vcons.check();
  vcons2.check();
}


int main() {
  testsVConsignee();
  // testsLuggages();
}