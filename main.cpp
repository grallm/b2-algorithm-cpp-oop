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
  cout << endl << "TESTS FOR CLASS Ticket" << endl;

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
  cout << endl << "TESTS FOR CLASS Consignee" << endl;

  // Creating a Consignee
  Consignee cons1 = Consignee(1);

  // Testing isFull
  cout << "isFull : " << condToString(cons1.isFull()) << endl;

  // Creating a luggage, depositing it and recovering it
  Luggage lug = "Luggage no 1";
  Ticket ticket = cons1.depositLuggage(lug);
  cout << "isFull when full : " << condToString(cons1.isFull()) << endl;
  Luggage lug2 = cons1.recoverLuggage(ticket);
  cout << "Luggage deposited = Luggage recovered : " << condToString(lug == lug2) << endl << endl;

  // Testing if the queue is working
  // (Uncomment Consignee.check() in 'consignee.hpp' to debug)
  /* Consignee cons2 = Consignee(2);
  Luggage lugg1 = "Lug1", lugg2 = "Lug2";
  Ticket tick1 = cons2.depositLuggage(lugg1);
  Ticket tick2 = cons2.depositLuggage(lugg2);
  cons2.check();
  cons2.recoverLuggage(tick2);
  cons2.recoverLuggage(tick1);
  tick1 = cons2.depositLuggage(lugg1);
  tick2 = cons2.depositLuggage(lugg2);
  cons2.check(); */

  // Testing with multiple luggages (3)
  Consignee cons3 = Consignee(3);
  Luggage luggge1 = "Lug1", luggge2 = "Lug2", luggge3 = "Lug3";
  Ticket tickt1, tickt2, tickt3;
  cout << "isFull before depositing : " << condToString(cons3.isFull()) << endl;
  tickt1 = cons3.depositLuggage(luggge1);
  tickt2 = cons3.depositLuggage(luggge2);
  tickt3 = cons3.depositLuggage(luggge3);
  cout << "isFull after depositing (should) : " << condToString(cons3.isFull()) << endl;
  Luggage recLuggge1, recLuggge2, recLuggge3;
  recLuggge1 = cons3.recoverLuggage(tickt1);
  recLuggge2 = cons3.recoverLuggage(tickt2);
  recLuggge3 = cons3.recoverLuggage(tickt3);
  cout << "isFull after revoering all (shouldn't) : " << condToString(cons3.isFull()) << endl;
  cout << "Luggages deposited = Luggages recovered : " << condToString(luggge1 == recLuggge1 && luggge2 == recLuggge2 && luggge3 == recLuggge3) << endl << endl;
}

void testsErrorsConsignee() {
  cout << endl << "TESTS FOR CLASS Consignee METHODS EXCEPTIONS" << endl;

  // Constructor size error
  try {
    Consignee(0);
  }catch(exception const& err){
    cout << err.what() << endl;
  }
  
  // Adding a Luggage to a full Consignee
  try {
    Consignee cons = Consignee(1);
    Luggage lug = "Lug";
    cons.depositLuggage(lug);
    cons.depositLuggage(lug);
  }catch(exception const& err){
    cout << err.what() << endl;
  }
  
  // Recovering a Luggage with a Ticket but none corresponding
  try {
    Consignee cons = Consignee(1);
    Luggage lug = "Lug";
    Ticket ticket = cons.depositLuggage(lug);
    cons.recoverLuggage(ticket);
    cons.recoverLuggage(ticket);
  }catch(exception const& err){
    cout << err.what() << endl;
  }
}


int main() {
  unsigned int test = 2;
  unsigned int test2 = 3;
  cout << round((test/test2)*1.0) << endl;
  cout << "INFORMATION" << endl;
  cout << "The next log messages are tests to show the functionalities of classes Consignee and Ticket." << endl;
  cout << "To understand each one, see main.cpp" << endl;
  testsTicket();
  testsConsignee();
  testsErrorsConsignee();
}