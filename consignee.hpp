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
    Consignee(unsigned int size);
    
    bool isFull();
    
    Ticket depositLuggage(Luggage luggage);
    Luggage recoverLuggage(Ticket ticket);
    
    void check();
};