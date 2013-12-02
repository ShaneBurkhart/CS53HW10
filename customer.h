//////////////////////////////////////////////////////////////////////////////
// Programer: Shane Burkhart         Student ID: 99999
//	      Brendan Nulsen
// Assignment: 10 "business"          Filename: main.cpp
// Due Date: 12/4/13                Class: CS53, Section E
// Desc: Header file for customer class
//

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include<string>
#include<cstdlib>
#include "product.h"
using namespace std;

// Customer constants
const char MAX_PURCHASES = 20;
const int MAX_MONEY = 250;
const int MIN_MONEY = 4;
const int MAX_HAP = 101;
const int SUCCESS_BUY = 15;
const int FAILED_BUY = 10;
const int NUM_CUSTOMERS = 20;
const char CUSTOMER_FILE[11] = "people.txt";

class Business;

class Customer
{
  const int SUCCESS_THROW_PERP = 5;
  const int SUCCESS_THROW_VICTIM = 20;
  const int FAILED_THROW_PERP = 25;
  const string CUSTOMER_FILE = "people.txt";

  public:
    Customer():numPurchases(0), name("")
    {
      this->spendingMoney = rand() % (MAX_MONEY - MIN_MONEY + 1) + MIN_MONEY;
      happiness = rand() % MAX_HAP;
    }

    Customer(string name, float money):numPurchases(0),
      spendingMoney(money), name(name)
    {
      happiness = rand() % MAX_HAP;
    }

    // Pre: Valid string
    // Post: Whether or not the purchase was made
    // Desc: Adds an item desc to customer purchases
    bool buySomething(const Business & b);

    // Pre: None
    // Post: Name of customer
    // Desc: Gets customer name
    string getName() const;

    // Pre: valid string
    // Post: none
    // Desc: Sets customer name
    void setName(string name);

    //pre: none.
    //post: returns happiness level.
    //desc: gets the happiness level of a customer.
    void getInclination() const;

    // Pre: false is moe and true is cbg
    // Post: none
    // Desc: Sets customer inclination
    void setInclination(bool inclination);

    // Pre: None
    // Post: Money customer has
    // Desc: Gets customer money
    float getMoney() const;

    // Pre: Greater than or equal to zero
    // Post: None
    // Desc: Sets customer money
    void setMoney(const float money);

    //pre: between 0 - 100.
    //post: happiness set to value.
    //desc: sets the happiness of customer.
    void setHappiness(const int happiness);

    //pre: none.
    //post: item taken from customer's array and happiness changes accordingly.
    //desc: simulates customer throwing items at another customer.
    void throws(const Customer & c);

    //pre: none.
    //post: item taken from one customer's array and added to the others.
    //desc: simulates customer robbing another customer.
    void rob(const Customer & c);

    //pre: none.
    //post: customer output to screen.
    //desc: allows you to output customer class to screen.
    friend ostream & operator << (ostream & stream, const Customer & c);

    //pre: Customer array with num of customers passed in
    //post: none
    //desc: reads customers in from file and sets names and inclinations
    static void readCustomers(Customer customers[], int num_customers);



  private:
    short numPurchases;
    Product purchases[MAX_PURCHASES];
    float spendingMoney;
    string name;
    int happiness;
    bool inclination;
};

#endif
