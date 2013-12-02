//////////////////////////////////////////////////////////////////////////////
// Programer: Shane Burkhart         Student ID: 99999
// Assignment: 9 "business"          Filename: main.cpp
// Due Date: 11/12/13                Class: CS53, Section E
// Desc: Header file for business class
//

#ifndef BUSINESS_H
#define BUSINESS_H

#include<string>
#include "customer.h"
using namespace std;

// Business constants
const char MAX_ITEMS = 10;
const char MAX_CUSTOMERS = 10;
const float ITEM_PRICE = 40;

class Business
{
  public:
    Business():name(""), money(0), num_items(0), num_customers(0){};
    Business(string name, float money, string f_name);

    // Pre: None
    // Post: None
    // Desc: Prints business and all of its members
    void print();

    // Pre: Customer must be initialized
    // Post: None
    // Desc: Adds customer to business.  Simulates walking into a store
    void addCustomer(Customer customer);

    // Pre: None
    // Post: None
    // Desc: Sells a random item to everyone in store if has money
    void sell_stuff();

    void customers_leave(Customer customers[MAX_CUSTOMERS], int num_customers);

  private:
    string name;
    float money;
    product items[MAX_ITEMS];
    Customer customers[MAX_CUSTOMERS];
    short num_items;
    short num_customers;
};

#endif
