#ifndef VCONSIGNEE_HPP
#define VCONSIGNEE_HPP

#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
#include "ticket.hpp"

using namespace std;

// Luggage
typedef struct {
  unsigned int volume;
  string content;
} Luggage;

class VConsignee {
  private:
    // Locker (where you deposit a Luggage)
    typedef struct {
      unsigned int id;
      unsigned int volume;
      Luggage luggage;
    } Locker;
    // Queue of all lockers with same volume with the number of them
    typedef struct {
      unsigned int volume;
      unsigned int number;
      queue<Locker>* lockers;
    } LockerType;
    
    unsigned int nbLockers; // Global number of lockers
    unsigned int nbFreeLockers; // Global number of free lockers
    vector<LockerType> freeLockers; // All locker groups ordered by volume
    unordered_map<Ticket, Locker> usedLockers; // Lockers used, full with a bagage

  public:
    VConsignee(vector< pair<unsigned int, unsigned int> > lockers);
    ~VConsignee();

    // bool isFull();

    // Ticket depositLuggage(Luggage luggage);
    // Luggage recoverLuggage(Ticket ticket);

    void check() {
      cout << "***** VConsignee check *****" << endl;

      cout << "Total number of lockers : " << nbLockers << endl;
      cout << "Total number of free lockers : " << nbFreeLockers << endl;
      cout << "Total number of volumes : " << freeLockers.size() << endl;
      // Loop all LockerType
      for(LockerType locker : freeLockers){
        cout << "Vol: " << locker.volume << " - " << "Size: " << locker.number << " - " << "Queue size: " << (*(locker.lockers)).size() << endl;
      }

      cout << "****************************" << endl << endl;
    }
};

#endif