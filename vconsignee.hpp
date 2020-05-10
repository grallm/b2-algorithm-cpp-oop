#ifndef VCONSIGNEE_HPP
#define VCONSIGNEE_HPP

#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include "luggage.hpp"
#include "ticket.hpp"

using namespace std;

class VConsignee {
  private:
    // Locker (where you deposit a Luggage)
    typedef struct {
      unsigned int id;
      unsigned int volume;
      Luggage* luggage;
    } Locker;
    // Queue of all lockers with same volume with the number of them available
    typedef struct {
      unsigned int number;
      queue<Locker> lockers;
    } LockerType;
    
    unsigned int nbLockers; // Global number of lockers
    unsigned int nbFreeLockers; // Global number of free lockers
    map<unsigned int, LockerType> freeLockers; // All locker groups, each associated to their volume
    unordered_map<Ticket, Locker> usedLockers; // Lockers used, full with a bagage

  public:
    VConsignee(vector< pair<unsigned int, unsigned int> > lockers);

    bool isFull();
    bool hasFreeLockerForVolume(unsigned int volume);

    Ticket depositLuggage(Luggage & luggage);
    Luggage* recoverLuggage(Ticket ticket);

    void check() {
      cout << "***** VConsignee check *****" << endl;

      cout << "Total number of lockers : " << nbLockers << endl;
      cout << "Total number of free lockers : " << nbFreeLockers << endl;
      cout << "Total number of volumes : " << freeLockers.size() << endl;
      // Loop all LockerType
      for (pair<unsigned int, LockerType> lockerType : freeLockers) {
        cout << "Vol: " << lockerType.first << " - " << "Size: " << lockerType.second.number << " - " << "Queue size: " << lockerType.second.lockers.size() << endl;
      }

      cout << "****************************" << endl << endl;
    }
};

#endif