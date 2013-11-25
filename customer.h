//////////////////////////////////////////////////////////////////////////////
// Programer: Shane Burkhart         Student ID: 99999
//	      Brendan Nulsen
// Assignment: 9 "business"          Filename: main.cpp
// Due Date: 11/12/13                Class: CS53, Section E
// Desc: Header file for customer class
//

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include<string>
#include<cstdlib>
using namespace std;

// Customer constants
const char MAX_PURCHASES = 20;
const int MAX_MONEY = 250;
const int MIN_MONEY = 4;
const int MAX_HAP = 101;

struct product
{
  string prodName;
  float prodPrice;
};

class Customer{
  public:
    Customer():num_purchases(0), name("")
    {
      this->spending_money = rand() % (MAX_MONEY - MIN_MONEY + 1) + MIN_MONEY;
      happiness = rand() % MAX_HAP;
    }

    Customer(string name, float money):num_purchases(0),
      spending_money(money), name(name){}

    // Pre: Valid string
    // Post: Whether or not the purchase was made
    // Desc: Adds an item desc to customer purchases
    bool purchase(const string desc);

    // Pre: None
    // Post: Name of customer
    // Desc: Gets customer name
    string getName() const;

    // Pre: None
    // Post: Money customer has
    // Desc: Gets customer money
    float getMoney() const;

    // Pre: Greater than or equal to zero
    // Post: None
    // Desc: Sets customer money
    void setMoney(const float money);

    // Pre: None
    // Post: None
    // Desc: Prints a customer in the format specified
    void print();


  private:
    short num_purchases;
    product purchases[MAX_PURCHASES];
    float spending_money;
    string name;
    int happiness;
    bool destination;
};

#endif
