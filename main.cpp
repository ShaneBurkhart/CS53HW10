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
  Customer customers[20];

  Customer::readCustomers(customers, 20);

  for(int i = 0 ; i < 20 ; i ++)
    cout << customers[i];

  return 0;
}


