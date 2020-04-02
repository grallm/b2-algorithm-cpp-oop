#include "ticket.hpp"
#include <functional>

using namespace std;

/**
 * Ticket's constructor
 * Generating a unique ID (hash) for the ticket
 */
hash<string> strHash;
Ticket::Ticket() {
  string notHashed = "";
  for(int i=0; i < 5; i++)
    notHashed += notHashed + to_string(rand());

  size_t hashed = strHash(notHashed);
  this->idCode = hashed;
}

/**
 * Ticket's destructor
 */
// Ticket::~Ticket() {}

/**
 * @return ticket's ID, hash
 */
size_t Ticket::hashCode() const {
  return this->idCode;
}

/**
 * If tickets are the same
 * 
 * @return true if equal
 */
bool Ticket::operator==(Ticket const& t) const {
  return this->idCode == t.idCode;
}

/**
 * If tickets are not the same
 * 
 * @return true if different
 */
bool Ticket::operator!=(Ticket const& t) const {
  return this->idCode != t.idCode;
}