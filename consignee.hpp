#ifndef CONSIGNEE_HPP
#define CONSIGNEE_HPP

#include <iostream>
#include <queue>
#include <unordered_map>
#include "ticket.hpp"

using namespace std;

// Luggage
typedef string Luggage;

// Locker (where you deposit a Luggage)
typedef struct {
  unsigned int id;
  Luggage luggage;
} Locker;

class Consignee {
  private:
    queue<Locker> freeLockers;
    unordered_map<Ticket, Locker> usedLockers;

  public:
    Consignee(int size);
    
    bool isFull();
    
    Ticket depositLuggage(Luggage luggage);
    Luggage recoverLuggage(Ticket ticket);
    
    /** 
     * Useful for debugging the Consignee and its Lockers
    */
    /* void check() {
      cout << "***** Consignee check *****" << endl;
      cout << "Free " << freeLockers.size() << endl;
      cout << freeLockers.front().luggage << " / " << freeLockers.back().luggage << endl << endl;

      cout << "Used " << usedLockers.size() << endl;
      for(auto l: usedLockers){
        cout << "Locker ID : " << l.second.id << " - " << l.second.luggage << endl;
      }
      cout << "****************************" << endl << endl;
    } */
};

#endif