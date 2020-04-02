#include <iostream>
#include <string>

using namespace std;

class Ticket {
  private:
    string idCode; // Stockage 

  public:
    Ticket(); // Constructor of a ticket
    
    size_t hashCode() const;

    bool operator==(Ticket const& t) const;
    bool operator!=(Ticket const& t) const;
};

template<> struct hash<Ticket> {
  size_t operator()(const Ticket& t) const
  {
    return t.hashCode();
  }
};