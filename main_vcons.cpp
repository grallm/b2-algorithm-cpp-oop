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
  cout << endl << "TESTS FOR CLASS VConsignee" << endl;

  // Creating a VConsignee with multiple lockers with 2 different volumes
  vector<pair<unsigned int,unsigned int> > listLockers {
    make_pair<unsigned int, unsigned int>(5, 70),
    make_pair<unsigned int, unsigned int>(5, 50)
  };
  VConsignee vcons = VConsignee(listLockers);
  vector<pair<unsigned int,unsigned int> > listLockers2 {};
  VConsignee vcons2 = VConsignee(listLockers2);

  // Checking if VConsignee is full (when it isn't)
  cout << endl << "isFull when not : " << condToString(vcons.isFull()) << endl;
  // Checking if VConsignee is full when there is no locker
  cout << "isFull when 0 locker : " << condToString(vcons2.isFull()) << endl;

  // Testing if there is availability for volumes
  cout << endl << "Space for strictly greater than max (71) : " << condToString(vcons.hasFreeLockerForVolume(71)) << endl;
  cout << "Space for strictly equal (70) : " << condToString(vcons.hasFreeLockerForVolume(70)) << endl;
  cout << "Space for strictly lower than max (51) : " << condToString(vcons.hasFreeLockerForVolume(51)) << endl;
  cout << "Space for strictly lower than min (49) : " << condToString(vcons.hasFreeLockerForVolume(49)) << endl;


  vcons.check();
  vcons2.check();
}

void depositVConsignee() {
  cout << endl << "TESTS FOR depositing Luggage WITH CLASS VConsignee" << endl;

  // Creating a VConsignee with only one locker
  vector<pair<unsigned int,unsigned int> > listLockers {
    make_pair<unsigned int, unsigned int>(1, 70)
  };
  VConsignee vcons = VConsignee(listLockers);

  // Deposit a perfect fit luggage
  Luggage* trunk = new Trunk(70, 1, 1);
  vcons.depositLuggage(*trunk);
  cout << endl << "Is VConsignee with 1 locker and 1 luggage full : " << condToString(vcons.isFull()) << endl;

  // Try to add another luggage in a full VConsignee
  try {
    Luggage* trunk2 = new Trunk(70, 1, 1);
    vcons.depositLuggage(*trunk2);
  } catch (exception const& err) {
    cout << endl << err.what() << endl;
  }

  // Try to add a too big luggage
  VConsignee vcons2 = VConsignee(listLockers);
  try {
    Luggage* trunk3 = new Trunk(80, 1, 1);
    vcons.depositLuggage(*trunk3);
  } catch (exception const& err) {
    cout << endl << err.what() << endl;
  }

  // Adding a luggage with a volume less than locker's volume
  Luggage* trunk3 = new Trunk(60, 1, 1);
  vcons2.depositLuggage(*trunk3);
}


int main() {
  // testsVConsignee();
  depositVConsignee();
  // testsLuggages();
  /* map<int, int> test = {
    {2,2},
    {3,1},
    {1,3}
  };
  auto it = test.upper_bound(1);
  // cout << (--it)->second << endl;
  cout << it->second << endl; */
  
}