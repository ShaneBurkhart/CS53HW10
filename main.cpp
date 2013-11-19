//////////////////////////////////////////////////////////////////////////////
// Programer: Shane Burkhart         Student ID: 99999
// Assignment: 9 "business"          Filename: main.cpp
// Due Date: 11/12/13                Class: CS53, Section E
// Desc: Program that tests the business and customer classes
//

#include<fstream>
#include<iostream>
#include "customer.h"
#include "business.h"
using namespace std;

int main(){
  // Constants
  const string F_NAME = "items.txt";
  const char NUM_ITEMS = 7;

  // Variables
  ofstream out;

  // Make file
  out.open(F_NAME.c_str());
  for(int i = 0 ; i < NUM_ITEMS ; i ++)
    out << "item" << i << endl;
  out.close();

  // Test Customer
  // Default constructor
  Customer default_customer;

  default_customer.setMoney(1000.10);
  default_customer.purchase("The best item ever!!");

  cout << "===Default Customer===" << endl;
  default_customer.print();

  // Second constructor
  Customer customer("Shane", 100);

  customer.purchase("The best item ever!!");
  customer.purchase("The worst item ever!!");

  cout << "===Second Customer===" << endl;
  customer.print();


  // Test Business
  // Default constructor
  Business default_business;

  default_business.enterCustomer(default_customer);
  default_business.enterCustomer(customer);
  default_business.makeASell();
  default_business.makeASell();

  cout << "===Default Business===" << endl;
  default_business.print();

  // Second constructor
  Business business("Shane Co.", 100, F_NAME);

  business.enterCustomer(default_customer);
  business.enterCustomer(customer);
  business.makeASell();
  business.makeASell();

  cout << "===Second Business===" << endl;
  business.print();

  return 0;
}


