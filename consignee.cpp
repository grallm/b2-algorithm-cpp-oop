#include "consignee.hpp"

using namespace std;

/**
 * Construct a Consignee with size lockers
 * @param size number of lockers in the Consignee
 * @pre
 * @throw 
 */
Consignee::Consignee(unsigned int size) {
  for(size_t i=0; i<size; i++){
    Locker lock;
    lock.id = i;

    (this->freeLockers).push(lock);
  }
}

/**
 * Check if all Consignee's lockers are used, if it can take more luggages
 * @return true if the consignee doesn't have free lockers anymore
 */
bool Consignee::isFull() {
  return (this->freeLockers).empty();
}

/**
 * Allows to put a Lugagge in a locker
 * @param luggage is the Luggage to deposit
 * @pre TODO
 * @throw TODO
 * @return the Ticket corresponding to the Luggage, allowing to get it back
 */
Ticket Consignee::depositLuggage(Luggage luggage){
  if (this->isFull()) {
    // throw
  }

  Locker locker = (this->freeLockers).front();
  locker.luggage = luggage;

  Ticket ticket = Ticket();
  (this->usedLockers).insert({ ticket, locker });

  return ticket;
}

/**
 * Recover the Luggage given earlier with the corresponding Ticket
 * @param ticket given when deposed
 * @pre TODO
 * @throw TODO
 * @return Luggage given corresponding to ticket
 */
Luggage Consignee::recoverLuggage(Ticket ticket){
  Luggage deposedLug = (this->usedLockers)[ticket].luggage;

  Locker nowFreeLocker = (this->usedLockers)[ticket];
  (this->usedLockers).erase(ticket);
  (this->freeLockers).push(nowFreeLocker);

  return deposedLug;
}

void Consignee::check() {
  cout << "Free " << freeLockers.size << endl;
  cout << freeLockers.front().luggage << " / " << freeLockers.back().luggage << endl << endl;

  cout << "Used " << usedLockers.size << endl;
  for(auto l: usedLockers){
    cout << l.second.luggage << endl << endl;
  }
}