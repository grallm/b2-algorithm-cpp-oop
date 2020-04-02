#include <iostream>

using namespace std;

class Ticket {
  private:
    size_t idCode; // Stockage of Ticket's hashcode

  public:
    Ticket(); // Constructor of a ticket
    
    size_t hashCode() const; // Creating a hashcode

    bool operator==(Ticket const& t) const; // Overcharged == operator for Tickets
    bool operator!=(Ticket const& t) const; // Overcharged != operator for Tickets
};

/**
 * Specialized hash<Ticket>
 * Using the ticket's unique ID
 *  */
template<> struct hash<Ticket> {
  size_t operator()(const Ticket &t) const
  {
    return t.hashCode();
  }
};