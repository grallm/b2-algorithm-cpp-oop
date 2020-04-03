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
  Consignee cons1 = Consignee(1);

  // Testing isFull
  cout << "isFull : " << condToString(cons1.isFull()) << endl;

  // Creating a luggage, depositing it and recovering it
  Luggage lug = "Luggage no 1";
  Ticket ticket = cons1.depositLuggage(lug);
  cout << "isFull when full : " << condToString(cons1.isFull()) << endl << endl;
  Luggage lug2 = cons1.recoverLuggage(ticket);
  cout << "Luggage deposited = Luggage recovered : " << condToString(lug == lug2) << endl;

  // Testing if the queue is working
  // (Uncomment Consignee.check() to debug)
  Consignee cons2 = Consignee(2);
  Luggage lugg1 = "Lug1", lugg2 = "Lug2";
  Ticket tick1 = cons2.depositLuggage(lugg1);
  Ticket tick2 = cons2.depositLuggage(lugg2);
  cons2.check();
  cons2.recoverLuggage(tick2);
  cons2.recoverLuggage(tick1);
  tick1 = cons2.depositLuggage(lugg1);
  tick2 = cons2.depositLuggage(lugg2);
  cons2.check();

  // Testing with multiple luggages (3)
  // Consignee cons3 = Consignee(3);
  // Luggage lug1 = "Lug1", lug2 = "Lug2", lug3 = "Lug3";
  // Ticket ticket1, ticket2, ticket3;

}


int main() {
  // testsTicket();
  testsConsignee();
}