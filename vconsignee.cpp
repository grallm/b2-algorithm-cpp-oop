#include <typeinfo>
#include "vconsignee.hpp"

using namespace std;

/**
 * Constructing VConsignee with vector (list) of pairs (volume of lockers, number of them)
 * @param lockers vector of pairs (volume of lockers, number of them)
 */
VConsignee::VConsignee(vector< pair<unsigned int, unsigned int> > lockers) {
  // Reserve space for vector from a defined size to reduce the cost of adding elements
  (this->freeLockers).reserve(lockers.size());

  int idLocker = 0;
  for(pair<unsigned int, unsigned int> lockerNbVol : lockers) {
    // Creating the LockerType, getting the number of lockers for a specific volume
    LockerType lType;
    lType.number = lockerNbVol.first;
    lType.volume = lockerNbVol.second;
    
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
    *(lType.lockers) = typeQueue;


    // ADD SORTED IN FREELOCKERS
    // CAREFUL IF SAME VOLUME
    (this->freeLockers).push_back(lType);
  }

  // Total number of lockers
  (this->nbLockers) = ++idLocker;
  (this->nbFreeLockers) = idLocker;
}


/**
 * Destruct the object VConsignee and all allocated variables
 */
VConsignee::~VConsignee() {
  // Deallocate all queue of Lockers
  for(LockerType lType : this->freeLockers) {
    delete lType.lockers;
  }
}
