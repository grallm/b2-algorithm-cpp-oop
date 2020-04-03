#include "consignee.hpp"
#include <stdexcept>

using namespace std;

/**
 * Construct a Consignee with size lockers
 * @param size number of lockers in the Consignee
 * @pre
 * @throw 
 */
Consignee::Consignee(int size) {
  if (size < 1) {
    throw invalid_argument("ERR: the Consignee can't have less than 1 Locker");
  }

  // Generating the number of Lockers asked and putting them in the free queue
  for(int i=0; i<size; i++){
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
  // Consignee is full when there are no more free Lockers
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
  // Can't another luggage if the Consignee is full (no more Lockers)
  if (this->isFull()) {
    throw length_error("ERR: you can't deposit a Luggage, no more Lockers are free");
  }

  // Remove the first Locker in the queue of free ones
  Locker locker = (this->freeLockers).front();
  (this->freeLockers).pop();
  locker.luggage = luggage;

  // Generate a Ticket for this Locker and put it in the used ones
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
  // No luggage corresponding to this Ticket if none are found in the usedLockers map
  if (usedLockers.find(ticket) == usedLockers.end()){
    throw out_of_range("ERR: no luggage corresponding to this ticket");
  }

  // Stock the luggage to give bakc
  Luggage deposedLug = (this->usedLockers)[ticket].luggage;

  // Remove the Locker from the used one and put it at the end of the freeLockers queue 
  Locker nowFreeLocker = (this->usedLockers)[ticket];
  (this->usedLockers).erase(ticket);
  (this->freeLockers).push(nowFreeLocker);

  return deposedLug;
}