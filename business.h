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
#include "product.h"
using namespace std;

// Business constants
const char MAX_ITEMS = 10;
const char MAX_CUSTOMERS = 10;
const float ITEM_PRICE = 40;

class Business
{
  public:
    Business():name(""), money(0), numItems(0), numCustomers(0){};
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
    void sellStuff();

    //Pre: None
    //Post: Copies customers from the customers array and then sets num_cust
    //to zero.
    //Description: All customers are removed from the business.
    void customersLeave(Customer c[], int num);

  private:
    string name;
    float money;
    Product items[MAX_ITEMS];
    Customer customers[MAX_CUSTOMERS];
    short numItems;
    short numCustomers;
};

#endif
