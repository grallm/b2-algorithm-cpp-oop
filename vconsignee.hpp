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
    vector<LockerType> freeLockers; // All locker groups ordered by volume
    unordered_map<Ticket, Locker> usedLockers; // Lockers used, full with a bagage

  public:
    VConsignee(vector< pair<unsigned int, unsigned int> >);
    ~VConsignee();

    bool isFull();

    Ticket depositLuggage(Luggage luggage);
    Luggage recoverLuggage(Ticket ticket);
};

#endif