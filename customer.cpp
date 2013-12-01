//////////////////////////////////////////////////////////////////////////////
// Programer: Shane Burkhart         Student ID: 99999
//            Brendan Nulsen
// Assignment: 9 "business"          Filename: main.cpp
// Due Date: 11/12/13                Class: CS53, Section E
// Desc: Implementation file for customer class
//

#include<iostream>
#include<string>
#include "customer.h"
using namespace std;


bool Customer::buy_something(const string desc)
{
  if(num_purchases >= MAX_PURCHASES)
    return false;
  purchases[num_purchases] = desc;
  num_purchases ++;
  return true;
}

string Customer::getName() const
{
  return this->name;
}

float Customer::getMoney() const
{
  return this->spending_money;
}

void Customer::setMoney(const float spending_money)
{
  this->spending_money = spending_money;
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
  cout << c.name << " has $" << c.spending_money << " and purchases";
  for(int i = 0; i < c.num_purchases; i++)
    cout << " " << c.purchases[i];
  cout << endl;
  return stream;
}
