//////////////////////////////////////////////////////////////////////////////
// Programer: Shane Burkhart         Student ID: 99999
//            Brendan Nulsen
// Assignment: 9 "business"          Filename: main.cpp
// Due Date: 11/12/13                Class: CS53, Section E
// Desc: Implementation file for customer class
//

#include<iostream>
#include<fstream>
#include<string>
#include "customer.h"
using namespace std;


bool Customer::buySomething(const string desc)
{
  if(numPurchases >= MAX_PURCHASES)
    return false;
  purchases[numPurchases] = desc;
  numPurchases ++;
  return true;
}

string Customer::getName() const
{
  return this->name;
}

float Customer::getMoney() const
{
  return this->spendingMoney;
}

void Customer::setName(string name)
{
  this->name = name;
  return;
}

void Customer::setInclination(bool inclination)
{
  this->inclination = inclination;
  return;
}

void Customer::setMoney(const float spending_money)
{
  this->spendingMoney = spending_money;
  return;
}

void Customer::throws(const Customer & c1, const Customer & c2)
{

}

void Customer::rob(const Customer & c1, const Customer & c2)
{

}

ostream & operator << (ostream & stream, const Customer & c)
{
  cout << c.name << " has $" << c.spendingMoney << " and purchases";
  for(int i = 0; i < c.numPurchases; i++)
    cout << " " << c.purchases[i];
  cout << endl;
  return stream;
}

static void Customer::readCustomers(Customer customers[], int num_customers)
{
  ifstream fin;
  fin.open(CUSTOMER_FILE);
  for(int i = 0 ; i < num_customer ; i ++)
  {
    string name;
    getline(fin, name, ',');
    customers[i].setName(name);
    fin.ignore(1);
    if(static_cast<char>(fin.peek()) == '-')
      customer[i].setDestination(false);
    else
      customer[i].setDestination(true);
    fin.ignore(100, '\n');
  }
  return;
}



