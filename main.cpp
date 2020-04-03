#include <iostream>
#include <string>
#include "consignee.hpp"

using namespace std;

// Converts boolean result (0/1) to a readable string (false/true)
string condToString(bool cond) {
  return ((cond) ? "true" : "false");
};

/**
 * Tests of class Ticket
 */
void testsTicket(){
  // Creating 2 tickets, which are different
  Ticket t1 = Ticket();
  Ticket t2 = Ticket();

  // Showing both hashes
  cout << t1.hashCode() << endl;
  cout << t2.hashCode() << endl << endl;

  // Comparing tickets with operator ==
  cout << "t1 = t1 : " << condToString(t1 == t1) << endl;
  cout << "t1 = t2 : " << condToString(t1 == t2) << endl << endl;

  // Comparing tickets with operator !=
  cout << "t1 ≠ t1 : " << condToString(t1 != t1) << endl;
  cout << "t1 ≠ t2 : " << condToString(t1 != t2) << endl;
}

/**
 * Tests of class Consignee
 */
void testsConsignee(){
  // Creating a Consignee
  Consignee cons = Consignee(1);

  // Testing isFull
  cout << "isFull : " << condToString(cons.isFull()) << endl << endl;

  // Creating a luggage and depositing it
  Luggage lug = "Luggage no 1";
  Ticket ticket = cons.depositLuggage(lug);
  cons.depositLuggage(lug);
  cons.depositLuggage(lug);
  cons.check();
  cons.recoverLuggage(ticket);
  cons.check();
  cons.recoverLuggage(ticket);
  cons.check();
}


int main() {
  // testsTicket();
  testsConsignee();
}