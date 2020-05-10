#include <stdexcept>
#include "vconsignee.hpp"

using namespace std;

/**
 * Constructing VConsignee with vector (list) of pairs (volume of lockers, number of them)
 * @param lockers vector of pairs (volume of lockers, number of them)
 */
VConsignee::VConsignee(vector< pair<unsigned int, unsigned int> > lockers) {
  if (lockers.size() == 0) {
    // Consignee with 0 lockers
    nbLockers = nbFreeLockers = 0;

  } else {
    int idLocker = 0;
    for(pair<unsigned int, unsigned int> lockerNbVol : lockers) {
      // Creating the LockerType, getting the number of lockers for a specific volume
      LockerType lType;
      lType.number = lockerNbVol.first;

      // Creating all the lockers of the volume, adding them in the queue
      queue<Locker> typeQueue;
      for(size_t i=0; i<lockerNbVol.first; i++){
        Locker newLocker;
        newLocker.id = idLocker;
        newLocker.volume = lockerNbVol.first;
        typeQueue.push(newLocker);

        idLocker++;
      }
      // Adding the queue in LockerType
      lType.lockers = (queue<Locker> *) malloc(sizeof(typeQueue));
      cout << "HERE3" << endl;
      cout << typeQueue.size() << endl;
      cout << sizeof(*(lType.lockers)) << endl;
      *(lType.lockers) = typeQueue;

      // Insert pair (volume, LockerType): sorts automatically because of map type
      (this->freeLockers).insert(make_pair(lockerNbVol.second, lType));
    }

    // Total number of lockers
    (this->nbLockers) = idLocker;
    (this->nbFreeLockers) = idLocker;
  }
}

/**
 * Check if all VConsignee's lockers are used, if it can take more luggages
 * 
 * @return true if the consignee doesn't have free lockers anymore
 */
bool VConsignee::isFull() {
  return nbFreeLockers == 0;
}

/**
 * Check if VConsignee has an available locker for a specified volume
 * = With a volume equal or greater
 * 
 * @exception invalid_argument when volume is less than 1
 * @return true if the consignee doesn't have free lockers anymore
 */
bool VConsignee::hasFreeLockerForVolume(unsigned int volume) {
  if (volume < 1) {
    throw invalid_argument("ERR: volume can't be less than 1");
  }
  // If no lockers are available or if the volume is greater than bigger locker's
  if (this->isFull()) {
    return false;
  } else {
    map<unsigned int, LockerType>::iterator it_freeLockers = freeLockers.upper_bound(volume);
    
    // If there is a greater locker, there is space
    if (it_freeLockers->first >= volume && (it_freeLockers->second).number > 0) {
      return true;
    // If there is a perfect fit locker available, there is space
    } else if (volume == (--it_freeLockers)->first && (it_freeLockers->second).number > 0) {
      return true;
    } else {
      // End element and no volume greater
      return false;
    }
  }
}

/**
 * Allows to put a Lugagge in a locker
 * 
 * @param luggage is the Luggage to deposit
 * @pre VConsignee shouldn't be full to add a luggage
 * @throw length_error if the VConsignee is full
 * @return the Ticket corresponding to the Luggage, allowing to get it back
 */
Ticket VConsignee::depositLuggage(Luggage & luggage){
  unsigned int lugVolume = luggage.getVolume();
  cout << lugVolume << endl;
  // Can't another luggage if the Consignee is full (no more Lockers)
  if (!this->hasFreeLockerForVolume(lugVolume)) {
    throw length_error("ERR: you can't deposit a Luggage, no more Lockers are free for this volume");
  }

  // Get the best available volume: perfect fit or greater
  map<unsigned int, LockerType>::iterator it_freeLockers = freeLockers.upper_bound(lugVolume);

  // Locker that perfect fits luggage's volume
  if (it_freeLockers != freeLockers.begin() && (--it_freeLockers)->first == lugVolume) {
    // Remove from freeLockers the first locker and link it to the luggage
    Locker locker = (*(it_freeLockers->second.lockers)).front();
    (*(it_freeLockers->second.lockers)).pop();
    locker.luggage = &luggage;

    // Remove LockerType from freeLockers if no more lockers in queue
    nbFreeLockers--;
    if (--(it_freeLockers->second.number) == 0) {
      freeLockers.erase(it_freeLockers);
    }

    // Generate the ticket
    Ticket ticket = Ticket();
    (this->usedLockers).insert({ ticket, locker });

    return ticket;

  } else {
    // Get back to first volume greater
    ++it_freeLockers;
  }

  // Remove the first Locker in the queue of free ones
  /* Locker locker = (this->freeLockers).front();
  (this->freeLockers).pop();
  locker.luggage = luggage;

  // Generate a Ticket for this Locker and put it in the used ones
  Ticket ticket = Ticket();
  (this->usedLockers).insert({ ticket, locker });

  return ticket; */
}

/**
 * Destruct the object VConsignee and all allocated variables
 */
VConsignee::~VConsignee() {
  // Deallocate all queue of Lockers
  for (pair<unsigned int, LockerType> lockerType : freeLockers) {
    delete lockerType.second.lockers;
  }
}
